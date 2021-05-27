#include "board.h"
#include <cstdlib>

using namespace std;

pair<int, bool> Board::Move(Direction direction, Board *to_board) {
    Board board(value_, side_), *p_board;
    if (to_board != this) {
        *to_board = *this;
        p_board = this;
    } else {
        p_board = &board;
    }

    int total_point = 0;
    bool final_moved = false;

    pair<int, int> pair_direction = direction_to_pair_[direction];
    int operate_order = pair_direction.first + pair_direction.second;
    vector<int> is_merge(value_.size());

    for (int i = 0; i < value_.size(); ++i) {
        bool is_inbound = true;
        int current_position = operate_order > 0 ? (value_.size() - i - 1) : i;
        if (to_board->value_[current_position] == 0)
            continue;
        int next_position;
        pair<int, int> current_pair_position = SingleToPair(current_position);
        pair<int, int> next_pair_position;

        while (true) {
            auto PairPlus = [](pair<int, int> a, pair<int, int> b) {
                return make_pair(a.first + b.first, a.second + b.second);
            };
            next_pair_position =
                PairPlus(current_pair_position, pair_direction);
            if (next_pair_position.first < 0 ||
                next_pair_position.first >= side_ ||
                next_pair_position.second < 0 ||
                next_pair_position.second >= side_) {
                is_inbound = false;
                break;
            }
            next_position = PairToSingle(next_pair_position);
            if (to_board->value_[next_position] > 0)
                break;
            to_board->value_[next_position] =
                to_board->value_[current_position];
            to_board->value_[current_position] = 0;
            current_pair_position = next_pair_position;
            current_position = next_position;
        }

        if (is_inbound &&
            to_board->value_[next_position] ==
                to_board->value_[current_position] &&
            !is_merge[next_position]) {
            to_board->value_[next_position] +=
                to_board->value_[current_position];
            total_point += to_board->value_[next_position];
            to_board->value_[current_position] = 0;
            is_merge[next_position] = true;
        }
    }
    for (int i = 0; i < value_.size(); ++i) {
        if (p_board->value_[i] != to_board->value_[i]) {
            final_moved = true;
            break;
        }
    }
    return make_pair(total_point, final_moved);
}

set<Direction> Board::AvailableDirections() {
    set<Direction> ret;
    vector<int> empty_vector(value_.size());
    for (int i = 0; i < kDirection; ++i) {
        Board empty_board(empty_vector, side_);
        if (Move(Direction(i), &empty_board).second)
            ret.insert(Direction(i));
    }
    return ret;
}

pair<int, int> Board::PickRandomNumber() {
    vector<int> order;
    for (int i = 0; i < value_.size(); ++i)
        if (value_[i] == 0)
            order.push_back(i);
    if (!order.empty()) {
        int pos = order[rand() % order.size()];
        value_[pos] = 2;
        return SingleToPair(pos);
    } else {
        return make_pair(-1, -1);
    }
}
