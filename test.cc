#include "direction.h"
#include "game.h"
#include "game_cli.h"
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
    Game g{Board{4}, {Player{"default player"}}, 32};
    GameCli c{&g};
    g.Init();
    while (!g.IsWin()) {
        g.Move(GetInput());
    }
    return 0;
}
