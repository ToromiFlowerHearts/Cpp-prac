#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <optional>
using namespace std;


struct EntityPos
{
    int x;
    int y;
};

struct EntitySize
{
    int Height;
    int Width;
};

enum EntityColor {
white,
red,
blue,
};

const Color RaylibColors[] = { WHITE, RED, BLUE, GREEN };


struct EntityData
{
std::vector<EntityPos> positions;
std::vector<EntitySize> sizes;
std::vector<EntityColor> Colors;
};

struct ChunkData {

EntityData Chunk [10][10];

};


void CreateEntity(EntityData & Data, int EntityPosx, int EntityPosy, int Height, int Width, EntityColor color){
    Data.positions.push_back({EntityPosx,EntityPosy});
    Data.sizes.push_back({Height,Width});
    Data.Colors.push_back(color);
}; 



void DrawEntity(int id, EntityData & Data){
DrawRectangle(Data.positions[id].x, Data.positions[id].y, Data.sizes[id].Height, Data.sizes[id].Width, RaylibColors[Data.Colors[id]]);
}


void CreateChunk(EntityData & Data, int chunkposX, int chunkposY,int chunkWidth,int chunkHeight, int Height, int Width, EntityColor color ){
int EntityPosx = chunkposX;
int EntityPosy = chunkposY; 


int counterY = chunkHeight / Height;
int counterX = chunkWidth / Width;


for (int y = 0; y < counterY; y++){
    for (int x = 0; x < counterX; x++){
    Data.positions.push_back({EntityPosx,EntityPosy});
    Data.sizes.push_back({Height,Width});
    Data.Colors.push_back((EntityColor)GetRandomValue(0, 2));
    EntityPosx += Width;
    };
    EntityPosx = chunkposX;
    EntityPosy += Height;
}
};
int main(){

EntityData Data;

int chunkposee = 100; 
int chunkposeew = 100; 
for (int i = 0; i < 3; i++){
    chunkposee += 350;
    for (int i = 0; i < 3; i++){
CreateChunk(Data, chunkposee, chunkposeew, 320, 320, 32, 32,(EntityColor)GetRandomValue(0, 2));
            chunkposee += 350;

    }
    chunkposee = 100;
    chunkposeew += 350;
};

    InitWindow(1920, 1080, "games");
    SetTargetFPS(1000000);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);  


        for (int i = 0; i <  Data.positions.size(); i++){
        DrawEntity(i, Data); 
        }
        DrawFPS(10, 10);
        EndDrawing();
                    };
        CloseWindow();
       return 0;
};



// for (int i = 1; i < 10000; i++){
// int x = (GetRandomValue(0, 1000) / 32) * 32;
// int y = (GetRandomValue(0, 1000) / 32) * 32;
// CreateEntity(Data, x, y, 32, 32, (EntityColor)GetRandomValue(0, 2)); // ЦИКЛ СОЗДАНИЯ ЭНТИТИ 

// };


// СТАРЫЙ ЦИКЛ СОЗДАНИЯ ЭНТИТИ 