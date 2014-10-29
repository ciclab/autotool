#ifndef _STAGE_BASE_H
#define _STAGE_BASE_H

class Stage
{
 public:
  string mName;
  virtual <typename TStage> TStage template NextStage(TStage);
};

#endif
