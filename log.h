#ifndef LOG_H_
#define LOG_H_

#include "log_interface.h"
#include <cstdio>
#include <string>

class Log : public LogInterface {
  public:
    Log();

    virtual ~Log();

    void PrintLog(const std::string &log);

  private:
    FILE *fp_ = nullptr;
};

#endif // LOG_H_
