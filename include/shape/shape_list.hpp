#ifndef _SHAPELIST_HPP
#define _SHAPELIST_HPP

#include <vector>

namespace lycoris {
class ShapeList : public Shape {
public:
  ShapeList() {}

  void add(const ShapePtr &shape);

  bool intersect(const Ray &r, float t_min, float t_max,
                 Hit &hit) const override;

private:
  std::vector<ShapePtr> m_list;
};
} // namespace lycoris

#endif