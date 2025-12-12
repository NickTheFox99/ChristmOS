#include "snow.h"
#include "../consts.cpp"
#include "Color.hpp"
#include "Vector2.hpp"
#include <raylib.h>

namespace Snow {
Snow::Snow() : Snow(GetRandomValue(0, 320)) {}
Snow::Snow(int x) : Snow(raylib::Vector2(x, 0)) {}
Snow::Snow(raylib::Vector2 pos) : position(pos) {}

void Snow::Move() {
  raylib::Vector2 move;
  int hMove = GetRandomValue(0, INV_CHANCE);
  if (hMove <= 1) {
    hMove = hMove * 2 - 1;
  } else {
    hMove = 0;
  }
  move.x = hMove;
  move.y = 1;
  position += move;
}

bool Snow::IsAlive() { return live; }

void Snow::CheckLive() {
  if (position.y >= SCREEN_HEIGHT) {
    live = false;
  }
}

void Snow::Update() {
  if (currCycle >= MAX_SECS) {
    Move();
    CheckLive();
    currCycle = 0;
    return;
  }
  currCycle++;
}

void Snow::Draw() { raylib::Color::White().DrawPixel(position); }

Snow::~Snow() = default;
} // namespace Snow
