#ifndef GAME_H_
#define GAME_H_

#include "board.h"
#include "direction.h"
#include "game_observer_interface.h"
#include "player.h"
#include <algorithm>
#include <chrono>
#include <utility>
#include <vector>

class Game {
  public:
    Game() = default;

    Game(Board board, std::vector<Player> player, int end_num = 2048);

    void Init();

    bool Move(Direction dir);

    bool IsWin() const;

    inline Board board() const { return board_; }

    inline std::vector<Player> player() const { return player_; }

    inline Player GetCurPlayer() const { return player_[turn_]; }

    inline Player GetNextPlayer() const {
        return player_[(turn_ + 1) % player_.size()];
    }

    void PickRandomNumber();

    inline void AddObserver(GameObserverInterface *observer) {
        observers_.push_back(observer);
    }

    inline void RemoveObserver(GameObserverInterface *observer) {
        observers_.erase(
            std::find(observers_.begin(), observers_.end(), observer));
    }

    inline std::chrono::time_point<std::chrono::system_clock> move_time() {
        return move_time_;
    }

  private:
    inline void NextPlayer() { turn_ = (turn_ + 1) % player_.size(); }

    Board board_;
    std::vector<Player> player_;
    int turn_, end_num_;
    std::vector<GameObserverInterface *> observers_;
    std::chrono::time_point<std::chrono::system_clock> move_time_;
};

#endif // GAME_H_
