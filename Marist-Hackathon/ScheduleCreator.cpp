#include "ScheduleCreator.h"
#include <iostream>
#include <string>

using namespace std;

ScheduleCreator::ScheduleCreator()
{
	schedule = Schedule(Time("8:00"), Time("24:00"));

	Course sd2 = Course("Software Development II", 4);
	vector<ClassTime> times;
	times.push_back(ClassTime(3, "8:00", "10:45"));
	times.push_back(ClassTime(6, "8:00", "9:15"));
	sd2.addSection("111", times);
}

void ScheduleCreator::startCreator(){
	cout << "Starting..." << endl;
}

void ScheduleCreator::createSchedule(){

	unordered_map<string, vector<ClassTime>> map;
	permutation(map, schedule.getCourses());

}

void ScheduleCreator::permutation(unordered_map<string, vector<ClassTime>> selectedSec, vector<Course> unusedCourses){

}