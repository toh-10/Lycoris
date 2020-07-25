#include "Lycoris.hpp"

using namespace lycoris;

bool Diffuse::scatter(const Ray &r_in, const Hit &hit, vec3 &attenuation, Ray &scattered) const {
  vec3 sccattered_direction = hit.n + random_in_unit_sphere();
  scattered = Ray(hit.p, sccattered_direction);
  attenuation = m_albedo;
  return true;
}
