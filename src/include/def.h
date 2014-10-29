#ifndef _DEF_H_
#define _DEF_H_
#include <utility>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
#define FOR(a,b,c) for(auto a=b;a<c;++a)
typedef long long ll;
/* #define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a) */
#define FR(a, b) for(auto a:b)
#define FRA(a, b) for( auto a = b.begin(); a != b.end(); ++a)
const char c_sep='\1';
const string s_sep="\1";
const string s_type_beg="\2";
const char c_type_beg='\2';
const string s_enum_beg="\3";
const char c_enum_beg='\3';
const char c_addr_beg='\4';
const string s_addr_beg="\4";
typedef pair<int,int> ppi;
typedef pair<string,string> pps;
#define LITTLE_END
#endif
