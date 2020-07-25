#ifndef _RANDOM_HPP
#define _RANDOM_HPP

inline vec3 random_vector() { return vec3(drand48(), drand48(), drand48()); }

inline vec3 random_in_unit_sphere() {
  vec3 p;
  do {
    p = 2.f * random_vector() - vec3(1.f);
  } while (lengthSqr(p) >= 1.f);
  return p;
}

#endif