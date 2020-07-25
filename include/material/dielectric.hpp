#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP

namespace lycoris {
class Dielectric : public Material {
public:
  Dielectric(float ri) : m_ref_idx(ri) {}

  bool scatter(const Ray &r_in, const Hit &hit, vec3 &attenuation,
                       Ray &scattered) const override;
  
  float schlick(float cosine, float ref_idx) const;

  float m_ref_idx;
};
} // namespace lycoris

#endif