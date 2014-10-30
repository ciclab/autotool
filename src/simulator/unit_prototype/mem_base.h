#ifndef _MEM_BASE_H_
#define _MEM_BASE_H_

#include <functional>
#include <string>
#include <vector>

class MemoryBase
{
 public:
  const static uint mSize = 0;

  // called before ReadMemory
  // return 0 if ok, else ReadMemory won't be called
  virtual bool BeforeRead();
  virtual bool AfterRead();

  // called before WriteMemory is called
  // return 0 if ok, else WriteMemory won't be called
  virtual int BeforeWrite();
  virtual int AfterWrite();

 private:
  // return true if placeHoder is valid address in offset
  int CheckAddressValidity(uint offset, uint size);

  // read value from memory
  int ReadMemory(uint offset, uint size, std::vector<char>& value);

  // write value from memory
  int WriteMemory(uint offset, uint size, const std::vector<char>& value);

  // Initialize memory default to set memory zero 
  virtual int Init();
};

#endif
