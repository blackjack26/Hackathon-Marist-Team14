#include "ScheduleCreator.h"
#include <iostream>
#include <unordered_map>

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

	vector<ClassTime> times2;
	times2.push_back(ClassTime(MONDAY, "14:00", "15:15"));
	times2.push_back(ClassTime(THURSDAY, "12:30", "13:45"));
	sd2.addSection("113", times2);


	Course comm = Course("Data Communications", 4);
	vector<ClassTime> ctimes;
	ctimes.push_back(ClassTime(MONDAY, "14:00", "15:15"));
	ctimes.push_back(ClassTime(THURSDAY, "12:30", "15:15"));
	ctimes.push_back(ClassTime(FRIDAY, "11:00", "12:15"));
	comm.addSection("111", ctimes);

	vector<ClassTime> ctimes2;
	ctimes2.push_back(ClassTime(MONDAY, "17:45", "21:00"));
	comm.addSection("113", ctimes2);

	schedule.addCourse(sd2);
	schedule.addCourse(comm);
}

void ScheduleCreator::startCreator(){
	createSchedule();
}

void ScheduleCreator::createSchedule(){
	cout << "Create Schedule" << endl;
	unordered_map<string, vector<ClassTime>> map;
	permutation(map, schedule.getCourses());

	for (unordered_map<string, vector<ClassTime>> map : combos){
		cout << "\nNew Schedule" << endl;
		for (auto it : map){
			cout << it.first << endl;
			for (ClassTime t : it.second){
				cout << t.getDay() << "- " << t.getStart().toString() << " --> " << t.getEnd().toString() << endl;
			}
		}
	}

}

void ScheduleCreator::permutation(unordered_map<string, vector<ClassTime>> selectedSec, vector<Course> unusedCourses){
	
	int n = unusedCourses.size();
	if (n == 0)
		combos.push_back(selectedSec);
	else{
		int c = 0;
		do{
			for (auto it : unusedCourses.at(c).getSections()){
				if (isAllowed(it.second)){
					bool overlaps = false;

					size_t i = 0;
					do{
						if (checkOverlapWithExisting(selectedSec, it.second.at(i))){
							overlaps = true;
							break;
						}
						i++;
					} while (i < it.second.size());

					if (overlaps)
						continue;

					vector<Course> temp;

					size_t j = 0;
					do{
						if (c != j){
							temp.push_back(unusedCourses.at(j));
						}
						j++;
					} while (j < unusedCourses.size());

					unordered_map<string, vector<ClassTime>> clone = selectedSec;
					clone[unusedCourses.at(c).toString() + ", " + it.first] = it.second;
					permutation(clone, temp);
				}
			}
			c++;
		} while (c < n);
	}
}

bool ScheduleCreator::isAllowed(vector<ClassTime> times){
	if (times.size() <= 0)
		return true;
	size_t i = 0;
	do{
		if (times.at(i).getStart().getHourTime() < schedule.earlyTime.getHourTime() ||
			times.at(i).getEnd().getHourTime() > schedule.lateTime.getHourTime()){
			return false;
		}
		i++;
	} while (i < times.size());
	return true;
}

bool ScheduleCreator::checkOverlapWithExisting(unordered_map <string, vector<ClassTime>> selectedCourses, ClassTime t){
	bool overlaps = false;
	if (selectedCourses.size() <= 0)
		return false;

	auto it = selectedCourses.begin();
	do{
		
		size_t i = 0;
		do{
			if (it->second.at(i).overlaps(t)){
				overlaps = true;
			}
			i++;
		} while (i < it->second.size());


		++it;
	} while (it != selectedCourses.end());
	return overlaps;
}

void ScheduleCreator::addCourse(string name){
	schedule.addCourse(Course(name, 4));
}

void ScheduleCreator::addSection(string courseName, string secName, vector<ClassTime> times){
	schedule.getCourse(courseName)->addSection(secName, times);
}