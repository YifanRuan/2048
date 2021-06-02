#ifndef GAME_CLI_H_
#define GAME_CLI_H_

#include "game.h"
#include "game_observer_interface.h"

class GameCli : public GameObserverInterface {
  public:
    GameCli(Game *g);

    virtual ~GameCli();

    void GameStart();

    void NewRound();

    void PointIncremented(int inc, Direction dir);

    void EndOfGame(bool status);

  private:
    void OutputGraph(const Board &board);
    Game *g_;
};

#endif // GAME_CLI_H_
