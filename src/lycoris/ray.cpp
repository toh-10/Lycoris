#include "Lycoris.hpp"

using namespace lycoris;

Ray::Ray(const vec3 &o, const vec3 &dir) : m_origin(o), m_direction(dir) {}

const vec3 &Ray::origin() const { return m_origin; }
const vec3 &Ray::direction() const { return m_direction; }

vec3 Ray::at(float t) const { return m_origin + t * m_direction; }