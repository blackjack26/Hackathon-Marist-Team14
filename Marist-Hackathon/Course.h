#pragma once
#include <string>
#include <unordered_map>
#include "ClassTime.h"

using namespace std;

class Course
{
public:
	Course(string courseName, int credits);
	void addSection(string name, vector<ClassTime> times);
	void removeSection(string name);
	vector<ClassTime> getSection(string name);
	unordered_map<string, vector<ClassTime>> getSections();
	string toString();
private:
	string courseName;
	int credits;
	unordered_map<string, vector<ClassTime>> sections;
};

