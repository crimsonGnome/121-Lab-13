#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <fstream>

#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

struct UserInput : public UnitTestFileManager {
  UserInput() : UnitTestFileManager("contacts.txt") {}
};

struct FileCreation : public UnitTestFileManager {
  FileCreation() : UnitTestFileManager("create_file_contacts.txt") {}
};

TEST_F(UserInput, FileNameAndContactInfo) {
  std::string user_input = "contacts.txt\nElsie Simon\n2025550115\nDone\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for the file name and each contact's "
         "name and number.";
}

TEST_F(FileCreation, CreatedFile) {
  std::ifstream user_file;
  std::string user_input =
      "create_file_contacts.txt\nElsie Simon\n2025550115\nDone\n";
  ASSERT_DURATION_LE(3, { exec_program("main", user_input); })

  user_file.open("create_file_contacts.txt");
  ASSERT_TRUE(user_file.good())
      << "      Your program should create a file using the filename provided "
         "by the user. In this case, create_file_contacts.txt.";
}

TEST_F(FileCreation, OneContact) {
  std::ifstream user_file;
  std::string user_input =
      "create_file_contacts.txt\nKaisha Cope\n5455689016\nDone\n";

  ASSERT_DURATION_LE(3, { exec_program("main", user_input); })

  user_file.open("create_file_contacts.txt");

  ASSERT_TRUE(user_file.good())
      << "      Your program should create a file using the filename provided "
         "by the user. In this case, create_file_contacts.txt.";

  std::string your_name, your_number;

  std::getline(user_file, your_name);

  ASSERT_EQ(your_name, "Kaisha Cope")
      << "      Your program should save the name of the first contact, Kaisha "
         "Cope";

  std::getline(user_file, your_number);

  ASSERT_EQ(your_number, "5455689016")
      << "      Your program should save the number of the first contact , "
         "5455689016";

  user_file.close();
}

TEST_F(FileCreation, MultipleContacts) {
  std::ifstream user_file;
  std::string user_input =
      "create_file_contacts.txt\nKaisha Cope\n5455689016\nElsie "
      "Simon\n2025550115\nSultan Vargas\n3719984166\nDone\n";

  ASSERT_DURATION_LE(3, { exec_program("main", user_input); })

  user_file.open("create_file_contacts.txt");

  ASSERT_TRUE(user_file.good())
      << "      Your program should create a file using the filename provided "
         "by the user. In this case, create_file_contacts.txt.";

  std::string your_firstname, your_firstnumber;

  std::getline(user_file, your_firstname);

  ASSERT_EQ(your_firstname, "Kaisha Cope")
      << "      Your program should save the name of the first contact, Kaisha "
         "Cope";

  std::getline(user_file, your_firstnumber);

  ASSERT_EQ(your_firstnumber, "5455689016")
      << "      Your program should save the number of the first contact , "
         "5455689016";

  std::string your_secondname, your_secondnumber;

  std::getline(user_file, your_secondname);

  ASSERT_EQ(your_secondname, "Elsie Simon")
      << "      Your program should save the name of the second contact, Elsie "
         "Simon";

  std::getline(user_file, your_secondnumber);

  ASSERT_EQ(your_secondnumber, "2025550115")
      << "      Your program should save the number of the second contact , "
         "2025550115";

  std::string your_thirdname, your_thirdnumber;

  std::getline(user_file, your_thirdname);

  ASSERT_EQ(your_thirdname, "Sultan Vargas")
      << "      Your program should save the name of the third contact, Kaisha "
         "Cope";

  std::getline(user_file, your_thirdnumber);

  ASSERT_EQ(your_thirdnumber, "3719984166")
      << "      Your program should save the number of the third contact , "
         "3719984166";

  user_file.close();
}

TEST_F(FileCreation, NoContact) {
  std::ifstream user_file;
  std::string user_input = "create_file_contacts.txt\nDone\n";
  ASSERT_DURATION_LE(3, { exec_program("main", user_input); })
  user_file.open("create_file_contacts.txt");

  std::string name;
  bool has_contents = true && user_file >> name;
  ASSERT_FALSE(has_contents) << "      The file that is created should be "
                                "empty because no contacts were added.";

  user_file.close();
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
