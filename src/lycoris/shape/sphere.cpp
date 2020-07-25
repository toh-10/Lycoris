#include "Lycoris.hpp"

using namespace lycoris;

bool Sphere::intersect(const Ray &r, float t_min, float t_max, Hit &hit) const {
  vec3 oc = r.origin() - m_center;
  float a = dot(r.direction(), r.direction());
  float b = 2.0f * dot(oc, r.direction());
  float c = dot(oc, oc) - pow2(m_radius);
  float D = b * b - 4 * a * c;
  if (D > 0) {
    float root = sqrtf(D);
    float temp = (-b - root) / (2.0f * a);
    if (temp < t_max && temp > t_min) {
      hit.t = temp;
      hit.p = r.at(hit.t);
      vec3 outward_normal = (hit.p - m_center) / m_radius;
      hit.set_face_normal(r, outward_normal);
      hit.material_ptr = m_material_ptr;
      return true;
    }
    temp = (-b + root) / (2.0f * a);
    if (temp < t_max && temp > t_min) {
      hit.t = temp;
      hit.p = r.at(hit.t);
      vec3 outward_normal = (hit.p - m_center) / m_radius;
      hit.set_face_normal(r, outward_normal);
      hit.material_ptr = m_material_ptr;
      return true;
    }
  }

  return false;
};
