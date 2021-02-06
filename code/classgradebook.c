 /*Modify Class GradeBook
a. Include another string data member that represents the course lecturer’s name.
b. Provide a set function to change the lecturer’s name and a get function to retrieve it.
c. Modify the constructor to specify course name and lecturer’s name parameters.
d. Modify function displayMessage to output the welcome message and course name, and the string "This course is presented by: " followed by the lecturer’s name
*/

#include<iostream>
#include <string>
using namespace std;

class GradeBook
{
public:
GradeBook( string, string );
void setCourseName( string );
string getCourseName();
void setInstructorName(string);
string getInstructorName();
void displayMessage();
private:
string courseName;
string instructorName;
};
GradeBook::GradeBook( string course, string instructor )
{
courseName=course;
instructorName=instructor;
}
void GradeBook::setCourseName( string course)
{
if ( course.length() <= 25 )
courseName = course;
if ( course.length() > 25 )
{
courseName = course.substr( 0, 25 );
cout << "Name \"" << course <<"\" exceeds maximum length (25).\n"<< "Limiting courseName to first 25 characters.\n" << endl;
}
}
void GradeBook::setInstructorName(string instructor )
{
if ( instructor.length() <= 25 )
instructorName = instructor;
if ( instructor.length() > 25 )
{
instructorName = instructor.substr( 0, 25 );
cout << "Name \"" << instructor <<"\" exceeds maximum length (25).\n"<< "Limiting instructorName to first 25 characters.\n" << endl;
}
}
string GradeBook::getCourseName()
{
return courseName;
}
string GradeBook::getInstructorName()
{
return instructorName;
}
void GradeBook::displayMessage()
{
cout << "Welcome to the grade book for\n" << getCourseName()<< "!" << endl;
cout << "This course is presented by: \n" << getInstructorName()<< "." << endl;
}
int main()
{
GradeBook gradeBook1( "CS101 Introduction to Computer Science" ,"Pam");
GradeBook gradeBook2( "CS102 C++ Data Structures", "Dwight" );
cout << "gradeBook1's initial course name is: "<< gradeBook1.getCourseName()<< "\ngradeBook2's initial course name is: "<< gradeBook2.getCourseName() << endl;
cout << "gradeBook1's initial instructor name is: "<< gradeBook1.getInstructorName()<< "\ngradeBook2's initial instructor name is: "<< gradeBook2.getInstructorName() << endl;
gradeBook1.setCourseName( "CS101 C++ Programming" );
cout << "\ngradeBook1's course name is: "<< gradeBook1.getCourseName()<< "\ngradeBook2's course name is: "<< gradeBook2.getCourseName() << endl;
gradeBook2.setInstructorName("John Wick");
gradeBook1.displayMessage();
gradeBook2.displayMessage();
}

