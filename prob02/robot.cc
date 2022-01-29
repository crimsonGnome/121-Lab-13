#include "robot.h"

#include <string>

#include "cpputils/graphics/image.h"

Robot::Robot(const std::string& filename1, const std::string& filename2)
    : filename1_(filename1), filename2_(filename2) {
  icon1_.Load(filename1_);
  icon2_.Load(filename2_);
}

void Robot::SetPosition(int x, int y) {
  x_ = x;
  y_ = y;
}

int Robot::GetX() const { return x_; }

int Robot::GetY() const { return y_; }

void Robot::Draw(graphics::Image& image) {
  mod_ = (mod_ + 1) % 2;
  DrawIconOnImage(mod_ ? icon1_ : icon2_, image);
}

void Robot::DrawIconOnImage(graphics::Image& icon, graphics::Image& image) {
  int width = icon.GetWidth();
  int height = icon.GetHeight();
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      int x = x_ + i - width / 2;
      int y = y_ + j - height / 2;
      if (y >= 0 && x >= 0 && x < image.GetWidth() && y < image.GetHeight()) {
        image.SetColor(x, y, icon.GetColor(i, j));
      }
    }
  }
}
