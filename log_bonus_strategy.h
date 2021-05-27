#ifndef LOG_BONUS_STRATEGY_H_
#define LOG_BONUS_STRATEGY_H_

#include "log_strategy_interface.h"
#include "player.h"
#include <chrono>
#include <string>

class LogBonusStrategy : public LogStrategyInterface {
  public:
    LogBonusStrategy() = default;

    LogBonusStrategy(const Player &player, time_t time,
                     std::chrono::duration<double> diff, int point)
        : log_("Bonus point: " + player.name() + " " + ctime(&time) + " " +
               std::to_string(diff.count()) + " " + std::to_string(point)) {}

    std::string GetLog() const { return log_; }

    inline bool IsLog() const { return can_log_; }

  private:
    std::string log_;
    static constexpr bool can_log_ = true;
};

#endif // LOG_BONUS_STRATEGY_H_
