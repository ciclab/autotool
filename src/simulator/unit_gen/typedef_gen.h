#ifndef _TYPEDEF_GEN_H_
#define _TYPEDEF_GEN_H_

#include <string>
#include <unordered_set>

#include "type_gen.h"

class TypeDefGen
{
 private:
  // record all existing typedef
  static std::unordered_set<std::string> mTypeDefSet;
  
 public:
  // Initialize internal type define record
  void Init();

  // generte type define C++ code given width and signed or not info
  // will not add entry to intenal record
  static std::string GenTypeDefCStr(int width, bool sig);

  // add enrty to interanl record
  static void AddTypeDef(int width, bool sig);

  // return all internal type define record
  static std::string TypeDefDump();
};

#endif
