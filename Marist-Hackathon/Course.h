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
	int credits;
private:
	string courseName;
	unordered_map<string, vector<ClassTime>> sections;
};

