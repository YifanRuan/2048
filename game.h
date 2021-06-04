#ifndef GAME_H_
#define GAME_H_

#include "board.h"
#include "direction.h"
#include "game_controller_interface.h"
#include "game_observer_interface.h"
#include "player.h"
#include <algorithm>
#include <chrono>
#include <utility>
#include <vector>

class Game {
  public:
    Game() = default;

    Game(Board board, GameControllerInterface *c, int end_num = 2048);

    Game(Board board, std::vector<Player> player, GameControllerInterface *c,
         int end_num = 2048);

    void Init();

    bool IsEnd();

    void PlayRound();

    Board board() const { return board_; }

    std::vector<Player> player() const { return player_; }

    Player *GetCurPlayer() { return &player_[turn_]; }

    Player GetNextPlayer() const {
        return player_[(turn_ + 1) % player_.size()];
    }

    void AddObserver(GameObserverInterface *observer) {
        observers_.push_back(observer);
    }

    void RemoveObserver(GameObserverInterface *observer) {
        observers_.erase(
            std::find(observers_.begin(), observers_.end(), observer));
    }

    std::chrono::time_point<std::chrono::system_clock> move_time() {
        return move_time_;
    }

  private:
    inline void NextPlayer() { turn_ = (turn_ + 1) % player_.size(); }

    bool Move(Direction dir);

    void AddPlayer(std::string name);

    Board board_;
    std::vector<Player> player_;
    int turn_, end_num_;
    std::vector<GameObserverInterface *> observers_;
    std::chrono::time_point<std::chrono::system_clock> move_time_;
    GameControllerInterface *controller_;
};

#endif // GAME_H_
