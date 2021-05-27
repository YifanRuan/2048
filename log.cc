#include "log.h"

using namespace std;
using namespace std::chrono;

Log::Log(bool is_log) : is_log_(is_log) {
    if (is_log_) {
        fp_ = fopen("log.txt", "w");
    }
}

Log::~Log() {
    if (is_log_) {
        fclose(fp_);
    }
}

void Log::PrintMove(const Player &player, time_t time, Direction dir,
                    int point) {
    if (!is_log_ || point <= 0)
        return;
    fprintf(fp_, "Move point: %s %s %s %d\n", player.name().c_str(),
            ctime(&time), direction_to_string[dir].c_str(), point);
}

void Log::PrintBonus(const Player &player, time_t time, duration<double> diff,
                     int point) {
    if (!is_log_ || point <= 0)
        return;
    fprintf(fp_, "Bonus point: %s %s %.1lf %d\n", player.name().c_str(),
            ctime(&time), diff.count(), point);
}
