#include "game.h"
#include "status.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
  srand(unsigned(time(NULL)));
  Status status;
  if (argc > 1 && strcasecmp(argv[1], "-t") == 0)
    status = Status(64);
  PlayGame(&status);
  return 0;
}