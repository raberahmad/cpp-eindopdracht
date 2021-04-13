#include "Name.h"

using namespace std;

Name::Name(string s) {
	name = s;
	string_length = name.length();
}

int Name::getLength() {
	return string_length;
}

string Name::getName() {
	return name;
}