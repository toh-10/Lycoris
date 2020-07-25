#ifndef _MATH_HPP
#define _MATH_HPP

using namespace Vectormath::Aos;
typedef Vector3 vec3;
typedef Vector3 col3;

#include <float.h> // FLT_MIN, FLT_MAX
#define PI 3.14159265359f
#define PI2 6.28318530718f
#define RECIP_PI 0.31830988618f
#define RECIP_PI2 0.15915494f
#define LOG2 1.442695f
#define EPSILON 1e-6f
#define GAMMA_FACTOR 2.2f

inline float pow2(float x) { return x * x; }
inline float pow3(float x) { return x * x * x; }
inline float pow4(float x) { return x * x * x * x; }
inline float pow5(float x) { return x * x * x * x * x; }
inline float clamp(float x, float a, float b) {
  return x < a ? a : x > b ? b : x;
}
inline float saturate(float x) { return x < 0.f ? 0.f : x > 1.f ? 1.f : x; }
inline float recip(float x) { return 1.f / x; }
inline float mix(float a, float b, float t) {
  return a * (1.f - t) + b * t; /* return a + (b-a) * t; */
}
inline float step(float edge, float x) { return (x < edge) ? 0.f : 1.f; }
inline float smoothstep(float a, float b, float t) {
  if (a >= b)
    return 0.f;
  float x = saturate((t - a) / (b - a));
  return x * x * (3.f - 2.f * t);
}
inline float radians(float deg) { return (deg / 180.f) * PI; }
inline float degrees(float rad) { return (rad / PI) * 180.f; }
inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n;
}
inline vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
    auto cos_theta = dot(-uv, n);
    vec3 r_out_parallel =  etai_over_etat * (uv + cos_theta*n);
    vec3 r_out_perp = -sqrt(1.0 - lengthSqr(r_out_parallel)) * n;
    return r_out_parallel + r_out_perp;
}

#endif