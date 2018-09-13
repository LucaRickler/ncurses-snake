#include <iostream>
#include <thread>
#include <chrono>
#include <signal.h>

#include <grid.hpp>

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

    grid.SetCell(2,2,CellStatus::fruit);

    ClearTerm();

    for (int i = 0;; i++) {
        cout << grid.Print() <<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
        ClearTerm();
    }
    return 0;
}
