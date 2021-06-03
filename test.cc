#include "bonus.h"
#include "direction.h"
#include "game.h"
#include "game_cli.h"
#include "log.h"
#include "log_bonus.h"
#include "log_game.h"
#include "log_null.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Direction GetInput() {
    char c = getchar();
    while (!char_to_direction.count(c))
        c = getchar();
    return char_to_direction[c];
}

int main(int argc, const char *argv[]) {
    srand(unsigned(time(nullptr)));

    Game g{Board{4}, {Player{"default"}, Player{"fuck"}}, 32};

    set<string> ss;
    for (int i = 1; i < argc; ++i) {
        ss.insert(static_cast<string>(argv[i]));
    }
    bool is_log = static_cast<bool>(ss.count("-log")),
         is_p = static_cast<bool>(ss.count("-p"));

    Log *l = nullptr;
    LogGame *lg = nullptr;
    Bonus *b = nullptr;
    LogBonus *lb = nullptr;
    if (is_log) {
        l = new Log{};
        lg = new LogGame{&g, l};
    }
    if (is_p) {
        b = new Bonus{&g};
    }
    if (is_log && is_p) {
        lb = new LogBonus{b, l};
    }

    GameCli c{&g};
    g.Init();
    while (!g.IsWin()) {
        g.Move(GetInput());
    }
    return 0;
}
