#include "game.h"

using namespace std;

Game::Game(Board board, vector<Player> player, int end_num)
    : board_(std::move(board)), player_(std::move(player)), end_num_(end_num),
      turn_(player.size() - 1) {}

void Game::Init() {
    for (auto it : observers_) {
        it->GameStart();
        it->NewRound();
    }
}

bool Game::Move(Direction dir) {
    pair<int, bool> merge_result = board_.Move(dir, &board_);
    if (merge_result.second) {
        NextPlayer();
        player_[turn_].AddPoint(merge_result.first);
        board_.PickRandomNumber();
        for (auto it : observers_) {
            it->PointIncremented(merge_result.first);
            it->NewRound();
        }
        return true;
    } else {
        return false;
    }
}

bool Game::IsWin() const {
    for (auto it : board_.value()) {
        if (it == end_num_) {
            for (auto it : observers_)
                it->EndOfGame(true);
            return true;
        }
    }
    return false;
}

void Game::PickRandomNumber() { board_.PickRandomNumber(); }
