/*3.
(a) Define a C++ base class named Rectangle containing length and width data members. From this class, derive a class named Box with another data member named depth. The member functions for the base class Rectangle should consist of a constructor and an area() function. The derived class Box should have a constructor, a volume() function and an override function named  area() that returns the surface area of the box.

(b) Include the classes written in part a, above in a working C++ program that creates an object  for each class and calls each member function for each class to test them. Verify the results manually.
*/
#include <iostream>
#include <cmath>
using namespace std;
const double PI = 2.0 * asin(1.0);
// class declaration section
class Rectangle
{
protected:
	double length;
	double width;

public:
	Rectangle(double = 4.0, double  = 8.0);  // constructor
	double area();
};
// class implementation section for Point
Rectangle::Rectangle(double ll, double ww)  // constructor
{
	length = ll;
	width = ww;
}

double Rectangle::area()
{
	double area = length * width;
	return area;
}

// class declaration section where Box is derived from Rectangle
class Box : public Rectangle
{
protected:
	double depth;  // add one data member and
public:           // two member functions
	Box(double d = 5.0, double l = 3.0, double w = 4.0) : Rectangle(l,w), depth(d) {}
	double volume();
	double surf_area();
};
// class implementation section
double Box::surf_area()   // calculates a volume
{
	double surf_area = (2*length*width) +(2 *length * depth) + (2*width * depth);
	return surf_area; // note the base function call
}
double Box::volume()
{
	double volume = length * width  * depth;
	return volume;
}

int main()
{
	Rectangle Rect_1, Rect_2;  // create two Rectangle objects
	Box Box_1;      // create one BOX object
	cout << "The area of box 1 is " << Box_1.area() << endl;
	cout << "The volume of box 1 is " << Box_1.volume() << endl;
	cout << "The area of the rectangle is " << Rect_2.area() << endl;
	system("PAUSE");
	return 0;
}

