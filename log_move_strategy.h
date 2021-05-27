#ifndef LOG_MOVE_STRATEGY_H_
#define LOG_MOVE_STRATEGY_H_

#include "direction.h"
#include "log_strategy_interface.h"
#include "player.h"
#include <chrono>
#include <string>

class LogMoveStrategy : public LogStrategyInterface {
  public:
    LogMoveStrategy() = default;

    LogMoveStrategy(const Player &player, time_t time, Direction dir, int point)
        : log_("Move point: " + player.name() + " " + ctime(&time) + " " +
               direction_to_string[dir] + " " + std::to_string(point)),
          can_log_(point > 0) {}

    inline std::string GetLog() const { return log_; }

    inline bool IsLog() const { return can_log_; }

  private:
    std::string log_;
    bool can_log_;
};

#endif // LOG_MOVE_STRATEGY_H_
