#ifndef GAME_OBSERVER_INTERFACE_H_
#define GAME_OBSERVER_INTERFACE_H_

#include "direction.h"
#include <string>

class GameObserverInterface {
  public:
    virtual void NewGame() = 0;
    virtual void NewPlayer(int no) = 0;
    virtual void NewRound() = 0;
    virtual void ProcessCommand(std::string) = 0;
    virtual void PointIncremented(int inc, Direction dir) = 0;
    virtual void BoardToChange() = 0;
    virtual void ToRetract(int freq) = 0;
    virtual void EndOfGame(bool status) = 0;
};

#endif // GAME_OBSERVER_INTERFACE_H_
