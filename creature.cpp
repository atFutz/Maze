// Bruno Futino 
// 10/31/2021

#include "creature.h"

// Overloads << operator
// Prints current location of the creature
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  return Out << "Current location : " << Creature.Row<< ',' << Creature.Col << endl;
}

// Constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {
}

// Determines if the Creature is at the exit or not
// Returns true if it is, otherwise returns false
bool Creature::atExit(const Maze &Maze) const {
  if(Row == Maze.getExitRow() && Col == Maze.getExitColumn()){
    return true;
  }
  return false; 
}

// Recursive function to solve the maze
// Checks if creature is at the end of the maze
// If creature not at exit, it will look for a path
//It marks positions as path and visited
//If no path is found then "No solution" will be returned
string Creature::solve(Maze &Maze) {
  Maze.markAsPath(Row,Col);
  
  if(!atExit(Maze)){

    if(Maze.isClear(Row - 1,Col) && Row - 1 >= 0){ //checks north
      Path += goNorth();
      solve(Maze);
    }else if(Maze.isClear(Row,Col - 1) && Col - 1 >=0){ // checks west
      Path += goWest();
      solve(Maze);
    }else if(Maze.isClear(Row + 1, Col) && Row + 1 < Maze.getHeight()){ // checks south
      Path += goSouth();
      solve(Maze);
    }else if(Maze.isClear(Row, Col + 1) && Col + 1 < Maze.getWidth()){
      Path += goEast();
      solve(Maze);
    }


    if(Maze.getField(Row - 1,Col) == '*' && !atExit(Maze)){
      Path.pop_back();
      Row--;
      Maze.markAsVisited(Row + 1,Col);
    }else if(Maze.getField(Row,Col - 1) == '*'  && !atExit(Maze)){
      Path.pop_back();
      Maze.markAsVisited(Row,Col);
      Col--;
    }else if(Maze.getField(Row + 1,Col) == '*'  && !atExit(Maze)){
      Path.pop_back();
      Maze.markAsVisited(Row,Col);
      Row++;
    }else if(Maze.getField(Row,Col + 1) == '*'  && !atExit(Maze)){
      Path.pop_back();
      Maze.markAsVisited(Row,Col);
      Col++;
    }else if(!atExit(Maze)){
      return "No Solution";
    }
    solve(Maze);
  }
  return Path;
}

// Moves creature north and returns char 'N' to be added to path
string Creature::goNorth() {
  Row--;
  return "N";
}
// Moves creature west and returns char 'W' to be added to path
string Creature::goWest() {
  Col--;
  return "W";
}
// Moves creature east and returns char 'E' to be added to path
string Creature::goEast() {
  Col++;
  return "E";
}
// Moves creature south and returns char 'S' to be added to path
string Creature::goSouth() {
  Row++;
  return "S";
}