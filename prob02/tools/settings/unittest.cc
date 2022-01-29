#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"
#include "../../cpputils/graphics/test/image_test_utils.h"
#include "../../maze.h"
using ::testing::HasSubstr;

TEST(MazeData, Getters) {
  MazeData your_maze_data("tools/settings/working.txt");
  your_maze_data.GetWidth();
  your_maze_data.GetHeight();
  your_maze_data.GetStartRow();
  your_maze_data.GetStartCol();
  your_maze_data.GetGoalRow();
  your_maze_data.GetGoalCol();
  your_maze_data.IsValid();  
}

TEST(LoadMap, MapFileDoesNotExist) {
  MazeData your_maze_data("tools/settings/nonexistent.txt");
  ASSERT_FALSE(your_maze_data.IsValid());
}

TEST(LoadMap, MapDimensions1) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_EQ(4, your_maze_data.GetWidth()) << "    Take note that the width of the map"
      " is on the first line of the file.";
  ASSERT_EQ(3, your_maze_data.GetHeight()) << "    Take note that the height of the map"
      " is on the second line of the file."; 
}

TEST(LoadMap, MapDimensions2) {
  MazeData your_maze_data("tools/settings/working2.txt");
  ASSERT_EQ(3, your_maze_data.GetWidth()) << "    Take note that the width of the map"
      " is on the first line of the file.";
  ASSERT_EQ(5, your_maze_data.GetHeight()) << "    Take note that the height of the map"
      " is on the second line of the file."; 
}

TEST(LoadMap, StartLoc1) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_EQ(0, your_maze_data.GetStartRow()) << "    The start row is the row you find the"
      " 'S' character in the file. Remember indices start with 0.";
  ASSERT_EQ(3, your_maze_data.GetStartCol()) << "    The start column is the column you find the"
      " 'S' character in the file. Remember indices start with 0.";
}

TEST(LoadMap, StartLoc2) {
  MazeData your_maze_data("tools/settings/working2.txt");
  ASSERT_EQ(3, your_maze_data.GetStartRow()) << "    The start row is the row you find the"
      " 'S' character in the file. Remember indices start with 0.";
  ASSERT_EQ(0, your_maze_data.GetStartCol()) << "    The start column is the column you find the"
      " 'S' character in the file. Remember indices start with 0.";
}

TEST(LoadMap, GoalLoc1) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_EQ(1, your_maze_data.GetGoalRow()) << "    The start row is the row you find the"
      " 'S' character in the file. Remember indices start with 0.";
  ASSERT_EQ(1, your_maze_data.GetGoalCol()) << "    The start column is the column you find the"
      " 'S' character in the file. Remember indices start with 0.";
}

TEST(LoadMap, GoalLoc2) {
  MazeData your_maze_data("tools/settings/working2.txt");
  ASSERT_EQ(1, your_maze_data.GetGoalRow()) << "    The start row is the row you find the"
      " 'S' character in the file. Remember indices start with 0.";
  ASSERT_EQ(2, your_maze_data.GetGoalCol()) << "    The start column is the column you find the"
      " 'S' character in the file. Remember indices start with 0.";
}

TEST(LoadMap, NoStart) {
  MazeData your_maze_data("tools/settings/nostart.txt");
  ASSERT_FALSE(your_maze_data.IsValid()) << "    LoadMap should check if the file contains"
      " a start element indicated by an 'S'.";  
}

TEST(LoadMap, NoGoal) {
  MazeData your_maze_data("tools/settings/nogoal.txt");
  ASSERT_FALSE(your_maze_data.IsValid()) << "    LoadMap should check if the file contains"
      " a goal element indicated by a 'G'.";
}

TEST(LoadMap, Valid) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_TRUE(your_maze_data.IsValid()) << "    Maps that contain a 'S' and 'X' character"
      " are considered valid.";
}

TEST(GetElement, kWall) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_EQ(kWall, your_maze_data.GetElement(0, 0)) << "    The function should return kWall"
      " for 'W' elements.";
  ASSERT_EQ(kWall, your_maze_data.GetElement(0, 1)) << "    The function should return kWall"
      " for 'W' elements.";
  ASSERT_EQ(kWall, your_maze_data.GetElement(0, 2)) << "    The function should return kWall"
      " for 'W' elements.";
  ASSERT_EQ(kWall, your_maze_data.GetElement(2, 3)) << "    The function should return kWall"
      " for 'W' elements.";
}

TEST(GetElement, kGround) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_EQ(kGround, your_maze_data.GetElement(1, 0)) << "    The function should return kGround"
      " for 'G' elements.";
  ASSERT_EQ(kGround, your_maze_data.GetElement(1, 2)) << "    The function should return kGround"
      " for 'G' elements.";
  ASSERT_EQ(kGround, your_maze_data.GetElement(1, 3)) << "    The function should return kGround"
      " for 'G' elements.";
  ASSERT_EQ(kGround, your_maze_data.GetElement(2, 0)) << "    The function should return v"
      " for 'G' elements.";
  ASSERT_EQ(kGround, your_maze_data.GetElement(2, 1)) << "    The function should return v"
      " for 'G' elements.";
  ASSERT_EQ(kGround, your_maze_data.GetElement(2, 2)) << "    The function should return v"
      " for 'G' elements.";
}

TEST(GetElement, kStart1) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_EQ(kStart, your_maze_data.GetElement(0, 3)) << "    The function should return kStart"
      " for 'S' elements.";
}

TEST(GetElement, kStart2) {
  MazeData your_maze_data("tools/settings/working2.txt");
  ASSERT_EQ(kStart, your_maze_data.GetElement(3, 0)) << "    The function should return kStart"
      " for 'S' elements.";
}

TEST(GetElement, kGoal1) {
  MazeData your_maze_data("tools/settings/working.txt");
  ASSERT_EQ(kGoal, your_maze_data.GetElement(1, 1)) << "    The function should return kGoal"
      " for 'X' elements.";
}

TEST(GetElement, kGoal2) {
  MazeData your_maze_data("tools/settings/working2.txt");
  ASSERT_EQ(kGoal, your_maze_data.GetElement(1, 2)) << "    The function should return kGoal"
      " for 'X' elements.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++)
  {
    if (std::string(argv[i]) == "--noskip")
    {
      skip = false;
    }
  }
  if (skip)
  {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
