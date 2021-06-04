#ifndef GAME_CONTROLLER_INTERFACE_H_
#define GAME_CONTROLLER_INTERFACE_H_

#include <string>

class GameControllerInterface {
  public:
    virtual std::string GetInput() = 0;
};
#endif
