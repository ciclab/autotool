#ifndef _REGISTER_BASE_H_
#define _REGISTER_BASE_H_

#include <vector>
#include <string>
#include <functional>

class RegisterBase
{
 public:
  static const std::string cName;
  static const uint cWidth;
  static const uint cSize;

  RegisterBase();
  ~RegisterBase();

  virtual bool Init();

  // called before Read is called. If return false,
  // Read won't be called
  virtual bool BeforeRead();

  // called after Read is called.
  virtual bool AfterRead();

  // If reutrn false, Write won't be called
  virtual bool BeforeWrite();

  // called after Write
  virtual bool AfterWrite();

  // read a register into value, value will be resized to cWidth
  bool Read(uint offset, std::vector<char>& value);

  // write a register
  bool Write(uint offset, const std::vector<char>& value);
 private:
  std::vector<char> mContent;

  bool CheckAddressValidity(uint offset);
 private:
  RegisterBase(const RegisterBase& RegisterBase);
  RegisterBase(RegisterBase& RegisterBase);
  RegisterBase& operator=(const RegisterBase& RegisterBase);
  RegisterBase& operator=(const RegisterBase&& RegisterBase);
};

#endif
