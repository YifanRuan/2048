#include "play.h"
#include "test.h"
#include "util.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, const char *argv[]) {
    srand(unsigned(time(nullptr)));
    if (GetArg(argc, argv, false, "-i")) {
        Test(argc, argv);
        return 0;
    }
    PlayGame(argc, argv);
    return 0;
}
