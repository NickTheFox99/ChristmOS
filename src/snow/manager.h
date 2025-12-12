#include "snow.h"
#include <memory>
#include <vector>

namespace Snow {
class Manager {
public:
  Manager();
  void NewSnows(int snows);
  void NewSnow();
  void Update();
  void Draw();
  ~Manager();

private:
  std::vector<std::unique_ptr<Snow>> snows;
  void Kill(int pos);
  int frames = 0;
};
} // namespace Snow
