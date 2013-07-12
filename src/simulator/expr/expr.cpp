#include <vector>
#include <string>
using namespace std;
typedef pair<string,string> Tss;

//用于保存do的表达式的类
class Expr
{
private:
  // 这个表达式的类型
  #define IS_ASSIGN 1
  #define IS_STRING 2
  #define IS_VECTOR 3
  int type;
  string entry;
  vector<Expr> expr;
public:
  // 分析当前表达式，返回依赖关系
  void analyze(vector<Tss> &r);
  // 返回当前表达式是否是赋值
  bool is_assign();
  // 返回当前表达式entry是否有效
  bool is_string();
  // 返回当前表达式expr是否有效
  bool is_vector();
};
bool Expr::is_string()
{
  return type==IS_STRING;
}

bool Expr::is_vector()
{
  return type==IS_VECTOR;
}

bool Expr::is_assign()
{
  return (is_vector() && expr.size()>0 && expr[0].is_string() && expr[0].entry==(string)"=");
}
void Expr::analyze(vector<Tss> &r)
{
  if(is_assign())
    {
      //for(int 
    }
}
