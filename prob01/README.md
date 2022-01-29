# Vectors, arrays and pointer arithmetic

Write three different functions to return the index of the minimum value in a vector or array, or `-1` if the vector/array doesn't have any elements.

In this lab you will complete three functions in ``minimum.cc`` and then call those functions from ``main.cc``. These three functions all have the same goal but use different inputs to allow you to compare how to implement one algorithm using vectors, arrays, or pointer arithmetic.

You do not need to edit ``minimum.h``.

You may prefer do these one at a time (finish the function in minimum.cc and call the function from main.cc) in order to manually test with ``./main`` as you go.

## Index of minimum value with ``std::vector``

Complete ``IndexOfMinWithVector`` in ``minimum.cc``. This function takes a ``std::vector`` containing doubles as input and should return the index of the smallest value in the vector, or -1 if there are no elements.

## Index of minimum value using an array

Complete ``IndexOfMinWithArray`` in ``minimum.cc``. This function takes an array of doubles and an integer length of the array, and should return the index of the smallest value in the array or -1 if there are no elements.

You must use array notation (square brackets) for credit.

## Index of minimum value using a pointer

Complete ``IndexOfMinWithPointer`` in ``minimum.cc``. This function takes a pointer to the address of the first double in an array and an integer length of the array, and should return the index of the smallest value in the array or -1 if there are no elements.

You must use pointer arithmetic for credit.

## Complete ``main.cc``

Your ``main`` function should ask the user how many elements they want, construct an array and a vector, then prompt the user for each element and fill in that array and vector with values.

``main`` should then call each of the three functions from ``minimum.h``. Here's an example of how this might look:

```
How many elements? 3
Element 0: 7
Element 1: -4
Element 2: 2
Minimum index using vector: 1
Minimum index using array: 1
Minimum index using pointer math: 1
```

The unit tests will look for "vector: 1", "array: 1" and "pointer math: 1" substrings. Otherwise your output can be whatever you like.

## Run the program

To manually test your code you can compile and run with:

```
clang++ -std=c++17 main.cc minimum.cc -o main
./main
```

## Run the unit tests

We've provided unit tests, which you can try with ``make test``. Use the output to help you debug any issues in your program.

# Submission checklist
1. Completed `minimum.cc`.
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
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `main.cc` `minimum.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc minimum.cc -o main
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
