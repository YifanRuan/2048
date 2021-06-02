#include "log.h"
using namespace std;

Log::Log() { fp_ = fopen("log.txt", "w"); }

Log::~Log() { fclose(fp_); }

void Log::PrintLog(const string &log) { fprintf(fp_, "%s\n", log.c_str()); }
