#include "bonus.h"
#include "direction.h"
#include "game.h"
#include "game_cli.h"
#include "game_controller_cli.h"
#include "game_controller_interface.h"
#include "log.h"
#include "log_bonus.h"
#include "log_game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void PlayGame(int argc, const char *argv[]) {
    GameControllerInterface *controller = new GameControllerCli{};
    Game g{Board{2}, {Player{"default"}, Player{"fuck"}}, controller, 32};

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
    while (!g.IsEnd()) {
        g.PlayRound();
    }
}

int main(int argc, const char *argv[]) {
    srand(unsigned(time(nullptr)));
    PlayGame(argc, argv);
    return 0;
}
