#ifndef CLI_STRATEGY_H_
#define CLI_STRATEGY_H_

#include "cli_strategy_interface.h"
#include "game.h"

class CliStrategy : public CliStrategyInterface {
  public:
    CliStrategy(Game *g) : g_(g) {}

    void OutputPrompt() {
        printf("\nIt's %s's turn: ", g_->GetCurPlayer()->name().c_str());
    }

  private:
    Game *g_;
};

#endif // CLI_STRATEGY_H_
