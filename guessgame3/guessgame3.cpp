#include <iostream>
#include <raylib.h>
#include <string> 
using namespace std;

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Find the Common Element Game");
    SetTargetFPS(60);

    // Load background
    Texture2D backgroundImage = LoadTexture("bg.png");

    // Load level-specific textures
    Texture2D water1 = LoadTexture("water1.png");
    Texture2D water2 = LoadTexture("water2.png");
    Texture2D water3 = LoadTexture("water3.png");
    
    Texture2D chess1 = LoadTexture("chess1.png");
    Texture2D chess2 = LoadTexture("chess2.png");
    Texture2D chess3 = LoadTexture("chess3.png");
    
    Texture2D car1 = LoadTexture("car1.png");
    Texture2D car2 = LoadTexture("car2.png");
    Texture2D car3 = LoadTexture("car3.png");

    Texture2D love1 = LoadTexture("love1.png");
    Texture2D love2 = LoadTexture("love2.png");
    Texture2D love3 = LoadTexture("love3.png");

    Texture2D checkmate1 = LoadTexture("checkmate1.png");
    Texture2D checkmate2 = LoadTexture("checkmate2.png");
    Texture2D checkmate3 = LoadTexture("checkmate3.png");

    // Define level words
    string words[5] = { "water", "chess", "car", "love", "checkmate" };

    // Game loop
    int level = 0;
    int correctGuesses = 0;

    while (!WindowShouldClose() && level < 5) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
   
        DrawTexture(backgroundImage, 0, 0, WHITE);

        if (level == 0) {

            Rectangle srcRect = { 0, 0, water1.width, water1.height }; 
            Rectangle destRect = { 75, 100, 200, 200 }; 
            DrawTexturePro(water1, srcRect, destRect, { 0, 0 }, 0, WHITE);

        
            destRect.x = 300;
            DrawTexturePro(water2, srcRect, destRect, { 0, 0 }, 0, WHITE);

         
            destRect.x = 525;
            DrawTexturePro(water3, srcRect, destRect, { 0, 0 }, 0, WHITE);
        } 

        if (level == 1) {
           
            Rectangle srcRect = { 0, 0, chess1.width, chess1.height }; 
            Rectangle destRect = { 75, 100, 200, 200 };
            DrawTexturePro(chess1, srcRect, destRect, { 0, 0 }, 0, WHITE);


            destRect.x = 300;
            DrawTexturePro(chess2, srcRect, destRect, { 0, 0 }, 0, WHITE);

            destRect.x = 525;
            DrawTexturePro(chess3, srcRect, destRect, { 0, 0 }, 0, WHITE);
        }

        if (level == 2) {
        
            Rectangle srcRect = { 0, 0, car1.width, car1.height }; 
            Rectangle destRect = { 75, 100, 200, 200 }; 
            DrawTexturePro(car1, srcRect, destRect, { 0, 0 }, 0, WHITE);

            destRect.x = 300;
            DrawTexturePro(car2, srcRect, destRect, { 0, 0 }, 0, WHITE);

        
            destRect.x = 525;
            DrawTexturePro(car3, srcRect, destRect, { 0, 0 }, 0, WHITE);
        }

        if (level == 3) {

            Rectangle srcRect = { 0, 0, love1.width, love1.height }; 
            Rectangle destRect = { 75, 100, 200, 200 }; 
            DrawTexturePro(love1, srcRect, destRect, { 0, 0 }, 0, WHITE);

        
            destRect.x = 300;
            DrawTexturePro(love2, srcRect, destRect, { 0, 0 }, 0, WHITE);

            destRect.x = 525;
            DrawTexturePro(love3, srcRect, destRect, { 0, 0 }, 0, WHITE);
        }

        if (level == 4) {
      
            Rectangle srcRect = { 0, 0, checkmate1.width, checkmate1.height }; 
            Rectangle destRect = { 75, 100, 200, 200 };
            DrawTexturePro(checkmate1, srcRect, destRect, { 0, 0 }, 0, WHITE);

            destRect.x = 300;
            DrawTexturePro(checkmate2, srcRect, destRect, { 0, 0 }, 0, WHITE);

            destRect.x = 525;
            DrawTexturePro(checkmate3, srcRect, destRect, { 0, 0 }, 0, WHITE);
        }

        DrawText("Press enter to guess the word:", 250, 400, 20, WHITE);
        
        if (IsKeyPressed(KEY_ENTER)) {
            char input[64] = { 0 };
            // TODO: take input from the user (display text input or make a b c d variants)
            string userInput(input);
            if (userInput == words[level]) {
                level++;
                correctGuesses++;
            }
            else {
                DrawText("INCORRECT!", 300, 450, 20, RED);
            }
        }

        EndDrawing();
    }

    ClearBackground(RAYWHITE);
    DrawText("Game Over!", 300, 200, 40, BLACK);
    DrawText(("Correct Guesses: " + to_string(correctGuesses)).c_str(), 300, 250, 30, BLACK);

    CloseWindow();
    return 0;
}
