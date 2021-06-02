#include "game_cli.h"
using namespace std;

GameCli::GameCli(Game *g) : g_(g) { g_->AddObserver(this); }

GameCli::~GameCli() { g_->RemoveObserver(this); }

void GameCli::GameStart() { ; }

void GameCli::NewRound() {
    OutputGraph(g_->board());
    printf("It's %s's turn: ", g_->GetNextPlayer().name().c_str());
}

void GameCli::PointIncremented(int inc, Direction dir) {
    printf("\n%s has %d points now.\n\n", g_->GetCurPlayer().name().c_str(),
           g_->GetCurPlayer().point());
}

void GameCli::EndOfGame(bool status) {
    for (auto &it : g_->player()) {
        printf("%s: %d points.\n", it.name().c_str(), it.point());
    }
}

void GameCli::OutputGraph(const Board &board) {
    vector<int> value = board.value();
    int side = board.side();
    auto OutputDivs = [=] {
        for (int i = 0; i < side; ++i)
            printf("+-----");
        printf("+\n");
    };
    auto OutputNums = [&](int row) {
        for (int i = 0; i < side; ++i)
            printf("|%5d", value[side * row + i]);
        printf("|\n");
    };
    for (int i = 0; i < side; ++i) {
        OutputDivs();
        OutputNums(i);
    }
    OutputDivs();
}
