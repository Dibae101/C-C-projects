
/* Write a complete program that prompt the user for the radius of a sphere and calculates and prints its volume. Use an inline function sphereVolume that returns the result of the volume.
*/
#include <iostream>
#include <cmath>
using namespace std;

inline double sphereVolume (double radius)
{
	return (4.0 / 3.0 * 3.14159 * pow(radius, 3));
}

int main()
{
	double radius;
	cout << "Enter radius of sphere: ";
	cin >> radius;
	cout << "Volume of that sphere is: " << sphereVolume(radius) << endl;
}
