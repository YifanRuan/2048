#ifndef CHEAT_H_
#define CHEAT_H_
#include "cli_strategy_interface.h"
#include "game.h"
#include "player.h"

class Cheat : public CliStrategyInterface {
  public:
    Cheat(Game *g, Player *cheater, std::string cheat)
        : g_(g), cheater_(cheater), cheat_(std::move(cheat)),
          is_cheated_(false) {}

    void OutputPrompt();

  private:
    Game *g_;
    Player *cheater_;
    std::string cheat_;
    bool is_cheated_;
};

#endif // CHEAT_H_
