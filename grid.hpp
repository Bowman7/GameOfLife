#pragma once

#include<vector>

class Grid{
public:
  Grid(int width,int height,int cellSize)
    :g_rows(height/cellSize),g_cols(width/cellSize),g_cellSize(cellSize),
     cells(g_rows,std::vector<int>(g_cols,0)){}
  ~Grid(){}

  void Draw();
  void SetValue(int row,int col,int value);
  bool IsWithinBounds(int row,int col);
  int GetValue(int row,int col);
  int GetRow(int val);
  int GetCol(int val);
  int GetRows(){
    return g_rows;
  }
  int GetCols(){
    return g_cols;
  }
  //fill random
  void FillRandom();
  void ClearGrid();
  void TogglePosition(int row,int col);
private:
  int g_rows;
  int g_cols;
  int g_cellSize;

  //matrix
  std::vector<std::vector<int>> cells;

};
