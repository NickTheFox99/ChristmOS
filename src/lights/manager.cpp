#include "manager.h"
#include "../consts.cpp"
#include <memory>

namespace Lights {

Manager::Manager() {
  int cycle = 0;
  lights.reserve(POSITIONS.size());
  for (const auto &position : POSITIONS) {
    lights.emplace_back(new Light(
        position, col1, col2, 4,
        (cycle % 2 == 0) ? LightState::color1 : LightState::color2, 0));
    cycle++;
  }
};
Manager::~Manager() = default;

void Manager::Update() {
  for (auto lighti = 0; lighti < lights.size(); lighti++) {
    auto &light = lights[lighti];
    light->Update();
  }
}

void Manager::Draw() {
  for (auto lighti = 0; lighti < lights.size(); lighti++)
    lights[lighti]->Draw();
}

} // namespace Lights
