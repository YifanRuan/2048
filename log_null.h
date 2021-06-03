#ifndef LOG_NULL_H_
#define LOG_NULL_H_

#include "log_interface.h"

class LogNull : public LogInterface {
  public:
    void PrintLog(const std::string &log) {}
};

#endif // LOG_NULL_H_
