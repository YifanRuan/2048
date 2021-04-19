#include "status.h"
using namespace std;

Status::Status() { Init(Single, 2048, 4); }
Status::Status(int argument, int end, int side) {
    mode_ = Mode(argument);
    Init(mode_, end, side);
}

void Status::OutputGraph() const {
    for (int i = 0; i < side_; ++i) {
        OutputDivs();
        OutputNums(i);
    }
    OutputDivs();
}

void Status::Update(Direction direction) {
    pair<int, int> pair_direction = direction_to_pair_[direction];
    int operate_order = pair_direction.first + pair_direction.second;
    fill(is_merge_.begin(), is_merge_.end(), false);

    for (int i = 0; i < size_; ++i) {
        bool is_inbound = true;
        int current_position = operate_order > 0 ? (size_ - i - 1) : i;
        if (value_[current_position] == 0)
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
            if (value_[next_position] > 0)
                break;
            value_[next_position] = value_[current_position];
            value_[current_position] = 0;
            current_pair_position = next_pair_position;
            current_position = next_position;
        }

        if (is_inbound && value_[next_position] == value_[current_position] &&
            !is_merge_[next_position]) {
            value_[next_position] += value_[current_position];
            point_[current_player_] += value_[next_position];
            value_[current_position] = 0;
            is_merge_[next_position] = true;
        }
    }
}

bool Status::operator==(const Status &other) {
    for (int i = 0; i < size_; ++i) {
        if (value_[i] != other.value_[i])
            return false;
    }
    return true;
}

bool Status::IsWin() const {
    for (auto it : value_) {
        if (it == end_num_) {
            if (mode_ == Dual)
                PrintWinner();
            else
                printf("Your score is %d.\nYou win!!\n", point_[0]);
            return true;
        }
    }
    return false;
}

void Status::PickRandomNumber() {
    vector<int> order;
    for (int i = 0; i < size_; ++i) {
        if (value_[i] == 0)
            order.push_back(i);
    }
    if (!order.empty())
        value_[order[rand() % order.size()]] = 2;
}

int Status::GetNonZeros() const {
    int cnt = 0;
    for (auto it : value_) {
        if (it > 0)
            ++cnt;
    }
    return cnt;
}

void Status::PrintWinner() const {
    if (mode_ == Single) {
        printf("Your score is %d.\nYou lose!!\n", point_[0]);
    } else {
        printf("%s scores %d.\n", player_name_[0].c_str(), point_[0]);
        printf("%s scores %d.\n", player_name_[1].c_str(), point_[1]);
        // cout << player_name_[0] << " scores " << point_[0] << ".\n";
        // cout << player_name_[1] << " scores " << point_[1] << ".\n";
        if (point_[0] == point_[1]) {
            printf("Tie!!\n");
        } else if (point_[0] > point_[1]) {
            printf("%s wins!!\n", player_name_[0].c_str());
            // cout << player_name_[0] << " wins!!\n";
        } else {
            printf("%s wins!!\n", player_name_[1].c_str());
            // cout << player_name_[1] << " wins!!\n";
        }
    }
}

void Status::OutputPoints() const {
    if (mode_ == Dual) {
        printf("%s has %d points now.\n\n",
               player_name_[current_player_].c_str(), point_[current_player_]);
        // cout << player_name_[current_player_] << " has ";
        // cout << point_[current_player_] << " points now.\n\n";
    } else {
        printf("Now you have %d points.\n\n", point_[current_player_]);
    }
}

void Status::Init(Mode mode, int end, int side) {
    end_num_ = end, point_[0] = point_[1] = 0;
    side_ = side, size_ = side * side;
    direction_to_pair_ = {{W, {-1, 0}}, {A, {0, -1}}, {S, {1, 0}}, {D, {0, 1}}};
    if (mode == Single) {
        current_player_ = 0;
        player_name_[0] = "You";
    } else {
        for (int i = 0; i < 2; ++i) {
            printf("Please input player %d's name: ", i + 1);
            // cin >> player_name_[i];
            getline(cin, player_name_[i]);
        }
        current_player_ = 1;
    }
    for (int i = 0; i < size_; ++i) {
        value_.push_back(0);
        is_merge_.push_back(false);
    }
    PickRandomNumber();
    PickRandomNumber();
}

void Status::OutputDivs() const {
    for (int i = 0; i < side_; ++i)
        printf("+-----");
    printf("+\n");
}

void Status::OutputNums(int row) const {
    for (int i = 0; i < side_; ++i) {
        printf("|%5d", value_[side_ * row + i]);
    }
    printf("|\n");
}
