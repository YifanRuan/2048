#include "log_bonus.h"
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace std::chrono;

LogBonus::LogBonus(Bonus *b, LogInterface *l) : b_(b), log_(l) {
    b_->AddObserver(this);
}

LogBonus::~LogBonus() { b_->RemoveObserver(this); }

void LogBonus::BonusPointIncremented(int inc, const Player &player) {
    auto cur_time = system_clock::to_time_t(b_->cur_time());
    string s = static_cast<string>(ctime(&cur_time));
    duration<double> diff = b_->cur_time() - b_->last_time();
    stringstream ss;
    ss << "Bonus point: " << player.name() << " " << s.substr(0, s.length() - 2)
       << " " << std::setprecision(1) << diff.count() << " " << inc;
    log_->PrintLog(ss.str());
}
