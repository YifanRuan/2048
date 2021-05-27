#include "game.h"

using namespace std;
using namespace std::chrono;

Game::Game(Board board, vector<Player> player, Log log, Bonus bonus,
           int end_num)
    : board_(std::move(board)), player_(std::move(player)), end_num_(end_num),
      turn_(player.size() - 1), log_(std::move(log)), bonus_(std::move(bonus)),
      previous_time_(system_clock::from_time_t(static_cast<time_t>(1))) {}

bool Game::Move(Direction dir) {
    pair<int, bool> merge_result = board_.Move(dir, &board_);
    if (merge_result.second) {
        NextPlayer();
        auto cur_time = system_clock::now();
        log_.PrintLog(LogMoveStrategy{GetCurPlayer(),
                                      system_clock::to_time_t(cur_time), dir,
                                      merge_result.first});
        player_[turn_].AddPoint(merge_result.first +
                                bonus_.GetBonusPoint(GetCurPlayer(), &log_,
                                                     cur_time, previous_time_));
        previous_time_ = cur_time;
        return true;
    } else {
        return false;
    }
}

bool Game::IsWin() const {
    for (auto it : board_.value())
        if (it == end_num_)
            return true;
    return false;
}

void Game::PickRandomNumber() { board_.PickRandomNumber(); }
