

/* Return the length of a microMIPS instruction in bytes.  If bits of
   the mask beyond the low 16 are 0, then it is a 16-bit instruction.
   Otherwise assume a 32-bit instruction; 48-bit instructions (0x1f
   major opcode) will require further modifications to the opcode
   table.  */

/* static void my_getExpression(expressionS * ep, char *str) */
/* { */
/* 	char *save_in; */
/* //  valueT val; */

/* 	save_in = input_line_pointer; */
/* 	input_line_pointer = str; */
/* 	expression(ep); */
/* 	expr_end = input_line_pointer; */
/* 	input_line_pointer = save_in; */

/* 	/\* If we are in mips16 mode, and this is an expression based on `.', */
/* 	   then we bump the value of the symbol by 1 since that is how other */
/* 	   text symbols are handled.  We don't bother to handle complex */
/* 	   expressions, just `.' plus or minus a constant.   */
/* 	   if (mips_opts.mips16 */
/* 	   && ep->X_op == O_symbol */
/* 	   && strcmp (S_GET_NAME (ep->X_add_symbol), FAKE_LABEL_NAME) == 0 */
/* 	   && S_GET_SEGMENT (ep->X_add_symbol) == now_seg */
/* 	   && symbol_get_frag (ep->X_add_symbol) == frag_now */
/* 	   && symbol_constant_p (ep->X_add_symbol) */
/* 	   && (val = S_GET_VALUE (ep->X_add_symbol)) == frag_now_fix ()) */
/* 	   S_SET_VALUE (ep->X_add_symbol, val + 1); *\/ */
/* } */

/* This function is called once, at assembler startup time.  It should set up
   all the tables, etc. that the MD part of the assembler will need.  */

void
md_begin (void)
{
  ini(&strsta);
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  int c=BFD_DUMMY_2_1;c^=c;
}

