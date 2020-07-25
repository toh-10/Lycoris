#include "Lycoris.hpp"

using namespace lycoris;

void ShapeList::add(const ShapePtr &shape) { m_list.push_back(shape); }

bool ShapeList::intersect(const Ray &r, float t_min, float t_max,
                          Hit &hit) const {
  Hit temp_hit;
  bool intersect_anything = false;
  float closest_so_far = t_max;
  for (auto &shape : ShapeList::m_list) {
    if (shape->intersect(r, t_min, closest_so_far, temp_hit)) {
      intersect_anything = true;
      closest_so_far = temp_hit.t;
      hit = temp_hit;
    }
  }
  return intersect_anything;
};
