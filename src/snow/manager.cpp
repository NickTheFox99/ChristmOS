#include "manager.h"
#include <memory>

namespace Snow {

Manager::Manager() = default;
Manager::~Manager() = default;

void Manager::NewSnow() { snows.emplace_back(new Snowflake()); }
void Manager::NewSnows(int count) {
  snows.reserve(snows.size() + count);
  for (int i = 0; i < count; i++)
    NewSnow();
}

void Manager::Update() {
  frames++;
  if (frames % 2 == 1)
    NewSnow();
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

void Manager::Kill(int pos) {
  std::swap(snows[pos], snows.back());
  snows.pop_back();
}

} // namespace Snow
