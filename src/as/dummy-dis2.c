
static int
_print_insn_mips(bfd_vma memaddr,
		 struct disassemble_info *info, enum bfd_endian endianness)
{
  bfd_byte buffer[MAX_BINARY_LEN/8+7]; 
  int status;

  //set_default_mips_dis_options(info);
  //parse_mips_dis_options(info->disassembler_options);

  WST(endianness);/*TODO*/
  void *unused=(void*)s2hex;
  WST(unused);
  int ii=0;
  static char buf[MAX_BINARY_LEN*MAX_SLOT_LEN+7];
  int i;
  for(;ii<MAX_SLOT_LEN && 0==(*info->read_memory_func) (memaddr+(ii*MAX_BINARY_LEN/8), buffer , MAX_BINARY_LEN/8, info);++ii)
    {
      for(i=0;i<MAX_BINARY_LEN;++i)
	buf[i+ii*MAX_BINARY_LEN]=(buffer[i/8]&(1<<(7-(i%8))))?'1':'0';
    }
  /* if (status == 0)  */
    {
    /* printf("$$$\n "); */
    /* unsigned long int insn; */
	
    /* if (endianness == BFD_ENDIAN_BIG) */
    /*   insn = (unsigned long int)bfd_getb32(buffer); */
    /* else */
    /*   insn = (unsigned long int)bfd_getl32(buffer); */
      buf[MAX_BINARY_LEN*ii]='\0';
    YY_BUFFER_STATE bs = dis__scan_string (buf);
    dis_list_cnt=0;
    dis_pc=memaddr;
    dis_info=info;
    dis_parse ();
    dis__delete_buffer (bs);
    int sum=0;
    for(i=0;i<dis_list_cnt;++i)
      dis_pc+=dis_list_len[i]/8,sum+=dis_list_len[i]/8;
    char * j=buf;
    for(i=0;i<dis_list_cnt;j+=dis_list_len[i],++i)
      (*dis_list[i])(j);
    return sum;
    /* return dis(info,buf,memaddr); */
  } 
	
    (*info->memory_error_func) (status, memaddr, info);
    return -1;
}

int print_insn_big_dummy(bfd_vma memaddr, struct disassemble_info *info)
{
  return _print_insn_mips(memaddr, info, BFD_ENDIAN_BIG);
}

int print_insn_little_dummy(bfd_vma memaddr, struct disassemble_info *info)
{
  return _print_insn_mips(memaddr, info, BFD_ENDIAN_LITTLE);
}

void print_mips_disassembler_options(FILE * stream)
{
  WST(stream);
}
