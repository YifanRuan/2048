#include "play.h"
#include "bonus.h"
#include "direction.h"
#include "game.h"
#include "game_cli.h"
#include "game_controller_cli.h"
#include "game_controller_interface.h"
#include "log.h"
#include "log_bonus.h"
#include "log_game.h"
#include "util.h"
using namespace std;

void PlayGame(int argc, const char *argv[]) {
    GameControllerInterface *controller = new GameControllerCli{};
    Game g{Board{GetArg(argc, argv, 4, "-s", true)}, controller,
           GetArg(argc, argv, 2048, "-t", true, 64)};

    bool is_log = static_cast<bool>(GetArg(argc, argv, false, "-log")),
         is_p = static_cast<bool>(GetArg(argc, argv, false, "-p"));

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
