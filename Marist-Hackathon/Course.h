#include <string>
#include <unordered_map>
#pragma once

using namespace std;

class Course
{
public:
	Course();
private:
	string courseName;
	int credits;
	unordered_map<string, ClassTime[]> sections;
};

