#include "game.h"
using namespace std;

Direction GetInput() {
  string s = "0";
  static map<string, Direction> string_to_direction = {
      {"w", W}, {"a", A}, {"s", S}, {"d", D}};
  do {
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  } while (!string_to_direction.count(s));
  return string_to_direction[s];
}

bool CheckWin(const Status &status) {
  if (status.IsWin()) {
    printf("You win!!\n");
    return true;
  } else {
    return false;
  }
}

void PlayGame(Status *status) {
  static const int kDirection = 4, kSize = 16;
  status->OutputGraph();

  while (!CheckWin(*status)) {
    bool is_dead = true, is_same_status[kDirection] = {false};
    Status next_status[kDirection];
    int non_zeros = status->GetNonZeros();

    for (int i = 0; i < kDirection; ++i) {
      next_status[i] = *status;
      next_status[i].Update(Direction(i));
      if (next_status[i] == *status)
        is_same_status[i] = true;
      next_status[i].PickRandomNumber();
      if (non_zeros != kSize || !(next_status[i] == *status))
        is_dead = false;
    }

    if (is_dead) {
      printf("You lose!!\n");
      break;
    }

    Direction direction = GetInput();
    if (!is_same_status[direction])
      *status = next_status[direction];
    status->OutputGraph();
  }
}