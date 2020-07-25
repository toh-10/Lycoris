#include "Lycoris.hpp"

// #define NUM_THREAD 8

using namespace lycoris;

Scene::Scene(int width, int height, char const *filename, int samples, int max_bounce)
    : m_image(std::make_unique<Image>(width, height)), m_backgroundColor(0.2f),
      m_filename(filename), m_samples(samples), m_max_bounce(max_bounce) {}

void Scene::build() {
  // shape
  ShapeList *world = new ShapeList();
  std::shared_ptr diffuse1 = std::make_shared<Diffuse>(vec3(0.1, 0.1, 0.1));
  std::shared_ptr diffuse2 = std::make_shared<Diffuse>(vec3(0.7, 0.3, 0.3));
  std::shared_ptr metal1 = std::make_shared<Metal>(vec3(1, 1, 1), 0.02);
  std::shared_ptr metal2 = std::make_shared<Metal>(vec3(0.7, 0.5, 0.3), 0.1);
  std::shared_ptr glass = std::make_shared<Dielectric>(1.5);

  world->add(std::make_shared<Sphere>(vec3(0, -100.25, -1), 100, diffuse1));
  world->add(std::make_shared<Sphere>(vec3(-0.375, 0, -1), 0.25, diffuse2));
  world->add(std::make_shared<Sphere>(vec3(0.375, 0, -1), 0.25, glass));
  world->add(std::make_shared<Sphere>(vec3(1.125, 0, -1), 0.25, metal1));
  world->add(std::make_shared<Sphere>(vec3(-1.125, 0, -1), 0.25, metal2));
  m_world.reset(world);

  // camera
  vec3 w(-2.0f, -1.0f, -1.0f);
  vec3 u(4.0f, 0.0f, 0.0f);
  vec3 v(0.0f, 2.0f, 0.0f);
  m_camera = std::make_unique<Camera>(u, v, w);
}

vec3 Scene::color(const Ray ray, const Shape *world, int depth) {
  Hit hit;

  if (depth <= 0) return vec3(0);

  if (world->intersect(ray, 0.001, FLT_MAX, hit)) {
    Ray scattered;
    vec3 attenuation;
    vec3 col;
    if (hit.material_ptr->scatter(ray, hit, attenuation, scattered))
      col = color(scattered, world, depth - 1);
      return vec3(
        attenuation[0] * col[0],
        attenuation[1] * col[1],
        attenuation[2] * col[2]
      );
    return vec3(0);
  }

  return backgroundSky(ray.direction());
}

vec3 Scene::background() const { return m_backgroundColor; }

vec3 Scene::backgroundSky(const vec3 &v) const {
  float t = 0.5f * (normalize(v).getY() + 1.0f);
  vec3 sky_blue(0.5f, 0.7f, 1.0f);
  vec3 sky_white(1);
  return lerp(t, sky_white, sky_blue);
}

void Scene::render() {
  build();
  int nx = m_image->width();
  int ny = m_image->height();

#pragma omp parallel for schedule(dynamic, 1) num_threads(NUM_THREAD)
  for (int j = 0; j < ny; ++j) {
    std::cout << "Rendering (y = " << j << ") " << (100.0 * j / (ny - 1)) << "%"
              << std::endl;
    for (int i = 0; i < nx; ++i) {
      vec3 c(0);
      for (int s = 0; s < m_samples; ++s) {
        float u = float(i + drand48()) / float(nx);
        float v = float(j + drand48()) / float(ny);
        Ray r = m_camera->getRay(u, v);
        c += color(r, m_world.get(), m_max_bounce);
      }
      c /= m_samples;
      m_image->write_pixel(i, (ny - j - 1), c.getX(), c.getY(), c.getZ());
    }
  }

  m_image->export_image(m_filename);
}
