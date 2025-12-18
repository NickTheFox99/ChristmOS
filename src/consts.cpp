#include "Color.hpp"
#include <array>
#include <raylib.h>
#include <sys/types.h>

// SCREEN CONSTS
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 60;

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

namespace Snow {
const int MAX_CYCLE_FRAMES = 4;
const int INV_HORMOVE_CHANCE = 5;
} // namespace Snow

namespace Lights {
const int MAX_CYCLE_FRAMES = 30;
const std::array<Vector2, 9> POSITIONS{{{112, 68},
                                        {144, 60},
                                        {196, 64},
                                        {88, 124},
                                        {136, 124},
                                        {244, 120},
                                        {236, 168},
                                        {112, 112},
                                        {188, 116}}};
const raylib::Color col1 = raylib::Color::Green();
const raylib::Color col2 = raylib::Color::Red();
} // namespace Lights
