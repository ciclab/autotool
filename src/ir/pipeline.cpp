#include "pipeline.h"
void Pipeline::read(ifstream &fin)
{
  fin>>name;
  int n;
  fin >> n;
  for( int i = 0; i < n; ++i )
    {
      string typeName;
      int width;
      fin >> typeName >> width ;
      ele.push_back( make_pair( typeName, width ) );
    }
}
void Pipeline::output(ofstream &fout)
{
  fout << name << endl;
  fout << ele.size() << endl;
  for( auto i : ele )
    fout << i.first << ' ' << i.second << endl;
}
int Pipeline::get_ele_width(int i)
{
  return ele[i].second;
}
string Pipeline::get_ele_name(int i)
{
  return ele[i].first;
}
string Pipeline::get_name()
{
  return name;
}
int Pipeline::get_num_ele()
{
  return ele.size();
}
