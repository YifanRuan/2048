#ifndef LOG_H_
#define LOG_H_

#include "direction.h"
#include "player.h"
#include <chrono>
#include <cstdio>

class Log {
  public:
    Log() = default;

    Log(bool is_log);

    ~Log();

    void PrintMove(const Player &player, time_t time, Direction dir, int point);

    void PrintBonus(const Player &player, time_t time,
                    std::chrono::duration<double> diff, int point);

  private:
    bool is_log_;
    FILE *fp_ = nullptr;
};

#endif // LOG_H_
