#ifndef METAL_HPP
#define METAL_HPP

namespace lycoris {
class Metal : public Material {
public:
  Metal(const vec3 &a, float r);

  bool scatter(const Ray &r_in, const Hit &hit, vec3 &attenuation,
                       Ray &scattered) const override;

  vec3 m_albedo;
  float m_roughness;
};
} // namespace lycoris

#endif