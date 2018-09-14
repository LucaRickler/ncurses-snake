#ifndef GRID_HPP
#define GRID_HPP

class Grid;

#include <string>
#include <snake.hpp>
#include <session.hpp>


const int GRID_MIN_WIDTH = 10;
const int GRID_MIN_HEIGHT = 10;

enum class CellStatus {empty, fruit, snake, wall};

struct Cell {
public:
  CellStatus status;
  int x;
  int y;
};

class Grid {
public:
  Grid();
  Grid(int width, int height);
  virtual ~Grid();

  Cell GetCell(int x, int y);
  void SetCell(int x, int y, CellStatus status);

  void AddFruit();
  SnakeCell* AddSnake(Session* ssn);

  std::string Print();
private:
  int _width;
  int _height;
  Cell** _grid;

  void initGrid ();
  void FindEmpty (int& x, int& y, int x_padding, int y_padding);
};

#endif