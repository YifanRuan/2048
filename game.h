#ifndef GAME_H_
#define GAME_H_

#include <bits/stdc++.h>
#include <unistd.h>

#include "status.h"

std::pair<int, int> GetArg(int argc, char *argv[]);

void PlayGame(Status *status);

// TODO: Check input availability
int ChooseMode();

#endif