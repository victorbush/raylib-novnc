#include "raylib.h"

#include <stdexcept>

using namespace std;

/* ----------------------------------------------------------------------------
Constants
----------------------------------------------------------------------------- */

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

/* ----------------------------------------------------------------------------
Variables
----------------------------------------------------------------------------- */

Camera2D camera;

Texture2D catTexture;
int catX = (SCREEN_WIDTH / 2);
int catY = (SCREEN_HEIGHT / 2);

/* ----------------------------------------------------------------------------
Functions
----------------------------------------------------------------------------- */

/**
Update frame

Run any logic to compute the state of this frame, such
as user input, game state, and physics computations.
*/
void UpdateFrame()
{
    // TODO
}

/**
Draw frame

Draw any objects in the world or text on the screen based on their current
position/state.
*/
void DrawFrame()
{
    // Draw the cat
    DrawTexture(catTexture, catX, catY, WHITE);
}

/**
Program entry point.
*/
int main()
{
    /* ------------------------------------------------------------------------
    Initialization
    ------------------------------------------------------------------------- */

    // Scale things for high DPI monitors so we can see it
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    // Enable anti-aliasing
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    // Setup the application window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Example");

    // Set game to run at 60 frames-per-second
    SetTargetFPS(60);

    // Create a basic 2D camera
    camera.offset = {0, 0};
    camera.rotation = 0;
    camera.target = {0, 0};
    camera.zoom = 1.0f;

    // Load cat texture
    catTexture = LoadTexture("../assets/cat.png");
    if (!catTexture.id)
        throw new runtime_error("Failed to load cat texture.");

    /* ------------------------------------------------------------------------
    Main loop
    ------------------------------------------------------------------------- */

    // Main game loop
    while (!WindowShouldClose()) {
        UpdateFrame();

        // For simplicity, the drawing setup is not actually done in DrawFrame(), but
        // here instead. This is solely to eliminate confusion during the learning
        // process.
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        DrawFrame();
        EndMode2D();
        EndDrawing();
    }

    // Close window and OpenGL context
    CloseWindow();

    return 0;
}
