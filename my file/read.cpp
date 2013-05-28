#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using std::vector;
using namespace std;
//表示Asem的ivec有效
#define type_is_vector 0

//表示Asem的name有效
//表示没有引号的string，可能是关键词，操作符等
#define type_is_string1 1
//表示有引号的string
#define type_is_string2 2

class Asem{
public:
	vector<Asem> ivec;
	string name;
	int type;
};

void gen(Asem &asem){
	char c1;
	while((c1=getchar())!=EOF){
		if(c1==')') return;
		//一个vector开始
		else if(c1=='('){
			Asem asem_1;
			asem_1.type=type_is_vector;
			asem.ivec.push_back(asem_1);
			gen(asem.ivec[asem.ivec.size()-1]);
		}
		//带单引号的string
		else if(c1=='\''){
			Asem asem_2;
			asem_2.type=type_is_string2;
			char c2;
			
			while((c2=getchar())!=EOF&&c2!='\'')
			  asem_2.name+=c2;
			asem.ivec.push_back(asem_2);
		}
		//普通string
		else if(c1!=' '&&c1!='\n'){
			Asem asem_3;
			asem_3.type=type_is_string1;
			asem_3.name=c1;
			char c3;

			while((c3=getchar())!=EOF&&c3!=' '&&c3!='\n'&&c3!=')') 
				asem_3.name+=c3;
			asem.ivec.push_back(asem_3);
			if(c3==')')
			  return ;
		}
		
	}
}

void display(Asem asem,int lev){
  for(int i=0;i<asem.ivec.size();++i){
    if(asem.ivec[i].type==type_is_vector){
      cout<<endl;
      for(int j=0;j<lev;++j)
	cout<<"  ";
      cout<<'(';
      display(asem.ivec[i],lev+1);
      cout<<')';
    }
    else if(asem.ivec[i].type==type_is_string1)
      cout<<asem.ivec[i].name<<' ';
    else cout<<'\''<<asem.ivec[i].name<<'\''<<' ';
  }
}


int main(){
	freopen("tct.in","r",stdin);
	freopen("tct.out","w",stdout);
	Asem asem;
	asem.type=type_is_vector;
	gen(asem);
	display(asem,0);
	return 0;
}