void
md_mips_end (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

void
md_assemble (char *str)
{
	/* bfd_reloc_code_real_type unused_reloc = BFD_RELOC_UNUSED; */
	/* struct mips_cl_insn insn; */
	/* imm_expr.X_op = O_absent; */
	/* offset_expr.X_op = O_absent; */
	/* imm_reloc = BFD_RELOC_UNUSED; */
	/* offset_reloc = BFD_RELOC_UNUSED; */
	/* mips_ip(str, &insn); */
	//printf("\n\n1  code222:%llx   \n\n",insn.insn_opcode);
	/* if (insn_error) { */
	/* 	as_bad("%s %s'", insn_error, str); */
	/* 	return; */
	/* } */
	/* if (offset_expr.X_op == O_absent && imm_expr.X_op == O_absent) */
	/* 	append_insn(&insn, NULL, &unused_reloc); */
	/* else if (offset_expr.X_op != O_absent && imm_expr.X_op == O_absent) */
	/* 	append_insn(&insn, &offset_expr, &offset_reloc); */
	/* else if (imm_expr.X_op != O_absent && offset_expr.X_op == O_absent) */
	/* 	append_insn(&insn, &imm_expr, &imm_reloc); */
	/* else */
	/* 	gas_assert(0); */
  printf("!%s\n",str);
  YY_BUFFER_STATE bs=dummy__scan_string(str);
  dummy_parse();
  dummy__delete_buffer(bs);
  clear(&strsta);
}


static void
append_insn(struct mips_cl_insn *ip, struct expressionS *address_expr,
	    bfd_reloc_code_real_type * reloc_type)
{
  /* if (address_expr == NULL && *reloc_type == BFD_RELOC_UNUSED) */
  /* 	add_fixed_insn(ip); */
  /* else if (address_expr != NULL && *reloc_type <= BFD_RELOC_UNUSED) { */
  /* 	if (address_expr->X_op == O_constant) { */
  /* 		switch (*reloc_type) { */
  /* 		case MIPS_RELOC_PCREL18: */
  /* 			DBG(("!\n")); */
  /* 			/\*      if ((address_expr->X_add_number & 3) != 0) */
  /* 			   as_bad (_("jump to misaligned address (0x%lx)"), */
  /* 			   (unsigned long) address_expr->X_add_number); *\/ */
  /* 			ip->insn_opcode |= (address_expr->X_add_number & 0x0FFFFFF);break;     //  no check now */
  /* 		case MIPS_RELOC_PCREL8: */
  /* 			ip->insn_opcode |= (address_expr->X_add_number & 0x01ff);break; */
  /* 		case MIPS_RELOC_PCREL3: */
  /* 			ip->insn_opcode |= (address_expr->X_add_number & 0xff);break; */
  /* 		case MIPS_RELOC_PCREL4: */
  /* 			ip->insn_opcode |= (address_expr->X_add_number & 0x01ff);break; */
  /* 		case MIPS_RELOC_PCREL5: */
  /* 			ip->insn_opcode |= (address_expr->X_add_number & 0x01ff);break; */
  /* 		default: */
  /* 			break; */
  /* 		} */
  /* 		add_fixed_insn(ip); */
  /* 	} else {      //表达式address_expr不是可以确定的常量 */
  /* 		reloc_howto_type *howto; */
  /* 		howto = bfd_reloc_type_lookup(stdoutput, *reloc_type); */
  /* 		if (howto == NULL) */
  /* 			gas_assert(0); */
  /*                 printf("frag:%p where:%d\n",(ip->frag),(int)(ip->where)); */
  /* 		ip->fixp[0] = fix_new_exp(ip->frag, ip->where,  //创建一个fixup */
  /* 					  4, */
  /* 					  address_expr, */
  /* 					  reloc_type[0] == */
  /* 					  MIPS_RELOC_PCREL18 || */
  /* 					  reloc_type[0] == */
  /* 					  MIPS_RELOC_PCREL8/\*|| */
  /* 					  reloc_type[0] == */
  /* 					  MIPS_RELOC_PCREL5*\/,     //若结果为1，表示这个重定位是PC相关 */
  /* 					  reloc_type[0]); */
  /* 				//	 printf("reloctype:%d\n",reloc_type[0]); */
  /* 		/\* Tag symbols that have a R_MIPS16_26 relocation against them. */
  /* 		   if (reloc_type[0] == BFD_RELOC_MIPS16_JMP&& ip->fixp[0]->fx_addsy) */
  /* 		   *symbol_get_tc (ip->fixp[0]->fx_addsy) = 1; */
  /* 		   These relocations can have an addend that won't */
  /* 		   fit in 4 octets for 64bit assembly.  *\/ */
  /*                 printf("frag:%p where:%d\n",(ip->frag),(int)(ip->where)); */
  /* 		add_fixed_insn(ip); */
  /*                 printf("frag:%p where:%d\n",(ip->frag),(int)(ip->where)); */
  /* 	} */
  /* } */
}

void
mips_emit_delays (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}


/* UDI immediates.  */
struct mips_immed {
  char		type;
  unsigned int	shift;
  unsigned long	mask;
  const char *	desc;
};


struct percent_op_match
{
  const char *str;
  bfd_reloc_code_real_type reloc;
};

char *
md_atof (int type, char *litP, int *sizeP)
{
  return ieee_md_atof (type, litP, sizeP, target_big_endian);
}

void
md_number_to_chars (char *buf, valueT val, int n)
{
  if (target_big_endian)
    number_to_chars_bigendian (buf, val, n);
  else
    number_to_chars_littleendian (buf, val, n);
}

/* Set STRING_PTR (either &mips_arch_string or &mips_tune_string) to
   NEW_VALUE.  Warn if another value was already specified.  Note:
   we have to defer parsing the -march and -mtune arguments in order
   to handle 'from-abi' correctly, since the ABI might be specified
   in a later argument.  */

int
md_parse_option (int c, char *arg)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  c=c,arg=arg;
  return 0;
}

/* Set up globals to generate code for the ISA or processor
   described by INFO.  */


void
mips_after_parse_args (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

void
mips_init_after_args (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

long
md_pcrel_from (fixS *fixP)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  fixP=fixP;
  return 0;
}

/* This is called before the symbol table is processed.  In order to
   work with gcc when using mips-tfile, we must keep all local labels.
   However, in other cases, we want to discard them.  If we were
   called with -g, but we didn't see any debugging information, it may
   mean that gcc is smuggling debugging information through to
   mips-tfile, in which case we must generate all local labels.  */

void
mips_frob_file_before_adjust (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

/* Sort any unmatched HI16 and GOT16 relocs so that they immediately precede
   the corresponding LO16 reloc.  This is called before md_apply_fix and
   tc_gen_reloc.  Unmatched relocs can only be generated by use of explicit
   relocation operators.

   For our purposes, a %lo() expression matches a %got() or %hi()
   expression if:

      (a) it refers to the same symbol; and
      (b) the offset applied in the %lo() expression is no lower than
	  the offset applied in the %got() or %hi().

   (b) allows us to cope with code like:

	lui	$4,%hi(foo)
	lh	$4,%lo(foo+2)($4)

   ...which is legal on RELA targets, and has a well-defined behaviour
   if the user knows that adding 2 to "foo" will not induce a carry to
   the high 16 bits.

   When several %lo()s match a particular %got() or %hi(), we use the
   following rules to distinguish them:

     (1) %lo()s with smaller offsets are a better match than %lo()s with
         higher offsets.

     (2) %lo()s with no matching %got() or %hi() are better than those
         that already have a matching %got() or %hi().

     (3) later %lo()s are better than earlier %lo()s.

   These rules are applied in order.

   (1) means, among other things, that %lo()s with identical offsets are
   chosen if they exist.

   (2) means that we won't associate several high-part relocations with
   the same low-part relocation unless there's no alternative.  Having
   several high parts for the same low part is a GNU extension; this rule
   allows careful users to avoid it.

   (3) is purely cosmetic.  mips_hi_fixup_list is is in reverse order,
   with the last high-part relocation being at the front of the list.
   It therefore makes sense to choose the last matching low-part
   relocation, all other things being equal.  It's also easier
   to code that way.  */

void
mips_frob_file (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

/* We may have combined relocations without symbols in the N32/N64 ABI.
   We have to prevent gas from dropping them.  */

int
mips_force_relocation (fixS *fixp)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  fixp=fixp;
  return 0;
}

/* Apply a fixup to the object file.  */

void
md_apply_fix (fixS *fixP, valueT *valP, segT seg ATTRIBUTE_UNUSED)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  fixP=fixP,valP=valP,seg=seg;
}
/*
void
s_change_section (int ignore ATTRIBUTE_UNUSED)
{
  ignore=ignore;
}
*/
void
mips_enable_auto_align (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

/* Parse a register string into a number.  Called from the ECOFF code
   to parse .frame.  The argument is non-zero if this is the frame
   register, so that we can record it in mips_frame_reg.  */

int
tc_get_register (int frame)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  frame=frame;
  return 0;
}

valueT
md_section_align (asection *seg, valueT addr)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  seg=seg,addr=addr;
  return addr;
}

