#include<iostream>
#include <fstream>
#include<cstdio>
#include<vector>
#include<string>
#include "hash.h"
#include <utility>
#include <assert.h>
#include <ctype.h>
#include "ir/ir.cpp"
#include "ir/wire.h"
#include "ir/instruction.h"
using namespace std;
//±íÊ¾AsemµÄivecÓĞĞ§
#define type_is_vector 0

//±íÊ¾AsemµÄnameÓĞĞ§
//±íÊ¾Ã»ÓĞÒıºÅµÄstring£¬¿ÉÄÜÊÇ¹Ø¼ü´Ê£¬²Ù×÷·ûµÈ
#define type_is_string1 1
//±íÊ¾ÓĞÒıºÅµÄstring
#define type_is_string2 2
string reserved[] ={
  "rule",
  "stage","false","true","enum","const","width",
  "size","type","index","read","write","wire","pipe_line",
  "register","like","override","alias","function_unit",
  "instruction","top","select","code","do","binary","switch"};

// ¹şÏ£±í hash controller
class hash_control hc;

class Asem{
public:
  vector<Asem> ivec;
  string name;
  int type;
  Asem * find(const string &name);
};

// ²éÕÒµ±Ç°vectorÖĞÃû×ÖÊÇµÄnameÄÇÒ»Ïî
Asem * Asem::find(const string &name)
{
  if(this->type==type_is_vector)
    for(int i=0;i<this->ivec.size();++i)
      if(this->ivec[i].type==type_is_vector &&
	 this->ivec[i].ivec[0].type==type_is_string1 &&
	 name==this->ivec[i].ivec[0].name)
	return &(this->ivec[i]);
  cout<<"Cannot find "<<name<<endl;
  assert(0);
  return NULL;
}

