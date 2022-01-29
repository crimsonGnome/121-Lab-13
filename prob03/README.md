# Phonebook
This program is used to create a phonebook for storing contact information into a text file.

The program begins by asking the user to provide a name for the file that will contain their phone book information. It will then ask the user to provide the names and numbers of their contacts. It should keep asking the user for contact information until they type in `Done` (case-sensitive).

Store all contact information into the file name they provided at the beginning of the program. We assume the user will type in a filename ending in `.txt` If the user does not add any contacts, then the file should still be created, but should be empty. To view your output file, you can either open it in an editor like *Atom* or you can type `cat contacts.txt` at the command prompt in a *Terminal* window.

Please see the sample below to guide the design of your program. Note that <b>bold</b> values in the sample represent input by the user.

## Sample Input/Output:
<pre>
Please provide the file name for your phone book: <b>contacts.txt</b>

Contact 1:
Please provide the name: <b>Elsie Simon</b>
Please provide their number: <b>(202)555-0115</b>

Contact 2:
Please provide the name: <b>Kaisha Cope</b>
Please provide their number: <b>5455689016</b>

Contact 3:
Please provide the name: <b>Sultan Vargas</b>
Please provide their number: <b>371-998-4166</b>

Contact 4:
Please provide the name: <b>Done</b>

Saving phonebook into contacts.txt

Done!
</pre>
### Sample output file:
```
Elsie Simon
(202)555-0115

Kaisha Cope
5455689016

Sultan Vargas
371-998-4166
```
# Submission checklist
1. Compiled and ran the driver (`main`).
1. Manually checked for compilation and logical errors.
1. Ensured no errors on the unit test (`make test`).
1. Followed advice from the stylechecker (`make stylecheck`).
1. Followed advice from the formatchecker to improve code readbility (`make formatcheck`).

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

Use the `clang++` command (or ``make build``) to compile your code and the `./` command to run it. The sample code below shows how you would compile code save in `main.cc` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 main.cc -o main
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
