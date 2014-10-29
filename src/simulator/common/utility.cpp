#include <boost/lexical_cast.hpp>
#include "utility.h"

int str2int( std::string &s )
{
  return boost::lexical_cast<int>(s);
}

std::string int2str( int num )
{
  return boost::lexical_cast<std::string>(num);
}
