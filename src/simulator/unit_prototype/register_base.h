#ifndef _REGISTER_BASE_H_
#define _REGISTER_BASE_H_

#include <vector>
#include <string>
#include <functional>

class RegisterBase
{
 public:
  const static std::string mName;
  const uint mWidth;
  const uint mSize;
  // called before Read is called. If return false, Read won't be called
  bool BeforeRead();
  // called after Read is called.
  bool AfterRead();
  // If reutrn false, Write won't be called
  bool BeforeWrite();
  // called after Write
  bool AfterWrite();
  // read a register
  bool Read(uint offset, std::vector<char>& value);
  // write a register
  bool Write(uint offset, const std::vector<char>& value);
};
#endif
