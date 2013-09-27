#include "ir.h"
#include "def.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
// static string int2string(int w,int v)
// {
//   string r;
//   r.resize(w);
//   FOR(i,0,w)
//     {
//       r[i]=(v&1)?'1':'0';
//       v>>=1;
//     }
//   return r;
// }
int main(int argc,char *argv[])
{
  assert(argc==3);
  ifstream fin;
  fin.open(argv[1],ofstream::in);
  Ir ir;
  ir.read_all(fin);
  
  int instr_size=ir.get_instr_size();
  string top_rule_name=ir.get_top_rule_name();
  ofstream fout;
  fout.open(argv[2],ofstream::out);

  fout<<"%{\n";
  fout<<"%}\n";

  fout<<"BLANK [ \\t]+\n";

  fout<<"%%\n";
  //output rules for enum
  int enum_size=ir.get_num_enum();
  FOR(i,0,enum_size)
    {
      Enum enu;
      ir.get_enum(i,enu);
      int enum_ent_size=enu.size();
      int width=0;
      for(;(1<<width)<enum_ent_size;++width)
	;
      FOR(j,0,enum_ent_size)
	fout<<enu.ent_name(j)<<" \""<<enu.ent_code(j)<<"\""<<endl;
      fout<<enu.enum_name()<<" [";
      FOR(j,0,enum_ent_size)
	fout<<'{'<<enu.ent_name(j)<<'}';
      fout<<"]";
      fout<<endl;
    }
  fout<<"BLANK {}\n";
  //fout<<"\\n return 0;\n";

  FOR(i,0,instr_size)
    {
      string n=ir.get_instr_name(i);
      if(n.compare(0,top_rule_name.length(),top_rule_name)==0)
	{
#if ASGEN_COUT==1
	  FR(j,off)
	    cout<<j->first<<' '<<j->second<<endl;
	  cout<<endl<<endl;
#endif
	  vector<ppi> off;
	  ir.get_instr_off(i,off);
	  string code=ir.get_instr_code(i);
	  string binary=ir.get_instr_binary(i);
	  int off_in_code=0,offi=0;
	  sort(off.begin(),off.end());
	  //fout<<off.size()<<' '<<n<<endl;
	  for(typeof(code.begin()) j=code.begin();j!=code.end();)
	    {
	      switch(*j)
		{
		case ' ':
		  for(;j!=code.end() && *j==' ';++j,++off_in_code)
		    ;
		  fout<<"BLANK";
		  break;
		case c_sep:
		  ++j,++off_in_code;
		default:
		  string token;
		  for(;offi<(int)off.size() && off[offi].first<off_in_code;++offi)
		    ;
		  bool is_string=true;
		  if(offi<(int)off.size() && off[offi].first==off_in_code)
		    {
		      //may be a type or enum;
		      is_string=false;
		    }
		  if(!is_string)
		    {
		      assert(*j==c_type_beg || *j==c_enum_beg);
		      ++off_in_code;
		      ++j;
		    }
		  for(;j!=code.end() && *j!=' ' && *j!='\1';++j,++off_in_code)
		    token+=*j;
		  if(is_string)
		    fout<<'"'<<token<<'"';
		  else fout<<'{'<<token<<'}';
		  break;
		}
	    }
	  fout<<"{return \""<<binary<<"\";}"<<endl;
	  fout<<endl;
	}
    }
  return 0;
}
