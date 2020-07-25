#ifndef _RAY_HPP
#define _RAY_HPP

namespace lycoris {
class Ray {
public:
  Ray() {}
  Ray(const vec3 &o, const vec3 &dir);

  const vec3 &origin() const;
  const vec3 &direction() const;
  vec3 at(float t) const;

private:
  vec3 m_origin;    // 始点
  vec3 m_direction; // 方向（非正規化）
};
} // namespace lycoris

#endif