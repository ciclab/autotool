#include <sys/mman.h>
#include <sys/stat.h>
#include <cstring>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <errno.h>
using namespace std;
#include "mem.h"
#include "reg.h"
#include "sim_dis.h"
#include "sim_dis.l.h"
#define MAX_INSTR_LEN ( MAX_BINARY_LEN * MAX_SLOT_LEN + 7 )
extern int sim_dis_list_cnt;
extern int dis_parse(void);
int main(int argc, char *argv[])
{
  if( argc != 2 )
    {
      cerr << " usage: " << argv[0] << " filename" << endl;
    }
  else
    {
      // FILE * binaryFile = fopen( argv[1], "r" );
      int fd = open( argv[1], O_RDONLY);
      if( fd == -1 )
	{
	  perror( argv[1] );
	}
      struct stat sb;
      if(  fstat(fd, &sb) == -1 )
	{
	  perror( argv[1] );
	}
      else
	{
	  void * r = mmap( NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0 );
	  if( r == MAP_FAILED )
	    {
	      perror("mmap");
	    }
	  else
	    {
	      // for( int i = 0, j = 0; i < 2000000; ++i )
	      // 	{
	      // 	  if( ( i % 1000 ) == 0 )
	      // 	    {
	      // 	      cout << j << endl;
	      // 	      ++j;
	      // 	    }
	      // 	  char c = ((char*)r)[i];
	      // 	  if( isprint(c) )
	      // 	    cout << c;
	      // 	  else cout << (unsigned int)( unsigned char)c;
	      // 	  cout << ' ';
	      // 	}
	      // // TODO configure how to map binary image to memory
	      // a little hack now
	      // 100 * 16 ^ 2 is offset of data
	      memcpy( (char*)mem1 + 16 * 16, r, sb.st_size );
	      pc = 1LL << 20;
	      char buf[ MAX_INSTR_LEN ], bi(0);
	      pc += 8;
	      pc += 4;
	      for( int i = 0 ; i < ( MAX_INSTR_LEN + 7 ) / 8 ; ++i )
		{
		  for( int j = 0 ; j < 8 ; ++j )
		    {
		      buf[bi] = ( *((char*)mem1 + pc + i ) & ( 1 << ( 7 - j ) ) ) ? '1' : '0';
		      ++bi;
		    }
		}
	      cout << buf << endl;
	      buf[bi] = 0;
	      YY_BUFFER_STATE bs = dis__scan_string(buf);
	      sim_dis_list_cnt = 0;
	      dis_parse();
	      cout << endl << sim_dis_list_cnt << endl;
    //   buf[MAX_BINARY_LEN*ii]='\0';
    // YY_BUFFER_STATE bs = dis__scan_string (buf);
    // dis_list_cnt=0;
    // dis_pc=memaddr;
    // dis_info=info;
    // dis_parse ();
    // dis__delete_buffer (bs);
    // int sum=0;
    // for(i=0;i<dis_list_cnt;++i)
    //   dis_pc+=dis_list_len[i]/8,sum+=dis_list_len[i]/8;
    // char * j=buf;
    // for(i=0;i<dis_list_cnt;j+=dis_list_len[i],++i)
    //   (*dis_list[i])(j);

	    }
	}
    }
  return 0;
}
