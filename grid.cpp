#include"grid.hpp"
#include"raylib.h"

void Grid::Draw(){
  for(int i=0;i<g_rows;i++){
    for(int j=0;j<g_cols;j++){
      Color color;
      if(cells[i][j] == 1){
	color = SKYBLUE;
      }else{
	color = BLACK;
      }

      //draw current rectangle
      DrawRectangle(j*g_cellSize,i*g_cellSize,
		    g_cellSize-1,g_cellSize-1,color);
    }
  }
}
//set value

void Grid::SetValue(int row,int col,int value){
  if(IsWithinBounds(row,col)){
    cells[row][col] = value;
  }
}
//check bounds
bool Grid::IsWithinBounds(int row,int col){
  if(row >= 0 && row < g_rows && col >= 0 && col < g_cols){
    return true;
  }
  return false;
}
//get value
int Grid::GetValue(int row,int col){
  if(IsWithinBounds(row,col)){
    return cells[row][col];
  }
  return 0;
}
//get row val toroidal
int Grid::GetRow(int val){
  int temp = (val+g_rows)%g_rows;
  return temp;
}
//get cols
int Grid::GetCol(int val){
  int temp = (val+g_cols)%g_cols;
  return temp;
}
//fll random val
void Grid::FillRandom(){
  for(int row=0;row<g_rows;row++){
    for(int col=0;col<g_cols;col++){
      int randomValue =GetRandomValue(0,4);
      cells[row][col]=(randomValue==4)?1:0;
      
    }
  }
}
//clear grid
void Grid::ClearGrid(){
  for(int row=0;row<g_rows;row++){
    for(int col=0;col<g_cols;col++){
      cells[row][col] = 0;
    }
  }
}
//toggle val
void Grid::TogglePosition(int row,int col){
  if(IsWithinBounds(row,col)){
    cells[row][col] = !cells[row][col];
  }
}
