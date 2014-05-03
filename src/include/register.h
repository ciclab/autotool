#ifndef _REGISTER_H_
#define _REGISTER_H_
#include <string>
#include <fstream>
using namespace std;
class Register
{
 private:
#define N_ELE 3
  /* string ele[N_ELE]; */
  string name;
  int size; 
  int width;
  /* string &name=ele[0]; */
  /* string &type=ele[1]; */
  /* string &idx=ele[2]; */
  /* string &alias=ele[3]; */
  /* string &read_port=ele[4]; */
  /* string &write_port=ele[5]; */
 public:
  Register(){};
  /* Register(string n,int s,string t, */
  /* 	   string i,string a,string r, */
  /* 	   string w) */
  /*   { */
  /*     ele[0]=n,ele[1]=t,ele[2]=i,ele[3]=a, */
  /* 	ele[4]=r,ele[5]=w; */
  /*     size=s; */
  /*     for(int i=0;i<N_ELE;++i) */
  /* 	if(ele[i].size()==0) */
  /* 	  ele[i]='0'; */
  /*   }; */
  Register( string n, int s, int w)
    {
      name = n, size = s, width = w;
    }
  void read(ifstream &);
  void output(ofstream &);
  string get_name();
  int get_size();
  int get_width();
};
#endif
