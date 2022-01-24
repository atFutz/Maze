// Bruno Futino 
// 10/31/2021
#include <iostream>
#include "creature.h"
#include "maze.h"


void test1() {
    Maze M("maze1.txt");
    // cout << m << endl;
    Creature C(4, 3);
    cout << "Maze 1" << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

void test2() {
    Maze M("maze2.txt");
    // cout << m << endl;
    Creature C(3, 20);
    cout << "Maze 2" << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}
void test3() {
    Maze M("maze3.txt");
    // cout << m << endl;
    Creature C(12, 15);
    cout << "Maze 3" << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}
void test4() {
    Maze M("maze4.txt");
    // cout << m << endl;
    Creature C(15, 20);
    cout << "Maze 4" << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}


int main() {
    // Testcases for the mazes given
    test1();
    test2();
    test3();
    test4();
    cout << "Done!" << std::endl;
    return 0;
}