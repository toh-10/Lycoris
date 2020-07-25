#include "Lycoris.hpp"

using namespace lycoris;

bool Dielectric::scatter(const Ray &r_in, const Hit &hit, vec3 &attenuation, Ray &scattered) const {
  attenuation = vec3(1.0, 1.0, 1.0);
  float etai_over_etat;
  if (hit.front_face) {
      etai_over_etat = 1.0 / m_ref_idx;
  } else {
      etai_over_etat = m_ref_idx;
  }

  vec3 unit_direction = normalize(r_in.direction());
  float cos_theta = fmin(dot(-unit_direction, hit.n), 1.0);
  float sin_theta = sqrt(1.0 - cos_theta*cos_theta);
  if (etai_over_etat * sin_theta > 1.0 ) {
      vec3 reflected = reflect(unit_direction, hit.n);
      scattered = Ray(hit.p, reflected);
      return true;
  }

  float reflect_prob = schlick(cos_theta, etai_over_etat);
  if (drand48() < reflect_prob)
  {
      vec3 reflected = reflect(unit_direction, hit.n);
      scattered = Ray(hit.p, reflected);
      return true;
  }

  vec3 refracted = refract(unit_direction, hit.n, etai_over_etat);
  scattered = Ray(hit.p, refracted);
  return true;
}

float Dielectric::schlick(float cosine, float ref_idx) const {
    auto r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0*r0;
    return r0 + (1-r0)*pow((1 - cosine),5);
}