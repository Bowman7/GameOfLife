#include<iostream>
#include"raylib/raylib.h"

#include"simulation.hpp"

#define WIDTH 1920
#define HEIGHT 1000
#define CELL_SIZE 25

int main(){

  //init
  InitWindow(WIDTH,HEIGHT,"window");
  int FPS = 12;
  SetTargetFPS(FPS);

  Simulation simulation(WIDTH,HEIGHT,CELL_SIZE);

  while(!WindowShouldClose()){

    //event handle
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
      Vector2 mousePos= GetMousePosition();
      int row = mousePos.y/CELL_SIZE;
      int col = mousePos.x/CELL_SIZE;
      if(!simulation.IsRunning()){
	simulation.TogglePosition(row,col);
      }
    }
    if(IsKeyPressed(KEY_ENTER)){
      simulation.Start();
    }else if(IsKeyPressed(KEY_SPACE)){
      simulation.Stop();
    }else if(IsKeyPressed(KEY_S)){
      FPS+=2;
      SetTargetFPS(FPS);
    }else if(IsKeyPressed(KEY_A)){
      FPS-=2;
      SetTargetFPS(FPS);
    }else if(IsKeyPressed(KEY_C)){
      if(!simulation.IsRunning()){
	simulation.Clear();
      }
    }else if(IsKeyPressed(KEY_R)){
      if(!simulation.IsRunning()){
	simulation.FillRandom();
      }
    }

    //update
    simulation.Update();

    //draw
    BeginDrawing();
    ClearBackground(BLUE);

    simulation.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
