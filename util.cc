#include "util.h"
#include <algorithm>
#include <cstring>

using namespace std;

int GetArg(int argc, const char *argv[], int ret, const char *opt,
           bool additional, int alt) {
    for (int i = 1; i < argc; ++i) {
        if (strcasecmp(argv[i], opt) == 0) {
            if (additional && i + 1 < argc && argv[i + 1][0] >= '0' &&
                argv[i + 1][0] <= '9') {
                return static_cast<int>(max(argv[i + 1][0] - '0', 0));
            }
            return alt;
        }
    }
    return ret;
}
