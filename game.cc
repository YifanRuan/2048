#include "game.h"
#include <sstream>

using namespace std;
using namespace std::chrono;

Game::Game(Board board, vector<Player> player, GameControllerInterface *c,
           int end_num)
    : board_(std::move(board)), player_(std::move(player)), controller_(c),
      end_num_(end_num), turn_(player_.size() - 1) {}

void Game::Init() {
    for (auto it : observers_)
        it->GameInfo();
}

bool Game::Move(Direction dir) {
    pair<int, bool> merge_result = board_.Move(dir, &board_);
    if (merge_result.second) {
        move_time_ = system_clock::now();
        NextPlayer();
        GetCurPlayer()->AddPoint(merge_result.first);
        board_.PickRandomNumber();
        for (auto it : observers_) {
            it->PointIncremented(merge_result.first, dir);
        }
        return true;
    } else {
        return false;
    }
}

bool Game::IsEnd() {
    for (auto it : board_.value()) {
        if (it == end_num_) {
            for (auto it : observers_)
                it->EndOfGame(true);
            return true;
        }
    }
    if (board_.AvailableDirections().size() == 0) {
        for (auto it : observers_)
            it->EndOfGame(false);
        return true;
    }
    return false;
}

void Game::PlayRound() {
    for (auto it : observers_)
        it->NewRound();
    while (true) {
        string cmd = controller_->GetInput();
        stringstream ss;
        ss.str(cmd);
        string s;
        ss >> s;
        if (s.length() == 0)
            continue;
        for (auto it : observers_)
            it->ProcessCommand(cmd);
        if (!char_to_direction.count(s[0]))
            continue;
        if (Move(char_to_direction[s[0]]))
            break;
    }
}
