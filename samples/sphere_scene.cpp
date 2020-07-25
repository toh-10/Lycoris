#include "Lycoris.hpp"

int main() {
  int width = 1000;
  int height = 500;
  int samples = 100;
  int max_bounce = 50;
  const char *filename = "render.bmp";
  std::unique_ptr<lycoris::Scene> scene(
      std::make_unique<lycoris::Scene>(width, height, filename, samples, max_bounce));
  scene->render();

  return 0;
}
