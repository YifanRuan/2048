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
            while (!(strlen(optarg) == 1 && optarg[0] >= '2' &&
                     optarg[0] <= '5')) {
                printf("Wrong size! Please input 2 or 3 or 4 or 5!\n");
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

Status::Direction GetInput(string *cheat, bool *can_cheat) {
    string s = "0";
    static map<string, Status::Direction> string_to_direction = {
        {"w", Status::W}, {"a", Status::A}, {"s", Status::S}, {"d", Status::D}};
    while (true) {
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (*can_cheat && s == "c") {
            cin >> *cheat;
            *can_cheat = false;
            printf("bingo!%s\n", cheat->c_str());
        } else if (string_to_direction.count(s)) {
            return string_to_direction[s];
        } else {
            printf("Wrong input format! Please input again: ");
        }
    }
}

void GetCheat(string cheat, Status::Direction direction) {
    string s = "0";
    static map<Status::Direction, char> direction_to_char = {
        {Status::W, 'w'}, {Status::A, 'a'}, {Status::S, 's'}, {Status::D, 'd'}};
    static map<string, Status::Direction> string_to_direction = {
        {"w", Status::W}, {"a", Status::A}, {"s", Status::S}, {"d", Status::D}};
    do {
        printf("[%s] please press %c: ", cheat.c_str(),
               direction_to_char[direction]);
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    } while (!string_to_direction.count(s) ||
             string_to_direction[s] != direction);
}

void PlayGame(Status *status) {
    constexpr int kDirection = 4;
    int game_size = status->size();
    Status::Mode game_mode = status->mode();
    string cheat[2];
    bool can_cheat[2] = {false, false};
    bool is_cheated[2] = {false, false};

    if (game_mode == Status::Dual)
        can_cheat[0] = can_cheat[1] = true;

    status->OutputGraph();

    while (!status->IsWin()) {
        bool is_dead = true, is_same_status[kDirection] = {false};
        Status next_status[kDirection];
        int non_zeros = status->GetNonZeros();
        status->ChangePlayer();
        int status_num = 0;
        Status::Direction last_direction;

        for (int i = 0; i < kDirection; ++i) {
            next_status[i] = *status;
            next_status[i].Update(Status::Direction(i));

            if (next_status[i] == *status) {
                is_same_status[i] = true;
            } else {
                ++status_num;
                last_direction = Status::Direction(i);
            }
            next_status[i].PickRandomNumber();
            if (non_zeros != game_size || !(next_status[i] == *status))
                is_dead = false;
        }

        if (is_dead) {
            status->PrintWinner();
            break;
        }

        status->OutputPlayer();
        Status::Direction direction;

        int player = status->current_player();
        if (status_num == 1 && !can_cheat[player ^ 1] && !is_cheated[player]) {
            is_cheated[player] = true;
            GetCheat(cheat[player], last_direction);
            direction = last_direction;
        } else {
            direction = GetInput(&cheat[player ^ 1], &can_cheat[player]);
        }

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