/* Estimate the size of a frag before relaxing.  Unless this is the
   mips16, we are not really relaxing here, and the final size is
   encoded in the subtype information.  For the mips16, we have to
   decide whether we are using an extended opcode or not.  */

int
md_estimate_size_before_relax (fragS *fragp, asection *segtype)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  fragp=fragp,segtype=segtype;
  return 0;
}

/* This is called to see whether a reloc against a defined symbol
   should be converted into a reloc against a section.  */

int
mips_fix_adjustable (fixS *fixp)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  fixp=fixp;
  return 1;
}

/* Translate internal representation of relocation info to BFD target
   format.  */

arelent **
tc_gen_reloc (asection *section ATTRIBUTE_UNUSED, fixS *fixp)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  fixp=fixp;section=section;
  return NULL;
}

/* Relax a machine dependent frag.  This returns the amount by which
   the current size of the frag should change.  */

int
mips_relax_frag (asection *sec, fragS *fragp, long stretch)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  sec=sec,fragp=fragp,stretch=stretch;
  return 0;
}

/* Convert a machine dependent frag.  */

void
md_convert_frag (bfd *abfd ATTRIBUTE_UNUSED, segT asec, fragS *fragp)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  abfd=abfd,asec=asec,fragp=fragp;
}

#ifdef OBJ_ELF

/* This function is called after the relocs have been generated.
   We've been storing mips16 text labels as odd.  Here we convert them
   back to even for the convenience of the debugger.  */

void
mips_frob_file_after_relocs (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

#endif

/* This function is called whenever a label is defined, including fake
   labels instantiated off the dot special symbol.  It is used when
   handling branch delays; if a branch has a label, we assume we cannot
   move it.  This also bumps the value of the symbol by 1 in compressed
   code.  */

void
mips_record_label (symbolS *sym)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  sym=sym;
}

/* This function is called as tc_frob_label() whenever a label is defined
   and adds a DWARF-2 record we only want for true labels.  */

void
mips_define_label (symbolS *sym)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  sym=sym;
}

#if defined (OBJ_ELF) || defined (OBJ_MAYBE_ELF)

/* Some special processing for a MIPS ELF file.  */

void
mips_elf_final_processing (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

#endif /* OBJ_ELF || OBJ_MAYBE_ELF */

char
mips_nop_opcode (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  return (char)0;
}


/* Fill in an rs_align_code fragment.  Unlike elsewhere we want to use
   32-bit microMIPS NOPs here (if applicable).  */

void
mips_handle_align (fragS *fragp)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  fragp=fragp;
}


void
md_show_usage (FILE *stream)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  stream=stream;
}

#ifdef TE_IRIX
enum dwarf2_format
mips_dwarf2_format (asection *sec ATTRIBUTE_UNUSED)
{
  return dwarf2_format_32bit;
}
#endif

int
mips_dwarf2_addr_size (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  return 4;
}

/* Standard calling conventions leave the CFA at SP on entry.  */
void
mips_cfi_frame_initial_instructions (void)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
}

int
tc_mips_regname_to_dw2regnum (char *regname)
{
  DBG(("INTERNAL ERROR: %s %d %s\n",__FUNCTION__,__LINE__,__FUNCTION__));
  regname=regname;
  return 0;
}
