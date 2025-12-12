#include "snow.h"
#include <memory>
#include <vector>

namespace Snow {
class Manager {
public:
  Manager();
  void NewSnow();
  void Update();
  void Draw();
  ~Manager();

private:
  std::vector<std::unique_ptr<Snow>> snows;
  void Kill(uint pos);
};
} // namespace Snow
