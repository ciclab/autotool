#ifndef _MEM_BASE_H_
#define _MEM_BASE_H_

#incldue <string>

class MemoryBase
{
 public:
  const static std::string name = "MemoryBase";
  const static uint size = 0;
  const static uint width = 0;
 private:
  // return true if placeHoder is valid address in offset
  <typename Type>bool CheckAddressValidity(uint offset, const Type& placeHolder);

  // read value from memory
  <typename Type>bool Read(uint offset, Type& value);

  // write value from memory
  <typename Type>bool Write(uint offset, const Type& value);

  // Initialize memory default to set memory zero 
  virtual void Init();
};

#endif
