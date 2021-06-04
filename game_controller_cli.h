#ifndef GAME_CONTROLLER_CLI_H_
#define GAME_CONTROLLER_CLI_H_

#include "game_controller_interface.h"
#include <iostream>

class GameControllerCli : public GameControllerInterface {
  public:
    std::string GetInput() {
        using namespace std;
        string ret = "";
        while (ret.length() == 0)
            getline(cin, ret);
        return ret;
    }
};

#endif // GAME_CONTROLLER_CLI_H_
