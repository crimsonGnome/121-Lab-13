#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

#include "../../minimum.h"
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(VectorTest, ReturnsNegativeOneForEmptyVector) {
  std::vector<double> v;
  EXPECT_EQ(-1, IndexOfMinWithVector(v))
      << "    IndexOfMinWithVector should return -1 when the vector's size is "
         "0";
}

TEST(VectorTest, ReturnsZeroForOneElementVector) {
  std::vector<double> v{42};
  EXPECT_EQ(0, IndexOfMinWithVector(v))
      << "    IndexOfMinWithVector should return 0 (the first index) when the "
         "vector's size is 1";
}

TEST(VectorTest, ReturnsIndexOfFirstElementInSortedVector) {
  std::vector<double> v{-7, 0, 7, 14, 21, 28, 35, 42};
  EXPECT_EQ(0, IndexOfMinWithVector(v))
      << "    IndexOfMinWithVector should return 0 (the first index) when the "
         "vector is sorted (each element is bigger than the previous)";
}

TEST(VectorTest, ReturnsIndexOfMiddleElementInUnsortedVector) {
  std::vector<double> v{76, -7, 35, 42, 12, -50, 93};
  EXPECT_EQ(5, IndexOfMinWithVector(v))
      << "    IndexOfMinWithVector should return 5 when the vector is [76, -7, "
         "35, 42, 12, -50, 93]";
}

TEST(VectorTest, ReturnsIndexOfLastElement) {
  std::vector<double> v{-4, 7, -3, 5, 4, 2, -8};
  EXPECT_EQ(6, IndexOfMinWithVector(v))
      << "    IndexOfMinWithVector should return 6 when the vector is [-4, 7, "
         "-3, 5, 4, 2, -8]";
}

TEST(ArrayTest, ReturnsNegativeOneForEmptyArray) {
  double a[] = {};
  EXPECT_EQ(-1, IndexOfMinWithArray(a, 0))
      << "    IndexOfMinWithArray should return -1 when the array's size is 0";
}

TEST(ArrayTest, ReturnsZeroForOneElementArray) {
  double a[] = {42};
  EXPECT_EQ(0, IndexOfMinWithArray(a, 1))
      << "    IndexOfMinWithArray should return 0 (the first index) when the "
         "array's size is 1";
}

TEST(ArrayTest, ReturnsIndexOfFirstElementInSortedArray) {
  double a[] = {-7, 0, 7, 14, 21, 28, 35, 42};
  EXPECT_EQ(0, IndexOfMinWithArray(a, 8))
      << "    IndexOfMinWithArray should return 0 (the first index) when the "
         "array is sorted (each element is bigger than the previous)";
}

TEST(ArrayTest, ReturnsIndexOfMiddleElementInUnsortedArray) {
  double a[] = {76, -7, 35, 42, 12, -50, 93};
  EXPECT_EQ(5, IndexOfMinWithArray(a, 7))
      << "    IndexOfMinWithArray should return 5 when the array is [76, -7, "
         "35, 42, 12, -50, 93]";
}

TEST(ArrayTest, ReturnsIndexOfLastElement) {
  double a[] = {-4, 7, -3, 5, 4, 2, -8};
  EXPECT_EQ(6, IndexOfMinWithArray(a, 7))
      << "    IndexOfMinWithArray should return 6 when the array is [-4, 7, "
         "-3, 5, 4, 2, -8]";
}

TEST(PointerTest, ReturnsNegativeOneForEmptyArray) {
  double a[] = {};
  EXPECT_EQ(-1, IndexOfMinWithPointer(a, 0))
      << "    IndexOfMinWithPointer should return -1 when the array's size is "
         "0";
}

TEST(PointerTest, ReturnsZeroForOneElementArray) {
  double a[] = {42};
  EXPECT_EQ(0, IndexOfMinWithPointer(a, 1))
      << "    IndexOfMinWithPointer should return 0 (the first index) when the "
         "array's size is 1";
}

TEST(PointerTest, ReturnsIndexOfFirstElementInSortedArray) {
  double a[] = {-7, 0, 7, 14, 21, 28, 35, 42};
  EXPECT_EQ(0, IndexOfMinWithPointer(a, 8))
      << "    IndexOfMinWithPointer should return 0 (the first index) when the "
         "array is sorted (each element is bigger than the previous)";
}

TEST(PointerTest, ReturnsIndexOfMiddleElementInUnsortedArray) {
  double a[] = {76, -7, 35, 42, 12, -50, 93};
  EXPECT_EQ(5, IndexOfMinWithPointer(a, 7))
      << "    IndexOfMinWithPointer should return 5 when the array is [76, -7, "
         "35, 42, 12, -50, 93]";
}

TEST(PointerTest, ReturnsIndexOfLastElement) {
  double a[] = {-4, 7, -3, 5, 4, 2, -8};
  EXPECT_EQ(6, IndexOfMinWithPointer(a, 7))
      << "    IndexOfMinWithPointer should return 6 when the array is [-4, 7, "
         "-3, 5, 4, 2, -8]";
}

TEST(MainTest, ZeroElements) {
  std::string user_input = "0\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("vector: -1"))
        << "    If the user asks for zero elements, the vector and array "
           "should be empty and the IndexOf functions should all return -1";
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("array: -1"))
        << "    If the user asks for zero elements, the vector and array "
           "should be empty and the IndexOf functions should all return -1";
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("pointer math: -1"))
        << "    If the user asks for zero elements, the vector and array "
           "should be empty and the IndexOf functions should all return -1";
  });
}

TEST(MainTest, SeveralElements) {
  std::string user_input = "4\n2\n4\n-6\n8\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("vector: 2"))
        << "    If the user asks for four elements and provides 2, 4, -6 and "
           "8, those numbers should be placed  in the vector and array in that "
           "order. The index of the minimue value is 2.";
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("array: 2"))
        << "    If the user asks for four elements and provides 2, 4, -6 and "
           "8, those numbers should be placed  in the vector and array in that "
           "order. The index of the minimue value is 2.";
  });
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("pointer math: 2"))
        << "    If the user asks for four elements and provides 2, 4, -6 and "
           "8, those numbers should be placed  in the vector and array in that "
           "order. The index of the minimue value is 2.";
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  bool skip = true;
  for (int i = 0; i < argc; i++) {
    if (std::string(argv[i]) == "--noskip") {
      skip = false;
    }
  }
  if (skip) {
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  }
  return RUN_ALL_TESTS();
}
