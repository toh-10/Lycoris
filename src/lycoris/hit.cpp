#include "Lycoris.hpp"

using namespace lycoris;

void Hit::set_face_normal(const Ray& ray, const vec3& outward_normal) {
  front_face = dot(ray.direction(), outward_normal) < 0;
  n = front_face ? outward_normal :-outward_normal;
}