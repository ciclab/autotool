	.file	"ir.cpp"
	.section	.text$_ZnwjPv,"x"
	.linkonce discard
	.globl	__ZnwjPv
	.def	__ZnwjPv;	.scl	2;	.type	32;	.endef
__ZnwjPv:
LFB243:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	12(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE243:
	.section	.text$_ZdlPvS_,"x"
	.linkonce discard
	.globl	__ZdlPvS_
	.def	__ZdlPvS_;	.scl	2;	.type	32;	.endef
__ZdlPvS_:
LFB245:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE245:
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
LC0:
	.ascii "(instruction_set\0"
LC1:
	.ascii "(\0"
LC2:
	.ascii " \0"
LC3:
	.ascii ")\0"
	.text
	.align 2
	.globl	__ZN2Ir22output_instruction_setERSt14basic_ofstreamIcSt11char_traitsIcEE
	.def	__ZN2Ir22output_instruction_setERSt14basic_ofstreamIcSt11char_traitsIcEE;	.scl	2;	.type	32;	.endef
__ZN2Ir22output_instruction_setERSt14basic_ofstreamIcSt11char_traitsIcEE:
LFB1295:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1295
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$68, %esp
	.cfi_offset 3, -12
	movl	%ecx, -44(%ebp)
	movl	8(%ebp), %eax
	movl	$LC0, 4(%esp)
	movl	%eax, (%esp)
LEHB0:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
LEHE0:
	subl	$4, %esp
	movl	-44(%ebp), %eax
	addl	$12, %eax
	movl	%eax, %ecx
LEHB1:
	call	__ZNSt6vectorI11InstructionSaIS0_EE5beginEv
	movl	%eax, -28(%ebp)
	jmp	L5
L8:
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv
	leal	-20(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN11Instruction10get_binaryEv
LEHE1:
	subl	$4, %esp
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv
	leal	-16(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, %ecx
LEHB2:
	call	__ZN11Instruction8get_codeEv
LEHE2:
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
LEHB3:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-20(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
LEHE3:
	leal	-16(%ebp), %eax
	movl	%eax, %ecx
LEHB4:
	call	__ZNSsD1Ev
LEHE4:
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
LEHB5:
	call	__ZNSsD1Ev
	movl	$0, -12(%ebp)
	jmp	L6
L7:
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN11Instruction7get_offEi
	subl	$4, %esp
	movl	%edx, %ebx
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN11Instruction7get_offEi
	subl	$4, %esp
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$32, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$32, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	incl	-12(%ebp)
L6:
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv
	movl	%eax, %ecx
	call	__ZN11Instruction12get_off_sizeEv
	cmpl	-12(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	L7
	movl	8(%ebp), %eax
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEppEv
L5:
	movl	-44(%ebp), %eax
	addl	$12, %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI11InstructionSaIS0_EE3endEv
LEHE5:
	movl	%eax, -24(%ebp)
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
LEHB6:
	call	__ZN9__gnu_cxxneIP11InstructionSt6vectorIS1_SaIS1_EEEEbRKNS_17__normal_iteratorIT_T0_EESB_
LEHE6:
	testb	%al, %al
	jne	L8
	jmp	L17
L15:
	movl	%eax, %ebx
	leal	-16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	jmp	L10
L14:
	movl	%eax, %ebx
L10:
	leal	-20(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	jmp	L11
L16:
	jmp	L11
L13:
L11:
	movl	%eax, (%esp)
LEHB7:
	call	__Unwind_Resume
LEHE7:
L17:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1295:
	.def	___gxx_personality_v0;	.scl	2;	.type	32;	.endef
	.section	.gcc_except_table,"w"
LLSDA1295:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1295-LLSDACSB1295
LLSDACSB1295:
	.uleb128 LEHB0-LFB1295
	.uleb128 LEHE0-LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB1-LFB1295
	.uleb128 LEHE1-LEHB1
	.uleb128 L13-LFB1295
	.uleb128 0
	.uleb128 LEHB2-LFB1295
	.uleb128 LEHE2-LEHB2
	.uleb128 L14-LFB1295
	.uleb128 0
	.uleb128 LEHB3-LFB1295
	.uleb128 LEHE3-LEHB3
	.uleb128 L15-LFB1295
	.uleb128 0
	.uleb128 LEHB4-LFB1295
	.uleb128 LEHE4-LEHB4
	.uleb128 L14-LFB1295
	.uleb128 0
	.uleb128 LEHB5-LFB1295
	.uleb128 LEHE5-LEHB5
	.uleb128 L13-LFB1295
	.uleb128 0
	.uleb128 LEHB6-LFB1295
	.uleb128 LEHE6-LEHB6
	.uleb128 L16-LFB1295
	.uleb128 0
	.uleb128 LEHB7-LFB1295
	.uleb128 LEHE7-LEHB7
	.uleb128 0
	.uleb128 0
LLSDACSE1295:
	.text
	.align 2
	.globl	__ZN2Ir15add_instructionER11Instruction
	.def	__ZN2Ir15add_instructionER11Instruction;	.scl	2;	.type	32;	.endef
__ZN2Ir15add_instructionER11Instruction:
LFB1296:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	12(%eax), %edx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt6vectorI11InstructionSaIS0_EE9push_backERKS0_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1296:
	.align 2
	.globl	__ZN2Ir8add_wireE4Wire
	.def	__ZN2Ir8add_wireE4Wire;	.scl	2;	.type	32;	.endef
__ZN2Ir8add_wireE4Wire:
LFB1297:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorI4WireSaIS0_EE9push_backERKS0_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1297:
	.section .rdata,"dr"
LC4:
	.ascii "(wire\0"
	.text
	.align 2
	.globl	__ZN2Ir11output_wireERSt14basic_ofstreamIcSt11char_traitsIcEE
	.def	__ZN2Ir11output_wireERSt14basic_ofstreamIcSt11char_traitsIcEE;	.scl	2;	.type	32;	.endef
__ZN2Ir11output_wireERSt14basic_ofstreamIcSt11char_traitsIcEE:
LFB1298:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1298
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	$LC4, 4(%esp)
	movl	%eax, (%esp)
LEHB8:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	movl	$0, -12(%ebp)
	jmp	L21
L22:
	movl	-12(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorI4WireSaIS0_EEixEj
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZN4Wire9get_widthEv
	movl	%eax, %ebx
	movl	-12(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorI4WireSaIS0_EEixEj
	subl	$4, %esp
	leal	-16(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN4Wire8get_nameEv
LEHE8:
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
LEHB9:
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$32, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movl	%ebx, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
LEHE9:
	subl	$4, %esp
	leal	-16(%ebp), %eax
	movl	%eax, %ecx
LEHB10:
	call	__ZNSsD1Ev
	incl	-12(%ebp)
L21:
	movl	-12(%ebp), %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE4sizeEv
	cmpl	%eax, %ebx
	setb	%al
	testb	%al, %al
	jne	L22
	movl	8(%ebp), %eax
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
LEHE10:
	subl	$4, %esp
	jmp	L25
L24:
	movl	%eax, %ebx
	leal	-16(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB11:
	call	__Unwind_Resume
LEHE11:
L25:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1298:
	.section	.gcc_except_table,"w"
LLSDA1298:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1298-LLSDACSB1298
LLSDACSB1298:
	.uleb128 LEHB8-LFB1298
	.uleb128 LEHE8-LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB9-LFB1298
	.uleb128 LEHE9-LEHB9
	.uleb128 L24-LFB1298
	.uleb128 0
	.uleb128 LEHB10-LFB1298
	.uleb128 LEHE10-LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB11-LFB1298
	.uleb128 LEHE11-LEHB11
	.uleb128 0
	.uleb128 0
LLSDACSE1298:
	.text
	.section	.text$_ZNSt6vectorI11InstructionSaIS0_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI11InstructionSaIS0_EE5beginEv
	.def	__ZNSt6vectorI11InstructionSaIS0_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI11InstructionSaIS0_EE5beginEv:
LFB1303:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEC1ERKS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1303:
	.section	.text$_ZNSt6vectorI11InstructionSaIS0_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI11InstructionSaIS0_EE3endEv
	.def	__ZNSt6vectorI11InstructionSaIS0_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI11InstructionSaIS0_EE3endEv:
LFB1304:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEC1ERKS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1304:
	.section	.text$_ZN9__gnu_cxxneIP11InstructionSt6vectorIS1_SaIS1_EEEEbRKNS_17__normal_iteratorIT_T0_EESB_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxneIP11InstructionSt6vectorIS1_SaIS1_EEEEbRKNS_17__normal_iteratorIT_T0_EESB_
	.def	__ZN9__gnu_cxxneIP11InstructionSt6vectorIS1_SaIS1_EEEEbRKNS_17__normal_iteratorIT_T0_EESB_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxneIP11InstructionSt6vectorIS1_SaIS1_EEEEbRKNS_17__normal_iteratorIT_T0_EESB_:
LFB1305:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	setne	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1305:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEppEv
	.def	__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEppEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEppEv:
LFB1306:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leal	20(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1306:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEptEv:
LFB1307:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1307:
	.section	.text$_ZNSt6vectorI11InstructionSaIS0_EE9push_backERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI11InstructionSaIS0_EE9push_backERKS0_
	.def	__ZNSt6vectorI11InstructionSaIS0_EE9push_backERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI11InstructionSaIS0_EE9push_backERKS0_:
LFB1316:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L37
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE9constructIS1_EEvRS2_PS1_RKT_
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	20(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L36
L37:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI11InstructionSaIS0_EE3endEv
	movl	-12(%ebp), %edx
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt6vectorI11InstructionSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_
	subl	$8, %esp
L36:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1316:
	.section	.text$_ZNSt6vectorI4WireSaIS0_EE9push_backERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4WireSaIS0_EE9push_backERKS0_
	.def	__ZNSt6vectorI4WireSaIS0_EE9push_backERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4WireSaIS0_EE9push_backERKS0_:
LFB1317:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L40
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE9constructIS1_EEvRS2_PS1_RKT_
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	leal	16(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L39
L40:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI4WireSaIS0_EE3endEv
	movl	-12(%ebp), %edx
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt6vectorI4WireSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_
	subl	$8, %esp
L39:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1317:
	.section	.text$_ZNKSt6vectorI4WireSaIS0_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI4WireSaIS0_EE4sizeEv
	.def	__ZNKSt6vectorI4WireSaIS0_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI4WireSaIS0_EE4sizeEv:
LFB1318:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$4, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1318:
	.section	.text$_ZNSt6vectorI4WireSaIS0_EEixEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4WireSaIS0_EEixEj
	.def	__ZNSt6vectorI4WireSaIS0_EEixEj;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4WireSaIS0_EEixEj:
LFB1319:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$4, %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1319:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEC1ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEC1ERKS2_
	.def	__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEC1ERKS2_:
LFB1327:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1327:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv:
LFB1328:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1328:
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE9constructIS1_EEvRS2_PS1_RKT_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE9constructIS1_EEvRS2_PS1_RKT_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE9constructIS1_EEvRS2_PS1_RKT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE9constructIS1_EEvRS2_PS1_RKT_:
LFB1337:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI11InstructionE9constructEPS1_RKS1_
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1337:
	.section	.text$_ZN11InstructionC1ERKS_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN11InstructionC1ERKS_
	.def	__ZN11InstructionC1ERKS_;	.scl	2;	.type	32;	.endef
__ZN11InstructionC1ERKS_:
LFB1341:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1341
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB12:
	call	__ZNSsC1ERKSs
LEHE12:
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB13:
	call	__ZNSsC1ERKSs
LEHE13:
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB14:
	call	__ZNSt6vectorISt4pairIiiESaIS1_EEC1ERKS3_
LEHE14:
	subl	$4, %esp
	jmp	L55
L54:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	jmp	L52
L53:
	movl	%eax, %ebx
L52:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB15:
	call	__Unwind_Resume
LEHE15:
L55:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1341:
	.section	.gcc_except_table,"w"
LLSDA1341:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1341-LLSDACSB1341
LLSDACSB1341:
	.uleb128 LEHB12-LFB1341
	.uleb128 LEHE12-LEHB12
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB13-LFB1341
	.uleb128 LEHE13-LEHB13
	.uleb128 L53-LFB1341
	.uleb128 0
	.uleb128 LEHB14-LFB1341
	.uleb128 LEHE14-LEHB14
	.uleb128 L54-LFB1341
	.uleb128 0
	.uleb128 LEHB15-LFB1341
	.uleb128 LEHE15-LEHB15
	.uleb128 0
	.uleb128 0
LLSDACSE1341:
	.section	.text$_ZN11InstructionC1ERKS_,"x"
	.linkonce discard
	.section	.text$_ZN11InstructionD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN11InstructionD1Ev
	.def	__ZN11InstructionD1Ev;	.scl	2;	.type	32;	.endef
__ZN11InstructionD1Ev:
LFB1344:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1344
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
LEHB16:
	call	__ZNSt6vectorISt4pairIiiESaIS1_EED1Ev
LEHE16:
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, %ecx
LEHB17:
	call	__ZNSsD1Ev
LEHE17:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
LEHB18:
	call	__ZNSsD1Ev
LEHE18:
	jmp	L62
L60:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	jmp	L59
L61:
	movl	%eax, %ebx
L59:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB19:
	call	__Unwind_Resume
LEHE19:
L62:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1344:
	.section	.gcc_except_table,"w"
LLSDA1344:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1344-LLSDACSB1344
LLSDACSB1344:
	.uleb128 LEHB16-LFB1344
	.uleb128 LEHE16-LEHB16
	.uleb128 L60-LFB1344
	.uleb128 0
	.uleb128 LEHB17-LFB1344
	.uleb128 LEHE17-LEHB17
	.uleb128 L61-LFB1344
	.uleb128 0
	.uleb128 LEHB18-LFB1344
	.uleb128 LEHE18-LEHB18
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB19-LFB1344
	.uleb128 LEHE19-LEHB19
	.uleb128 0
	.uleb128 0
LLSDACSE1344:
	.section	.text$_ZN11InstructionD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN11InstructionaSERKS_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN11InstructionaSERKS_
	.def	__ZN11InstructionaSERKS_;	.scl	2;	.type	32;	.endef
__ZN11InstructionaSERKS_:
LFB1345:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSsaSERKSs
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$4, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSsaSERKSs
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt6vectorISt4pairIiiESaIS1_EEaSERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1345:
	.section .rdata,"dr"
LC5:
	.ascii "vector::_M_insert_aux\0"
	.section	.text$_ZNSt6vectorI11InstructionSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI11InstructionSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_
	.def	__ZNSt6vectorI11InstructionSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI11InstructionSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_:
LFB1338:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1338
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	4(%eax), %edx
	movl	-60(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L66
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	-20(%eax), %ecx
	movl	-60(%ebp), %eax
	movl	4(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB20:
	call	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE9constructIS1_EEvRS2_PS1_RKT_
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	20(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%eax)
	leal	-48(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN11InstructionC1ERKS_
LEHE20:
	subl	$4, %esp
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	-20(%eax), %esi
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	-40(%eax), %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
LEHB21:
	call	__ZSt13copy_backwardIP11InstructionS1_ET0_T_S3_S2_
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEdeEv
	leal	-48(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN11InstructionaSERKS_
LEHE21:
	subl	$4, %esp
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
LEHB22:
	call	__ZN11InstructionD1Ev
LEHE22:
	jmp	L65
L66:
	movl	-60(%ebp), %eax
	movl	$LC5, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
LEHB23:
	call	__ZNKSt6vectorI11InstructionSaIS0_EE12_M_check_lenEjPKc
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI11InstructionSaIS0_EE5beginEv
	movl	%eax, -28(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIP11InstructionSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_
	movl	%eax, -20(%ebp)
	movl	-60(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI11InstructionSaIS0_EE11_M_allocateEj
LEHE23:
	subl	$4, %esp
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-60(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
LEHB24:
	call	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE9constructIS1_EEvRS2_PS1_RKT_
	movl	$0, -12(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIP11InstructionS1_SaIS0_EET0_T_S4_S3_RT1_
	movl	%eax, -12(%ebp)
	addl	$20, -12(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	movl	-60(%ebp), %eax
	movl	4(%eax), %esi
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIP11InstructionS1_SaIS0_EET0_T_S4_S3_RT1_
LEHE24:
	movl	%eax, -12(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv
	movl	-60(%ebp), %edx
	movl	4(%edx), %ecx
	movl	-60(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
LEHB25:
	call	__ZSt8_DestroyIP11InstructionS0_EvT_S2_RSaIT0_E
	movl	-60(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %ecx
	addl	%ecx, %eax
	sall	%eax
	addl	%edx, %eax
	movl	%eax, %ecx
	sall	$8, %ecx
	addl	%ecx, %eax
	movl	%eax, %ecx
	sall	$16, %ecx
	addl	%ecx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%eax, %ecx
	movl	-60(%ebp), %eax
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI11InstructionSaIS0_EE13_M_deallocateEPS0_j
LEHE25:
	subl	$8, %esp
	movl	-60(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	-60(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L65
L75:
	movl	%eax, %ebx
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN11InstructionD1Ev
	movl	%ebx, %eax
	jmp	L69
L74:
L69:
	movl	%eax, (%esp)
LEHB26:
	call	__Unwind_Resume
LEHE26:
L77:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB27:
	call	__Unwind_Resume
LEHE27:
L76:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	cmpl	$0, -12(%ebp)
	jne	L72
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB28:
	call	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE7destroyERS2_PS1_
	jmp	L73
L72:
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP11InstructionS0_EvT_S2_RSaIT0_E
L73:
	movl	-60(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI11InstructionSaIS0_EE13_M_deallocateEPS0_j
	subl	$8, %esp
	call	___cxa_rethrow
LEHE28:
L65:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1338:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1338:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1338-LLSDATTD1338
LLSDATTD1338:
	.byte	0x1
	.uleb128 LLSDACSE1338-LLSDACSB1338
LLSDACSB1338:
	.uleb128 LEHB20-LFB1338
	.uleb128 LEHE20-LEHB20
	.uleb128 L74-LFB1338
	.uleb128 0
	.uleb128 LEHB21-LFB1338
	.uleb128 LEHE21-LEHB21
	.uleb128 L75-LFB1338
	.uleb128 0
	.uleb128 LEHB22-LFB1338
	.uleb128 LEHE22-LEHB22
	.uleb128 L74-LFB1338
	.uleb128 0
	.uleb128 LEHB23-LFB1338
	.uleb128 LEHE23-LEHB23
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB24-LFB1338
	.uleb128 LEHE24-LEHB24
	.uleb128 L76-LFB1338
	.uleb128 0x1
	.uleb128 LEHB25-LFB1338
	.uleb128 LEHE25-LEHB25
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB26-LFB1338
	.uleb128 LEHE26-LEHB26
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB27-LFB1338
	.uleb128 LEHE27-LEHB27
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB28-LFB1338
	.uleb128 LEHE28-LEHB28
	.uleb128 L77-LFB1338
	.uleb128 0
LLSDACSE1338:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1338:
	.section	.text$_ZNSt6vectorI11InstructionSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_,"x"
	.linkonce discard
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4WireEE9constructIS1_EEvRS2_PS1_RKT_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE9constructIS1_EEvRS2_PS1_RKT_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE9constructIS1_EEvRS2_PS1_RKT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE9constructIS1_EEvRS2_PS1_RKT_:
LFB1346:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4WireE9constructEPS1_RKS1_
	subl	$8, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1346:
	.section	.text$_ZN4WireC1ERKS_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4WireC1ERKS_
	.def	__ZN4WireC1ERKS_;	.scl	2;	.type	32;	.endef
__ZN4WireC1ERKS_:
LFB1350:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1350
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB29:
	call	__ZNSsC1ERKSs
LEHE29:
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-28(%ebp), %eax
	leal	8(%eax), %ebx
	movl	%ebx, %edi
	movl	$1, %esi
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, -32(%ebp)
	jmp	L80
L81:
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edi, %ecx
LEHB30:
	call	__ZNSsC1ERKSs
LEHE30:
	subl	$4, %esp
	addl	$4, %edi
	addl	$4, -32(%ebp)
	decl	%esi
L80:
	cmpl	$-1, %esi
	setne	%al
	testb	%al, %al
	jne	L81
	jmp	L86
L85:
	movl	%eax, %edi
	testl	%ebx, %ebx
	je	L83
	movl	$0, %eax
	subl	%esi, %eax
	sall	$2, %eax
	addl	$4, %eax
	leal	(%ebx,%eax), %esi
L84:
	cmpl	%ebx, %esi
	je	L83
	subl	$4, %esi
	movl	%esi, %ecx
	call	__ZNSsD1Ev
	jmp	L84
L83:
	movl	%edi, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB31:
	call	__Unwind_Resume
LEHE31:
L86:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1350:
	.section	.gcc_except_table,"w"
LLSDA1350:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1350-LLSDACSB1350
LLSDACSB1350:
	.uleb128 LEHB29-LFB1350
	.uleb128 LEHE29-LEHB29
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB30-LFB1350
	.uleb128 LEHE30-LEHB30
	.uleb128 L85-LFB1350
	.uleb128 0
	.uleb128 LEHB31-LFB1350
	.uleb128 LEHE31-LEHB31
	.uleb128 0
	.uleb128 0
LLSDACSE1350:
	.section	.text$_ZN4WireC1ERKS_,"x"
	.linkonce discard
	.section	.text$_ZN4WireD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4WireD1Ev
	.def	__ZN4WireD1Ev;	.scl	2;	.type	32;	.endef
__ZN4WireD1Ev:
LFB1353:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1353
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	testl	%eax, %eax
	je	L88
	movl	-12(%ebp), %eax
	leal	16(%eax), %ebx
L89:
	movl	-12(%ebp), %eax
	addl	$8, %eax
	cmpl	%eax, %ebx
	je	L88
	subl	$4, %ebx
	movl	%ebx, %ecx
LEHB32:
	call	__ZNSsD1Ev
LEHE32:
	jmp	L89
L88:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
LEHB33:
	call	__ZNSsD1Ev
LEHE33:
	jmp	L93
L92:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB34:
	call	__Unwind_Resume
LEHE34:
L93:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1353:
	.section	.gcc_except_table,"w"
LLSDA1353:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1353-LLSDACSB1353
LLSDACSB1353:
	.uleb128 LEHB32-LFB1353
	.uleb128 LEHE32-LEHB32
	.uleb128 L92-LFB1353
	.uleb128 0
	.uleb128 LEHB33-LFB1353
	.uleb128 LEHE33-LEHB33
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB34-LFB1353
	.uleb128 LEHE34-LEHB34
	.uleb128 0
	.uleb128 0
LLSDACSE1353:
	.section	.text$_ZN4WireD1Ev,"x"
	.linkonce discard
	.section	.text$_ZN4WireaSERKS_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4WireaSERKS_
	.def	__ZN4WireaSERKS_;	.scl	2;	.type	32;	.endef
__ZN4WireaSERKS_:
LFB1354:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSsaSERKSs
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-28(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %esi
	movl	$1, %ebx
	movl	8(%ebp), %eax
	leal	8(%eax), %edi
	jmp	L95
L96:
	movl	%edi, (%esp)
	movl	%esi, %ecx
	call	__ZNSsaSERKSs
	subl	$4, %esp
	addl	$4, %esi
	addl	$4, %edi
	decl	%ebx
L95:
	cmpl	$-1, %ebx
	setne	%al
	testb	%al, %al
	jne	L96
	movl	-28(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1354:
	.section	.text$_ZNSt6vectorI4WireSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4WireSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_
	.def	__ZNSt6vectorI4WireSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4WireSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_:
LFB1347:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1347
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	%ecx, -60(%ebp)
	movl	-60(%ebp), %eax
	movl	4(%eax), %edx
	movl	-60(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	je	L99
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	-16(%eax), %ecx
	movl	-60(%ebp), %eax
	movl	4(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB35:
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE9constructIS1_EEvRS2_PS1_RKT_
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	16(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%eax)
	leal	-44(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN4WireC1ERKS_
LEHE35:
	subl	$4, %esp
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	-16(%eax), %esi
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	leal	-32(%eax), %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
LEHB36:
	call	__ZSt13copy_backwardIP4WireS1_ET0_T_S3_S2_
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEdeEv
	leal	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN4WireaSERKS_
LEHE36:
	subl	$4, %esp
	leal	-44(%ebp), %eax
	movl	%eax, %ecx
LEHB37:
	call	__ZN4WireD1Ev
LEHE37:
	jmp	L98
L99:
	movl	-60(%ebp), %eax
	movl	$LC5, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
LEHB38:
	call	__ZNKSt6vectorI4WireSaIS0_EE12_M_check_lenEjPKc
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorI4WireSaIS0_EE5beginEv
	movl	%eax, -28(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIP4WireSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_
	movl	%eax, -20(%ebp)
	movl	-60(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4WireSaIS0_EE11_M_allocateEj
LEHE38:
	subl	$4, %esp
	movl	%eax, -24(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, %edx
	sall	$4, %edx
	movl	-24(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-60(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
LEHB39:
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE9constructIS1_EEvRS2_PS1_RKT_
	movl	$0, -12(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-24(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIP4WireS1_SaIS0_EET0_T_S4_S3_RT1_
	movl	%eax, -12(%ebp)
	addl	$16, -12(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	movl	-60(%ebp), %eax
	movl	4(%eax), %esi
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt34__uninitialized_move_if_noexcept_aIP4WireS1_SaIS0_EET0_T_S4_S3_RT1_
LEHE39:
	movl	%eax, -12(%ebp)
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv
	movl	-60(%ebp), %edx
	movl	4(%edx), %ecx
	movl	-60(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
LEHB40:
	call	__ZSt8_DestroyIP4WireS0_EvT_S2_RSaIT0_E
	movl	-60(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$4, %eax
	movl	%eax, %ecx
	movl	-60(%ebp), %eax
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4WireSaIS0_EE13_M_deallocateEPS0_j
LEHE40:
	subl	$8, %esp
	movl	-60(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	-60(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	-16(%ebp), %eax
	movl	%eax, %edx
	sall	$4, %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L98
L108:
	movl	%eax, %ebx
	leal	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN4WireD1Ev
	movl	%ebx, %eax
	jmp	L102
L107:
L102:
	movl	%eax, (%esp)
LEHB41:
	call	__Unwind_Resume
LEHE41:
L110:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB42:
	call	__Unwind_Resume
LEHE42:
L109:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	cmpl	$0, -12(%ebp)
	jne	L105
	movl	-20(%ebp), %eax
	movl	%eax, %edx
	sall	$4, %edx
	movl	-24(%ebp), %eax
	addl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB43:
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE7destroyERS2_PS1_
	jmp	L106
L105:
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP4WireS0_EvT_S2_RSaIT0_E
L106:
	movl	-60(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseI4WireSaIS0_EE13_M_deallocateEPS0_j
	subl	$8, %esp
	call	___cxa_rethrow
LEHE43:
L98:
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1347:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1347:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1347-LLSDATTD1347
LLSDATTD1347:
	.byte	0x1
	.uleb128 LLSDACSE1347-LLSDACSB1347
LLSDACSB1347:
	.uleb128 LEHB35-LFB1347
	.uleb128 LEHE35-LEHB35
	.uleb128 L107-LFB1347
	.uleb128 0
	.uleb128 LEHB36-LFB1347
	.uleb128 LEHE36-LEHB36
	.uleb128 L108-LFB1347
	.uleb128 0
	.uleb128 LEHB37-LFB1347
	.uleb128 LEHE37-LEHB37
	.uleb128 L107-LFB1347
	.uleb128 0
	.uleb128 LEHB38-LFB1347
	.uleb128 LEHE38-LEHB38
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB39-LFB1347
	.uleb128 LEHE39-LEHB39
	.uleb128 L109-LFB1347
	.uleb128 0x1
	.uleb128 LEHB40-LFB1347
	.uleb128 LEHE40-LEHB40
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB41-LFB1347
	.uleb128 LEHE41-LEHB41
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB42-LFB1347
	.uleb128 LEHE42-LEHB42
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB43-LFB1347
	.uleb128 LEHE43-LEHB43
	.uleb128 L110-LFB1347
	.uleb128 0
LLSDACSE1347:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1347:
	.section	.text$_ZNSt6vectorI4WireSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorI4WireSaIS0_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4WireSaIS0_EE3endEv
	.def	__ZNSt6vectorI4WireSaIS0_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4WireSaIS0_EE3endEv:
LFB1355:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEC1ERKS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1355:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI11InstructionE9constructEPS1_RKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI11InstructionE9constructEPS1_RKS1_
	.def	__ZN9__gnu_cxx13new_allocatorI11InstructionE9constructEPS1_RKS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI11InstructionE9constructEPS1_RKS1_:
LFB1367:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1367
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$20, (%esp)
	call	__ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L113
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
LEHB44:
	call	__ZN11InstructionC1ERKS_
LEHE44:
	subl	$4, %esp
	jmp	L113
L117:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB45:
	call	__Unwind_Resume
LEHE45:
L113:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1367:
	.section	.gcc_except_table,"w"
LLSDA1367:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1367-LLSDACSB1367
LLSDACSB1367:
	.uleb128 LEHB44-LFB1367
	.uleb128 LEHE44-LEHB44
	.uleb128 L117-LFB1367
	.uleb128 0
	.uleb128 LEHB45-LFB1367
	.uleb128 LEHE45-LEHB45
	.uleb128 0
	.uleb128 0
LLSDACSE1367:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI11InstructionE9constructEPS1_RKS1_,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EEC1ERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorISt4pairIiiESaIS1_EEC1ERKS3_
	.def	__ZNSt6vectorISt4pairIiiESaIS1_EEC1ERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISt4pairIiiESaIS1_EEC1ERKS3_:
LFB1370:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1370
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaISt4pairIiiEEE17_S_select_on_copyERKS3_
	movl	%eax, %ebx
	movl	8(%ebp), %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv
	movl	-28(%ebp), %edx
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	movl	%edx, %ecx
LEHB46:
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EEC2EjRKS2_
LEHE46:
	subl	$8, %esp
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %esi
	movl	-28(%ebp), %eax
	movl	(%eax), %edi
	movl	8(%ebp), %ecx
LEHB47:
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE3endEv
	movl	%eax, %ebx
	movl	8(%ebp), %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE5beginEv
	movl	%esi, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E
LEHE47:
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, 4(%eax)
	jmp	L121
L120:
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB48:
	call	__Unwind_Resume
LEHE48:
L121:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1370:
	.section	.gcc_except_table,"w"
LLSDA1370:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1370-LLSDACSB1370
LLSDACSB1370:
	.uleb128 LEHB46-LFB1370
	.uleb128 LEHE46-LEHB46
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB47-LFB1370
	.uleb128 LEHE47-LEHB47
	.uleb128 L120-LFB1370
	.uleb128 0
	.uleb128 LEHB48-LFB1370
	.uleb128 LEHE48-LEHB48
	.uleb128 0
	.uleb128 0
LLSDACSE1370:
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EEC1ERKS3_,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorISt4pairIiiESaIS1_EED1Ev
	.def	__ZNSt6vectorISt4pairIiiESaIS1_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISt4pairIiiESaIS1_EED1Ev:
LFB1373:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1373
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	movl	-12(%ebp), %edx
	movl	4(%edx), %ecx
	movl	-12(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
LEHB49:
	call	__ZSt8_DestroyIPSt4pairIiiES1_EvT_S3_RSaIT0_E
LEHE49:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
LEHB50:
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
LEHE50:
	jmp	L126
L125:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB51:
	call	__Unwind_Resume
LEHE51:
L126:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1373:
	.section	.gcc_except_table,"w"
LLSDA1373:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1373-LLSDACSB1373
LLSDACSB1373:
	.uleb128 LEHB49-LFB1373
	.uleb128 LEHE49-LEHB49
	.uleb128 L125-LFB1373
	.uleb128 0
	.uleb128 LEHB50-LFB1373
	.uleb128 LEHE50-LEHB50
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB51-LFB1373
	.uleb128 LEHE51-LEHB51
	.uleb128 0
	.uleb128 0
LLSDACSE1373:
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZSt13copy_backwardIP11InstructionS1_ET0_T_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt13copy_backwardIP11InstructionS1_ET0_T_S3_S2_
	.def	__ZSt13copy_backwardIP11InstructionS1_ET0_T_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt13copy_backwardIP11InstructionS1_ET0_T_S3_S2_:
LFB1374:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIP11InstructionENSt11_Miter_baseIT_E13iterator_typeES3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIP11InstructionENSt11_Miter_baseIT_E13iterator_typeES3_
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt23__copy_move_backward_a2ILb0EP11InstructionS1_ET1_T0_S3_S2_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1374:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEdeEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEdeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEEdeEv:
LFB1375:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1375:
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EEaSERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorISt4pairIiiESaIS1_EEaSERKS3_
	.def	__ZNSt6vectorISt4pairIiiESaIS1_EEaSERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISt4pairIiiESaIS1_EEaSERKS3_:
LFB1377:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -44(%ebp)
	movl	8(%ebp), %eax
	cmpl	-44(%ebp), %eax
	je	L132
	movl	8(%ebp), %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv
	movl	%eax, -28(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE8capacityEv
	cmpl	-28(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L133
	movl	8(%ebp), %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE3endEv
	movl	%eax, %ebx
	movl	8(%ebp), %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE5beginEv
	movl	-44(%ebp), %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt6vectorISt4pairIiiESaIS1_EE20_M_allocate_and_copyIN9__gnu_cxx17__normal_iteratorIPKS1_S3_EEEEPS1_jT_SB_
	subl	$12, %esp
	movl	%eax, -32(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	movl	-44(%ebp), %edx
	movl	4(%edx), %ecx
	movl	-44(%ebp), %edx
	movl	(%edx), %edx
	movl	%eax, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt8_DestroyIPSt4pairIiiES1_EvT_S3_RSaIT0_E
	movl	-44(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$3, %eax
	movl	%eax, %ecx
	movl	-44(%ebp), %eax
	movl	(%eax), %edx
	movl	-44(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE13_M_deallocateEPS1_j
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, (%eax)
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L134
L133:
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv
	cmpl	-28(%ebp), %eax
	setae	%al
	testb	%al, %al
	je	L135
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %esi
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorISt4pairIiiESaIS1_EE3endEv
	movl	%eax, %ebx
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt6vectorISt4pairIiiESaIS1_EE5beginEv
	movl	%eax, -52(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE3endEv
	movl	%eax, %edi
	movl	8(%ebp), %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE5beginEv
	movl	-52(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET0_T_SD_SC_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RSaIT0_E
	jmp	L134
L135:
	movl	-44(%ebp), %eax
	movl	(%eax), %ebx
	movl	8(%ebp), %eax
	movl	(%eax), %esi
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv
	sall	$3, %eax
	leal	(%esi,%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%ebx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4copyIPSt4pairIiiES2_ET0_T_S4_S3_
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, %ebx
	movl	-44(%ebp), %eax
	movl	4(%eax), %edi
	movl	8(%ebp), %eax
	movl	4(%eax), %esi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -48(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv
	sall	$3, %eax
	addl	-48(%ebp), %eax
	movl	%ebx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__uninitialized_copy_aIPSt4pairIiiES2_S1_ET0_T_S4_S3_RSaIT1_E
L134:
	movl	-44(%ebp), %eax
	movl	(%eax), %eax
	movl	-28(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	%edx, 4(%eax)
L132:
	movl	-44(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1377:
	.section	.text$_ZNKSt6vectorI11InstructionSaIS0_EE12_M_check_lenEjPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI11InstructionSaIS0_EE12_M_check_lenEjPKc
	.def	__ZNKSt6vectorI11InstructionSaIS0_EE12_M_check_lenEjPKc;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI11InstructionSaIS0_EE12_M_check_lenEjPKc:
LFB1378:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI11InstructionSaIS0_EE8max_sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	8(%ebp), %eax
	cmpl	%eax, %edx
	setb	%al
	testb	%al, %al
	je	L138
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt20__throw_length_errorPKc
L138:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv
	movl	%eax, -16(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv
	cmpl	-12(%ebp), %eax
	ja	L139
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI11InstructionSaIS0_EE8max_sizeEv
	cmpl	-12(%ebp), %eax
	jae	L140
L139:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI11InstructionSaIS0_EE8max_sizeEv
	jmp	L141
L140:
	movl	-12(%ebp), %eax
L141:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1378:
	.section	.text$_ZN9__gnu_cxxmiIP11InstructionSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxmiIP11InstructionSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_
	.def	__ZN9__gnu_cxxmiIP11InstructionSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxmiIP11InstructionSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_:
LFB1379:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP11InstructionSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %ecx
	addl	%ecx, %eax
	sall	%eax
	addl	%edx, %eax
	movl	%eax, %ecx
	sall	$8, %ecx
	addl	%ecx, %eax
	movl	%eax, %ecx
	sall	$16, %ecx
	addl	%ecx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1379:
	.section	.text$_ZNSt12_Vector_baseI11InstructionSaIS0_EE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI11InstructionSaIS0_EE11_M_allocateEj
	.def	__ZNSt12_Vector_baseI11InstructionSaIS0_EE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI11InstructionSaIS0_EE11_M_allocateEj:
LFB1380:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L146
	movl	-12(%ebp), %eax
	movl	$0, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI11InstructionE8allocateEjPKv
	subl	$8, %esp
	jmp	L147
L146:
	movl	$0, %eax
L147:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1380:
	.section	.text$_ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv:
LFB1381:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1381:
	.section	.text$_ZSt34__uninitialized_move_if_noexcept_aIP11InstructionS1_SaIS0_EET0_T_S4_S3_RT1_,"x"
	.linkonce discard
	.globl	__ZSt34__uninitialized_move_if_noexcept_aIP11InstructionS1_SaIS0_EET0_T_S4_S3_RT1_
	.def	__ZSt34__uninitialized_move_if_noexcept_aIP11InstructionS1_SaIS0_EET0_T_S4_S3_RT1_;	.scl	2;	.type	32;	.endef
__ZSt34__uninitialized_move_if_noexcept_aIP11InstructionS1_SaIS0_EET0_T_S4_S3_RT1_:
LFB1382:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt22__uninitialized_copy_aIP11InstructionS1_S0_ET0_T_S3_S2_RSaIT1_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1382:
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE7destroyERS2_PS1_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE7destroyERS2_PS1_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE7destroyERS2_PS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE7destroyERS2_PS1_:
LFB1383:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI11InstructionE7destroyEPS1_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1383:
	.section	.text$_ZSt8_DestroyIP11InstructionS0_EvT_S2_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIP11InstructionS0_EvT_S2_RSaIT0_E
	.def	__ZSt8_DestroyIP11InstructionS0_EvT_S2_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIP11InstructionS0_EvT_S2_RSaIT0_E:
LFB1384:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP11InstructionEvT_S2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1384:
	.section	.text$_ZNSt12_Vector_baseI11InstructionSaIS0_EE13_M_deallocateEPS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI11InstructionSaIS0_EE13_M_deallocateEPS0_j
	.def	__ZNSt12_Vector_baseI11InstructionSaIS0_EE13_M_deallocateEPS0_j;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI11InstructionSaIS0_EE13_M_deallocateEPS0_j:
LFB1385:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L155
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI11InstructionE10deallocateEPS1_j
	subl	$8, %esp
L155:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1385:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4WireE9constructEPS1_RKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4WireE9constructEPS1_RKS1_
	.def	__ZN9__gnu_cxx13new_allocatorI4WireE9constructEPS1_RKS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4WireE9constructEPS1_RKS1_:
LFB1386:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1386
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$16, (%esp)
	call	__ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L157
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
LEHB52:
	call	__ZN4WireC1ERKS_
LEHE52:
	subl	$4, %esp
	jmp	L157
L161:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB53:
	call	__Unwind_Resume
LEHE53:
L157:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1386:
	.section	.gcc_except_table,"w"
LLSDA1386:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1386-LLSDACSB1386
LLSDACSB1386:
	.uleb128 LEHB52-LFB1386
	.uleb128 LEHE52-LEHB52
	.uleb128 L161-LFB1386
	.uleb128 0
	.uleb128 LEHB53-LFB1386
	.uleb128 LEHE53-LEHB53
	.uleb128 0
	.uleb128 0
LLSDACSE1386:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4WireE9constructEPS1_RKS1_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv:
LFB1387:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1387:
	.section	.text$_ZSt13copy_backwardIP4WireS1_ET0_T_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt13copy_backwardIP4WireS1_ET0_T_S3_S2_
	.def	__ZSt13copy_backwardIP4WireS1_ET0_T_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt13copy_backwardIP4WireS1_ET0_T_S3_S2_:
LFB1388:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIP4WireENSt11_Miter_baseIT_E13iterator_typeES3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIP4WireENSt11_Miter_baseIT_E13iterator_typeES3_
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt23__copy_move_backward_a2ILb0EP4WireS1_ET1_T0_S3_S2_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1388:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEdeEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEdeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEdeEv:
LFB1389:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1389:
	.section	.text$_ZNKSt6vectorI4WireSaIS0_EE12_M_check_lenEjPKc,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI4WireSaIS0_EE12_M_check_lenEjPKc
	.def	__ZNKSt6vectorI4WireSaIS0_EE12_M_check_lenEjPKc;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI4WireSaIS0_EE12_M_check_lenEjPKc:
LFB1390:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE8max_sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE4sizeEv
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	8(%ebp), %eax
	cmpl	%eax, %edx
	setb	%al
	testb	%al, %al
	je	L169
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt20__throw_length_errorPKc
L169:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE4sizeEv
	movl	%eax, %ebx
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE4sizeEv
	movl	%eax, -16(%ebp)
	leal	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	addl	%ebx, %eax
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE4sizeEv
	cmpl	-12(%ebp), %eax
	ja	L170
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE8max_sizeEv
	cmpl	-12(%ebp), %eax
	jae	L171
L170:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt6vectorI4WireSaIS0_EE8max_sizeEv
	jmp	L172
L171:
	movl	-12(%ebp), %eax
L172:
	addl	$52, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1390:
	.section	.text$_ZNSt6vectorI4WireSaIS0_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorI4WireSaIS0_EE5beginEv
	.def	__ZNSt6vectorI4WireSaIS0_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorI4WireSaIS0_EE5beginEv:
LFB1391:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEC1ERKS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1391:
	.section	.text$_ZN9__gnu_cxxmiIP4WireSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxmiIP4WireSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_
	.def	__ZN9__gnu_cxxmiIP4WireSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxmiIP4WireSt6vectorIS1_SaIS1_EEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS9_SC_:
LFB1392:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEE4baseEv
	movl	(%eax), %eax
	movl	%ebx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$4, %eax
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1392:
	.section	.text$_ZNSt12_Vector_baseI4WireSaIS0_EE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4WireSaIS0_EE11_M_allocateEj
	.def	__ZNSt12_Vector_baseI4WireSaIS0_EE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4WireSaIS0_EE11_M_allocateEj:
LFB1393:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L179
	movl	-12(%ebp), %eax
	movl	$0, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4WireE8allocateEjPKv
	subl	$8, %esp
	jmp	L180
L179:
	movl	$0, %eax
L180:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1393:
	.section	.text$_ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv:
LFB1394:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1394:
	.section	.text$_ZSt34__uninitialized_move_if_noexcept_aIP4WireS1_SaIS0_EET0_T_S4_S3_RT1_,"x"
	.linkonce discard
	.globl	__ZSt34__uninitialized_move_if_noexcept_aIP4WireS1_SaIS0_EET0_T_S4_S3_RT1_
	.def	__ZSt34__uninitialized_move_if_noexcept_aIP4WireS1_SaIS0_EET0_T_S4_S3_RT1_;	.scl	2;	.type	32;	.endef
__ZSt34__uninitialized_move_if_noexcept_aIP4WireS1_SaIS0_EET0_T_S4_S3_RT1_:
LFB1395:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt22__uninitialized_copy_aIP4WireS1_S0_ET0_T_S3_S2_RSaIT1_E
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1395:
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4WireEE7destroyERS2_PS1_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE7destroyERS2_PS1_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE7destroyERS2_PS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE7destroyERS2_PS1_:
LFB1396:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4WireE7destroyEPS1_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1396:
	.section	.text$_ZSt8_DestroyIP4WireS0_EvT_S2_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIP4WireS0_EvT_S2_RSaIT0_E
	.def	__ZSt8_DestroyIP4WireS0_EvT_S2_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIP4WireS0_EvT_S2_RSaIT0_E:
LFB1397:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIP4WireEvT_S2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1397:
	.section	.text$_ZNSt12_Vector_baseI4WireSaIS0_EE13_M_deallocateEPS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseI4WireSaIS0_EE13_M_deallocateEPS0_j
	.def	__ZNSt12_Vector_baseI4WireSaIS0_EE13_M_deallocateEPS0_j;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseI4WireSaIS0_EE13_M_deallocateEPS0_j:
LFB1398:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L188
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4WireE10deallocateEPS1_j
	subl	$8, %esp
L188:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1398:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEC1ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEC1ERKS2_
	.def	__ZN9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIP4WireSt6vectorIS1_SaIS1_EEEC1ERKS2_:
LFB1401:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1401:
	.section	.text$_ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv
	.def	__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorISt4pairIiiESaIS1_EE4sizeEv:
LFB1405:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$3, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1405:
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaISt4pairIiiEEE17_S_select_on_copyERKS3_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaISt4pairIiiEEE17_S_select_on_copyERKS3_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaISt4pairIiiEEE17_S_select_on_copyERKS3_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaISt4pairIiiEEE17_S_select_on_copyERKS3_:
LFB1406:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1406:
	.section	.text$_ZNKSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	.def	__ZNKSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv:
LFB1407:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1407:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implD1Ev
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implD1Ev:
LFB1411:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaISt4pairIiiEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1411:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EEC2EjRKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EEC2EjRKS2_
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EEC2EjRKS2_;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EEC2EjRKS2_:
LFB1412:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1412
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implC1ERKS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB54:
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE17_M_create_storageEj
LEHE54:
	subl	$4, %esp
	jmp	L202
L201:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB55:
	call	__Unwind_Resume
LEHE55:
L202:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1412:
	.section	.gcc_except_table,"w"
LLSDA1412:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1412-LLSDACSB1412
LLSDACSB1412:
	.uleb128 LEHB54-LFB1412
	.uleb128 LEHE54-LEHB54
	.uleb128 L201-LFB1412
	.uleb128 0
	.uleb128 LEHB55-LFB1412
	.uleb128 LEHE55-LEHB55
	.uleb128 0
	.uleb128 0
LLSDACSE1412:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EEC2EjRKS2_,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev:
LFB1415:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1415
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$3, %eax
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB56:
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE13_M_deallocateEPS1_j
LEHE56:
	subl	$8, %esp
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implD1Ev
	jmp	L207
L206:
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implD1Ev
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB57:
	call	__Unwind_Resume
LEHE57:
L207:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1415:
	.section	.gcc_except_table,"w"
LLSDA1415:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1415-LLSDACSB1415
LLSDACSB1415:
	.uleb128 LEHB56-LFB1415
	.uleb128 LEHE56-LEHB56
	.uleb128 L206-LFB1415
	.uleb128 0
	.uleb128 LEHB57-LFB1415
	.uleb128 LEHE57-LEHB57
	.uleb128 0
	.uleb128 0
LLSDACSE1415:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EED2Ev,"x"
	.linkonce discard
	.section	.text$_ZNKSt6vectorISt4pairIiiESaIS1_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorISt4pairIiiESaIS1_EE5beginEv
	.def	__ZNKSt6vectorISt4pairIiiESaIS1_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorISt4pairIiiESaIS1_EE5beginEv:
LFB1417:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS4_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1417:
	.section	.text$_ZNKSt6vectorISt4pairIiiESaIS1_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorISt4pairIiiESaIS1_EE3endEv
	.def	__ZNKSt6vectorISt4pairIiiESaIS1_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorISt4pairIiiESaIS1_EE3endEv:
LFB1418:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS4_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1418:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv:
LFB1419:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1419:
	.section	.text$_ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E:
LFB1420:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1420:
	.section	.text$_ZSt8_DestroyIPSt4pairIiiES1_EvT_S3_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPSt4pairIiiES1_EvT_S3_RSaIT0_E
	.def	__ZSt8_DestroyIPSt4pairIiiES1_EvT_S3_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPSt4pairIiiES1_EvT_S3_RSaIT0_E:
LFB1421:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPSt4pairIiiEEvT_S3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1421:
	.section	.text$_ZSt12__miter_baseIP11InstructionENSt11_Miter_baseIT_E13iterator_typeES3_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIP11InstructionENSt11_Miter_baseIT_E13iterator_typeES3_
	.def	__ZSt12__miter_baseIP11InstructionENSt11_Miter_baseIT_E13iterator_typeES3_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIP11InstructionENSt11_Miter_baseIT_E13iterator_typeES3_:
LFB1422:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIP11InstructionLb0EE7_S_baseES1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1422:
	.section	.text$_ZSt23__copy_move_backward_a2ILb0EP11InstructionS1_ET1_T0_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt23__copy_move_backward_a2ILb0EP11InstructionS1_ET1_T0_S3_S2_
	.def	__ZSt23__copy_move_backward_a2ILb0EP11InstructionS1_ET1_T0_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt23__copy_move_backward_a2ILb0EP11InstructionS1_ET1_T0_S3_S2_:
LFB1423:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIP11InstructionENSt11_Niter_baseIT_E13iterator_typeES3_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIP11InstructionENSt11_Niter_baseIT_E13iterator_typeES3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIP11InstructionENSt11_Niter_baseIT_E13iterator_typeES3_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__copy_move_backward_aILb0EP11InstructionS1_ET1_T0_S3_S2_
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1423:
	.section	.text$_ZNKSt6vectorISt4pairIiiESaIS1_EE8capacityEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorISt4pairIiiESaIS1_EE8capacityEv
	.def	__ZNKSt6vectorISt4pairIiiESaIS1_EE8capacityEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorISt4pairIiiESaIS1_EE8capacityEv:
LFB1424:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$3, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1424:
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EE20_M_allocate_and_copyIN9__gnu_cxx17__normal_iteratorIPKS1_S3_EEEEPS1_jT_SB_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorISt4pairIiiESaIS1_EE20_M_allocate_and_copyIN9__gnu_cxx17__normal_iteratorIPKS1_S3_EEEEPS1_jT_SB_
	.def	__ZNSt6vectorISt4pairIiiESaIS1_EE20_M_allocate_and_copyIN9__gnu_cxx17__normal_iteratorIPKS1_S3_EEEEPS1_jT_SB_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISt4pairIiiESaIS1_EE20_M_allocate_and_copyIN9__gnu_cxx17__normal_iteratorIPKS1_S3_EEEEPS1_jT_SB_:
LFB1425:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1425
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	.cfi_offset 3, -12
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB58:
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE11_M_allocateEj
LEHE58:
	subl	$4, %esp
	movl	%eax, -12(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE19_M_get_Tp_allocatorEv
	movl	%eax, 12(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
LEHB59:
	call	__ZSt22__uninitialized_copy_aIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_S3_ET0_T_SC_SB_RSaIT1_E
LEHE59:
	movl	-12(%ebp), %eax
	jmp	L229
L228:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB60:
	call	__Unwind_Resume
LEHE60:
L227:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
LEHB61:
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE13_M_deallocateEPS1_j
	subl	$8, %esp
	call	___cxa_rethrow
LEHE61:
L229:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret	$12
	.cfi_endproc
LFE1425:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1425:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1425-LLSDATTD1425
LLSDATTD1425:
	.byte	0x1
	.uleb128 LLSDACSE1425-LLSDACSB1425
LLSDACSB1425:
	.uleb128 LEHB58-LFB1425
	.uleb128 LEHE58-LEHB58
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB59-LFB1425
	.uleb128 LEHE59-LEHB59
	.uleb128 L227-LFB1425
	.uleb128 0x1
	.uleb128 LEHB60-LFB1425
	.uleb128 LEHE60-LEHB60
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB61-LFB1425
	.uleb128 LEHE61-LEHB61
	.uleb128 L228-LFB1425
	.uleb128 0
LLSDACSE1425:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1425:
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EE20_M_allocate_and_copyIN9__gnu_cxx17__normal_iteratorIPKS1_S3_EEEEPS1_jT_SB_,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EE13_M_deallocateEPS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE13_M_deallocateEPS1_j
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE13_M_deallocateEPS1_j;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE13_M_deallocateEPS1_j:
LFB1426:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L230
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE10deallocateEPS2_j
	subl	$8, %esp
L230:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1426:
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorISt4pairIiiESaIS1_EE5beginEv
	.def	__ZNSt6vectorISt4pairIiiESaIS1_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISt4pairIiiESaIS1_EE5beginEv:
LFB1427:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1427:
	.section	.text$_ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET0_T_SD_SC_,"x"
	.linkonce discard
	.globl	__ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET0_T_SD_SC_
	.def	__ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET0_T_SD_SC_;	.scl	2;	.type	32;	.endef
__ZSt4copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET0_T_SD_SC_:
LFB1428:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Miter_baseIT_E13iterator_typeESB_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Miter_baseIT_E13iterator_typeESB_
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET1_T0_SD_SC_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1428:
	.section	.text$_ZNSt6vectorISt4pairIiiESaIS1_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt6vectorISt4pairIiiESaIS1_EE3endEv
	.def	__ZNSt6vectorISt4pairIiiESaIS1_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISt4pairIiiESaIS1_EE3endEv:
LFB1429:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	-28(%ebp), %eax
	leal	4(%eax), %edx
	leal	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1429:
	.section	.text$_ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RSaIT0_E,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RSaIT0_E
	.def	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RSaIT0_E;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RSaIT0_E:
LFB1430:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEEvT_S9_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1430:
	.section	.text$_ZSt4copyIPSt4pairIiiES2_ET0_T_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt4copyIPSt4pairIiiES2_ET0_T_S4_S3_
	.def	__ZSt4copyIPSt4pairIiiES2_ET0_T_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt4copyIPSt4pairIiiES2_ET0_T_S4_S3_:
LFB1431:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPSt4pairIiiEENSt11_Miter_baseIT_E13iterator_typeES4_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPSt4pairIiiEENSt11_Miter_baseIT_E13iterator_typeES4_
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt14__copy_move_a2ILb0EPSt4pairIiiES2_ET1_T0_S4_S3_
	addl	$20, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1431:
	.section	.text$_ZSt22__uninitialized_copy_aIPSt4pairIiiES2_S1_ET0_T_S4_S3_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aIPSt4pairIiiES2_S1_ET0_T_S4_S3_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aIPSt4pairIiiES2_S1_ET0_T_S4_S3_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aIPSt4pairIiiES2_S1_ET0_T_S4_S3_RSaIT1_E:
LFB1432:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyIPSt4pairIiiES2_ET0_T_S4_S3_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1432:
	.section	.text$_ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv
	.def	__ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI11InstructionSaIS0_EE4sizeEv:
LFB1433:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %ecx
	addl	%ecx, %eax
	sall	%eax
	addl	%edx, %eax
	movl	%eax, %ecx
	sall	$8, %ecx
	addl	%ecx, %eax
	movl	%eax, %ecx
	sall	$16, %ecx
	addl	%ecx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1433:
	.section	.text$_ZNKSt6vectorI11InstructionSaIS0_EE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI11InstructionSaIS0_EE8max_sizeEv
	.def	__ZNKSt6vectorI11InstructionSaIS0_EE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI11InstructionSaIS0_EE8max_sizeEv:
LFB1434:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE8max_sizeERKS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1434:
	.section	.text$_ZSt3maxIjERKT_S2_S2_,"x"
	.linkonce discard
	.globl	__ZSt3maxIjERKT_S2_S2_
	.def	__ZSt3maxIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3maxIjERKT_S2_S2_:
LFB1435:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jae	L248
	movl	12(%ebp), %eax
	jmp	L249
L248:
	movl	8(%ebp), %eax
L249:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1435:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI11InstructionE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI11InstructionE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorI11InstructionE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI11InstructionE8allocateEjPKv:
LFB1436:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorI11InstructionE8max_sizeEv
	cmpl	8(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L251
	call	__ZSt17__throw_bad_allocv
L251:
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1436:
	.section	.text$_ZSt22__uninitialized_copy_aIP11InstructionS1_S0_ET0_T_S3_S2_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aIP11InstructionS1_S0_ET0_T_S3_S2_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aIP11InstructionS1_S0_ET0_T_S3_S2_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aIP11InstructionS1_S0_ET0_T_S3_S2_RSaIT1_E:
LFB1437:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyIP11InstructionS1_ET0_T_S3_S2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1437:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI11InstructionE7destroyEPS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI11InstructionE7destroyEPS1_
	.def	__ZN9__gnu_cxx13new_allocatorI11InstructionE7destroyEPS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI11InstructionE7destroyEPS1_:
LFB1438:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %ecx
	call	__ZN11InstructionD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1438:
	.section	.text$_ZSt8_DestroyIP11InstructionEvT_S2_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIP11InstructionEvT_S2_
	.def	__ZSt8_DestroyIP11InstructionEvT_S2_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIP11InstructionEvT_S2_:
LFB1439:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb0EE9__destroyIP11InstructionEEvT_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1439:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI11InstructionE10deallocateEPS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI11InstructionE10deallocateEPS1_j
	.def	__ZN9__gnu_cxx13new_allocatorI11InstructionE10deallocateEPS1_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI11InstructionE10deallocateEPS1_j:
LFB1440:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1440:
	.section	.text$_ZSt12__miter_baseIP4WireENSt11_Miter_baseIT_E13iterator_typeES3_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIP4WireENSt11_Miter_baseIT_E13iterator_typeES3_
	.def	__ZSt12__miter_baseIP4WireENSt11_Miter_baseIT_E13iterator_typeES3_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIP4WireENSt11_Miter_baseIT_E13iterator_typeES3_:
LFB1441:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIP4WireLb0EE7_S_baseES1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1441:
	.section	.text$_ZSt23__copy_move_backward_a2ILb0EP4WireS1_ET1_T0_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt23__copy_move_backward_a2ILb0EP4WireS1_ET1_T0_S3_S2_
	.def	__ZSt23__copy_move_backward_a2ILb0EP4WireS1_ET1_T0_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt23__copy_move_backward_a2ILb0EP4WireS1_ET1_T0_S3_S2_:
LFB1442:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIP4WireENSt11_Niter_baseIT_E13iterator_typeES3_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIP4WireENSt11_Niter_baseIT_E13iterator_typeES3_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIP4WireENSt11_Niter_baseIT_E13iterator_typeES3_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__copy_move_backward_aILb0EP4WireS1_ET1_T0_S3_S2_
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1442:
	.section	.text$_ZNKSt6vectorI4WireSaIS0_EE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt6vectorI4WireSaIS0_EE8max_sizeEv
	.def	__ZNKSt6vectorI4WireSaIS0_EE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorI4WireSaIS0_EE8max_sizeEv:
LFB1443:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE8max_sizeERKS2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1443:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4WireE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4WireE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorI4WireE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4WireE8allocateEjPKv:
LFB1444:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorI4WireE8max_sizeEv
	cmpl	8(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L265
	call	__ZSt17__throw_bad_allocv
L265:
	movl	8(%ebp), %eax
	sall	$4, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1444:
	.section	.text$_ZSt22__uninitialized_copy_aIP4WireS1_S0_ET0_T_S3_S2_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aIP4WireS1_S0_ET0_T_S3_S2_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aIP4WireS1_S0_ET0_T_S3_S2_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aIP4WireS1_S0_ET0_T_S3_S2_RSaIT1_E:
LFB1445:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyIP4WireS1_ET0_T_S3_S2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1445:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4WireE7destroyEPS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4WireE7destroyEPS1_
	.def	__ZN9__gnu_cxx13new_allocatorI4WireE7destroyEPS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4WireE7destroyEPS1_:
LFB1446:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %ecx
	call	__ZN4WireD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1446:
	.section	.text$_ZSt8_DestroyIP4WireEvT_S2_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIP4WireEvT_S2_
	.def	__ZSt8_DestroyIP4WireEvT_S2_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIP4WireEvT_S2_:
LFB1447:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb0EE9__destroyIP4WireEEvT_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1447:
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4WireE10deallocateEPS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4WireE10deallocateEPS1_j
	.def	__ZN9__gnu_cxx13new_allocatorI4WireE10deallocateEPS1_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4WireE10deallocateEPS1_j:
LFB1448:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1448:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implC1ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implC1ERKS2_
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE12_Vector_implC1ERKS2_:
LFB1451:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSaISt4pairIiiEEC2ERKS1_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	movl	$0, 8(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1451:
	.section	.text$_ZNSaISt4pairIiiEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt4pairIiiEED2Ev
	.def	__ZNSaISt4pairIiiEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISt4pairIiiEED2Ev:
LFB1453:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEED2Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1453:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EE17_M_create_storageEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE17_M_create_storageEj
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE17_M_create_storageEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE17_M_create_storageEj:
LFB1455:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE11_M_allocateEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	sall	$3, %edx
	addl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1455:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS4_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS4_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS4_:
LFB1458:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1458:
	.section	.text$_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_
	.def	__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_:
LFB1459:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1459:
	.section	.text$_ZSt8_DestroyIPSt4pairIiiEEvT_S3_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIPSt4pairIiiEEvT_S3_
	.def	__ZSt8_DestroyIPSt4pairIiiEEvT_S3_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPSt4pairIiiEEvT_S3_:
LFB1460:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb1EE9__destroyIPSt4pairIiiEEEvT_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1460:
	.section	.text$_ZNSt10_Iter_baseIP11InstructionLb0EE7_S_baseES1_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseIP11InstructionLb0EE7_S_baseES1_
	.def	__ZNSt10_Iter_baseIP11InstructionLb0EE7_S_baseES1_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseIP11InstructionLb0EE7_S_baseES1_:
LFB1461:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1461:
	.section	.text$_ZSt12__niter_baseIP11InstructionENSt11_Niter_baseIT_E13iterator_typeES3_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIP11InstructionENSt11_Niter_baseIT_E13iterator_typeES3_
	.def	__ZSt12__niter_baseIP11InstructionENSt11_Niter_baseIT_E13iterator_typeES3_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIP11InstructionENSt11_Niter_baseIT_E13iterator_typeES3_:
LFB1462:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIP11InstructionLb0EE7_S_baseES1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1462:
	.section	.text$_ZSt22__copy_move_backward_aILb0EP11InstructionS1_ET1_T0_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt22__copy_move_backward_aILb0EP11InstructionS1_ET1_T0_S3_S2_
	.def	__ZSt22__copy_move_backward_aILb0EP11InstructionS1_ET1_T0_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt22__copy_move_backward_aILb0EP11InstructionS1_ET1_T0_S3_S2_:
LFB1463:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$0, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP11InstructionS4_EET0_T_S6_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1463:
	.section	.text$_ZNSt12_Vector_baseISt4pairIiiESaIS1_EE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE11_M_allocateEj
	.def	__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISt4pairIiiESaIS1_EE11_M_allocateEj:
LFB1464:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	cmpl	$0, 8(%ebp)
	je	L287
	movl	-12(%ebp), %eax
	movl	$0, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE8allocateEjPKv
	subl	$8, %esp
	jmp	L288
L287:
	movl	$0, %eax
L288:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1464:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIiiEE10deallocateEPS2_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE10deallocateEPS2_j
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE10deallocateEPS2_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE10deallocateEPS2_j:
LFB1465:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1465:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS3_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS3_:
LFB1468:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1468:
	.section	.text$_ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Miter_baseIT_E13iterator_typeESB_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Miter_baseIT_E13iterator_typeESB_
	.def	__ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Miter_baseIT_E13iterator_typeESB_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Miter_baseIT_E13iterator_typeESB_:
LFB1469:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb0EE7_S_baseES9_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1469:
	.section	.text$_ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET1_T0_SD_SC_,"x"
	.linkonce discard
	.globl	__ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET1_T0_SD_SC_
	.def	__ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET1_T0_SD_SC_;	.scl	2;	.type	32;	.endef
__ZSt14__copy_move_a2ILb0EN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEENS1_IPS3_S8_EEET1_T0_SD_SC_:
LFB1470:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$32, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESA_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESB_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESB_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt13__copy_move_aILb0EPKSt4pairIiiEPS1_ET1_T0_S6_S5_
	movl	%eax, -12(%ebp)
	leal	-16(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEEC1ERKS3_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	leal	-8(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1470:
	.section	.text$_ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEEvT_S9_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEEvT_S9_
	.def	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEEvT_S9_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEEvT_S9_:
LFB1471:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Destroy_auxILb1EE9__destroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS5_SaIS5_EEEEEEvT_SB_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1471:
	.section	.text$_ZSt12__miter_baseIPSt4pairIiiEENSt11_Miter_baseIT_E13iterator_typeES4_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIPSt4pairIiiEENSt11_Miter_baseIT_E13iterator_typeES4_
	.def	__ZSt12__miter_baseIPSt4pairIiiEENSt11_Miter_baseIT_E13iterator_typeES4_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIPSt4pairIiiEENSt11_Miter_baseIT_E13iterator_typeES4_:
LFB1472:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIPSt4pairIiiELb0EE7_S_baseES2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1472:
	.section	.text$_ZSt14__copy_move_a2ILb0EPSt4pairIiiES2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt14__copy_move_a2ILb0EPSt4pairIiiES2_ET1_T0_S4_S3_
	.def	__ZSt14__copy_move_a2ILb0EPSt4pairIiiES2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt14__copy_move_a2ILb0EPSt4pairIiiES2_ET1_T0_S4_S3_:
LFB1473:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	.cfi_offset 6, -12
	.cfi_offset 3, -16
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPSt4pairIiiEENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPSt4pairIiiEENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPSt4pairIiiEENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt13__copy_move_aILb0EPSt4pairIiiES2_ET1_T0_S4_S3_
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1473:
	.section	.text$_ZSt18uninitialized_copyIPSt4pairIiiES2_ET0_T_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyIPSt4pairIiiES2_ET0_T_S4_S3_
	.def	__ZSt18uninitialized_copyIPSt4pairIiiES2_ET0_T_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyIPSt4pairIiiES2_ET0_T_S4_S3_:
LFB1474:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIPSt4pairIiiES4_EET0_T_S6_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1474:
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE8max_sizeERKS2_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE8max_sizeERKS2_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE8max_sizeERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI11InstructionEE8max_sizeERKS2_:
LFB1475:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx13new_allocatorI11InstructionE8max_sizeEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1475:
	.section	.text$_ZNKSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNKSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt12_Vector_baseI11InstructionSaIS0_EE19_M_get_Tp_allocatorEv:
LFB1476:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1476:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorI11InstructionE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorI11InstructionE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorI11InstructionE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorI11InstructionE8max_sizeEv:
LFB1477:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$214748364, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1477:
	.section	.text$_ZSt18uninitialized_copyIP11InstructionS1_ET0_T_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyIP11InstructionS1_ET0_T_S3_S2_
	.def	__ZSt18uninitialized_copyIP11InstructionS1_ET0_T_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyIP11InstructionS1_ET0_T_S3_S2_:
LFB1478:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP11InstructionS3_EET0_T_S5_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1478:
	.section	.text$_ZNSt12_Destroy_auxILb0EE9__destroyIP11InstructionEEvT_S4_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb0EE9__destroyIP11InstructionEEvT_S4_
	.def	__ZNSt12_Destroy_auxILb0EE9__destroyIP11InstructionEEvT_S4_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb0EE9__destroyIP11InstructionEEvT_S4_:
LFB1479:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	jmp	L312
L313:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofI11InstructionEPT_RS1_
	movl	%eax, (%esp)
	call	__ZSt8_DestroyI11InstructionEvPT_
	addl	$20, 8(%ebp)
L312:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	setne	%al
	testb	%al, %al
	jne	L313
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1479:
	.section	.text$_ZNSt10_Iter_baseIP4WireLb0EE7_S_baseES1_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseIP4WireLb0EE7_S_baseES1_
	.def	__ZNSt10_Iter_baseIP4WireLb0EE7_S_baseES1_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseIP4WireLb0EE7_S_baseES1_:
LFB1480:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1480:
	.section	.text$_ZSt12__niter_baseIP4WireENSt11_Niter_baseIT_E13iterator_typeES3_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIP4WireENSt11_Niter_baseIT_E13iterator_typeES3_
	.def	__ZSt12__niter_baseIP4WireENSt11_Niter_baseIT_E13iterator_typeES3_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIP4WireENSt11_Niter_baseIT_E13iterator_typeES3_:
LFB1481:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIP4WireLb0EE7_S_baseES1_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1481:
	.section	.text$_ZSt22__copy_move_backward_aILb0EP4WireS1_ET1_T0_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt22__copy_move_backward_aILb0EP4WireS1_ET1_T0_S3_S2_
	.def	__ZSt22__copy_move_backward_aILb0EP4WireS1_ET1_T0_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt22__copy_move_backward_aILb0EP4WireS1_ET1_T0_S3_S2_:
LFB1482:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$0, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP4WireS4_EET0_T_S6_S5_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1482:
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4WireEE8max_sizeERKS2_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE8max_sizeERKS2_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE8max_sizeERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4WireEE8max_sizeERKS2_:
LFB1483:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx13new_allocatorI4WireE8max_sizeEv
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1483:
	.section	.text$_ZNKSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNKSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt12_Vector_baseI4WireSaIS0_EE19_M_get_Tp_allocatorEv:
LFB1484:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1484:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorI4WireE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorI4WireE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorI4WireE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorI4WireE8max_sizeEv:
LFB1485:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$268435455, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1485:
	.section	.text$_ZSt18uninitialized_copyIP4WireS1_ET0_T_S3_S2_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyIP4WireS1_ET0_T_S3_S2_
	.def	__ZSt18uninitialized_copyIP4WireS1_ET0_T_S3_S2_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyIP4WireS1_ET0_T_S3_S2_:
LFB1486:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP4WireS3_EET0_T_S5_S4_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1486:
	.section	.text$_ZNSt12_Destroy_auxILb0EE9__destroyIP4WireEEvT_S4_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb0EE9__destroyIP4WireEEvT_S4_
	.def	__ZNSt12_Destroy_auxILb0EE9__destroyIP4WireEEvT_S4_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb0EE9__destroyIP4WireEEvT_S4_:
LFB1487:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	jmp	L329
L330:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofI4WireEPT_RS1_
	movl	%eax, (%esp)
	call	__ZSt8_DestroyI4WireEvPT_
	addl	$16, 8(%ebp)
L329:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	setne	%al
	testb	%al, %al
	jne	L330
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1487:
	.section	.text$_ZNSaISt4pairIiiEEC2ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaISt4pairIiiEEC2ERKS1_
	.def	__ZNSaISt4pairIiiEEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSaISt4pairIiiEEC2ERKS1_:
LFB1489:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEEC2ERKS3_
	subl	$4, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1489:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIiiEED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIiiEED2Ev:
LFB1492:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1492:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_
	.def	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_:
LFB1494:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1494
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L335
L336:
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEdeEv
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofISt4pairIiiEEPT_RS2_
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt10_ConstructISt4pairIiiES1_EvPT_RKT0_
	leal	8(%ebp), %ecx
	call	__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEppEv
	addl	$8, -12(%ebp)
L335:
	leal	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
LEHB62:
	call	__ZN9__gnu_cxxneIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_
LEHE62:
	testb	%al, %al
	jne	L336
	movl	-12(%ebp), %eax
	jmp	L342
L341:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB63:
	call	__Unwind_Resume
LEHE63:
L340:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIPSt4pairIiiEEvT_S3_
LEHB64:
	call	___cxa_rethrow
LEHE64:
L342:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1494:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1494:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1494-LLSDATTD1494
LLSDATTD1494:
	.byte	0x1
	.uleb128 LLSDACSE1494-LLSDACSB1494
LLSDACSB1494:
	.uleb128 LEHB62-LFB1494
	.uleb128 LEHE62-LEHB62
	.uleb128 L340-LFB1494
	.uleb128 0x1
	.uleb128 LEHB63-LFB1494
	.uleb128 LEHE63-LEHB63
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB64-LFB1494
	.uleb128 LEHE64-LEHB64
	.uleb128 L341-LFB1494
	.uleb128 0
LLSDACSE1494:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1494:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS5_SaIS5_EEEEPS5_EET0_T_SE_SD_,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Destroy_auxILb1EE9__destroyIPSt4pairIiiEEEvT_S5_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb1EE9__destroyIPSt4pairIiiEEEvT_S5_
	.def	__ZNSt12_Destroy_auxILb1EE9__destroyIPSt4pairIiiEEEvT_S5_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb1EE9__destroyIPSt4pairIiiEEEvT_S5_:
LFB1495:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1495:
	.section	.text$_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP11InstructionS4_EET0_T_S6_S5_,"x"
	.linkonce discard
	.globl	__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP11InstructionS4_EET0_T_S6_S5_
	.def	__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP11InstructionS4_EET0_T_S6_S5_;	.scl	2;	.type	32;	.endef
__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP11InstructionS4_EET0_T_S6_S5_:
LFB1496:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, %edx
	sarl	$2, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %ecx
	addl	%ecx, %eax
	sall	%eax
	addl	%edx, %eax
	movl	%eax, %ecx
	sall	$8, %ecx
	addl	%ecx, %eax
	movl	%eax, %ecx
	sall	$16, %ecx
	addl	%ecx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	jmp	L345
L346:
	subl	$20, 12(%ebp)
	subl	$20, 16(%ebp)
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN11InstructionaSERKS_
	subl	$4, %esp
	decl	-12(%ebp)
L345:
	cmpl	$0, -12(%ebp)
	setg	%al
	testb	%al, %al
	jne	L346
	movl	16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1496:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIiiEE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIiiEE8allocateEjPKv:
LFB1497:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorISt4pairIiiEE8max_sizeEv
	cmpl	8(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L349
	call	__ZSt17__throw_bad_allocv
L349:
	movl	8(%ebp), %eax
	sall	$3, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$8
	.cfi_endproc
LFE1497:
	.section	.text$_ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb0EE7_S_baseES9_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb0EE7_S_baseES9_
	.def	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb0EE7_S_baseES9_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb0EE7_S_baseES9_:
LFB1498:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1498:
	.section	.text$_ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESB_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESB_
	.def	__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESB_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESB_:
LFB1499:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES9_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1499:
	.section	.text$_ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESA_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESA_
	.def	__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESA_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEEENSt11_Niter_baseIT_E13iterator_typeESA_:
LFB1500:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES8_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1500:
	.section	.text$_ZSt13__copy_move_aILb0EPKSt4pairIiiEPS1_ET1_T0_S6_S5_,"x"
	.linkonce discard
	.globl	__ZSt13__copy_move_aILb0EPKSt4pairIiiEPS1_ET1_T0_S6_S5_
	.def	__ZSt13__copy_move_aILb0EPKSt4pairIiiEPS1_ET1_T0_S6_S5_;	.scl	2;	.type	32;	.endef
__ZSt13__copy_move_aILb0EPKSt4pairIiiEPS1_ET1_T0_S6_S5_:
LFB1501:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$0, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKSt4pairIiiEPS4_EET0_T_S9_S8_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1501:
	.section	.text$_ZNSt12_Destroy_auxILb1EE9__destroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS5_SaIS5_EEEEEEvT_SB_,"x"
	.linkonce discard
	.globl	__ZNSt12_Destroy_auxILb1EE9__destroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS5_SaIS5_EEEEEEvT_SB_
	.def	__ZNSt12_Destroy_auxILb1EE9__destroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS5_SaIS5_EEEEEEvT_SB_;	.scl	2;	.type	32;	.endef
__ZNSt12_Destroy_auxILb1EE9__destroyIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS5_SaIS5_EEEEEEvT_SB_:
LFB1502:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1502:
	.section	.text$_ZNSt10_Iter_baseIPSt4pairIiiELb0EE7_S_baseES2_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseIPSt4pairIiiELb0EE7_S_baseES2_
	.def	__ZNSt10_Iter_baseIPSt4pairIiiELb0EE7_S_baseES2_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseIPSt4pairIiiELb0EE7_S_baseES2_:
LFB1503:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1503:
	.section	.text$_ZSt12__niter_baseIPSt4pairIiiEENSt11_Niter_baseIT_E13iterator_typeES4_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIPSt4pairIiiEENSt11_Niter_baseIT_E13iterator_typeES4_
	.def	__ZSt12__niter_baseIPSt4pairIiiEENSt11_Niter_baseIT_E13iterator_typeES4_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIPSt4pairIiiEENSt11_Niter_baseIT_E13iterator_typeES4_:
LFB1504:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIPSt4pairIiiELb0EE7_S_baseES2_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1504:
	.section	.text$_ZSt13__copy_move_aILb0EPSt4pairIiiES2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt13__copy_move_aILb0EPSt4pairIiiES2_ET1_T0_S4_S3_
	.def	__ZSt13__copy_move_aILb0EPSt4pairIiiES2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt13__copy_move_aILb0EPSt4pairIiiES2_ET1_T0_S4_S3_:
LFB1505:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movb	$0, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPSt4pairIiiES5_EET0_T_S7_S6_
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1505:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyIPSt4pairIiiES4_EET0_T_S6_S5_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIPSt4pairIiiES4_EET0_T_S6_S5_
	.def	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIPSt4pairIiiES4_EET0_T_S6_S5_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIPSt4pairIiiES4_EET0_T_S6_S5_:
LFB1506:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L367
L368:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofISt4pairIiiEEPT_RS2_
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt10_ConstructISt4pairIiiES1_EvPT_RKT0_
	addl	$8, 8(%ebp)
	addl	$8, -12(%ebp)
L367:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	setne	%al
	testb	%al, %al
	jne	L368
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1506:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP11InstructionS3_EET0_T_S5_S4_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP11InstructionS3_EET0_T_S5_S4_
	.def	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP11InstructionS3_EET0_T_S5_S4_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP11InstructionS3_EET0_T_S5_S4_:
LFB1507:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1507
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L371
L372:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofI11InstructionEPT_RS1_
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB65:
	call	__ZSt10_ConstructI11InstructionS0_EvPT_RKT0_
LEHE65:
	addl	$20, 8(%ebp)
	addl	$20, -12(%ebp)
L371:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	setne	%al
	testb	%al, %al
	jne	L372
	movl	-12(%ebp), %eax
	jmp	L378
L377:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB66:
	call	__Unwind_Resume
LEHE66:
L376:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
LEHB67:
	call	__ZSt8_DestroyIP11InstructionEvT_S2_
	call	___cxa_rethrow
LEHE67:
L378:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1507:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1507:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1507-LLSDATTD1507
LLSDATTD1507:
	.byte	0x1
	.uleb128 LLSDACSE1507-LLSDACSB1507
LLSDACSB1507:
	.uleb128 LEHB65-LFB1507
	.uleb128 LEHE65-LEHB65
	.uleb128 L376-LFB1507
	.uleb128 0x1
	.uleb128 LEHB66-LFB1507
	.uleb128 LEHE66-LEHB66
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB67-LFB1507
	.uleb128 LEHE67-LEHB67
	.uleb128 L377-LFB1507
	.uleb128 0
LLSDACSE1507:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1507:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP11InstructionS3_EET0_T_S5_S4_,"x"
	.linkonce discard
	.section	.text$_ZSt11__addressofI11InstructionEPT_RS1_,"x"
	.linkonce discard
	.globl	__ZSt11__addressofI11InstructionEPT_RS1_
	.def	__ZSt11__addressofI11InstructionEPT_RS1_;	.scl	2;	.type	32;	.endef
__ZSt11__addressofI11InstructionEPT_RS1_:
LFB1508:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1508:
	.section	.text$_ZSt8_DestroyI11InstructionEvPT_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyI11InstructionEvPT_
	.def	__ZSt8_DestroyI11InstructionEvPT_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyI11InstructionEvPT_:
LFB1509:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZN11InstructionD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1509:
	.section	.text$_ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP4WireS4_EET0_T_S6_S5_,"x"
	.linkonce discard
	.globl	__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP4WireS4_EET0_T_S6_S5_
	.def	__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP4WireS4_EET0_T_S6_S5_;	.scl	2;	.type	32;	.endef
__ZNSt20__copy_move_backwardILb0ELb0ESt26random_access_iterator_tagE13__copy_move_bIP4WireS4_EET0_T_S6_S5_:
LFB1510:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$4, %eax
	movl	%eax, -12(%ebp)
	jmp	L383
L384:
	subl	$16, 12(%ebp)
	subl	$16, 16(%ebp)
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN4WireaSERKS_
	subl	$4, %esp
	decl	-12(%ebp)
L383:
	cmpl	$0, -12(%ebp)
	setg	%al
	testb	%al, %al
	jne	L384
	movl	16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1510:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP4WireS3_EET0_T_S5_S4_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP4WireS3_EET0_T_S5_S4_
	.def	__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP4WireS3_EET0_T_S5_S4_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP4WireS3_EET0_T_S5_S4_:
LFB1511:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1511
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
	jmp	L387
L388:
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt11__addressofI4WireEPT_RS1_
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
LEHB68:
	call	__ZSt10_ConstructI4WireS0_EvPT_RKT0_
LEHE68:
	addl	$16, 8(%ebp)
	addl	$16, -12(%ebp)
L387:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	setne	%al
	testb	%al, %al
	jne	L388
	movl	-12(%ebp), %eax
	jmp	L394
L393:
	movl	%eax, %ebx
	call	___cxa_end_catch
	movl	%ebx, %eax
	movl	%eax, (%esp)
LEHB69:
	call	__Unwind_Resume
LEHE69:
L392:
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
LEHB70:
	call	__ZSt8_DestroyIP4WireEvT_S2_
	call	___cxa_rethrow
LEHE70:
L394:
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1511:
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1511:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1511-LLSDATTD1511
LLSDATTD1511:
	.byte	0x1
	.uleb128 LLSDACSE1511-LLSDACSB1511
LLSDACSB1511:
	.uleb128 LEHB68-LFB1511
	.uleb128 LEHE68-LEHB68
	.uleb128 L392-LFB1511
	.uleb128 0x1
	.uleb128 LEHB69-LFB1511
	.uleb128 LEHE69-LEHB69
	.uleb128 0
	.uleb128 0
	.uleb128 LEHB70-LFB1511
	.uleb128 LEHE70-LEHB70
	.uleb128 L393-LFB1511
	.uleb128 0
LLSDACSE1511:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1511:
	.section	.text$_ZNSt20__uninitialized_copyILb0EE13__uninit_copyIP4WireS3_EET0_T_S5_S4_,"x"
	.linkonce discard
	.section	.text$_ZSt11__addressofI4WireEPT_RS1_,"x"
	.linkonce discard
	.globl	__ZSt11__addressofI4WireEPT_RS1_
	.def	__ZSt11__addressofI4WireEPT_RS1_;	.scl	2;	.type	32;	.endef
__ZSt11__addressofI4WireEPT_RS1_:
LFB1512:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1512:
	.section	.text$_ZSt8_DestroyI4WireEvPT_,"x"
	.linkonce discard
	.globl	__ZSt8_DestroyI4WireEvPT_
	.def	__ZSt8_DestroyI4WireEvPT_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyI4WireEvPT_:
LFB1513:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %ecx
	call	__ZN4WireD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1513:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISt4pairIiiEEC2ERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEEC2ERKS3_
	.def	__ZN9__gnu_cxx13new_allocatorISt4pairIiiEEC2ERKS3_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISt4pairIiiEEC2ERKS3_:
LFB1515:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	$4
	.cfi_endproc
LFE1515:
	.section	.text$_ZN9__gnu_cxxneIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxxneIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_
	.def	__ZN9__gnu_cxxneIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxneIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEEbRKNS_17__normal_iteratorIT_T0_EESD_:
LFB1517:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	movl	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %ebx
	movl	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	cmpl	%eax, %ebx
	setne	%al
	addl	$4, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1517:
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEppEv
	.def	__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEppEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEppEv:
LFB1518:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leal	8(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1518:
	.section	.text$_ZSt11__addressofISt4pairIiiEEPT_RS2_,"x"
	.linkonce discard
	.globl	__ZSt11__addressofISt4pairIiiEEPT_RS2_
	.def	__ZSt11__addressofISt4pairIiiEEPT_RS2_;	.scl	2;	.type	32;	.endef
__ZSt11__addressofISt4pairIiiEEPT_RS2_:
LFB1519:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1519:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEdeEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEdeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEEdeEv:
LFB1520:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1520:
	.section	.text$_ZSt10_ConstructISt4pairIiiES1_EvPT_RKT0_,"x"
	.linkonce discard
	.globl	__ZSt10_ConstructISt4pairIiiES1_EvPT_RKT0_
	.def	__ZSt10_ConstructISt4pairIiiES1_EvPT_RKT0_;	.scl	2;	.type	32;	.endef
__ZSt10_ConstructISt4pairIiiES1_EvPT_RKT0_:
LFB1521:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$8, (%esp)
	call	__ZnwjPv
	movl	%eax, %ecx
	testl	%ecx, %ecx
	je	L407
	movl	12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
L407:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1521:
	.section	.text$_ZNK9__gnu_cxx13new_allocatorISt4pairIiiEE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorISt4pairIiiEE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorISt4pairIiiEE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorISt4pairIiiEE8max_sizeEv:
LFB1522:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$536870911, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1522:
	.section	.text$_ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES9_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES9_
	.def	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES9_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES9_:
LFB1523:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1523:
	.section	.text$_ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES8_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES8_
	.def	__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES8_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseIN9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS3_SaIS3_EEEELb1EE7_S_baseES8_:
LFB1524:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	leal	8(%ebp), %ecx
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv
	movl	(%eax), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1524:
	.section	.text$_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKSt4pairIiiEPS4_EET0_T_S9_S8_,"x"
	.linkonce discard
	.globl	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKSt4pairIiiEPS4_EET0_T_S9_S8_
	.def	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKSt4pairIiiEPS4_EET0_T_S9_S8_;	.scl	2;	.type	32;	.endef
__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPKSt4pairIiiEPS4_EET0_T_S9_S8_:
LFB1525:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$3, %eax
	movl	%eax, -4(%ebp)
	jmp	L417
L418:
	movl	16(%ebp), %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	addl	$8, 8(%ebp)
	addl	$8, 16(%ebp)
	decl	-4(%ebp)
L417:
	cmpl	$0, -4(%ebp)
	setg	%al
	testb	%al, %al
	jne	L418
	movl	16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1525:
	.section	.text$_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPSt4pairIiiES5_EET0_T_S7_S6_,"x"
	.linkonce discard
	.globl	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPSt4pairIiiES5_EET0_T_S7_S6_
	.def	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPSt4pairIiiES5_EET0_T_S7_S6_;	.scl	2;	.type	32;	.endef
__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mIPSt4pairIiiES5_EET0_T_S7_S6_:
LFB1526:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$3, %eax
	movl	%eax, -4(%ebp)
	jmp	L421
L422:
	movl	16(%ebp), %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	addl	$8, 8(%ebp)
	addl	$8, 16(%ebp)
	decl	-4(%ebp)
L421:
	cmpl	$0, -4(%ebp)
	setg	%al
	testb	%al, %al
	jne	L422
	movl	16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1526:
	.section	.text$_ZSt10_ConstructI11InstructionS0_EvPT_RKT0_,"x"
	.linkonce discard
	.globl	__ZSt10_ConstructI11InstructionS0_EvPT_RKT0_
	.def	__ZSt10_ConstructI11InstructionS0_EvPT_RKT0_;	.scl	2;	.type	32;	.endef
__ZSt10_ConstructI11InstructionS0_EvPT_RKT0_:
LFB1527:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1527
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$20, (%esp)
	call	__ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L424
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
LEHB71:
	call	__ZN11InstructionC1ERKS_
LEHE71:
	subl	$4, %esp
	jmp	L424
L428:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB72:
	call	__Unwind_Resume
LEHE72:
L424:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1527:
	.section	.gcc_except_table,"w"
LLSDA1527:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1527-LLSDACSB1527
LLSDACSB1527:
	.uleb128 LEHB71-LFB1527
	.uleb128 LEHE71-LEHB71
	.uleb128 L428-LFB1527
	.uleb128 0
	.uleb128 LEHB72-LFB1527
	.uleb128 LEHE72-LEHB72
	.uleb128 0
	.uleb128 0
LLSDACSE1527:
	.section	.text$_ZSt10_ConstructI11InstructionS0_EvPT_RKT0_,"x"
	.linkonce discard
	.section	.text$_ZSt10_ConstructI4WireS0_EvPT_RKT0_,"x"
	.linkonce discard
	.globl	__ZSt10_ConstructI4WireS0_EvPT_RKT0_
	.def	__ZSt10_ConstructI4WireS0_EvPT_RKT0_;	.scl	2;	.type	32;	.endef
__ZSt10_ConstructI4WireS0_EvPT_RKT0_:
LFB1528:
	.cfi_startproc
	.cfi_personality 0,___gxx_personality_v0
	.cfi_lsda 0,LLSDA1528
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$28, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	8(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	$16, (%esp)
	call	__ZnwjPv
	movl	%eax, %ebx
	testl	%ebx, %ebx
	je	L429
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%ebx, %ecx
LEHB73:
	call	__ZN4WireC1ERKS_
LEHE73:
	subl	$4, %esp
	jmp	L429
L433:
	movl	%eax, %edi
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	call	__ZdlPvS_
	movl	%edi, %eax
	movl	%eax, (%esp)
LEHB74:
	call	__Unwind_Resume
LEHE74:
L429:
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1528:
	.section	.gcc_except_table,"w"
LLSDA1528:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1528-LLSDACSB1528
LLSDACSB1528:
	.uleb128 LEHB73-LFB1528
	.uleb128 LEHE73-LEHB73
	.uleb128 L433-LFB1528
	.uleb128 0
	.uleb128 LEHB74-LFB1528
	.uleb128 LEHE74-LEHB74
	.uleb128 0
	.uleb128 0
LLSDACSE1528:
	.section	.text$_ZSt10_ConstructI4WireS0_EvPT_RKT0_,"x"
	.linkonce discard
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPKSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv:
LFB1529:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1529:
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPSt4pairIiiESt6vectorIS2_SaIS2_EEE4baseEv:
LFB1530:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1530:
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1532:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1532:
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
LFB1531:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L439
	cmpl	$65535, 12(%ebp)
	jne	L439
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L439:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1531:
	.def	__GLOBAL__sub_I__ZN2Ir22output_instruction_setERSt14basic_ofstreamIcSt11char_traitsIcEE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZN2Ir22output_instruction_setERSt14basic_ofstreamIcSt11char_traitsIcEE:
LFB1533:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1533:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZN2Ir22output_instruction_setERSt14basic_ofstreamIcSt11char_traitsIcEE
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZN11Instruction10get_binaryEv;	.scl	2;	.type	32;	.endef
	.def	__ZN11Instruction8get_codeEv;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZN11Instruction7get_offEi;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	__ZN11Instruction12get_off_sizeEv;	.scl	2;	.type	32;	.endef
	.def	__ZN4Wire9get_widthEv;	.scl	2;	.type	32;	.endef
	.def	__ZN4Wire8get_nameEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsaSERKSs;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
