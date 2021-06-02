#ifndef LOG_STRATEGY_INTERFACE_H_
#define LOG_STRATEGY_INTERFACE_H_

#include <string>

class LogStrategyInterface {
  public:
    virtual bool IsLog() const = 0;
    virtual std::string GetLog() const = 0;
};

#endif // LOG_STRATEGY_INTERFACE_H_
