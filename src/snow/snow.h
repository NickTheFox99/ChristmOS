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
  bool IsAlive();

  ~Snow();

private:
  raylib::Vector2 position;
  uint currCycle;
  bool live;

  inline void Move();
  inline void CheckLive();
};
} // namespace Snow
