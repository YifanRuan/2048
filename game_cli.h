#ifndef GAME_CLI_H_
#define GAME_CLI_H_

#include "cli_strategy_interface.h"
#include "game.h"
#include "game_observer_interface.h"

class GameCli : public GameObserverInterface {
  public:
    GameCli(Game *g);

    virtual ~GameCli();

    virtual void NewGame();

    void NewPlayer(int no);

    virtual void NewRound();

    virtual void ProcessCommand(std::string);

    virtual void PointIncremented(int inc, Direction dir);

    virtual void BoardToChange();

    virtual void ToRetract(int freq);

    virtual void EndOfGame(bool status);

  protected:
    // Is is protected?
    void OutputGraph(const Board &board);

  private:
    void Prompt() {
        printf("%s has %d point(s) now.\n", g_->GetCurPlayer()->name().c_str(),
               g_->GetCurPlayer()->point());
    }

    Game *g_;
    CliStrategyInterface *stragety_;
    bool is_cheat = false;
};

#endif // GAME_CLI_H_
