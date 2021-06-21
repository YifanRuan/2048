#include "log.h"
using namespace std;

Log::Log(Game *g) : g_(g) {
    g_->AddActionListener(this);
    fp_.open("log.txt");
}

Log::~Log() {
    fp_.close();
    g_->RemoveActionListener(this);
}

void Log::ActionPerformed(std::string info) {
    if (info.length() > 0)
        Println(info);
}

void Log::Println(const string &log) { fp_ << log << endl; }
