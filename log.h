#ifndef LOG_H_
#define LOG_H_

#include "direction.h"
#include "log_strategy_interface.h"
#include "player.h"
#include <chrono>
#include <cstdio>

class Log {
  public:
    Log() = default;

    Log(bool is_log);

    ~Log();

    void PrintLog(const LogStrategyInterface &log) const;

  private:
    bool is_log_ = false;
    FILE *fp_ = nullptr;
};

#endif // LOG_H_
