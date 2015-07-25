// I need to put in comments
// The idea is to creat a standard prototype function

#include <iostream>
using namespace std;

int someFunction(int, int);

int main(int argc, char **argv)
{
    cout << "Result = " << someFunction(5,6);
	
    cout << endl;

    return 0;
}


int someFunction( int a, int b)
{
	int result;
	result = a + b;
    // I need more complex function
	return result; 
}
