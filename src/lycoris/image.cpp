#include "Lycoris.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stb/stb_image.h>
#include <stb/stb_image_write.h>

using namespace lycoris;

Image::Image(int w, int h) {
  m_width = w;
  m_height = h;
  m_pixels.reset(new rgb[m_width * m_height]);
}

int Image::width() const { return m_width; }
int Image::height() const { return m_height; }
void *Image::pixels() const { return m_pixels.get(); }

void Image::write_pixel(int x, int y, float r, float g, float b) {
  int index = m_width * y + x;
  m_pixels[index].r = static_cast<unsigned char>(gamma_correction(r) * 255.99f);
  m_pixels[index].g = static_cast<unsigned char>(gamma_correction(g) * 255.99f);
  m_pixels[index].b = static_cast<unsigned char>(gamma_correction(b) * 255.99f);
}

void Image::export_image(const char* filename) {
  stbi_write_bmp(filename, m_width, m_height, sizeof(rgb), m_pixels.get());
}

float Image::gamma_correction(float x) {
  return std::pow(x, 1 / GAMMA_FACTOR);
}