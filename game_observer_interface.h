#ifndef GAME_OBSERVER_INTERFACE_H_
#define GAME_OBSERVER_INTERFACE_H_

#include "direction.h"

class GameObserverInterface {
  public:
    virtual void GameStart() = 0;
    virtual void NewRound() = 0;
    virtual void PointIncremented(int inc, Direction dir) = 0;
    virtual void EndOfGame(bool status) = 0;
};

#endif // GAME_OBSERVER_INTERFACE_H_
