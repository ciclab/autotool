#ifndef _REGISTER_BASE_H_
#define _REGISTER_BASE_H_

#include <string>

template<typename TRegister>
class RegisterBase
{
 public:
  const static std::string mName;
  const uint mWidth;
  const uint mSize;
  // called before Read is called. If return false, Read won't be called
  virutal bool BeforeRead();
  // called after Read is called.
  virtual bool AfterRead();
  // If reutrn false, Write won't be called
  virtual bool BeforeWrite();
  // called after Write
  virtual bool AfterWrite();
 protect:
  bool Read(uint offset, TRegister& value);
  bool Write(uint offset, const TRegister& value);
};
#endif
