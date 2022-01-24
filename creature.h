// Bruno Futino 
// 10/31/2021


#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;
  string Path;

public:
  Creature(int Row, int Col);
  string solve(Maze &Maze);
  bool atExit(const Maze &Maze) const;
  string goNorth();
  string goSouth();
  string goEast();
  string goWest();
};

#endif //ASS3_CREATURE_H
