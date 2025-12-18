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
const std::array<Vector2, 9> POSITIONS{{{28, 17},
                                        {36, 15},
                                        {49, 16},
                                        {22, 31},
                                        {34, 31},
                                        {61, 30},
                                        {59, 42},
                                        {28, 28},
                                        {47, 29}}};
const raylib::Color col1 = raylib::Color::Green();
const raylib::Color col2 = raylib::Color::Red();
} // namespace Lights
