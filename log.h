#ifndef LOG_H_
#define LOG_H_

#include "direction.h"
#include "player.h"
#include <chrono>

class Log {
  public:
    Log() = default;

    Log(bool is_log);

    ~Log();

    void PrintMove();

    void PrintBonus();

  private:
    bool is_log_;
    FILE *fp = nullptr;
};

#endif // LOG_H_
