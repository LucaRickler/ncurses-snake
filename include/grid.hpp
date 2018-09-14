#ifndef GRID_HPP
#define GRID_HPP


#include <string>
#include <definitions.hpp>

class Grid {
public:
  Grid();
  Grid(int width, int height);
  virtual ~Grid();

  Cell GetCell(int x, int y);
  void SetCellStatus(int x, int y, CellStatus status);

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