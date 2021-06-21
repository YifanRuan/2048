#ifndef ACTION_LISTENER_INTERFACE_H_
#define ACTION_LISTENER_INTERFACE_H_

#include <string>

class ActionListenerInterface {
  public:
    virtual void ActionPerformed(std::string) = 0;
};

#endif // ACTION_LISTENER_INTERFACE_H_
