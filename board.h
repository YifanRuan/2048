#ifndef BOARD_H_
#define BOARD_H_

#include "direction.h"
#include <map>
#include <set>
#include <vector>

class Board {
  public:
    Board() = default;

    Board(int side);

    Board(std::vector<int> values, int side)
        : value_(std::move(values)), side_(side) {}

    // Board(const Board &other);

    std::pair<int, bool> Move(Direction direction, Board *to_board);

    std::set<Direction> AvailableDirections();

    std::pair<int, int> PickRandomNumber();

    std::vector<int> value() const { return value_; }

    int side() const { return side_; }

  private:
    std::pair<int, int> SingleToPair(int position) const {
        return std::make_pair(position / side_, position % side_);
    }

    int PairToSingle(std::pair<int, int> position) const {
        return position.first * side_ + position.second;
    }

    std::map<Direction, std::pair<int, int>> direction_to_pair_ = {
        {W, {-1, 0}}, {A, {0, -1}}, {S, {1, 0}}, {D, {0, 1}}};

    std::vector<int> value_;
    int side_{};
};

#endif // BOARD_H_
