#include <bits/stdc++.h>

#include "game.h"
#include "status.h"
using namespace std;

int main(int argc, const char *argv[]) {
    srand(unsigned(time(NULL)));
    Status status = Status(ChooseMode());
    if (argc > 1 && strcasecmp(argv[1], "-t") == 0)
        status.SetEndNum(64);
    PlayGame(&status);
    return 0;
}