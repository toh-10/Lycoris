#ifndef DIFFUSE_HPP
#define DIFFUSE_HPP

namespace lycoris {
class Diffuse : public Material {
public:
  Diffuse(const vec3 &a) : m_albedo(a) {}

  bool scatter(const Ray &r_in, const Hit &hit, vec3 &attenuation,
                       Ray &scattered) const override;

  vec3 m_albedo;
};
} // namespace lycoris

#endif