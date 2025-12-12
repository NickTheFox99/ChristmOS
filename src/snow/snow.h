#include <raylib-cpp.hpp>
#include <sys/types.h>

namespace Snow {
class Snow {
public:
  Snow();
  Snow(int x);
  Snow(raylib::Vector2 pos);

  void Update();
  void Draw();
  bool IsAlive();

  ~Snow();

private:
  raylib::Vector2 position;
  int currCycle = 0;
  bool live = true;

  inline void Move();
  inline void CheckLive();
};
} // namespace Snow
