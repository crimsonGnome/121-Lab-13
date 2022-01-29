// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "maze.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "robot.h"

// TODO: Implement LoadMap and GetElement
using std::cin, std::getline, std::ifstream, std::string;

MazeData::MazeData(string filename) {
  this->filename_ = filename;
  LoadMap();
}

void MazeData::LoadMap() {
  string line;
  ifstream mazeFile(filename_);
  int width = this->width_;
  int height = this->height_;
  int rowCount = 0;
  vector<vector<char>>& mapData = GetMapData();
  if (mazeFile.is_open()) {
    // If file exist set valid to true;
    mazeFile >> width;
    mazeFile >> height;
    this->width_ = width;
    this->height_ = height;
    string compare = "SX";
    while (mazeFile) {
      // Get each line
      // Create a temp vector to turn string into vector of char
      getline(mazeFile, line);
      vector<char> tempVec;
      // std::cout << line << std::endl;

      for (int i = 0; i < line.size(); i++) {
        // Loop through each char and push in into charachter
        if (line[i] == compare[0]) {
          this->startingRow_ = rowCount;
          this->startCol_ = i;
        }
        if (line[i] == compare[1]) {
          this->goalCol_ = i;
          this->goalRow_ = rowCount;
        }
        tempVec.push_back(line[i]);
      }
      if (line.size() != 0) {
        // std::cout << "Row Count:  " << rowCount << std::endl;
        rowCount++;
        mapData.push_back(tempVec);
      }
    }
    if (startingRow_ != -1 && goalRow_ != -1) {
      this->is_valid_ = true;
    } else {
      std::cout << "ran not valid\n";
    }
  } else {
    std::cout << "file not opening\n";
  }
}

MapObjectType MazeData::GetElement(int x, int y) {
  // Get Vector from class
  vector<vector<char>>& mapData = GetMapData();
  char value = mapData[x][y];
  std::cout << value;
  MapObjectType answer;
  // Compare value from vector to class
  switch (value) {
    case 'W':
      answer = kWall;
      break;
    case 'G':
      answer = kGround;
      break;
    case 'S':
      answer = kStart;
      break;
    case 'X':
      answer = kGoal;
      break;
    default:
      answer = kWall;
  }
  return answer;
}

void Maze::Start() {
  if (maze_data_->IsValid()) {
    map_ = std::move(std::make_unique<graphics::Image>(
        maze_data_->GetWidth() * kSizeMultiplier_,
        maze_data_->GetHeight() * kSizeMultiplier_));

    char_row_ = maze_data_->GetStartRow();
    char_col_ = maze_data_->GetStartCol();

    map_->AddAnimationEventListener(*this);
    map_->AddMouseEventListener(*this);
    map_->ShowUntilClosed("Maze");
  } else {
    std::cout << "Cannot start maze." << std::endl;
  }
}

void Maze::OnAnimationStep() {
  DrawMap();
  DrawCharacter();
  if (is_solved_) {
    map_->DrawText(10, 10, "Solved it!", 20, 255, 0, 0);
  }
  map_->Flush();
}

void Maze::MoveCharacter(Direction dir) {
  int new_row = char_row_;
  int new_col = char_col_;
  switch (dir) {
    case kUp:
      new_row -= 1;
      break;
    case kDown:
      new_row += 1;
      break;
    case kLeft:
      new_col -= 1;
      break;
    case kRight:
      new_col += 1;
  }
  if (new_col < 0 || new_col >= maze_data_->GetWidth() || new_row < 0 ||
      new_row >= maze_data_->GetHeight()) {
    return;
  } else if (maze_data_->GetElement(new_row, new_col) != kWall) {
    char_row_ = new_row;
    char_col_ = new_col;
    if (char_row_ == maze_data_->GetGoalRow() &&
        char_col_ == maze_data_->GetGoalCol()) {
      is_solved_ = true;
    }
  }
}

void Maze::OnMouseEvent(const graphics::MouseEvent& event) {
  if (!is_solved_) {
    if (event.GetMouseAction() == graphics::MouseAction::kPressed) {
      int image_offset = kSizeMultiplier_ / 2;
      if (event.GetX() > character_->GetX() + image_offset) {
        MoveCharacter(kRight);
      } else if (event.GetX() < character_->GetX() - image_offset) {
        MoveCharacter(kLeft);
      } else if (event.GetY() > character_->GetY() + image_offset) {
        MoveCharacter(kDown);
      } else if (event.GetY() < character_->GetY() - image_offset) {
        MoveCharacter(kUp);
      }
    }
  }
}

void Maze::DrawMap() const {
  for (int i = 0; i < maze_data_->GetHeight(); i++) {
    for (int j = 0; j < maze_data_->GetWidth(); j++) {
      graphics::Color color;
      switch (maze_data_->GetElement(i, j)) {
        case kWall:
          color = gray_;
          break;
        case kGround:
          color = white_;
          break;
        case kStart:
          color = green_;
          break;
        case kGoal:
          color = red_;
          break;
      }
      map_->DrawRectangle(j * kSizeMultiplier_, i * kSizeMultiplier_,
                          kSizeMultiplier_, kSizeMultiplier_, color);
    }
  }
}

void Maze::DrawCharacter() const {
  int image_offset = kSizeMultiplier_ / 2;
  character_->SetPosition(char_col_ * kSizeMultiplier_ + image_offset,
                          char_row_ * kSizeMultiplier_ + image_offset);
  character_->Draw(*(map_.get()));
}
