#include "Lycoris.hpp"

using namespace lycoris;

class Shape {
public:
  virtual bool intersect(const Ray &ray, float t_min, float t_max,
                         Hit &hit) const = 0;
};
