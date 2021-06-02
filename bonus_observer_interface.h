#ifndef BONUS_OBSERVER_INTERFACE_H_
#define BONUS_OBSERVER_INTERFACE_H_

#include "player.h"

class BonusObserverInterface {
  public:
    virtual void BonusPointIncremented(int inc, const Player &player) = 0;
};

#endif // BONUS_OBSERVER_INTERFACE_H_
