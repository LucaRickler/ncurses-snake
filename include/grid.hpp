#ifndef GRID_HPP
#define GRID_HPP

class Grid;

#include <string>
#include <snake.hpp>
#include <session.hpp>


const int GRID_MIN_WIDTH = 10;
const int GRID_MIN_HEIGHT = 10;

enum class CellStatus {empty, fruit, snake, wall};

class Grid {
public:
  Grid();
  Grid(int width, int height);
  virtual ~Grid();

  CellStatus GetCell(int x, int y);
  void SetCell(int x, int y, CellStatus status);

  void AddFruit();
  SnakeCell* AddSnake(Session* ssn);

  std::string Print();
private:
  int _width;
  int _height;
  CellStatus** _grid;

  void initGrid ();
  void FindEmpty (int& x, int& y);
};

#endif