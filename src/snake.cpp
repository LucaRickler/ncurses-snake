#include <snake.hpp>

SnakeCell::SnakeCell(int x, int y, int speedX, int speedY, Grid* grid) {
  this->_x = x;
  this->_y = y;
  this->SetSpeed(speedX, speedY);
  this->_grid = grid;
  this->_next = nullptr;

  this->_grid->SetCell(x,y, CellStatus::snake);
}

SnakeCell::~SnakeCell() {
  delete this->_next;
}

void SnakeCell::Update(bool replicate) {
  int new_x, new_y;
  new_x = this->_x + this->_speedX;
  new_y = this->_y + this->_speedY;
  
  CellStatus status = this->_grid->GetCell(new_x, new_y);
  switch (status) {
    case CellStatus::fruit:
      replicate = true;
      break;
    case CellStatus::wall:
      break;
    default: ;
  }

  this->_grid->SetCell(this->_x, this->_y, CellStatus::empty);

  if (this->_next != nullptr)
    this->_next->Update(replicate);
  else if (replicate)
    this->Replicate();

  
  this->_x = new_x;
  this->_y = new_y;

  this->_grid->SetCell(this->_x, this->_y, CellStatus::snake);

  if (this->_next != nullptr)
    this->_next->SetSpeed(this->_speedX, this->_speedY);
}

void SnakeCell::Replicate() {
  this->_next = new SnakeCell(
    this->_x,
    this->_y,
    this->_speedX,
    this->_speedY,
    this->_grid
  );
}

void SnakeCell::SetSpeed(int x, int y) {
  this->_speedX = x;
  this->_speedY = y;
}