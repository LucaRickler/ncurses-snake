#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

void ClearTerm() {
    std::cout << "\033[2J\033[1;1H"; 
}

int main() {
    // ClearTerm();
    // for (int i=10; i>0; --i) {
    //     std::cout << "countdown: " << i << std::endl;
    //     std::this_thread::sleep_for (std::chrono::seconds(1));
    //     ClearTerm();
    // }
    // std::cout << "Lift off!\n";

    // return 0;
    ClearTerm();
    for (int i = 0;; i++) {    
        cout << "Cicle N " << i << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); 
        ClearTerm();
    }
    return 0;
}