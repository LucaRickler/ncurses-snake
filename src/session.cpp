#include <session.hpp>

Session::Session() {
  this->_gameOver = false;
  this->_points = 0;
}

Session::~Session() { }

void Session::SetGameOver() {
  this->_gameOver = true;
}

bool Session::GetGameOver() {
  return this->_gameOver;
}

void Session::AddPoint() {
  this->_points += 1;
}

int Session::GetPoints() {
  return this->_points;
}