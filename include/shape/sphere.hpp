#ifndef _SPHERE_HPP
#define _SPHERE_HPP

namespace lycoris {
class Sphere : public Shape {
public:
  Sphere(const vec3 &c, float r, std::shared_ptr<Material> m)
      : m_center(c), m_radius(r), m_material_ptr(m) {}

  bool intersect(const Ray &r, float t_min, float t_max,
                 Hit &hit) const override;

private:
  vec3 m_center;
  float m_radius;
  std::shared_ptr<Material> m_material_ptr;
};
} // namespace lycoris

#endif