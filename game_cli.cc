#include "game_cli.h"
#include "cheat.h"
#include "cli_strategy.h"
#include <sstream>
using namespace std;

GameCli::GameCli(Game *g) : g_(g) {
    g_->AddObserver(this);
    stragety_ = new CliStrategy{g_};
}

GameCli::~GameCli() {
    g_->RemoveObserver(this);
    delete stragety_;
}

void GameCli::GameInfo() {
    // OutputGraph(g_->board());
}

void GameCli::NewRound() {
    OutputGraph(g_->board());
    stragety_->OutputPrompt();
}

void GameCli::ProcessCommand(string cmd) {
    if (is_cheat)
        return;
    stringstream ss;
    ss.str(cmd);
    vector<string> vec;
    while (true) {
        string tmp;
        ss >> tmp;
        if (ss.fail())
            break;
        vec.push_back(tmp);
    }
    if (vec.size() >= 2 && vec[0] == "c") {
        // Debug
        delete stragety_;
        stragety_ = new Cheat{g_, g_->GetCurPlayer(), vec[1]};
        is_cheat = true;
    }
}

void GameCli::PointIncremented(int inc, Direction dir) {
    printf("\n%s has %d points now.\n\n", g_->GetCurPlayer()->name().c_str(),
           g_->GetCurPlayer()->point());
}

void GameCli::EndOfGame(bool status) {
    OutputGraph(g_->board());
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
