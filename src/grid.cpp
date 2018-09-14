#include <grid.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

Grid::Grid() : Grid(GRID_MIN_WIDTH, GRID_MIN_HEIGHT) { }

Grid::Grid(int width, int height) {
  this->_width = width < GRID_MIN_WIDTH ? GRID_MIN_WIDTH : width;
  this->_height = height < GRID_MIN_HEIGHT ? GRID_MIN_HEIGHT : height;
  this->initGrid();
  srand (time(NULL));
}

Grid::~Grid() {
  for(int i = 0; i < this->_height + 2; i++) {
    delete[] this->_grid[i];
  }
  delete this->_grid;
}

void Grid::initGrid() {
  this->_grid = new Cell*[this->_height + 2];
  for (int i = 0; i < this->_height + 2; i++) {
    this->_grid[i] = new Cell[this->_width + 2];
    for (int j = 0; j < this->_width + 2; j++) {
      if (i == 0 || i == this->_height + 1 || j == 0 || j == this->_width + 1)
        this->_grid[i][j] = Cell{CellStatus::wall,i,j};
      else
        this->_grid[i][j] = Cell{CellStatus::empty,i,j};
    }
  }
}

std::string Grid::Print() {
  std::string output = "";
  for (int i = 0; i < this->_height + 2; i++) {
    for (int j = 0; j < this->_width + 2; j++) {
      switch (this->_grid[i][j].status) {
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

Cell Grid::GetCell(int x, int y) {
  if (x >= 0 && x < this->_height +2 && y >= 0 && y < this->_width +2)
    return this->_grid[x][y];
  return Cell{}; 
}

void Grid::SetCellStatus(int x, int y, CellStatus status) {
  if (x >= 0 && x < this->_height +2 && y >= 0 && y < this->_width +2)
    this->_grid[x][y].status = status;
}

void Grid::AddFruit() {
  int x,y;
  this->FindEmpty(x,y,0,0);
  this->SetCellStatus(x, y, CellStatus::fruit);
}

SnakeCell* Grid::AddSnake(Session* ssn) {
  int x,y;
  this->FindEmpty(x,y,3,3);
  return new SnakeCell(
    x,y,
    1,0,this,ssn);
}

void Grid::FindEmpty(int& x, int& y, int x_padding, int y_padding) {
  do {
    x = rand() % (this->_height - x_padding) + x_padding + 1;
    y = rand() % (this->_width - y_padding) + y_padding + 1;
  } while (this->GetCell(x, y).status != CellStatus::empty);
}