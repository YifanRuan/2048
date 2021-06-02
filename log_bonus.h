#ifndef LOG_BONUS_H_
#define LOG_BONUS_H_

#include "bonus.h"
#include "bonus_observer_interface.h"
#include "log_interface.h"

class LogBonus : public BonusObserverInterface {
  public:
    LogBonus(Bonus *b, LogInterface *l);

    virtual ~LogBonus();

    void BonusPointIncremented(int inc, const Player &player);

  private:
    Bonus *b_;
    LogInterface *log_;
};

#endif // LOG_BONUS_H_
