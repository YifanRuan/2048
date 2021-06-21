#include "log_game.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

LogGame::LogGame(Game *g, LogInterface *log) : g_(g), log_(log) {
    g_->AddObserver(this);
}

LogGame::~LogGame() { g_->RemoveObserver(this); }

void LogGame::PointIncremented(int inc, Direction dir) {
    if (inc <= 0)
        return;
    time_t cur_time = system_clock::to_time_t(g_->move_time());
    string s = static_cast<string>(ctime(&cur_time));
    log_->Println("Move point : " + g_->GetCurPlayer()->name() + " " +
                  s.substr(0, s.length() - 1) + " " + direction_to_string[dir] +
                  " " + to_string(inc));
}
