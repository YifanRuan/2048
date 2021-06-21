#include "log.h"
using namespace std;

Log::Log() { fp_.open("log.txt"); }

Log::~Log() { fp_.close(); }

void Log::Println(const string &log) { fp_ << log << endl; }
