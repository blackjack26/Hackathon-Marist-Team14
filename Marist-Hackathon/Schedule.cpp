#include "Schedule.h"
#include "Course.h"

Schedule::Schedule(){

}

Schedule::Schedule(Time earlyTime, Time lateTime){
	this->earlyTime = earlyTime;
	this->lateTime = lateTime;
}

void Schedule::addCourse(Course c){
	courses.push_back(c);
}

Course* Schedule::getCourse(string name){
	if (courses.size() <= 0)
		return NULL;
	int i = 0;
	do{
		if (courses.at(i).toString() == name)
			return &courses.at(i);
		i++;
	} while (i < courses.size());
	return NULL;
}

vector<Course> Schedule::getCourses(){
	return courses;
}