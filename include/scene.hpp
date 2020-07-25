#ifndef _SCENE_HPP
#define _SCENE_HPP

#define NUM_THREAD 8

namespace lycoris {
class Scene {
public:
  Scene(int width, int height, char const *filename, int samples, int max_bounce);

  void build();

  float intersectSphere(const vec3 &center, const float &radius,
                        const Ray &ray) const;

  vec3 color(const Ray ray, const Shape *world, int depth);

  vec3 background() const;

  vec3 backgroundSky(const vec3 &v) const;

  void render();

private:
  std::unique_ptr<Camera> m_camera;
  std::unique_ptr<Image> m_image;
  std::unique_ptr<Shape> m_world;
  int m_samples;
  int m_max_bounce;
  vec3 m_backgroundColor;
  const char *m_filename;
};
} // namespace lycoris

#endif