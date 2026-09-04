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

enum EntityColor
{
    white,
    red,
    blue,
};

const Color RaylibColors[] = {WHITE, RED, BLUE, GREEN};

struct EntityData
{
    std::vector<EntityPos> positions;
    std::vector<EntitySize> sizes;
    std::vector<EntityColor> Colors;
    std::vector<std::pair<int, int>> Chunks;
};

struct ChunkData
{

    std::vector<EntityPos> positions;
};

void CreateEntity(EntityData &Data, int EntityPosx, int EntityPosy, int Height, int Width, EntityColor color)
{
    Data.positions.push_back({EntityPosx, EntityPosy});
    Data.sizes.push_back({Height, Width});
    Data.Colors.push_back(color);
};

void DrawEntity(int id, EntityData &Data)
{
    DrawRectangle(Data.positions[id].x, Data.positions[id].y, Data.sizes[id].Height, Data.sizes[id].Width, RaylibColors[Data.Colors[id]]);
}

void CreateChunk(EntityData &Data, int chunkposX, int chunkposY, int chunkWidth, int chunkHeight, int Height, int Width, EntityColor color)
{

    Data.Chunks.push_back({chunkposX, chunkposY});
    int EntityPosx = chunkposX;
    int EntityPosy = chunkposY;

    int counterY = chunkHeight / Height;
    int counterX = chunkWidth / Width;

    for (int y = 0; y < counterY; y++)
    {
        for (int x = 0; x < counterX; x++)
        {
            Data.positions.push_back({EntityPosx, EntityPosy});
            Data.sizes.push_back({Height, Width});
            Data.Colors.push_back((EntityColor)GetRandomValue(0, 2));
            EntityPosx += Width;
        };
        EntityPosx = chunkposX;
        EntityPosy += Height;
    }
};

int main()
{

    EntityData Data;

    int chunkposee = 100;
    int chunkposeew = 100;
    CreateChunk(Data, chunkposee, chunkposeew, 320, 320, 32, 32, (EntityColor)GetRandomValue(0, 2));

    cout << Data.Chunks.size() << "\n";
    InitWindow(1920, 1080, "games");
    SetTargetFPS(60);

    Vector2 CameraPos{500, 500};
    Vector2 CameraOffset{GetScreenHeight() / 2, GetScreenWidth() / 2};
    Camera2D mainCamera{CameraOffset, CameraPos, 0, 1};

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(mainCamera);
        if (IsKeyDown(KEY_W))
        {
            mainCamera.target.y -= 10;
        };
        if (IsKeyDown(KEY_S))
        {
            mainCamera.target.y += 10;
        };
        if (IsKeyDown(KEY_A))
        {
            mainCamera.target.x -= 10;
        };
        if (IsKeyDown(KEY_D))
        {
            mainCamera.target.x += 10;
        };

        for (int i = 0; i < Data.positions.size(); i++)
        {
            DrawEntity(i, Data);
        }
        EndMode2D();
        DrawFPS(10, 10);
        EndDrawing();
    };
    CloseWindow();
    return 0;
};
