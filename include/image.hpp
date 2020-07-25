#ifndef _IMAGE_HPP
#define _IMAGE_HPP

namespace lycoris {
class Image {
public:
  struct rgb {
    unsigned char r;
    unsigned char g;
    unsigned char b;
  };

  Image() : m_pixels(nullptr) {}
  Image(int w, int h);

  int width() const;
  int height() const;
  void *pixels() const;

  void write_pixel(int x, int y, float r, float g, float b);
  void export_image(const char* filename);

private:
  int m_width;
  int m_height;
  std::unique_ptr<rgb[]> m_pixels;
  float gamma_correction(float x);
};
} // namespace lycoris

#endif
