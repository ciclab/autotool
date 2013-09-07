void alu_opn_func_do()
{
  if((stage.E1))
    {
    }
}
void alu_left_opd_func_do()
{
}
void alu_right_opd_func_do()
{
}
void alu_instr_func_do()
{
  if((stage.E1))
    {
    }
}
void as_opn_func_do()
{
  if(stage.E1)
    {
    }
}
void sh_opn_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()sh_opn_AR)();
      (*(void (*))()sh_opn_S)();
      sh_opn_AR.tmp=sh_opn_S.val;
      sh_opn_S.tmp=.val;
    }
}
void as_sh_instr_func_do()
{
  if((stage.E1))
    {
    }
}
void shift_instr_func_do()
{
  if((stage.E1))
    {
      (*(void (*))()shift_instr_A)();
      (*(void (*))()shift_instr_al)();
      shift_instr_A.tmp=shift_instr_al.val;
      (*(void (*))()shift_instr_C)();
      shift_instr_C.tmp=.val;
      (*(void (*))()shift_instr_alu)();
      (*(void (*))()shift_instr_true)();
      shift_instr_alu.tmp=shift_instr_true.val;
      (*(void (*))()shift_instr_AR)();
      (*(void (*))()shift_instr_S)();
      shift_instr_AR.tmp=shift_instr_S.val;
      shift_instr_S.tmp=.val;
      (*(void (*))()shift_instr_sh)();
      (*(void (*))()shift_instr_true)();
      shift_instr_sh.tmp=shift_instr_true.val;
    }
}
void mult_left_opd_func_do()
{
}
void mult_right_opd_func_do()
{
}
void macc_instr_func_do()
{
  if(stage.E1)
    {
    }
  if(stage.E2)
    {
    }
}
void rnd_instr_func_do()
{
  if(stage.E2)
    {
    }
}
void arith_nop_func_do()
{
  if((stage.E1))
    {
    }
}
void macc_rnd_nop_instr_func_do()
{
  (*(void (*))()macc_rnd_nop_instr_subinstr)();
}
void arith_instr_func_do()
{
  (*(void (*))()arith_instr_subinstr)();
}
void ind_mem_acc1_func_do()
{
  if(stage.E1)
    {
    }
  if(stage.E2)
    {
    }
}
void ind_mem_acc2_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()ind_mem_acc2_acu2)();
      (*(void (*))()ind_mem_acc2_true)();
      ind_mem_acc2_acu2.tmp=ind_mem_acc2_true.val;
    }
}
void ind_mem_acc_func_do()
{
  (*(void (*))()ind_mem_acc_subinstr)();
}
void reg_sel_func_do()
{
}
void load_ind_instr_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()load_ind_instr_r)();
      (*(void (*))()load_ind_instr_XD)();
      (*(void (*))()load_ind_instr_m)();
      load_ind_instr_r.tmp=load_ind_instr_XD.val;
      load_ind_instr_XD.tmp=load_ind_instr_m.val;
    }
}
void store_ind_instr_func_do()
{
  if((or) || (stage.E1) || (stage.E2))
    {
      (*(void (*))()store_ind_instr_m)();
      (*(void (*))()store_ind_instr_XD)();
      (*(void (*))()store_ind_instr_r)();
      store_ind_instr_m.tmp=store_ind_instr_XD.val;
      store_ind_instr_XD.tmp=store_ind_instr_r.val;
    }
}
void ind_mem_acc_dbl1_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()ind_mem_acc_dbl1_idx1)();
      ind_mem_acc_dbl1_idx1.tmp=.val;
    }
  if(stage.E2)
    {
    }
}
void ind_mem_acc_dbl2_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()ind_mem_acc_dbl2_idx2)();
      ind_mem_acc_dbl2_idx2.tmp=.val;
    }
  if((stage.E2))
    {
    }
}
void dbl_reg_sel_func_do()
{
}
void load_load_ind_instr_func_do()
{
  if((or) || (stage.E1) || (stage.E2))
    {
    }
}
void store_load_ind_instr_func_do()
{
  if((or) || (stage.E1) || (stage.E2))
    {
      (*(void (*))()store_load_ind_instr_m1)();
      (*(void (*))()store_load_ind_instr_XD)();
      (*(void (*))()store_load_ind_instr_r1)();
      store_load_ind_instr_m1.tmp=store_load_ind_instr_XD.val;
      store_load_ind_instr_XD.tmp=store_load_ind_instr_r1.val;
      (*(void (*))()store_load_ind_instr_r2)();
      (*(void (*))()store_load_ind_instr_YD)();
      (*(void (*))()store_load_ind_instr_m2)();
      store_load_ind_instr_r2.tmp=store_load_ind_instr_YD.val;
      store_load_ind_instr_YD.tmp=store_load_ind_instr_m2.val;
    }
}
void move_nop_func_do()
{
  if(stage.E1)
    {
    }
}
void mem_ind_instr_func_do()
{
  (*(void (*))()mem_ind_instr_subinstr)();
}
void arith_mem_ind_instr_func_do()
{
  (*(void (*))()arith_mem_ind_instr_ar)();
  (*(void (*))()arith_mem_ind_instr_mi)();
}
void load_direct_func_do()
{
  if((or) || (stage.E2) || (stage.E1))
    {
      (*(void (*))()load_direct_r)();
      (*(void (*))()load_direct_XD)();
      load_direct_r.tmp=load_direct_XD.val;
      load_direct_XD.tmp=.val;
    }
}
void store_direct_func_do()
{
  if((or) || (stage.E2) || (stage.E1))
    {
      (*(void (*))()store_direct_XD)();
      (*(void (*))()store_direct_r)();
      .tmp=store_direct_XD.val;
      store_direct_XD.tmp=store_direct_r.val;
    }
}
void mem_dir_instr_func_do()
{
  (*(void (*))()mem_dir_instr_subinstr)();
}
void sp_idx_imm_acc_func_do()
{
  if(stage.E1)
    {
    }
}
void mem_sp_idx_imm_instr_func_do()
{
  if((stage.E2))
    {
      (*(void (*))()mem_sp_idx_imm_instr_r)();
      (*(void (*))()mem_sp_idx_imm_instr_XD)();
      (*(void (*))()mem_sp_idx_imm_instr_m)();
      mem_sp_idx_imm_instr_r.tmp=mem_sp_idx_imm_instr_XD.val;
      mem_sp_idx_imm_instr_XD.tmp=mem_sp_idx_imm_instr_m.val;
    }
}
void Iam_func_do()
{
}
void Ibm_func_do()
{
}
void Mam_func_do()
{
}
void Mbm_func_do()
{
}
void acu_regs_func_do()
{
  (*(void (*))()acu_regs_subinstr)();
}
void imm_load_addr_instr_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()imm_load_addr_instr_r)();
      (*(void (*))()imm_load_addr_instr_imm_a)();
      (*(void (*))()imm_load_addr_instr_c)();
      imm_load_addr_instr_r.tmp=imm_load_addr_instr_imm_a.val;
      imm_load_addr_instr_imm_a.tmp=imm_load_addr_instr_c.val;
    }
}
void imm_load8se_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()imm_load8se_r.value)();
      (*(void (*))()imm_load8se_imm_w)();
      (*(void (*))()imm_load8se_imm_c)();
      (*(void (*))()imm_load8se_c)();
      imm_load8se_r.value.tmp=imm_load8se_imm_w.val;
      imm_load8se_imm_w.tmp=imm_load8se_imm_c.val;
      imm_load8se_imm_c.tmp=imm_load8se_c.val;
    }
}
void imm_load8hi_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()imm_load8hi_imm)();
      (*(void (*))()imm_load8hi_true)();
      imm_load8hi_imm.tmp=imm_load8hi_true.val;
      (*(void (*))()imm_load8hi_r)();
      (*(void (*))()imm_load8hi_imm_w)();
      imm_load8hi_r.tmp=imm_load8hi_imm_w.val;
      imm_load8hi_imm_w.tmp=.val;
    }
}
void imm_load_data_instr_func_do()
{
  (*(void (*))()imm_load_data_instr_subinstr)();
}
void sp_mod_instr_func_do()
{
  (*(void (*))()sp_mod_instr_SP)();
  (*(void (*))()sp_mod_instr_upd1)();
  sp_mod_instr_SP.tmp=sp_mod_instr_upd1.val;
  sp_mod_instr_upd1.tmp=.val;
  (*(void (*))()sp_mod_instr_acu1)();
  (*(void (*))()sp_mod_instr_true)();
  sp_mod_instr_acu1.tmp=sp_mod_instr_true.val;
}
void ptr_init_sp_instr_func_do()
{
  if(stage.E1)
    {
    }
}
void regs_func_do()
{
  (*(void (*))()regs_subinstr)();
}
void rmove_instr_func_do()
{
  if(stages.E1)
    {
      (*(void (*))()rmove_instr_rd)();
      (*(void (*))()rmove_instr_XD)();
      (*(void (*))()rmove_instr_rs)();
      rmove_instr_rd.tmp=rmove_instr_XD.val;
      rmove_instr_XD.tmp=rmove_instr_rs.val;
    }
}
void doloop_instr_func_do()
{
  if(stage.E1)
    {
    }
}
void dir_abs_cond_branch_func_do()
{
  if(stage.E1)
    {
      (*(void (*))()dir_abs_cond_branch_tT)();
      (*(void (*))()dir_abs_cond_branch_t)();
      dir_abs_cond_branch_tT.tmp=dir_abs_cond_branch_t.val;
    }
}
void dir_abs_uncond_branch_func_do()
{
  if(stage.E1)
    {
    }
}
void branch_instr_func_do()
{
  (*(void (*))()branch_instr_subinstr)();
}
void jsr_instr_func_do()
{
  if(stage.E1)
    {
    }
}
void return_instr_func_do()
{
  if(stage.E1)
    {
    }
}
void tctcore_func_do()
{
  (*(void (*))()tctcore_subinstr)();
}
