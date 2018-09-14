#ifndef SESSION_HPP
#define SESSION_HPP

class Session {
public:
  Session();
  ~Session();
  void SetGameOver();
  bool GetGameOver();
  void AddPoint();
  int GetPoints();

private:
  int _points;
  bool _gameOver;
};

#endif