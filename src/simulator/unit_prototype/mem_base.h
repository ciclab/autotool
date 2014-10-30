#ifndef _MEM_BASE_H_
#define _MEM_BASE_H_

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

class MemoryBase
{
 public:
  const static std::string cName;
  const static uint cSize;

  // called before ReadMemory
  // return 0 if ok, else ReadMemory won't be called
  virtual bool BeforeRead();
  virtual bool AfterRead();

  // called before WriteMemory is called
  // return 0 if ok, else WriteMemory won't be called
  virtual bool BeforeWrite();
  virtual bool AfterWrite();

  // read value from memory, return true if success
  bool Read(uint offset, uint size,
	    std::vector<char>& value);

  // write value from memory, return true if success
  bool Write(uint offset, uint size,
	     const std::vector<char>& value);

  // Initialize memory default to set memory zero 
  virtual bool Init();

 private:
  // return true if placeHoder is valid address in offset
  bool CheckAddressValidity(uint offset, uint size);

  // memory data
  std::vector<char> mContent;
};

#endif
