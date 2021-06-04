#ifndef LOG_H_
#define LOG_H_

#include "log_interface.h"
#include <fstream>
#include <string>

class Log : public LogInterface {
  public:
    Log();

    virtual ~Log();

    void Println(const std::string &log);

  private:
    std::ofstream fp_;
};

#endif // LOG_H_
