#ifndef _HIT_HPP
#define _HIT_HPP

namespace lycoris {
class Material;
class Hit {
public:
  float t;
  vec3 p;
  vec3 n;
  std::shared_ptr<Material> material_ptr;
  bool front_face;

  void set_face_normal(const Ray& ray, const vec3& outward_normal);
};
} // namespace lycoris

#endif