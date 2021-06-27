#include "game.h"
#include <sstream>

using namespace std;
using namespace std::chrono;

Game::Game(Board board, GameControllerInterface *c, int end_num, int max_freq)
    : board_(std::move(board)), controller_(c), end_num_(end_num),
      kMaxRetractFreq(max_freq) {}

Game::Game(Board board, vector<Player> player, GameControllerInterface *c,
           int end_num, int max_freq)
    : board_(std::move(board)), player_(std::move(player)), controller_(c),
      end_num_(end_num), turn_(player_.size() - 1), kMaxRetractFreq(max_freq) {}

void Game::Init() {
    b_.push(board_);
    if (player_.size() > 0)
        return;
    for (auto it : observers_)
        it->NewGame();
    int num = atoll(controller_->GetInput().c_str());
    turn_ = num - 1;
    if (num == 1) {
        num = 0;
        AddPlayer("Default");
        return;
    }
    for (int i = 1; i <= num; ++i) {
        for (auto it : observers_)
            it->NewPlayer(i);
        AddPlayer(controller_->GetInput());
    }
}

void Game::AddPlayer(string name) {
    player_.push_back(Player{name});
    retract_freq_.push_back(kMaxRetractFreq);
}

bool Game::Move(Direction dir) {
    pair<int, bool> merge_result = board_.Move(dir, &board_);
    if (merge_result.second) {
        move_time_ = system_clock::now();
        GetCurPlayer()->AddNewPoint(merge_result.first);
        board_.PickRandomNumber();
        ActionPerformed(MoveInfo(merge_result.first, dir));
        for (auto it : observers_) {
            it->PointIncremented(merge_result.first, dir);
        }
        b_.push(board_);
        return true;
    } else {
        return false;
    }
}

string Game::MoveInfo(int inc, Direction dir) {
    if (inc <= 0)
        return "";
    time_t cur_time = system_clock::to_time_t(move_time());
    string s = static_cast<string>(ctime(&cur_time));
    string ret = "Move point :" + GetCurPlayer()->name() + " " +
                 s.substr(0, s.length() - 1) + " " + direction_to_string[dir] +
                 " " + to_string(inc);
    return ret;
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
    if (is_retracted_ == false || player_.size() == 1)
        NextPlayer();
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

    // Retraction
    is_retracted_ = false;
    while (retract_freq_[turn_] > 0 && b_.size() > 1) {
        // ask
        for (auto it : observers_) {
            it->BoardToChange();
            it->ToRetract(retract_freq_[turn_]);
        }
        // Command
        string cmd = controller_->GetInput();
        while (cmd != "y" && cmd != "n")
            cmd = controller_->GetInput();
        if (cmd == "n")
            break;

        ActionPerformed(RetractInfo(Retract()));

        if (player_.size() > 1)
            break;
    }
}

int Game::Retract() {
    int prev_point = GetCurPlayer()->point();
    BoardRollback();
    GetCurPlayer()->RollBack();
    retract_freq_[turn_] -= 1;
    is_retracted_ = true;
    return GetCurPlayer()->point() - prev_point;
}

string Game::RetractInfo(int dec) {
    if (dec == 0)
        return "";
    time_t cur_time = system_clock::to_time_t(move_time());
    string s = static_cast<string>(ctime(&cur_time));
    string ret = "Retract point : " + GetCurPlayer()->name() + " " +
                 s.substr(0, s.length() - 1) + " " + to_string(dec);
    return ret;
}

void Game::ActionPerformed(std::string info) {
    for (auto it : actions_) {
        it->ActionPerformed(info);
    }
}

void Game::BoardRollback() {
    b_.pop();
    board_ = b_.top();
}
