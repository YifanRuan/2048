#include "bonus.h"
#include "direction.h"
#include "game.h"
#include "game_cli.h"
#include "log.h"
#include "log_bonus.h"
#include "log_game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Direction GetInput() {
    char c = getchar();
    while (!char_to_direction.count(c))
        c = getchar();
    return char_to_direction[c];
}

int main() {
    srand(unsigned(time(nullptr)));
    Game g{Board{4}, {Player{"default"}}, 32};
    GameCli c{&g};
    Log l;
    LogGame lg{&g, &l};
    Bonus b{&g};
    LogBonus lb{&b, &l};
    g.Init();
    while (!g.IsWin()) {
        g.Move(GetInput());
    }
    return 0;
}
