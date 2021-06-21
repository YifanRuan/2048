#ifndef LOG_GAME_H_
#define LOG_GAME_H_

#include "game.h"
#include "game_observer_interface.h"
#include "log_interface.h"

class LogGame : public GameObserverInterface {
  public:
    LogGame(Game *g, LogInterface *log);

    virtual ~LogGame();

    void NewGame() {}

    void NewPlayer(int no) {}

    void NewRound() {}

    void ProcessCommand(std::string) {}

    void PointIncremented(int inc, Direction dir);

    void BoardToChange() {}

    void ToRetract(int freq) {}

    void EndOfGame(bool status) {}

  private:
    Game *g_;
    LogInterface *log_;
};

#endif // LOG_GAME_H_
