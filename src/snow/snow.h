#include <raylib-cpp.hpp>
#include <sys/types.h>

namespace Snow {
class Snowflake {
public:
  Snowflake();
  Snowflake(int x);
  Snowflake(raylib::Vector2 pos);

  void Update();
  void Draw();
  bool IsAlive();

  ~Snowflake();

private:
  raylib::Vector2 position;
  int currCycle = 0;
  bool live = true;

  inline void Move();
  inline void CheckLive();
};
} // namespace Snow
