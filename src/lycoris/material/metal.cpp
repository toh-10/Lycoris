#include "Lycoris.hpp"

using namespace lycoris;

Metal::Metal(const vec3 &a, float r) : m_albedo(a), m_roughness(r < 1 ? r : 1) {}

bool Metal::scatter(const Ray &r_in, const Hit &hit, vec3 &attenuation, Ray &scattered) const {
  vec3 reflected_direction = reflect(normalize(r_in.direction()), hit.n);
  scattered = Ray(hit.p, reflected_direction + m_roughness * random_in_unit_sphere());
  attenuation = m_albedo;
  return true;
}
