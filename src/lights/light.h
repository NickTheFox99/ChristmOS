#include "Color.hpp"
#include "Vector2.hpp"
namespace Lights {
enum LightState {
  color1,
  color2,
};

class Light {
public:
  Light(raylib::Vector2 position, raylib::Color color1, raylib::Color color2,
        int radius, LightState startingState, int startingCycle);

  void Update();
  void Draw();

  ~Light();

private:
  void SwitchState();

  raylib::Vector2 position;
  int radius;
  raylib::Color color1;
  raylib::Color color2;
  LightState state;
  int cycle;
};
} // namespace Lights
