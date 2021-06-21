#include "bonus.h"

using namespace std;
using namespace std::chrono;

Bonus::Bonus(Game *g) : g_(g) { g_->AddObserver(this); }

Bonus::~Bonus() { g_->RemoveObserver(this); }

void Bonus::PointIncremented(int inc, Direction dir) {
    cur_time_ = g_->move_time();
    if (is_moved_) {
        duration<double> diff = cur_time_ - last_time_;
        if (diff.count() < diff_time_) {
            printf("fuckyou\n");
            g_->GetCurPlayer()->AddPoint(bonus_point_);
            for (auto it : observers_) {
                it->BonusPointIncremented(bonus_point_, *(g_->GetCurPlayer()));
            }
        }
    } else {
        is_moved_ = true;
    }
    last_time_ = cur_time_;
}
