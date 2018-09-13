#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <grid.hpp>

class SnakeCell {
public:
  SnakeCell(int x, int y, int speedX, int speedY, Grid* grid);
  virtual ~SnakeCell();
  void Update(bool replicate);
  void Replicate();

  void SetSpeed(int x, int y);
private:
  int _x;
  int _y;
  int _speedX;
  int _speedY;

  Grid* _grid;
  SnakeCell* _next;
};

#endif