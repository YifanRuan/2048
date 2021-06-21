#ifndef PLAYER_H_
#define PLAYER_H_

#include <stack>
#include <string>
#include <utility>

class Player {
  public:
    Player() : name_(""), point_(-1) {}

    explicit Player(std::string name);

    Player(std::string name, int point);

    void AddNewPoint(int p);

    std::string name() const { return name_; }

    int point() const { return point_; }

    void SetCurPoint(int point);

    void RollBack();

  private:
    std::string name_;
    int point_;
    std::stack<int> prev_points_;
};

#endif // PLAYER_H_
