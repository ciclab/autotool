#ifndef _PIPELINE_H_
#define _PIPELINE_H_
#include <string>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
class Pipeline
{
 private:
  string name;
  vector< pair<string, int> > ele;
 public:
  Pipeline(){};
 Pipeline(string n,vector<pair<string,int> > &e):name(n),ele(e){};
  void read(ifstream &);
  void output(ofstream &);
  string get_ele_name(int i);
  int get_ele_width(int i);
  string get_name();
  int get_num_ele();
};
#endif
