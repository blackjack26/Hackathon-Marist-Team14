#include "ScheduleCreator.h"
#include <iostream>
#include <string>

using namespace std;

enum days {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

ScheduleCreator::ScheduleCreator()
{
	schedule = Schedule(Time("8:00"), Time("24:00"));

	Course sd2 = Course("Software Development II", 4);
	vector<ClassTime> times;
	times.push_back(ClassTime(TUESDAY, "8:00", "10:45"));
	times.push_back(ClassTime(FRIDAY, "8:00", "9:15"));
	sd2.addSection("111", times);

	schedule.addCourse(sd2);
}

void ScheduleCreator::startCreator(){
	createSchedule();
}

void ScheduleCreator::createSchedule(){

	unordered_map<string, vector<ClassTime>> map;
	permutation(map, schedule.getCourses());

}

void ScheduleCreator::permutation(unordered_map<string, vector<ClassTime>> selectedSec, vector<Course> unusedCourses){
	cout << "creating schedule" << endl;
}

bool ScheduleCreator::isAllowed(vector<ClassTime> times){
	if (times.size() <= 0)
		return true;

}