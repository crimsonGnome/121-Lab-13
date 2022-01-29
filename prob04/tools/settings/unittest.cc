#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <fstream>

#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

struct UserInput : public UnitTestFileManager {
  UserInput() : UnitTestFileManager("phonebook.txt") {}
};

struct FileLoading : public UnitTestFileManager {
  FileLoading() : UnitTestFileManager("load_file_contacts.txt") {}
};

TEST_F(UserInput, FileNameAndContactInfo) {
  std::string user_input = "phonebook.txt\n";
  ASSERT_EXECEXIT("main", user_input, 3)
      << "      Your program should ask for the file name of the phonebook "
         "file.";
}

TEST_F(FileLoading, OneContact) {
  std::ofstream user_file;
  user_file.open("load_file_contacts.txt");
  user_file << "Shanay Wickens\n7205972770\n";
  user_file.close();

  std::string user_input = "load_file_contacts.txt\n";

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("Shanay Wickens"))
        << "      Your program should show the contact's name, Shanay Wickens.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("7205972770"))
        << "      Your program should show the contact's number, 7205972770.";
  })
}

TEST_F(FileLoading, MultipleContacts) {
  std::ofstream user_file;
  user_file.open("load_file_contacts.txt");
  user_file << "Shanay Wickens\n7205972770\n";
  user_file << "Harlee Collins\n3328206140\n";
  user_file << "Addison Ryan\n7917471622\n";
  user_file.close();

  std::string user_input = "load_file_contacts.txt\n";

  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("Shanay Wickens"))
        << "      Your program should show the contact's name, Shanay Wickens.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("7205972770"))
        << "      Your program should show the contact's number, 7205972770.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("Harlee Collins"))
        << "      Your program should show the contact's name, Harlee Collins.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("3328206140"))
        << "      Your program should show the contact's number, 3328206140.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("Addison Ryan"))
        << "      Your program should show the contact's name, Addison Ryan.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("7917471622"))
        << "      Your program should show the contact's number, 7917471622.";
  })
}

TEST_F(FileLoading, EmptyFile) {
  std::ofstream user_file;
  user_file.open("load_file_contacts.txt");
  user_file << "";
  user_file.close();

  std::string user_input = "load_file_contacts.txt\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT(
        "main", user_input,
        MatchesRegex(R"(.*(empty|(does not contain)|(no contact)).*)"))
        << "      Your program should show an error message when the phonebook "
           "file does not contain any contacts.";
  })
}

TEST_F(FileLoading, MissingFile) {
  std::ifstream user_file;
  std::string user_input = "missingfile.txt\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input,
                    MatchesRegex(R"(.*(Invalid|invalid|error|missing).*)"))
        << "      Your program should show an error message when it is asked "
           "to load a missing phonebook file.";
  })
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
