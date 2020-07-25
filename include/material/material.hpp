#ifndef MATERIAL_HPP
#define MATERIAL_HPP

namespace lycoris {
class Material {
public:
  virtual bool scatter(const Ray &r_in, const Hit &hit, vec3 &attenuation,
                       Ray &scattered) const = 0;
};
} // namespace lycoris

#endif