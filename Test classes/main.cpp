// Your First C++ Program

#include <iostream>
#include "Name.h"
using namespace std;


int main() {
    
    Name mystring("hello world");
    int l = mystring.getLength();

    cout << mystring.getName() << " with length: " << mystring.getLength() << endl;

    return 0;
}