void gen(Asem &asem){
  int c1;
  while((c1=getchar())!=EOF){
    if(c1==')') return;
    //Ò»¸övector¿ªÊ¼
    else if(c1=='('){
      Asem asem_1;
      asem_1.type=type_is_vector;
      asem.ivec.push_back(asem_1);
      gen(asem.ivec[asem.ivec.size()-1]);
    }
    //´øµ¥ÒıºÅµÄstring
    else if(c1=='\''){
      Asem asem_2;
      asem_2.type=type_is_string2;
      int c2;
      while((c2=getchar())!=EOF && c2!='\'')
	asem_2.name+=c2;
      asem.ivec.push_back(asem_2);
    }
<<<<<<< HEAD
    //ÆÕÍ¨string
    else if(c1!=' '&&c1!='\n'){
=======
    //æ™®é€šstring
    else if(isgraph(c1)){
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
      Asem asem_3;
      asem_3.type=type_is_string1;
      asem_3.name=c1;
      int c3;
      while((c3=getchar())!=EOF && (c3==(int)']' || isalnum(c3) || c3=='_' || c3=='[' || c3=='.'
				    /*TODO è¿™é‡Œåº”è¯¥ä¹Ÿç”¨isgraph,ä½†æ˜¯ä¼šå‡ºç°å¥‡æ€ªçš„æ•ˆæœï¼Œæš‚æ—¶åˆ—ä¸¾]*/))
	asem_3.name+=c3;
      asem.ivec.push_back(asem_3);
      if(c3==')' || c3==EOF)
	return ;
    }
  }
}

void display(const Asem &asem,int lev){
  for(int i=0;i<asem.ivec.size();++i){
    if(asem.ivec[i].type==type_is_vector){
      if(i)
	{
	  cout<<endl;
	  for(int j=0;j<lev;++j)
	    cout<<"  ";
	}
      cout<<'(';
      display(asem.ivec[i],lev+1);
      cout<<')';
    }
    else
      {
	if(i && asem.ivec[i-1].type==type_is_vector)
	  {
	    cout<<endl;
	    for(int j=0;j<lev;++j)
	      cout<<"  ";
	  }
	if(asem.ivec[i].type==type_is_string1)
	  cout<<asem.ivec[i].name<<' ';
	else cout<<'\''<<asem.ivec[i].name<<'\''<<' ';
      }
  }
}

<<<<<<< HEAD
// µİ¹éµÄ²åÈëhash±í
void dfs_insert_hash(const Asem &asem,string pwd)
=======
// é€’å½’çš„æ’å…¥hashè¡¨
void dfs_insert_hash(Asem &asem,string pwd)
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
{
  // Èç¹ûÊÇ¶¨ÒåµÄ±äÁ¿»òÕßÊÇ±£Áô´Ê
  pwd+=".";
  if(asem.ivec[0].type==type_is_string1)
    {
      if(asem.ivec[0].name=="=" || 
	 asem.ivec[0].name=="+" ||
	 asem.ivec[0].name=="if" ||
	 asem.ivec[0].name=="[]")
	return ;
      pwd+=asem.ivec[0].name;
<<<<<<< HEAD
      // ²»Ó¦¸ÃÓĞÖØ¸´¶¨Òå
      assert(NULL==
	     hc.insert(pwd.c_str(),(int)(&asem)));
      assert(sizeof(int)==sizeof(&asem));
=======
      // ä¸åº”è¯¥æœ‰é‡å¤å®šä¹‰
      assert(NULL==hc.insert(pwd.c_str(),(void*)&asem));
      //assert(sizeof(int)==sizeof(&asem));
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
      for(int i=1;i<asem.ivec.size();++i)
	if(asem.ivec[i].type==type_is_vector)
	  dfs_insert_hash(asem.ivec[i],pwd);
    }
  else if(asem.ivec[0].type==type_is_vector)
    {
      for(int i=0;i<asem.ivec.size();++i)
	if(asem.ivec[i].type==type_is_vector)
	  dfs_insert_hash(asem.ivec[i],pwd);
    }
}
<<<<<<< HEAD
// ÓÃÓÚ²éÕÒÒÑ¾­Õ¹¿ªµÄÄÚÈİ
=======

//ç”¨äºä¿å­˜doçš„æ•°æ®ç»“æ„
vector<Asem*> do_list;
// ç”¨äºæŸ¥æ‰¾å·²ç»å±•å¼€çš„å†…å®¹
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
hash_control hc_unfold;
// ±íÊı¾İ½á¹¹ ÓÃÓÚ±£´æÄ£ÄâÆ÷ ×Ô¶¯Éú³ÉÊ±Õ¹¿ªµÄÄÚÈİ
class triple
{
public:
  string code;
  string binary;
  vector<int> doo;
  vector<int> off_in_code;
  vector<int> off_in_binary;
  vector<string> enum_name;
  triple(string c,string b){code=c,binary=b;};
  triple(){};
};
vector<vector<triple> > unfolded_list;

string get_full_name(string name,string pwd)
{
  // ×î¶Ì¿ÉÄÜµÄÈ«Â·¾¶
  int minl=name.length()+3;
  name=pwd+"."+name;
  //  ÕÒ...a.b..c.dÊ±£¬ÏÈÕÒ...a.b..c.d
  // Èç¹ûÃ»ÓĞ,ÔòÉ¾³ıc.,ÕÒ...a..b..d
  // Ã»ÓĞ,¼ÌĞøÕÒ...a..b.d > ...a..d > ...a.d > ...d
  for(;hc.find(name)==0 && name.length()>=minl;)
    {
      int l=name.length()-1;
      for(;l>=0 && name[l]!='.';--l)
	;
      int t=l;
      for(--l;l>=0 && name[l]!='.';--l)
	;
      name.erase(l+1,t-l);
    }
  // ³ö´í·µ»Ø¿Õ×Ö·û´®
  if(name.length()<minl)
    return "";
  return name;
}

// string get_val(Asem & asem,string pwd)
// {
//   assert(asem.size()==2);
//   string get_full_name(asem.ivec[1].name,pwd);
// }
bool is_instr(string name)
{
  return (hc.find((string)"...instruction."+name)!=0);
}
bool is_type(string name)
{
  return (hc.find((string)"...type."+name)!=0);
}
bool is_enum(string name)
{
  return (hc.find((string)"...enum."+name)!=0);
}
// ·µ»Øname¶ÔÓ¦µÄÄÇÒ»ÏîasemµØÖ·£¬ÏÖÔÚµÄÊµÏÖÊÇÊ×ÏÈ¼ÙÉèÊÇinstruction£¬
// È»ºóÊÇtype×îºóÊÇenum¡£¶ÔÕâĞ©¿ÉÄÜÒÀ´Î²éÕÒ
Asem *get_asem(string name)
{
  void *tmp=hc.find((string)"...instruction."+name);
  if(tmp==NULL)
    {
      tmp=hc.find((string)"...type."+name);
      if(tmp==NULL)
	tmp=hc.find((string)"...enum."+name);
    }
  return (Asem*)tmp;
}
int unfold(Asem &asem);

<<<<<<< HEAD
// ·ÖÎödoÖĞµÄ±í´ïÊ½£¬
// ¼ÙÉè¶Ô±äÁ¿doµÄÒıÓÃÖ»³öÏÖÔÚ×îÍâ²ã
int analyze_do_expr(Asem expr)
{
  
  if(expr.type==type_is_string1)
    {
      // Òò¸ÃÊÇÒ»¸ö±äÁ¿
    }
  else if(expr.type==type_is_ivec)
    {
      // Òò¸ÃÊÇÒ»¸ö±í´ïÊ½
    }
  return 0;
};
// Ã¿¸ö±äÁ¿ÒÑ¾­¶¨ºÃÈ¡Öµºó¼ÆËãcode£¬binary£¬do²¢±£´æµ½rÖĞ
=======

// TODO ä»£æ¢switchä¸­çš„å˜é‡ï¼Œç›®å‰ä»€ä¹ˆéƒ½æ²¡åš
void switch_chg(Asem & asem,
		vector<string> &var_name,
		vector<vector<string> >&var_choose_name,
		vector<vector<int> >&var_val,
		vector<pair<int,int> > &var_choosed_val
		)
{
  if(asem.type==type_is_vector)
    {
      if(asem.ivec.size()>0)
	{
	  if(asem.ivec[0].type==type_is_string1 && asem.ivec[0].name==(string)"switch")
	    {
	      // æ‰¾åˆ°switchè¯­å¥
	      // TODO è®¤ä¸ºå¦‚æœåˆ¤æ–­æ˜¯å«æœ‰å˜é‡åçš„è¡¨è¾¾å¼çš„è¯å°±æ˜¯æœ€ç®€å•çš„å½¢å¼: (switch var_name ...)
	      assert(asem.ivec.size()>1 && (asem.ivec.size()%2)==0);
	      if(asem.ivec[1].type==type_is_string1)
		{
		  // åˆ†æˆè¿™ä¸ªå˜é‡æ˜¯var.value å’Œ varä¸¤ç§
		  // å‰ä¸€ç§å¯¹åº”å˜é‡æ˜¯ä¸€ä¸ªæšä¸¾ç±»å‹
		  int pos=asem.ivec[1].name.find(".value");
		  if(pos!=string::npos)
		    {
		      // ç¬¬ä¸€ç§æƒ…å†µ
		      // ç”±äºç°åœ¨å¯¹enumç±»å‹çš„æ˜¯ä¸å±•å¼€ï¼Œæ‰€ä»¥åœ¨æ‰§è¡Œæ—¶å†å¤„ç†
		      string var=asem.ivec[1].name.substr(0,pos);
		      int i;
		      for(i=0;i<var_name.size();++i)
			if(var_name[i]==var)
			  break;
		      assert(i<var_name.size());
		      asem.ivec[1].name=(string)"ENUM_"+var+(string)"_"+var_choose_name[i][0];
		    }
		  else
		    {
		      // TODO ç°åœ¨æ²¡æœ‰å¯¹åº”æè¿°,æš‚æ—¶ä¸å†™
		    }
		}
	      else assert(false);
	    }
	  else
	    for(int i=0;i<asem.ivec.size();++i)
	      switch_chg(asem.ivec[i],
			 var_name,
			 var_choose_name,
			 var_val,
			 var_choosed_val);
	}
    }
}


// æ¯ä¸ªå˜é‡å·²ç»å®šå¥½å–å€¼åè®¡ç®—codeï¼Œbinaryï¼Œdoå¹¶ä¿å­˜åˆ°rä¸­
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
void eval_unfold(vector<string> &var_name,
		 vector<vector<string> >&var_choose_name,
		 vector<vector<int> >&var_val,
		 vector<pair<int,int> > &var_choosed_val,
		 Asem &code,
		 Asem &binary,
		 Asem * doo,
		 vector<triple> &r)
{
  // ¼ÇÂ¼±äÁ¿ÔÚcodeÖĞ³öÏÖµÄÎ»ÖÃ£¬Ä¿Ç°ÈÏÎªÒ»¸ö±äÁ¿ÔÚcodeÖĞÖ»³öÏÖÒ»´Î
  vector<int> var_off_in_code;
  // ¼ÇÂ¼±äÁ¿ÔÚbinaryÖĞ³öÏÖµÄÎ»ÖÃ£¬Ä¿Ç°ÈÏÎªÒ»¸ö±äÁ¿ÔÚbinaryÖĞÖ»³öÏÖÒ»´Î
  vector<int> var_off_in_bin;

  var_off_in_code.resize(var_name.size());
  var_off_in_bin.resize(var_name.size());

  // rÖĞĞÂÔöÒ»Ïî±£Áô½á¹û
  int k=r.size();
  r.resize(k+1);

  // ¶ÔcodeºÍbinaryµÄÇóÖµÓ¦¸Ã¿ÉÒÔĞ´³Éº¯Êı
  // Çó³öcode
  assert(code.ivec[0].name==(string)"code");
  for(int i=1;i<code.ivec.size();++i)
    {
      if(code.ivec[i].type==type_is_string2)
	{// ÊÇ´øÒıºÅµÄstring
	  r[k].code+=code.ivec[i].name;
	}
      else if(code.ivec[i].type==type_is_string1)
	{
	  // string1µÄÄÚÈİÄ¿Ç°Ö»ÄÜÊÇÁÙÊ±±äÁ¿µÄÃû×Ö
	  int j=0;
	  // ÕÒµ½¶ÔÓ¦µÄ±äÁ¿ÔÚvar_listµÄË÷Òı£¬Ä¿Ç°ÊÇË³Ğò²éÕÒ
	  for(;j<var_name.size() && var_name[j]!=code.ivec[i].name;++j)
	    ;
	  assert(j<var_name.size());

	  // ¼ÇÂ¼ÕÒµ½µÄ±äÁ¿ÔÚcodeÖĞµÄÆ«ÒÆ
	  var_off_in_code[j]=r[k].code.length();
	  r[k].code+=unfolded_list[var_val[j][var_choosed_val[j].first]][var_choosed_val[j].second].code;
	}
      else assert(0);
    }
  // Çó³öbinary
  for(int i=1;i<binary.ivec.size();++i)
    {
      if(binary.ivec[i].type==type_is_string2)
	{
	  r[k].binary+=binary.ivec[i].name;
	}
      else if(binary.ivec[i].type==type_is_string1)
	{
	  int j=0;
	  for(;j<var_name.size() && var_name[j]!=binary.ivec[i].name;++j)
	    ;
	  assert(j<var_name.size());

	  var_off_in_bin[j]=r[k].binary.length();
	  r[k].binary+=unfolded_list[var_val[j][var_choosed_val[j].first]][var_choosed_val[j].second].binary;
	}
      else if(binary.ivec[i].type==type_is_vector)
	{
	  // Ä¿Ç°Ö»¿ÉÄÜÊÇswitchÓï¾ä
	  assert(binary.ivec[i].ivec[0].name==(string)"switch");
	  
	  // ÕÒµ½switchÖĞÖ¸¶¨µÄ±äÁ¿ÔÚvar_nameÖĞµÄĞòºÅ
	  int j=0;
	  for(;j<var_name.size() && var_name[j]!=binary.ivec[i].ivec[1].name;++j)
	    ;
	  assert(j<var_name.size());

	  int z=2;
	  // ±éÀúswitchÖĞÃ¿Ò»¸öÑ¡Ïî£¬ÕÒµ½µ±Ç°Æ¥ÅäµÄÄÇÒ»Ïî
	  for(;z<binary.ivec[i].ivec.size() &&
		var_choose_name[j][var_choosed_val[j].first]!=binary.ivec[i].ivec[z].name;z+=2)
	    assert(binary.ivec[i].ivec[z].type==type_is_string1);
	  assert(z+1<binary.ivec[i].ivec.size());

	  // ÏÖÔÚÈÏÎªswitchºóÃæµÄÖµÖ»ÊÇ³£Á¿string£¬ÒÔºóÓ¦¸Ã´¦ÀíÆäËûÇé¿ö
	  assert(binary.ivec[i].ivec[z+1].type==type_is_string2);
	  r[k].binary+=binary.ivec[i].ivec[z+1].name;
	}
    }
  // ¼ÆËãĞÂÉú³ÉµÄcode offsetºÍbinary offset ĞÅÏ¢
  for(int i=0;i<var_val.size();++i)
    {
      int a=var_val[i][var_choosed_val[i].first];
      int b=var_choosed_val[i].second;
      int oc=var_off_in_code[i];
      int ob=var_off_in_bin[i];
      for(int j=0;j<unfolded_list[a][b].off_in_code.size();++j)
	{
	  r[k].off_in_code.push_back(unfolded_list[a][b].off_in_code[j]+oc);
	  r[k].off_in_binary.push_back(unfolded_list[a][b].off_in_binary[j]+ob);
	  if(unfolded_list[a][b].enum_name[j].length()>0)
	    r[k].enum_name.push_back(var_name[i]+(string)"#"+unfolded_list[a][b].enum_name[j]);
	  else r[k].enum_name.push_back((string)"");
	}
    }
  // ´¦ÀídoÃèÊö
  // Òª×öµÄ°üÀ¨
  // ´ú»»do±íÊöÖĞ±äÁ¿µÄdo
  if(doo)
    {
      // å¯¹å¯èƒ½å‡ºç°çš„switchä¸­çš„å˜é‡è¿›è¡Œä»£æ¢
      switch_chg(*doo,
		 var_name,
		 var_choose_name,
		 var_val,
		 var_choosed_val);
      // TODO å¯¹ifè¯­å¥ä¸­çš„å˜é‡è¿›è¡Œä»£æ¢
      //for(int i=0;i<var_name.size();++i)
      //cout<<var_choosed_val[i].first<<' '<<var_choosed_val[i].second<<endl;
      for(vector<Asem>::iterator ite=(*doo).ivec.begin()+1;ite!=(*doo).ivec.end();++ite)
	{
<<<<<<< HEAD
	  // ×îÍâ²ãÊÇstageÃèÊö
	  assert(ite->type==type_is_ivec);
	  if(
=======
	  if(ite->type==type_is_string1)
	    {
	      //åº”è¯¥æ˜¯å˜é‡
	      int i=0;
	      for(;i<var_name.size();++i)
		if(var_name[i]==ite->name)
		  break;
	      //æŠŠé‚£ä¸ªå˜é‡å¯¹åº”dooå‹å…¥
	      vector<int> &tmp=unfolded_list[var_val[i][var_choosed_val[i].first]][var_choosed_val[i].second].doo;
	      for(int j=0;j<tmp.size();++j)
		r[k].doo.push_back(tmp[j]);
	    }
	  else if(ite->type==type_is_vector)
	    {
	      // TODO åŠ å…¥çš„doå¯èƒ½æœ‰é‡å¤ï¼Œå¯ä»¥ç”¨hashä¼˜åŒ–
	      r[k].doo.push_back(do_list.size());
	      do_list.push_back(&(*ite));
	    }
	  else assert(0);

>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
	  //r[k].doo.push_back(analyze_do_expr((*doo).ivec[i]));
	}
    }

//   for(int i=0;i<var_val.size();++i)
//     {
//       int a=var_val[i][var_choosed_val[i].first];
//       int b=var_choosed_val[i].second;
//       for(int j=0;j<unfolded_list[a][b].doo.size();++j)
// 	r[k].doo.push_back(unfolded_list[a][b].doo[j]);
//     }
}
void dfs_unfold_instr(vector<string> &var_name, // ±äÁ¿Ãû×Ö
		      vector<vector<string> > &var_choose_name, // ±äÁ¿¿ÉÑ¡µÄÖµµÄÃû×Ö
		      vector<vector<int> > &var_val,		// ±äÁ¿¿ÉÑ¡Öµ¶ÔÓ¦unfolded_listµÄË÷Òı
		      vector<pair<int,int> > &var_choosed_val,	// ±äÁ¿È¡ÖµµÄÇé¿ö
		      Asem &code,				// ´ıÕ¹¿ªµÄcode¶ÔÓ¦asem
		      Asem &binary,				// ´ıÕ¹¿ªµÄbinary¶ÔÓ¦asem
		      Asem * doo,				// ´ıÕ¹¿ªdo¶ÔÓ¦µÄasem
		      int lev,					// µ±Ç°Ã¶¾Ùµ½µÚlev¸ö±äÁ¿
		      vector<triple> &r)			// ±£´æÕ¹¿ª½á¹û
{
  if(lev>=var_name.size())
    eval_unfold(var_name,var_choose_name,var_val,var_choosed_val,
		code,binary,doo,r);
  else
    for(int i=0;i<var_val[lev].size();++i)
      {
	// µÚlev¸ö±äÁ¿Ñ¡ÔñµÚi¸öÖµ
	var_choosed_val[lev].first=i;
	for(int j=0;j<unfolded_list[var_val[lev][i]].size();++j)
	  {
	    // µÚi¸öÖµÖĞµÚj¸öÕ¹¿ªÏî
	    var_choosed_val[lev].second=j;
	    dfs_unfold_instr(var_name,var_choose_name,var_val,var_choosed_val,
			     code,binary,doo,lev+1,r);
	  }
      }
}

// ·µ»ØvµÄ¶ş½øÖÆ£¬¿í¶ÈÄÜ±íÊ¾wÏî£¨´Ó0¿ªÊ¼£©
string num2string(int v,int w)
{
  string r;
  for(int i=1;i<w;i<<=1)
    {
      if(i&v)
	r=(string)"1"+r;
      else r=(string)"0"+r;
    }
  return r;
}

// ¶ÔenumÀàĞÍÃèÊöÕ¹¿ª
// ÀàËÆ(enum_name ('aaa' 'xxx') ...)
// Ã¶¾ÙÀàĞÍÃ¿Ò»Ïî¿ÉÒÔÊÇ¶şÔª×é£¬±íÊ¾Ãû×ÖºÍ¶ÔÓ¦µÄcode£¬binary¸ù¾İ
// ËüµÄÎ»ÖÃ¾ö¶¨
int unfold_enum(Asem &asem)
{
  // ĞÂÔöÒ»Ïî
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  //·¢ÏÖÈç¹ûÕ¹¿ªËùÓĞµÄenum½á¹û¿ÉÄÜºÜ´ó£¬ËùÒÔ¸Ä³É²»¶ÔenumÕ¹¿ªµ½
#define ENUM_NOT_UNFOLDED 1

#ifdef ENUM_NOT_UNFOLDED
  //cout<<"enum_"<<asem.ivec[0].name<<":"<<endl;
  string binary;
  for(int i=0;i<asem.ivec.size()-1;++i)
    binary+="-";
  unfolded_list[k].push_back(triple(asem.ivec[0].name,binary));
  unfolded_list[k][0].off_in_code.push_back(0);
  unfolded_list[k][0].off_in_binary.push_back(0);
  unfolded_list[k][0].enum_name.push_back(asem.ivec[0].name);
#endif
  for(int i=1;i<asem.ivec.size();++i)
    {
      if(asem.ivec[i].type==type_is_vector)
	{
	  // Èç¹ûÊÇivecÄÇÃ´Ö»ÓĞÁ½¸öÔªËØ,ÇÒ¶¼ÊÇÓĞÒıºÅµÄstring
	  assert(asem.ivec[i].ivec.size()==2 && 
		 asem.ivec[i].ivec[0].type==type_is_string2 && 
		 asem.ivec[i].ivec[1].type==type_is_string2);
	  
#ifndef ENUM_NOT_UNFOLDED
	  unfolded_list[k].push_back(triple((string)"#ENUM_"+
					    asem.ivec[i].ivec[1].name,num2string(i-1,asem.ivec.size()-1)));
	  cout<<"!!"<<asem.ivec[1].name<<endl;
#else
	  // TODO ²úÉúÕâ¸öÃ¶¾ÙÏàÓ¦µÄlex¹æÔòºÍ´¦Àíº¯Êı
#endif
	}
      else
	{
#ifndef ENUM_NOT_UNFOLDED
	  assert(asem.ivec[i].type==type_is_string2);
	  unfolded_list[k].push_back(triple((string)"#ENUM_"+
					    asem.ivec[i].name,num2string(i-1,asem.ivec.size()-1)));
#endif
	  // TODO ²úÉúÕâ¸öÃ¶¾ÙÏàÓ¦µÄlex¹æÔòºÍ´¦Àíº¯Êı
	}
    }
  return k;
}
// °Ñstring×ª³Éint
int string2num(string s)
{
  int v(0);
  // Ã»¿¼ÂÇÒç³öÇé¿ö
  for(int i=0;i<s.length();++i)
    v=(int)(s[i]-'0')+v*10;
  return v;
}

// ´¦ÀítypeÃèÊö
// (name (width num) (flag xxx) )
// Éú³ÉµÄcodeÊÇ"name_width_xxx"
// Éú³ÉµÄbinaryÊÇ"-..."(¹²width¸ö"-")
int unfold_type(Asem &asem)
{
  // type¶¨ÒåÓĞ3¸ö²¿·Ö
  assert(asem.ivec.size()==3);

  Asem & tmpw=*asem.find("width");
  assert(tmpw.ivec.size()==2 && tmpw.ivec[1].type==type_is_string1);
  int width=string2num(tmpw.ivec[1].name);

  Asem & tmpf=*asem.find("flag");
  assert(tmpf.ivec.size()==2 && tmpf.ivec[1].type==type_is_string1);

  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  string binary;
  for(int i=0;i<width;++i)
    binary+=(string)"-";
  unfolded_list[k].push_back(triple((string)"type_"+asem.ivec[0].name+
				    (string)"_"+tmpw.ivec[1].name+
				    (string)"_"+tmpf.ivec[1].name,
				    binary));
  unfolded_list[k][0].off_in_code.push_back(0);
  unfolded_list[k][0].off_in_binary.push_back(0);
  unfolded_list[k][0].enum_name.push_back((string)"");
  return k;
}
// ¶ÔinstructionÕ¹¿ª
int unfold_instr(Asem &asem)
{
  // ±äÁ¿Ãû
  vector<string> var_name;
  // ±äÁ¿¿ÉÑ¡µÄÖµ(¿ÉÄÜÊÇÆäËüinstruction»òÕßÊÇtype»òÕßÊÇenum)
  vector<vector<string> >var_choose_name;
  // ±äÁ¿Ñ¡²»Í¬Öµ¶ÔÓ¦µÄÔÚunfolded_listÖĞµÄË÷Òı
  vector<vector<int> > var_val;

  // ÕÒµ½ËùÓĞ±äÁ¿¶¨Òå ÕâÀïÈÏÎªÊÇÕâ¸öÑù×ÓµÄ£º
  // £¨= a b c ...£©
  // ±íÊ¾a¿ÉÒÔÊÇb»òc»ò...
  // ¼ÙÉè±äÁ¿¶¨ÒåºÜ¼òµ¥,Ã»ÓĞÇ¶Ì×ºÍµİ¹é
  // ËùÓĞ±äÁ¿¶¨ÒåÔÚµ±Ç°instructionÃèÊöµÄ×îÍâÃæÒ»²ã
  for(int i=1;i<asem.ivec.size();++i)
    if(asem.ivec[i].ivec[0].name==(string)"=")
      {// ÕâÒ»ÏîÊÇ±äÁ¿¶¨Òå
	// ÕâÊÇµÚk¸ö±äÁ¿
	int k=var_name.size();
	var_name.resize(k+1);
	var_choose_name.resize(k+1);
	var_val.resize(k+1);

	// ±£´æ±äÁ¿Ãûa
	var_name[k]=asem.ivec[i].ivec[1].name;
	// j´Ó2¿ªÊ¼,ÊÇµÚÒ»¸ö¿ÉÑ¡µÄÖµ
	for(int j=2;j<asem.ivec[i].ivec.size();++j)
	  {
	    const string &name=asem.ivec[i].ivec[j].name;
	    // ±£´æ¿ÉÑ¡µÄÖµµÄÃû×Ö
	    var_choose_name[k].push_back(name);
	    // Èç¹û±äÁ¿¶ÔÓ¦µÄÊÇÒ»¸öinstruction »òÕßÊÇtype»òÕßÊÇÃ¶¾Ù µİ¹éµØÕ¹¿ªÏÈ
	    if(is_instr(name) || is_type(name) || is_enum(name))
	      {
		int val=unfold(*get_asem(name));
		// ±£´æÕ¹¿ªµÄË÷Òı
		var_val[k].push_back(val);
	      }
	    else
	      {// ²»È»±¨´í
		assert(0);
	      }
	  }
      }

  // ±£´æ´ıÕ¹¿ªinstructionÏîµÄbinary,code,doµÄasemµØÖ·
  Asem & code=*asem.find("code");
  Asem & binary=*asem.find("binary");
  Asem * doo=asem.find("do");
  assert((&code!=0) && (&binary!=0) && (doo!=NULL));

  // ÔÚunfolded_listĞÂÔö¼ÓÒ»Ïî
  int k=unfolded_list.size();
  unfolded_list.resize(k+1);

  // ±£´æµ±Ç°±äÁ¿È¡µÄÖµ£¬¶şÔª×é±íÊ¾£º
  // (= a b c)
  // µÚÒ»Ïî±íÊ¾aÈ¡b»¹ÊÇc
  // µÚ¶şÏî±íÊ¾È¡b»òÊÇcÖĞµÄµÚ¼¸Ìõ£¨bºÍcÒÑ±»Õ¹¿ª£¬¿ÉÄÜÓĞ¶àÌõ¿ÉÑ¡Ïî£©
  vector<pair<int,int> > var_choosed_val;
  var_choosed_val.resize(var_name.size());
  // Õë¶Ô±äÁ¿È¡²»Í¬ÖµµÄÊ±ºòµÃµ½Õ¹¿ªµÄcode£¬binaryºÍdo
  dfs_unfold_instr(var_name,var_choose_name,var_val,var_choosed_val,
		   code,binary,doo,0,unfolded_list[k]);
  return k;
}


// Õ¹¿ªÒ»¸öÃèÊö£¬°üÀ¨Ã¶¾Ù£¬Ö¸Áî£¬ÀàĞÍ
int unfold(Asem &asem)
{
  string & name=asem.ivec[0].name;

  // Èç¹ûÒÑ¾­Õ¹¿ª¹ı
  if(hc_unfold.find(name)!=0)
    {
<<<<<<< HEAD
      return hc_unfold.find(name)-1; // ÓÉÓÚ¼ÓÈëhash±íµÄÊ±ºò¼Ó¹ı1
=======
      return (long long)hc_unfold.find(name)-1; // ç”±äºåŠ å…¥hashè¡¨çš„æ—¶å€™åŠ è¿‡1
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
    }

  cout<<"unfolding:"<<name<<endl;

  int r;
  // ¶Ô²»Í¬µÄÀàĞÍ·Ö±ğÕ¹¿ª
  if(is_instr(name))
    r=unfold_instr(asem);
  else if(is_enum(name))
    r=unfold_enum(asem);
  else if(is_type(name))
    r=unfold_type(asem);
  else assert(0);
<<<<<<< HEAD
  //cout<<"done:"<<name<<endl;
  // ¼ÓÈëhash±í£¬ÓÉÓÚr¿ÉÄÜÊÇ0£¬¶øhash.find·µ»Ø0±íÊ¾Ã»ÓĞÕÒµ½
  hc_unfold.insert(name,r+1);
=======

  cout<<"done:"<<name<<endl;
  // åŠ å…¥hashè¡¨ï¼Œç”±äºrå¯èƒ½æ˜¯0ï¼Œè€Œhash.findè¿”å›0è¡¨ç¤ºæ²¡æœ‰æ‰¾åˆ°
  hc_unfold.insert(name,(void*)(r+1));
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
  return r;
}
int string2int(string & s)
{
  int r(0);
  for(int i=0;i<s.length();++i)
    r=r*10+s[i]-'0';
  return r;
}
int main(){
  freopen("in.txt","r",stdin);
  Asem asem;

  asem.type=type_is_vector;
  // ¶ÁÈëÎÄ¼ş
  gen(asem);
  //display(asem,0);

  // °Ñ±£Áô×Ö¼ÓÈëhash±í
  for(int i=0;i<sizeof(reserved)/sizeof(reserved[0]);++i)
    hc.insert(reserved[i].c_str(),(void*)reserved);
  
  // ²åÈëhash±í
  dfs_insert_hash(asem,"");
<<<<<<< HEAD
  // instructionÀï±ØĞëÓĞ¶¥²ã¹æÔò
  string instr="...instruction.top";
  assert(hc.find(instr)!=0);
  Asem &rule=*(Asem*)hc.find(instr);
  assert(rule.type==type_is_vector && 
	 rule.ivec.size()==2
	 && rule.ivec[1].type==type_is_string1);

  // µÃµ½¶¥²ã¹æÔòÃû
  instr="...instruction."+rule.ivec[1].name;
  assert(hc.find(instr)!=0);
  rule=*(Asem*)hc.find(instr);
  //²é¿´½á¹û
=======

  // instructioné‡Œå¿…é¡»æœ‰é¡¶å±‚è§„åˆ™
  //string instr="...instruction.top";
  //assert(hc.find(instr)!=0);
  //æ‰¾åˆ°instructioné‚£ä¸€é¡¹
  Asem &instruction=*(asem.ivec[0].find((string)"instruction"));

  //æ‰¾åˆ°instructionä¸­çš„top
  Asem &top=*(instruction.find((string)"top"));
  Asem &rule=*instruction.find(top.ivec[1].name);

  //æŸ¥çœ‹ç»“æœ
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
  int allrule=unfold(rule);
  cout<<unfolded_list[allrule].size()<<endl;
  fstream out_txt("out.txt");
  hash_control tmp;
  for(int i=0;i<unfolded_list[allrule].size();++i)
    {
      out_txt<<i<<endl<<"\tcode: "<<unfolded_list[allrule][i].code<<endl
	  <<"\tbinary: "<<unfolded_list[allrule][i].binary<<endl;
      out_txt<<"do: "<<endl;
      for(int i=0;i<unfolded_list[allrule][i].doo.size();++i)
	out_txt<<unfolded_list[allrule][i].doo[i]<<' ';
      out_txt<<endl;
      for(int i=0;i<unfolded_list[allrule][i].off_in_code.size();++i)
	out_txt<<unfolded_list[allrule][i].off_in_code[i]<<' '<<unfolded_list[allrule][i].off_in_binary[i]<<' ';
      out_txt<<endl;
    }
<<<<<<< HEAD
  //½ÓÏÂÀ´ÊÇÊä³öµ½Îªir
  //´¦ÀíwireÃèÊö
=======

  //æ¥ä¸‹æ¥æ˜¯è¾“å‡ºåˆ°ä¸ºir
  //å¤„ç†wireæè¿°
>>>>>>> af6313631c21d57fd79af25f613e2af6f93b3e5f
  Ir ir;
  Asem &asem_wire=*asem.ivec[0].find((string)"wire");
  assert(asem_wire.type==type_is_vector);
  Asem &asem_type=*asem.ivec[0].find((string)"type");
  assert(asem_type.type==type_is_vector);
  for(int i=1;i<asem_wire.ivec.size();++i)
    {
      string wire_type_name=(*asem_wire.ivec[i].find((string)"width")).ivec[1].name;
      //TODO Ã»ÓĞ¼ì²étype¶ÔÓ¦µÄÊı¾İÀàĞÍÓ¦¸ÃÊÇÎŞ·ûºÅ£¬²éÕÒ¹ı³Ì¼ÓÈë³ö´í¼ì²é
      int wire_width=string2int((*(*(asem_type.find(wire_type_name))).find((string) "width")).ivec[1].name);
      ir.add_wire(Wire(asem_wire.ivec[i].ivec[0].name,wire_width));
    }
  ofstream out2_txt("out2.txt");
  ir.output_wire(out2_txt);

  // °ÑcodeºÍbinary¼ÓÈëµ½irÀï
  for(vector<triple>::iterator ite=unfolded_list[allrule].begin();
      ite!=unfolded_list[allrule].end();++ite)
    {
      vector<pp> tmp;
      for(int i=0;i<ite->off_in_code.size();++i)
	tmp.push_back(pp(ite->off_in_code[i],ite->off_in_binary[i]));
      ir.add_instruction(ite->code,ite->binary,ite->doo,tmp,ite->enum_name);
    }
  ir.output_instruction_set(out2_txt);

  
  
  return 0;
}
