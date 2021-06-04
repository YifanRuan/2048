#ifndef LOG_GAME_H_
#define LOG_GAME_H_

#include "game.h"
#include "game_observer_interface.h"
#include "log_interface.h"

class LogGame : public GameObserverInterface {
  public:
    LogGame(Game *g, LogInterface *log);

    virtual ~LogGame();

    void GameInfo() {}

    void NewRound() {}

    void ProcessCommand(std::string) {}

    void PointIncremented(int inc, Direction dir);

    void EndOfGame(bool status) {}

  private:
    Game *g_;
    LogInterface *log_;
};

#endif // LOG_GAME_H_
