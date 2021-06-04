#ifndef LOG_INTERFACE_H_
#define LOG_INTERFACE_H_

#include <string>

class LogInterface {
  public:
    virtual void Println(const std::string &s) = 0;
};

#endif // LOG_INTERFACE_H_
