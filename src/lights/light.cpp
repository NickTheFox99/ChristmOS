#include "light.h"
#include "../consts.cpp"
#include "Vector2.hpp"
#include "raylib.h"
#include <cstdio>

namespace Lights {
Light::Light(raylib::Vector2 position, raylib::Color color1,
             raylib::Color color2, int radius, LightState startingState,
             int startingCycle)
    : position(position), radius(radius), color1(color1), color2(color2),
      state(startingState), cycle(startingCycle) {};
Light::~Light() = default;

void Light::Update() {
  cycle++;
  if (cycle >= MAX_CYCLE_FRAMES) {
    SwitchState();
    cycle = 0;
  }
}

void Light::Draw() {
  raylib::Color col = (state == Lights::LightState::color1) ? color1 : color2;
  DrawCircleV(position, radius + 1, col.Alpha(0.5));
  DrawCircleV(position, radius, col);
}

Lights::LightState Light::SwitchState() {
  switch (state) {
  case Lights::LightState::color1:
    return state = Lights::LightState::color2;
  case Lights::LightState::color2:
    return state = Lights::LightState::color1;
  }
  return state;
}
} // namespace Lights
