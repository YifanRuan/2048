#ifndef GAME_OBSERVER_INTERFACE_H_
#define GAME_OBSERVER_INTERFACE_H_

class GameObserverInterface {
  public:
    virtual void GameStart() = 0;
    virtual void NewRound() = 0;
    virtual void PointIncremented(int inc) = 0;
    virtual void EndOfGame(bool status) = 0;
};

#endif // GAME_OBSERVER_INTERFACE_H_
