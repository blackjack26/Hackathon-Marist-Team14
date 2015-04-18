#pragma once
#include <vector>
#include "Course.h"
#include "Time.h"
using namespace std;

class Schedule
{
public:
	Schedule();
	Schedule(Time earlyTime, Time lateTime);
	void addCourse(Course c);
	Course* getCourse(string name);
	vector<Course> getCourses();
	Time earlyTime;
	Time lateTime;
private:
	vector<Course> courses;
};

