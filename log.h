#ifndef LOG_H_
#define LOG_H_

#include "action_listener_interface.h"
#include "game.h"
#include <fstream>
#include <string>

class Log : public ActionListenerInterface {
  public:
    Log(Game *g);

    virtual ~Log();

    void ActionPerformed(std::string info);

  private:
    void Println(const std::string &log);
    std::ofstream fp_;
    Game *g_;
};

#endif // LOG_H_
