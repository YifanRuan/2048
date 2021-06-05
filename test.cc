#include "test.h"
#include "board.h"
#include "direction.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>

using namespace std;

void Test(int argc, const char *argv[]) {
    srand(unsigned(time(nullptr)));

    if (argc > 4) {
        freopen(argv[2], "r", stdin);
        freopen(argv[4], "w", stdout);
    }
    int k;
    scanf("%d", &k);
    vector<int> value(k * k);
    for (int i = 0; i < k * k; ++i) {
        scanf("%d", &value[i]);
    }
    char c = getchar();
    while (!char_to_direction.count(c))
        c = getchar();
    Direction dir = char_to_direction[c];

    Board board(value, k);
    set<Direction> avail_dir = board.AvailableDirections();
    printf("%lu", avail_dir.size());
    for (auto it : avail_dir) {
        printf(" %c", direction_to_char[it]);
    }
    putchar('\n');
    int point = board.Move(dir, &board).first;
    value = board.value();
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            printf("%d%c", value[i * k + j], j == k - 1 ? '\n' : ' ');
        }
    }
    pair<int, int> pos = board.PickRandomNumber();
    if (pos.first != -1 && pos.second != -1) {
        printf("2\n%d %d\n", pos.first, pos.second);
    }
    printf("%d\n", point);
    fclose(stdin);
    fclose(stdout);
}
