#include "light.h"
#include <memory>
#include <vector>

namespace Lights {
class Manager {
public:
  Manager();
  void Update();
  void Draw();
  ~Manager();

private:
  std::vector<std::unique_ptr<Light>> lights;
};
} // namespace Lights
