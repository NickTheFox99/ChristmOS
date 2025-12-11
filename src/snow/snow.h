#include <raylib-cpp.hpp>
#include <sys/types.h>

namespace Snow {
class Snow {
public:
  Snow();
  Snow(uint x);
  Snow(raylib::Vector2 pos);

  void Update();
  void Draw();

  ~Snow();

private:
  raylib::Vector2 position;
  uint currCycle;
  uint maxCycle;
  bool live;

  inline void Move();
  inline void CheckLive();
};
} // namespace Snow
