#include <bits/stdc++.h>

#include "game.h"
#include "status.h"
using namespace std;

int main(int argc, char *argv[]) {
    srand(unsigned(time(NULL)));
    pair<int, int> pi = GetArg(argc, argv);
    printf("Ending number: %d, map size: %d.\n", pi.first, pi.second);
    Status status = Status(ChooseMode(), pi.first, pi.second);
    PlayGame(&status);
    return 0;
}