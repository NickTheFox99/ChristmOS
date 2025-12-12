#include "manager.h"
#include <memory>

namespace Snow {

Manager::Manager() = default;
Manager::~Manager() = default;

void Manager::NewSnow() { snows.push_back(std::make_unique<Snow>()); }
void Manager::NewSnows(int snows) {
  for (int i = 0; i < snows; i++)
    NewSnow();
}

void Manager::Update() {
  for (auto snowi = 0; snowi < snows.size(); snowi++) {
    auto &snow = snows[snowi];
    if (!snow->IsAlive()) {
      Kill(snowi);
      continue;
    }
    snow->Update();
  }
}

void Manager::Draw() {
  for (auto snowi = 0; snowi < snows.size(); snowi++)
    snows[snowi]->Draw();
}

void Manager::Kill(uint pos) {
  std::swap(snows[pos], snows.back());
  snows.pop_back();
}

} // namespace Snow
