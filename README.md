# students

In this exercise, you will need to implement a student information management system in the form of a linked list data structure. Each student has the following information.
* Name (a string of characters with a maximum length of 32 characters)
* Last name (a string of characters with a maximum length of 32 characters)
* National code (a string of characters with a maximum length of 10 characters)
* Unique student ID (integer)
* Gender (zero as boy and one as girl)
* Total GPA (floating point number)
* Home address (a string of characters with a maximum length of 256 characters)
* Contact number (a string of characters with a maximum length of 11 characters)

Operations you need to implement:
1- Adding a student: Your program should be able to add a student in two ways. The first is to receive the students' file path and add them to the system. The format of this file will be provided to you. The second method is also conversational. That is, ask the user what he intends to do? If the user chooses to add a student, they will receive the information in the next dialog and add to the system the link list described in the class in the form of a data structure. It is clear that a duplicate student should not be on the linked list and is based on a unique student ID.
2- Listing the information of all students: Your program should command the user to list the information of all students and put all the information of students in its output in the order of unique student ID. The output can be a file or a screen and should ask the user.
3- Delete a student: Your program should be able to take the command to remove a student from the user and remove the student from the linked list. Deletion is based on a unique student ID.
4- Editing student information: Your program should get the command to edit student information from the user. Then, based on the unique student ID, show the student information and ask the user which field he wants to change and change the desired field with the information he receives from the user.
5- Student search: Your program should get the student search command from the user. Then ask the user which field he wants to search by. When the user enters the desired value, search and print all the students that match the entered value on the screen.
