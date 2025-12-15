#include "snow.h"
#include "../consts.cpp"
#include "Color.hpp"
#include "Vector2.hpp"
#include <raylib.h>

namespace Snow {
Snowflake::Snowflake() : Snowflake(GetRandomValue(0, 320)) {}
Snowflake::Snowflake(int x) : Snowflake(raylib::Vector2(x, 0)) {}
Snowflake::Snowflake(raylib::Vector2 pos) : position(pos) {}

void Snowflake::Move() {
  raylib::Vector2 move;
  int hMove = GetRandomValue(0, INV_HORMOVE_CHANCE);
  if (hMove <= 1) {
    hMove = hMove * 2 - 1;
  } else {
    hMove = 0;
  }
  move.x = hMove;
  move.y = 1;
  position += move;
}

bool Snowflake::IsAlive() { return live; }

void Snowflake::CheckLive() {
  if (position.y >= SCREEN_HEIGHT) {
    live = false;
  }
}

void Snowflake::Update() {
  if (currCycle >= MAX_CYCLE_FRAMES) {
    Move();
    CheckLive();
    currCycle = 0;
    return;
  }
  currCycle++;
}

void Snowflake::Draw() { raylib::Color::White().DrawPixel(position); }

Snowflake::~Snowflake() = default;
} // namespace Snow
