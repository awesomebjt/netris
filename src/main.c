#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <raylib.h>
#include <raygui.h>
#include <raymath.h>
#include <rlgl.h>
#include <stdlib.h>
#include <time.h>

Camera3D cam = {0};
enum Screen {
    TITLE = 0,
    SETTINGS = 1,
    NETWORK = 2,
    MULTIPLAYER = 3,
    SOLO = 4,
    CREDITS = 5
};



int main(void)
{
    InitWindow(1280, 720, "NETRIS");
    SetTargetFPS(60);
    cam.position = (Vector3){2, 3, -5};
    cam.target = (Vector3){0,1,0};
    cam.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    //Mesh cubeMesh[244];
    Mesh cubeMesh = GenMeshCube(1,1,1);
    Model cubeModel = LoadModelFromMesh(cubeMesh);

    while (!WindowShouldClose()) {
        // Detect keystrokes

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("NETRIS", 20, 20, 40, LIGHTGRAY);
            GuiButton((Rectangle){20, 80, 100, 30}, "I'm a button :) ");
            BeginMode3D(cam);
                cubeModel.transform = MatrixMultiply(MatrixRotateY(0.1f * DEG2RAD), cubeModel.transform);
                DrawModelEx(cubeModel,
                        (Vector3){0,0.5,0},
                     (Vector3){0,1,0},
                    0.1f,
                          (Vector3){1,1,1},
                               RED);
                DrawModelWires(cubeModel, (Vector3){0,0.5,0}, 1.0f, BLACK);
                DrawGrid(100, 0.5f);
            EndMode3D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
