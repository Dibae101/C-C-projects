/*Default Argument allows a function to be called without providing one or more trailing arguments.
 It is indicated by using the following syntax for a parameter in the parameter-list of a function declaration.
*/
#include<iostream.h>
#include<conio.h>

	int Add(int x, int y=20, int z=30)
	{
		return x + y + z;
	}
	void main()
	{
		int rs;

		rs = Add(5);
		cout<<"\n\tThe sum is : "<<rs;

		rs = Add(4,8);
		cout<<"\n\tThe sum is : "<<rs;

		rs = Add(7,3,4);
		cout<<"\n\tThe sum is : "<<rs;

	}




