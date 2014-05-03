#include <iostream>
#include <cstdio>
#include <errno.h>
using namespace std;
int main(int argc, char *argv[])
{
  if( argc != 2 )
    {
      cerr << " usage: " << argv[0] << " filename" << endl;
    }
  else
    {
      FILE * binaryFile = fopen( argv[1], "r" );
      if( !binaryFile )
	{
	  perror( argv[1] );
	}
      else
	{
	  
	}
    }
  return 0;
}
