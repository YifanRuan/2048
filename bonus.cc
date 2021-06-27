#include "bonus.h"
#include <iomanip>
#include <sstream>

using namespace std;
using namespace std::chrono;

Bonus::Bonus(Game *g) : g_(g) { g_->AddObserver(this); }

Bonus::~Bonus() { g_->RemoveObserver(this); }

void Bonus::PointIncremented(int inc, Direction dir) {
    cur_time_ = g_->move_time();
    if (is_moved_) {
        duration<double> diff = cur_time_ - last_time_;
        if (diff.count() < diff_time_) {
            g_->GetCurPlayer()->SetCurPoint(g_->GetCurPlayer()->point() +
                                            bonus_point_);
            g_->ActionPerformed(BonusInfo(bonus_point_));
        }
    } else {
        is_moved_ = true;
    }
    last_time_ = cur_time_;
}

string Bonus::BonusInfo(int inc) {
    auto cur_time = system_clock::to_time_t(cur_time_);
    string s = static_cast<string>(ctime(&cur_time));
    duration<double> diff = cur_time_ - last_time_;
    stringstream ss;
    ss << "Bonus point: " << g_->GetCurPlayer()->name() << " "
       << s.substr(0, s.length() - 1) << " " << std::setprecision(1)
       << diff.count() << " " << inc;
    return ss.str();
}
