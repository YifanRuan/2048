#ifndef STATUS_H_
#define STATUS_H_

#include <bits/stdc++.h>

enum Direction { W, A, S, D };

// TODO: Add a copy function
class Status {
  public:
    Status();
    Status(int argument, int end, int side);

    void OutputGraph() const;

    void Update(Direction direction);

    bool operator==(const Status &other);

    bool IsWin() const;

    void PickRandomNumber();

    int GetNonZeros() const;

    inline void SetEndNum(int set_end_num);

    inline void ChangePlayer();

    inline void OutputPlayer() const;

    void PrintWinner() const;

    void OutputPoints() const;

    inline void SetSideSize(int side);

    inline int GetSize() const;

  private:
    int side_, size_;
    std::map<Direction, std::pair<int, int>> direction_to_pair_;
    std::vector<int> value_;
    std::vector<int> is_merge_;
    int end_num_;
    int point_[2];
    int current_player_;
    std::string player_name_[2];
    enum Mode { Single, Dual } mode_;

    void Init(Mode mode, int end, int side);

    void OutputDivs() const;

    void OutputNums(int row) const;

    inline std::pair<int, int> SingleToPair(int position);

    inline int PairToSingle(std::pair<int, int> position);
};

inline void Status::SetEndNum(int set_end_num) { end_num_ = set_end_num; }

inline void Status::ChangePlayer() {
    if (mode_ == Dual)
        current_player_ ^= 1;
}

inline void Status::OutputPlayer() const {
    if (mode_ == Dual)
        std::cout << "It's " << player_name_[current_player_] << "'s turn.\n";
}

inline void Status::SetSideSize(int side) { side_ = side, size_ = side * side; }

inline int Status::GetSize() const { return size_; }

inline std::pair<int, int> Status::SingleToPair(int position) {
    return std::make_pair(position / side_, position % side_);
}

inline int Status::PairToSingle(std::pair<int, int> position) {
    return position.first * side_ + position.second;
}

#endif