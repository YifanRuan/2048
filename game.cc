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

void PlayGame(Status *status) {
    static const int kDirection = 4, kSize = 16;
    status->OutputGraph();

    while (!status->IsWin()) {
        bool is_dead = true, is_same_status[kDirection] = {false};
        Status next_status[kDirection];
        int non_zeros = status->GetNonZeros();
        status->ChangePlayer();

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
            status->PrintWinner();
            break;
        }

        status->OutputPlayer();
        Direction direction = GetInput();
        if (!is_same_status[direction])
            *status = next_status[direction];
        status->OutputGraph();
        status->OutputPoints();
    }
}

int ChooseMode() {
    printf("Please choose your mode:\n1: Single Player\n2: Dual Player\n");
    printf("Please input the index of your option: ");
    int mode;
    scanf("%d", &mode);
    return mode - 1;
}