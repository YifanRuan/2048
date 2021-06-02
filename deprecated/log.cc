#include "log.h"

using namespace std;

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

void Log::PrintLog(const LogStrategyInterface &log) const {
    if (is_log_ && log.IsLog())
        fprintf(fp_, "%s\n", log.GetLog().c_str());
}
