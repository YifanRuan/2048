#ifndef STATUS_H_
#define STATUS_H_

#include <bits/stdc++.h>

enum Direction { W, A, S, D };

class Status {
 public:
  Status();
  Status(int argument);

  void OutputGraph() const;

  void Update(Direction direction);

  bool operator==(const Status &other);

  bool IsWin() const;

  void PickRandomNumber();

  int GetNonZeros() const;

 private:
  static const int kSide = 4, kSize = 16;
  std::map<Direction, std::pair<int, int>> direction_to_pair_ = {
      {W, {-1, 0}}, {A, {0, -1}}, {S, {1, 0}}, {D, {0, 1}}};
  std::vector<int> value_;
  std::vector<bool> is_merge_;
  int end_num_ = 2048;

  void Init();

  void OutputDivs() const;

  void OutputNums(int row) const;

  inline std::pair<int, int> SingleToPair(int position) {
    return std::make_pair(position / kSide, position % kSide);
  }

  inline int PairToSingle(std::pair<int, int> position) {
    return position.first * kSide + position.second;
  }
};

#endif