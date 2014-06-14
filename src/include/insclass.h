class _class_instr_
{
public:;
  int stageNum = ir.get_num_stage();
  for( int i = 0; i < stageNum; ++i )
    {
      string stageName = ir.get_stage_name(i);
      out << "int " << stageName << "_active\n;";
    }
    out <<"virtual void inti (char *c);		\
  virtual void Do ();\
};\n" ;

