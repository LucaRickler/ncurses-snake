#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

enum class CellStatus {empty, fruit, snake, wall};

struct Cell {
public:
  CellStatus status;
  int x;
  int y;
};

class Grid;
const int GRID_MIN_WIDTH = 10;
const int GRID_MIN_HEIGHT = 10;

class SnakeCell;
class Session;

#endif