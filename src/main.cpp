#include <iostream>
#include <thread>
#include <chrono>
#include <signal.h>

#include <grid.hpp>
#include <snake.hpp>

using std::cout;
using std::endl;

void PrintGameOver(Session* ssn) {
    cout << "\n\tGAME OVER\n\n\tPoints: " << ssn->GetPoints() << endl << endl;
}

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
    Session ssn;

    grid.AddFruit();
    grid.AddFruit();
    SnakeCell* s1 = grid.AddSnake(&ssn);

    //SnakeCell* s1 = new SnakeCell(3,3,1,0,&grid, &ssn);
    s1->SetHead();

    ClearTerm();

    while (!ssn.GetGameOver()) {
        s1->Update(false);
        cout << grid.Print() << "Points: " << ssn.GetPoints() << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
        ClearTerm();
    }
    PrintGameOver(&ssn);
    return 0;
}
