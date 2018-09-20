#include <curses.h>
#include <thread>
#include <chrono>
#include <signal.h>

#include <grid.hpp>
#include <snake.hpp>
#include <session.hpp>

void PrintGameOver(Session* ssn) {
    clear();
    endwin();
    printf("\n\tGAME OVER\n\n\tPoints: %d\n\n", ssn->GetPoints());
}

void SigIntHandler(int param) {
    refresh();
    endwin();
    exit(1);
}

int main() {
    //signal(SIGINT, SigIntHandler);
    initscr();
    raw();
    cbreak();
    keypad(stdscr, true);
    noecho();

    Grid grid;
    Session ssn;

    grid.AddFruit();
    grid.AddFruit();
    SnakeCell* s1 = grid.AddSnake(&ssn);
    s1->SetHead();

    for (int i= 0; !ssn.GetGameOver(); i++) {
        timeout(30);
        char c = getch();
        switch (c) {
            case 'a':
                s1->SetSpeed(0,-1);
                break;
            case 'd':
                s1->SetSpeed(0,1);
                break;
            case 'w':
                s1->SetSpeed(-1,0);
                break;
            case 's':
                s1->SetSpeed(1,0);
                break;
            case 'q':
                ssn.SetGameOver();
        }
        if(i%10 == 0) {
            clear();
            s1->Update(false);
            printw(grid.Print());
            printw("Points: %d", ssn.GetPoints());
            refresh();
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
    }
    delete s1;
    PrintGameOver(&ssn);
    return 0;
}
