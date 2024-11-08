#include"simulation.hpp"

void Simulation::Draw(){
  grid.Draw();
}

void Simulation::SetCellValue(int row,int col,int value){
  grid.SetValue(row,col,value);
}

int Simulation::CountLiveNeighbors(int row,int col){
  int count=0;
  //top-left top top-right
  if(grid.GetValue(grid.GetRow(row-1),grid.GetCol(col-1)) == 1){
    count++;
  }
  if(grid.GetValue(grid.GetRow(row-1),grid.GetCol(col)) == 1){
    count++;
  }
  if(grid.GetValue(grid.GetRow(row-1),grid.GetCol(col+1)) == 1){
    count++;
  }
  //left right
  if(grid.GetValue(grid.GetRow(row),grid.GetCol(col-1)) == 1){
    count++;
  }
  if(grid.GetValue(grid.GetRow(row),grid.GetCol(col+1)) == 1){
    count++;
  }

  //bottom-left bottom bottom-right
  if(grid.GetValue(grid.GetRow(row+1),grid.GetCol(col-1)) == 1){
    count++;
  }
  if(grid.GetValue(grid.GetRow(row+1),grid.GetCol(col)) == 1){
    count++;
  }
  if(grid.GetValue(grid.GetRow(row+1),grid.GetCol(col+1)) == 1){
    count++;
  }
  
  return count;
}
//update the sim
void Simulation::Update(){
  if(run){
    for(int row=0;row<grid.GetRows();row++){
      for(int col = 0;col<grid.GetCols();col++){
	int liveNeighbors = CountLiveNeighbors(row,col);
	int cellValue = grid.GetValue(row,col);
	
	if(cellValue == 1){
	  if(liveNeighbors >3 || liveNeighbors<2){
	    tempGrid.SetValue(row,col,0);
	  }
	  else{
	    tempGrid.SetValue(row,col,1);
	  }
	}else{
	  if(liveNeighbors == 3 ){
	    tempGrid.SetValue(row,col,1);
	  }else{
	    tempGrid.SetValue(row,col,0);
	  }
	}
      }
    }
    grid = tempGrid;
  }
}
//clear cell
void Simulation::Clear(){
  grid.ClearGrid();
  tempGrid.ClearGrid();
}
