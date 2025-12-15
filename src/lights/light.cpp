#include "light.h"
#include "../consts.cpp"
#include "Vector2.hpp"

namespace Lights {
Light::Light(raylib::Vector2 position, raylib::Color color1,
             raylib::Color color2, int radius, LightState startingState,
             int startingCycle)
    : position(position), radius(radius), color1(color1), color2(color2),
      state(startingState), cycle(startingCycle) {};

void Light::Update() {
  cycle++;
  if (cycle >= MAX_CYCLE_FRAMES)
    SwitchState();
}

void Light::SwitchState() {
  switch (state) { case Lights::LightState::color1: }
}
} // namespace Lights
