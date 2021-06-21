#include "play.h"
#include "action_listener_interface.h"
#include "bonus.h"
#include "direction.h"
#include "game.h"
#include "game_cli.h"
#include "game_controller_cli.h"
#include "game_controller_interface.h"
#include "log.h"
#include "util.h"
using namespace std;

void PlayGame(int argc, const char *argv[]) {
    GameControllerInterface *controller = new GameControllerCli{};
    Game g{Board{GetArg(argc, argv, 4, "-s", true)}, controller,
           GetArg(argc, argv, 2048, "-t", true, 64)};

    bool is_log = static_cast<bool>(GetArg(argc, argv, false, "-log")),
         is_p = static_cast<bool>(GetArg(argc, argv, false, "-p"));

    ActionListenerInterface *l = nullptr;
    Bonus *b = nullptr;

    if (is_log) {
        l = new Log{&g};
    }
    if (is_p) {
        b = new Bonus{&g};
    }

    GameCli c{&g};
    g.Init();
    while (!g.IsEnd()) {
        g.PlayRound();
    }

    if (is_p) {
        delete b;
    }
    if (is_log) {
        delete l;
    }
    delete controller;
}
