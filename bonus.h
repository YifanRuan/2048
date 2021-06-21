#ifndef BONUS_H_
#define BONUS_H_

#include "bonus_observer_interface.h"
#include "game.h"
#include "game_observer_interface.h"
#include <algorithm>
#include <chrono>
#include <vector>

class Bonus : public GameObserverInterface {
  public:
    Bonus(Game *g);

    virtual ~Bonus();

    void NewGame() {}

    void NewPlayer(int no) {}

    void NewRound() {}

    void ProcessCommand(std::string) {}

    void PointIncremented(int inc, Direction dir);

    void BoardToChange() {}

    void ToRetract(int freq) {}

    void EndOfGame(bool status) {}

    void AddObserver(BonusObserverInterface *observer) {
        observers_.push_back(observer);
    }

    void RemoveObserver(BonusObserverInterface *observer) {
        observers_.erase(
            std::find(observers_.begin(), observers_.end(), observer));
    }

    std::chrono::time_point<std::chrono::system_clock> last_time() {
        return last_time_;
    }

    std::chrono::time_point<std::chrono::system_clock> cur_time() {
        return cur_time_;
    }

  private:
    Game *g_;
    static const int bonus_point_ = 1;
    std::vector<BonusObserverInterface *> observers_;
    std::chrono::time_point<std::chrono::system_clock> last_time_, cur_time_;
    bool is_moved_ = false;
    static constexpr double diff_time_ = 1.0;
};

#endif // BONUS_H_
