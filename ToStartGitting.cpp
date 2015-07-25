<<<<<<< HEAD
// I need to put in comments

=======
>>>>>>> a374f82541aee3e5e98870c682b032d672794354
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
	return result;
}
