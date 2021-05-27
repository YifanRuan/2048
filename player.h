#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <utility>

class Player {
  public:
    Player() : name_(""), point_(-1) {}

    explicit Player(std::string name) : name_(std::move(name)), point_(0) {}

    Player(std::string name, int point)
        : name_(std::move(name)), point_(point) {}

    void AddPoint(int p) { point_ += p; }

    inline std::string name() const { return name_; }

    inline int point() const { return point_; }

    inline void SetPoint(int point) { point_ = point; }

  private:
    std::string name_;
    int point_;
};

#endif // PLAYER_H_
