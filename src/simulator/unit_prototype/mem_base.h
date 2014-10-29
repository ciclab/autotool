#ifndef _MEM_BASE_H_
#define _MEM_BASE_H_

#include <functional>
#incldue <string>

class MemoryBase
{
 public:
  const static std::string mName = "MemoryBase";
  const static uint mSize = 0;

  // called before ReadMemory
  // return 0 if ok, else ReadMemory won't be called
  virtual int BeforeRead(std::function func);
  virtual int AfterRead(std::function func);

  // called before WriteMemory is called
  // return 0 if ok, else WriteMemory won't be called
  virtual int BeforeWrite(std::function func);
  virtual int AfterWrite(std::function func);

 private:
  // return true if placeHoder is valid address in offset
  int CheckAddressValidity(uint offset, uint size);

  // read value from memory
  int ReadMemory(uint offset, uint size, vector<char>& value);

  // write value from memory
  int WriteMemory(uint offset, uint size, const vector<char>& value);

  // Initialize memory default to set memory zero 
  virtual int Init();
};

#endif
