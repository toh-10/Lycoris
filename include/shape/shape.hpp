#ifndef _SHAPE_HPP
#define _SHAPE_HPP

namespace lycoris {

class Shape {
public:
  virtual bool intersect(const Ray &ray, float t_min, float t_max,
                         Hit &hit) const = 0;
};

typedef std::shared_ptr<Shape> ShapePtr;
} // namespace lycoris

#endif