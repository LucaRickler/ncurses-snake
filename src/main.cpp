#include <iostream>
#include <thread>
#include <chrono>
#include <signal.h>

#include <grid.hpp>
#include <snake.hpp>

using std::cout;
using std::endl;

void ClearTerm() {
    std::cout << "\033[2J\033[1;1H";
}

void SigIntHandler(int param) {
    ClearTerm();
    exit(1);
}

int main() {
    signal(SIGINT, SigIntHandler);

    Grid grid;
    SnakeCell* s1 = new SnakeCell(3,3,1,0,&grid);

    grid.SetCell(2,2,CellStatus::fruit);

    ClearTerm();

    for (int i = 0;; i++) {
        s1->Update(false);
        cout << grid.Print() <<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
        ClearTerm();
    }
    return 0;
}
