#ifndef _CAMERA_HPP
#define _CAMERA_HPP

namespace lycoris {
class Camera {
public:
  Camera() {}
  Camera(const vec3 &u, const vec3 &v, const vec3 &w);
  Camera(const vec3 &lookfrom, const vec3 &lookat, const vec3 &vup, float vfov,
         float aspect);

  Ray getRay(float u, float v) const;

private:
  vec3 m_origin; // 位置
  vec3 m_uvw[3]; // 直交基底ベクトル
};
} // namespace lycoris

#endif