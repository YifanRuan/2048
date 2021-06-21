#include "player.h"
using namespace std;

Player::Player(string name) : name_(std::move(name)), point_(0) {
    prev_points_.push(point_);
}

Player::Player(std::string name, int point)
    : name_(std::move(name)), point_(point) {
    prev_points_.push(point_);
}

void Player::AddNewPoint(int p) {
    point_ += p;
    prev_points_.push(point_);
}

void Player::SetCurPoint(int point) {
    point_ = point;
    prev_points_.top() = point_;
}

void Player::RollBack() {
    if (prev_points_.size() > 1) {
        prev_points_.pop();
        point_ = prev_points_.top();
    }
}
