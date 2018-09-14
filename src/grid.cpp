#include <grid.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Grid::Grid() : Grid(GRID_MIN_WIDTH, GRID_MIN_HEIGHT) { }

Grid::Grid(int width, int height) {
  this->_width = width < GRID_MIN_WIDTH ? GRID_MIN_WIDTH : width;
  this->_height = height < GRID_MIN_HEIGHT ? GRID_MIN_HEIGHT : height;
  this->initGrid();
}

Grid::~Grid() {
  for(int i = 0; i < this->_height + 2; i++) {
    delete[] this->_grid[i];
  }
  delete this->_grid;
}

void Grid::initGrid() {
  this->_grid = new CellStatus*[this->_height + 2];
  for (int i = 0; i < this->_height + 2; i++) {
    this->_grid[i] = new CellStatus[this->_width + 2];
    for (int j = 0; j < this->_width + 2; j++) {
      if (i == 0 || i == this->_height + 1 || j == 0 || j == this->_width + 1)
        this->_grid[i][j] = CellStatus::wall;
      else
        this->_grid[i][j] = CellStatus::empty;
    }
  }
}

std::string Grid::Print() {
  std::string output = "";
  for (int i = 0; i < this->_height + 2; i++) {
    for (int j = 0; j < this->_width + 2; j++) {
      switch (this->_grid[i][j]) {
        case CellStatus::empty:
          output += " ";
          break;
        case CellStatus::snake:
          output += "S";
          break;
        case CellStatus::wall:
          output += "W";
          break;
        case CellStatus::fruit:
          output += "f";
          break;
      }
    }
    output += "\n";
  }
  return output;
}

CellStatus Grid::GetCell(int x, int y) {
  if (x >= 0 && x < this->_height +2 && y >= 0 && y < this->_width +2)
    return this->_grid[x][y];
  return CellStatus::empty; 
}

void Grid::SetCell(int x, int y, CellStatus status) {
  if (x >= 0 && x < this->_height +2 && y >= 0 && y < this->_width +2)
    this->_grid[x][y] = status;
}

void Grid::AddFruit() {
  int x,y;
  srand (time(NULL));
  do {
    x = rand() % this->_height +1;
    y = rand() % this->_width +1;
    std::cout << x << y <<std::endl;
  } while (this->GetCell(x, y) != CellStatus::empty);
  this->SetCell(x, y, CellStatus::fruit);
}

SnakeCell* Grid::AddSnake(Session* ssn) {
  int x,y;
  srand (time(NULL));
  do {
    x = rand() % this->_height - 3 +3;
    y = rand() % this->_width - 3 +3;
    std::cout << x << y <<std::endl;
  } while (this->GetCell(x, y) != CellStatus::empty);
  return new SnakeCell(
    x,y,
    1,0,this,ssn);
}

void Grid::FindEmpty(int& x, int& y) {
  srand (time(NULL));
  do {
    x = rand() % this->_height +1;
    y = rand() % this->_width +1;
    std::cout << x << y <<std::endl;
  } while (this->GetCell(x, y) != CellStatus::empty);
}