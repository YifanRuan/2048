#include "status.h"
using namespace std;

Status::Status() { Init(); }
Status::Status(int argument) {
  Init();
  end_num_ = argument;
}

void Status::OutputGraph() const {
  for (int i = 0; i < kSide; ++i) {
    OutputDivs();
    OutputNums(i);
  }
  OutputDivs();
}

void Status::Update(Direction direction) {
  pair<int, int> pair_direction = direction_to_pair_[direction];
  int operate_order = pair_direction.first + pair_direction.second;
  fill(is_merge_.begin(), is_merge_.end(), false);

  for (int i = 0; i < kSize; ++i) {
    bool is_inbound = true;
    int current_position = operate_order > 0 ? (kSize - i - 1) : i;
    if (value_[current_position] == 0) continue;
    int next_position;
    pair<int, int> current_pair_position = SingleToPair(current_position);
    pair<int, int> next_pair_position;

    while (true) {
      auto PairPlus = [](pair<int, int> a, pair<int, int> b) {
        return make_pair(a.first + b.first, a.second + b.second);
      };
      next_pair_position = PairPlus(current_pair_position, pair_direction);
      if (next_pair_position.first < 0 || next_pair_position.first >= kSide ||
          next_pair_position.second < 0 || next_pair_position.second >= kSide) {
        is_inbound = false;
        break;
      }
      next_position = PairToSingle(next_pair_position);
      if (value_[next_position] > 0) break;
      value_[next_position] = value_[current_position];
      value_[current_position] = 0;
      current_pair_position = next_pair_position;
      current_position = next_position;
    }

    if (is_inbound && value_[next_position] == value_[current_position] &&
        !is_merge_[next_position]) {
      value_[next_position] += value_[current_position];
      value_[current_position] = 0;
      is_merge_[next_position] = true;
    }
  }
}

bool Status::operator==(const Status &other) {
  for (int i = 0; i < kSize; ++i) {
    if (value_[i] != other.value_[i]) return false;
  }
  return true;
}

bool Status::IsWin() const {
  for (auto it : value_) {
    if (it == end_num_) return true;
  }
  return false;
}

void Status::PickRandomNumber() {
  vector<int> order;
  for (int i = 0; i < kSize; ++i) {
    if (value_[i] == 0) order.push_back(i);
  }
  if (!order.empty()) value_[order[rand() % order.size()]] = 2;
}

int Status::GetNonZeros() const {
  int cnt = 0;
  for (auto it : value_) {
    if (it > 0) ++cnt;
  }
  return cnt;
}

void Status::Init() {
  for (int i = 0; i < kSize; ++i) {
    value_.push_back(0);
    is_merge_.push_back(false);
  }
  PickRandomNumber();
  PickRandomNumber();
}

void Status::OutputDivs() const {
  for (int i = 0; i < kSide; ++i) printf("+-----");
  printf("+\n");
}

void Status::OutputNums(int row) const {
  for (int i = 0; i < kSide; ++i) {
    printf("|%5d", value_[kSide * row + i]);
  }
  printf("|\n");
}