#include "consts.cpp"
#include "snow/manager.h"
#include <raylib-cpp.hpp>
#include <raylib.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void MainLoop();

raylib::Window window(WIN_WIDTH, WIN_HEIGHT, "game",
                      FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

raylib::RenderTexture2D target(SCREEN_WIDTH, SCREEN_HEIGHT);

Snow::Manager sMgr;

int main(void) {
  window.SetMinSize({320, 240});
  window.SetTargetFPS(60);
  window.SetExitKey(KEY_BACKSPACE);

#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(MainLoop, 0, 1);
#else
  while (!window.ShouldClose() && !raylib::Keyboard::IsKeyDown(KEY_ESCAPE))
    MainLoop();
#endif

  window.Close();

  return 0;
}

void MainLoop() {
  {
    int winWidth = GetScreenWidth(), winHeight = GetScreenHeight();
    float scale =
        MIN((float)winWidth / SCREEN_WIDTH, (float)winHeight / SCREEN_HEIGHT);

    sMgr.Update();

    target.BeginMode();
    {
      ClearBackground(BLACK);
      sMgr.Draw();
    }
    target.EndMode();

    window.BeginDrawing();
    {
      ClearBackground(BLACK);
      target.GetTexture().Draw(
          raylib::Rectangle(0.0f, 0.0f, (float)SCREEN_WIDTH,
                            (float)-SCREEN_HEIGHT),
          raylib::Rectangle((winWidth - ((float)SCREEN_WIDTH * scale)) * 0.5f,
                            (winHeight - ((float)SCREEN_HEIGHT * scale)) * 0.5f,
                            (float)SCREEN_WIDTH * scale,
                            (float)SCREEN_HEIGHT * scale),
          raylib::Vector2(0, 0), 0.0f, WHITE);
    }
    window.EndDrawing();
  }
}
