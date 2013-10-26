/* Print mips instructions for GDB, the GNU debugger, or for objdump.
   Copyright 1989, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,
   2000, 2001, 2002, 2003, 2005, 2006, 2007, 2008, 2009
   Free Software Foundation, Inc.
   Contributed by Nobuyuki Hikichi(hikichi@sra.co.jp).

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "dis-asm.h"
#include "libiberty.h"
#include "opcode/mips.h"
#include "opintl.h"

//下面是我们加的include！
#include "../gas/hash.h"

/* FIXME: These are needed to figure out if the code is mips16 or
   not. The low bit of the address is often a good indicator.  No
   symbol table is available when this code runs out in an embedded
   system as when it is used for disassembler support in a monitor.  */

#if !defined(EMBEDDED_ENV)
#define SYMTAB_AVAILABLE 1
#include "elf-bfd.h"
#include "elf/mips.h"
//#include "bfd.h"
#endif

#define WST(a) ((a)=(a))

static char * s2hex(char *buf,int len)
{
  int val,i;
  for(val=i=0;i<len;++i)
    val=(val<<1)|(buf[i]=='1'?1:0);
  static char tmp[1000];/*TODO*/
  sprintf(tmp,"0X%X",val);
  return tmp;
}
static const char * get_entry(const char * a[],const char * b,int num)
{
  int i,j;
  for(i=0;i<num;++i)
    {
      for(j=0;a[i<<1][j];++j)
	if(a[i<<1][j]!=b[j])
	  break;
      if(a[i<<1][j]=='\0')
	return a[(i<<1)+1];
    }
  return NULL;
}

static void output(struct disassemble_info *info,const char *format,const char * arg);
static void output(struct disassemble_info *info,const char *format,const char * arg)
{
  (*info->fprintf_func) (info->stream, format, arg);
}
