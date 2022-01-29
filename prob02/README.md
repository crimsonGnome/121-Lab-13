# Maze

In this lab you will load map data from a file. The map represents the different elements of a maze that a player will try to solve.

The maze game has already been implemented for you so you just need to implement the program's data loading functionality. Place all class definitions in `maze.h` and its implementations in `maze.cc`. You do not need to modify any other files.

# `MazeData` class
`MazeData` contains all information about the map that is required to play the game.

## Constructor
Create a constructor that accepts a filename as a parameter that is represented as a `std::string`. It should store the filename into a private data member. Additionally, it should call the `LoadMap` function.

## Data members
Create a `std::vector` that contains a `std::vector` of `char`, called `map_data_`. This design will result in the creation of a two-dimensional vector of characters. This data member represents the type of elements in the  map.

## Data members with Getters
Create the following getters and their corresponding data members. Make sure all getters are `const`.

1. `GetWidth`: Returns the width of the map represented as an `int`.
1. `GetHeight`: Returns the height of the map represented as an `int`.
1. `GetStartRow`: Returns the starting row of the player as an `int`. This works in tandem with the `GetStartCol` function to retrieve the player's position in the map (row x col).
1. `GetStartCol`: Returns the starting column of the player as an `int`.
1. `GetGoalRow`: Returns the row of the goal block as an `int`. This works in tandem with the `GetGoalCol` function to retrieve the goal block's position in the map (row x col).
1. `GetGoalCol`: Returns the column of the goal block as an `int`.
1. `IsValid`: Returns `true` if the map file was loaded successfully and contains a start and goal node. It returns `false` otherwise.

## Member functions
1.  `LoadMap`: A private function that loads data from a map file. Take note that the function will use the filename data member initially provided when the `MazeData` object was created. The function should first check if the specified file exists. If it does not exist then the `MazeData` object is automatically considered invalid therefore `is_valid_` should be `false`. The map file's format is shown below. You can also take a look at [map.txt](map.txt) and [map2.txt](map2.txt) for reference.

    | Map Format  | Example       |
    |-------------|---------------|
    | Width       | 8             |
    | Height      | 5             |
    | Row 1       | WWWWWSGG      |
    | Row 2       | WWWWWWGG      |
    | ...         | ...           |
    | Row n       | WWWWWWWX      |

    While loading the map, the function should store the following information into the corresponding data members.
    1. map width: retrieved from the first row of the map file.
    1. map height: retrieved from the second row of the map file.
    1. map types: all characters below line three indicate the types of elements in the map represented as characters. These characters should be stored in the corresponding locations of `map_data_`. For example, the third character in the second row is a 'W'. Therefore, the element in [1][2] of the map_data_ should be 'W'. Similarly, the element in [0][6] should be a 'G'.
    1. starting location: An 'S' character indicates the start location of the user. When the function detects this character, it should use its row and column position as the values for `start_row_` and `start_col_`.
    1. goal location: An 'X' character indicates the goal location. When the function detects this character, it should use its row and column position as the values for `goal_row_` and `goal_col_`.
    1. validity: After reading all characters, the function should check whether it found a start ('S') and goal ('X') character. The map is considered valid if it finds both characters and the function should set `is_valid_` to true. Otherwise, `is_valid_` should be set to false.

1. `GetElement`: A public function that returns a `MapObjectType` and accepts two `int` parameters representing a row and a column position. The function will use the row and column parameters to identify the character in the corresponding position of `map_data_`. It will check the value of the character and return the corresponding value from the `MapObjectType` enumeration that has already been defined for you in `maze.h`. The table below shows the value to be returned for each character.

    | Character  | MapObjectType |
    |------------|---------------|
    | 'W'        | kWall         |
    | 'G'        | kGround       |
    | 'S'        | kStart        |
    | 'X'        | kGoal         |

    If the character is not on the list (e.g., Q), return kWall.

## Run the program
Now you are ready to play the Maze game. Run the program to see if you can find any bugs.

To manually test your code you can compile and run with a shortcut to create ``main``:

```
make build
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readability (`make formatcheck`).

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob02
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` `robot.cc` `maze.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc maze.cc robot.cc -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission

We recommend pushing to Github frequently to back up your work.
