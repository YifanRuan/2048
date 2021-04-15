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

    inline void SetEndNum(int set_end_num) { end_num_ = set_end_num; }

    inline void ChangePlayer() {
        if (mode_ == Dual)
            current_player_ ^= 1;
    }

    inline void OutputPlayer() const {
        if (mode_ == Dual)
            std::cout << "It's " << player_name_[current_player_]
                      << "'s turn.\n";
    }

    void PrintWinner() const;

    void OutputPoints() const;

  private:
    static const int kSide = 4, kSize = 16;
    std::map<Direction, std::pair<int, int>> direction_to_pair_;
    std::vector<int> value_;
    std::vector<int> is_merge_;
    int end_num_;
    int point_[2];
    int current_player_;
    std::string player_name_[2];
    enum Mode { Single, Dual } mode_;

    void Init(Mode mode);

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