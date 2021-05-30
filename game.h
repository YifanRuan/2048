#ifndef GAME_H_
#define GAME_H_

#include "board.h"
#include "bonus.h"
#include "direction.h"
#include "log.h"
#include "log_move_strategy.h"
#include "player.h"
#include <chrono>
#include <utility>
#include <vector>

class Game {
  public:
    Game() = default;

    Game(Board board, std::vector<Player> player, Log log, Bonus bonus,
         int end_num = 2048);

    bool Move(Direction dir);

    bool IsWin() const;

    inline Board board() const { return board_; }

    inline std::vector<Player> player() const { return player_; }

    inline Player GetCurPlayer() const { return player_[turn_]; }

    inline Player GetNextPlayer() const {
        return player_[(turn_ + 1) % player_.size()];
    }

    void PickRandomNumber();

  private:
    inline void NextPlayer() { turn_ = (turn_ + 1) % player_.size(); }

    Board board_;
    std::vector<Player> player_;
    int turn_, end_num_;
    // Observer mode
    Log log_;
    Bonus bonus_;
    bool is_first_move_ = true;
    std::chrono::time_point<std::chrono::system_clock> previous_time_;
};

#endif // GAME_H_
