#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <grid.hpp>
#include <session.hpp>

class SnakeCell {
public:
  SnakeCell(int x, int y, int speedX, int speedY, Grid* grid, Session* session);
  virtual ~SnakeCell();
  void Update(bool replicate);
  void Replicate();

  void SetSpeed(int x, int y);

  void SetHead();
private:
  int _x;
  int _y;
  int _speedX;
  int _speedY;

  bool _head;

  Grid* _grid;
  Session* _session;
  SnakeCell* _next;
};

#endif