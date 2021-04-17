#include "game.h"
using namespace std;

pair<int, int> GetArg(int argc, char *argv[]) {
    int c;
    pair<int, int> ret = make_pair(2048, 4);
    while ((c = getopt(argc, argv, "ts:")) != -1) {
        switch (c) {
        case 't':
            ret.first = 64;
            break;
        case 's':
            while (!(strlen(optarg) == 1 && optarg[0] >= '3' &&
                     optarg[0] <= '5')) {
                printf("Wrong input format! Please input 3 or 4 or 5!\n");
                scanf("%s", optarg);
            }
            ret.second = optarg[0] - '0';
            break;
        case '?':
            break;
        default:
            break;
        }
    }
    return ret;
}

Status::Direction GetInput() {
    string s = "0";
    static map<string, Status::Direction> string_to_direction = {
        {"w", Status::W}, {"a", Status::A}, {"s", Status::S}, {"d", Status::D}};
    do {
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    } while (!string_to_direction.count(s));
    return string_to_direction[s];
}

void PlayGame(Status *status) {
    int kDirection = 4, kSize = status->size();
    status->OutputGraph();

    while (!status->IsWin()) {
        bool is_dead = true, is_same_status[kDirection] = {false};
        Status next_status[kDirection];
        int non_zeros = status->GetNonZeros();
        status->ChangePlayer();

        for (int i = 0; i < kDirection; ++i) {
            next_status[i] = *status;
            next_status[i].Update(Status::Direction(i));
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
        Status::Direction direction = GetInput();
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