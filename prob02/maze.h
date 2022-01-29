// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <memory>
#include <string>
#include <vector>

#include "cpputils/graphics/image.h"
#include "robot.h"

using std::string, std::vector;

const graphics::Color red_(255, 0, 0);
const graphics::Color white_(255, 255, 255);
const graphics::Color gray_(128, 128, 128);
const graphics::Color green_(0, 255, 0);

enum MapObjectType { kWall, kGround, kGoal, kStart };
enum Direction { kUp, kDown, kLeft, kRight };

class MazeData {
 private:
  string filename_;
  int width_;
  int height_;
  int startingRow_ = -1;
  int startCol_;
  int goalCol_;
  int goalRow_ = -1;
  bool is_valid_ = false;
  vector<vector<char>> map_data_;

  // memeber functions
  void LoadMap();

 public:
  // Constructor
  MazeData(string filename);

  // Getters
  vector<vector<char>>& GetMapData() { return map_data_; };
  int GetWidth() const { return width_; };
  int GetHeight() const { return height_; };
  int GetStartRow() const { return startingRow_; };
  int GetStartCol() const { return startCol_; };
  int GetGoalRow() const { return goalRow_; };
  int GetGoalCol() const { return goalCol_; };
  bool IsValid() const { return is_valid_; };

  // PUblic Function
  MapObjectType GetElement(int x, int y);
};

class Maze : public graphics::AnimationEventListener,
             public graphics::MouseEventListener {
 public:
  Maze(const std::string& filename) : Maze(filename, 40) {}
  Maze(const std::string& filename, int size_multiplier)
      : maze_data_(std::make_unique<MazeData>(filename)),
        character_(std::make_unique<Robot>("robot1.bmp", "robot2.bmp")),
        char_row_(0),
        char_col_(0),
        is_solved_(false),
        kSizeMultiplier_(size_multiplier) {}
  void Start();
  void OnAnimationStep() override;
  void OnMouseEvent(const graphics::MouseEvent& event) override;

 private:
  void DrawMap() const;
  void DrawCharacter() const;
  void MoveCharacter(Direction dir);

  int kSizeMultiplier_;
  int char_row_;
  int char_col_;
  bool is_solved_;
  std::unique_ptr<Robot> character_;
  std::unique_ptr<MazeData> maze_data_;
  std::unique_ptr<graphics::Image> map_;
};
