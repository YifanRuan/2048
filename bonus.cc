#include "bonus.h"
#include "log_bonus_strategy.h"

using namespace std::chrono;

int Bonus::GetBonusPoint(const Player &player, const Log &log,
                         time_point<system_clock> last_time,
                         time_point<system_clock> cur_time) {
    if (!is_bonus_)
        return 0;
    duration<double> diff = cur_time - last_time;
    if (diff.count() >= 1.0)
        return 0;
    log.PrintLog(LogBonusStrategy{player, system_clock::to_time_t(cur_time),
                                  diff, bonus_point_});
    return bonus_point_;
}
