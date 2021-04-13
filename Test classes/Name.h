#pragma once
#include <string>
using namespace std;

class Name
{
private:
	string name;
	int string_length;
public:
	Name(string s) ;
	int getLength();
	string getName();
};
