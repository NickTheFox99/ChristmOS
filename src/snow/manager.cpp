#include "manager.h"
#include <memory>

namespace Snow {

Manager::Manager() = default;

void Manager::NewSnow() { std::make_unique<Snow>(); }
void Manager::Update() {}

} // namespace Snow
