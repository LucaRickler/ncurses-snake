#include <curses.h>
#include <thread>
#include <chrono>
#include <signal.h>

#include <grid.hpp>
#include <snake.hpp>
#include <session.hpp>

void PrintGameOver(Session* ssn) {
    clear();
    printw("\n\tGAME OVER\n\n\tPoints: %d\n\n", ssn->GetPoints());
    refresh();
}

// void ClearTerm() {
//    printw("\033[2J\033[1;1H");
//    refresh();
// }

void SigIntHandler(int param) {
    //ClearTerm();
    refresh();
    endwin();
    exit(1);
}

int main() {
    //signal(SIGINT, SigIntHandler);
    initscr();
    raw();
    keypad(stdscr, true);
    noecho();

    Grid grid;
    Session ssn;

    grid.AddFruit();
    grid.AddFruit();
    SnakeCell* s1 = grid.AddSnake(&ssn);
    s1->SetHead();
    //ClearTerm();

    while (!ssn.GetGameOver()) {
        clear();
        s1->Update(false);
        printw(grid.Print());
        printw("Points: %d", ssn.GetPoints());
        std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
        //ClearTerm();
        refresh();
    }
    delete s1;
    PrintGameOver(&ssn);
    endwin();
    return 0;
}
