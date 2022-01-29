#include <string>

#include "cpputils/graphics/image.h"

#ifndef ROBOT_H
#define ROBOT_H

class Robot {
 public:
  Robot(const std::string& filename1_, const std::string& filename2_);
  void SetPosition(int x, int y);
  int GetX() const;
  int GetY() const;
  void Draw(graphics::Image& image);

 private:
  void DrawIconOnImage(graphics::Image& icon, graphics::Image& image);
  std::string filename1_;
  std::string filename2_;
  graphics::Image icon1_;
  graphics::Image icon2_;
  graphics::Color color_;
  int x_ = 0;
  int y_ = 0;
  int mod_ = 0;
};

#endif  // ROBOT_H
