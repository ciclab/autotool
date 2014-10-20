#include "utility.h"

int str2int( std::string &s )
{
  int r(0);
  for(const auto& i : s )
    {
      r = r * 10 + i - '0';
    }

  return r;
}

std::string int2str( int num )
{
  using namespace std;

  if( num == 0 )
    return (string)"0";

  string r;
  for( ; num > 0; num /= 10 )
    {
      r.push_back( '0' + ( num % 10 ) );
    }

  reverse( r.begin(), r.end() );

  return r;
}
