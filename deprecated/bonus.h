#ifndef BONUS_H_
#define BONUS_H_

#include "log.h"
#include "player.h"
#include <chrono>

class Bonus {
  public:
    Bonus() = default;

    Bonus(bool is_bonus) : is_bonus_(is_bonus) {}

    int
    GetBonusPoint(const Player &player, const Log &log,
                  std::chrono::time_point<std::chrono::system_clock> last_time,
                  std::chrono::time_point<std::chrono::system_clock> cur_time);

  private:
    bool is_bonus_;
    static constexpr int bonus_point_ = 1;
};

#endif // BONUS_H_
