#include "cheat.h"
using namespace std;

void Cheat::OutputPrompt() {
    set<Direction> dirs = g_->board().AvailableDirections();
    if (!is_cheated_ && cheater_->name() != g_->GetCurPlayer()->name() &&
        dirs.size() == 1) {
        printf("%s Agree press '%c'\n", cheat_.c_str(),
               direction_to_char[*dirs.begin()]);
        is_cheated_ = true;
    } else {
        printf("It's %s's turn: ", g_->GetCurPlayer()->name().c_str());
    }
}
