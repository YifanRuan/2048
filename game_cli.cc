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

void GameCli::NewGame() {
    printf("Welcome to 2048!\n");
    printf("Map size: %dx%d, End number: %d\n", g_->board().side(),
           g_->board().side(), g_->end_num());
    printf("Please input a positive integer as the number of players: ");
}

void GameCli::NewPlayer(int no) {
    printf("Please input name of player %d: ", no);
}

void GameCli::NewRound() {
    BoardToChange();
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
        delete stragety_;
        stragety_ = new Cheat{g_, g_->GetCurPlayer(), vec[1]};
        is_cheat = true;
    }
}

void GameCli::PointIncremented(int inc, Direction dir) { Prompt(); }

void GameCli::BoardToChange() {
    OutputGraph(g_->board());
    Prompt();
}

void GameCli::ToRetract(int freq) {
    printf("You have %d chances left. Retract? y/n\n", freq);
}

void GameCli::EndOfGame(bool status) {
    printf("Game over!\n");
    OutputGraph(g_->board());
    for (auto &it : g_->player()) {
        printf("%s: %d point(s).\n", it.name().c_str(), it.point());
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
    printf("\n");
    for (int i = 0; i < side; ++i) {
        OutputDivs();
        OutputNums(i);
    }
    OutputDivs();
}
