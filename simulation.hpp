#pragma once

#include"grid.hpp"


class Simulation{
public:
  Simulation(int width,int height,int cellSize)
    :grid(width,height,cellSize),
     tempGrid(width,height,cellSize),
     run(false)
  {
    grid.FillRandom();
  }

  void Draw();
  void SetCellValue(int row,int col,int value);
  int CountLiveNeighbors(int row,int col);

  void Update();
  void Start(){
    run = true;
  }
  void Stop(){
    run = false;
  }
  void Clear();
  bool IsRunning(){
    return run;
  }
  void FillRandom(){
    grid.FillRandom();
  }
  void TogglePosition(int row,int col){
    
    grid.TogglePosition(row,col);
  }
private:
  Grid grid;
  Grid tempGrid;
  bool run;
  
};
