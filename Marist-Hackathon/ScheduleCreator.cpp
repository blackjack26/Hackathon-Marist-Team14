#include "ScheduleCreator.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const char days[] = {'U', 'M', 'T', 'W', 'R', 'F', 'S'};

ScheduleCreator::ScheduleCreator()
{

	/*Course sd2 = Course("Software Development II", 4);
	vector<ClassTime> times;
	times.push_back(ClassTime(TUESDAY, "8:00", "10:45"));
	times.push_back(ClassTime(FRIDAY, "8:00", "9:15"));
	sd2.addSection("111", times);

	vector<ClassTime> times2;
	times2.push_back(ClassTime(MONDAY, "14:00", "15:15"));
	times2.push_back(ClassTime(THURSDAY, "12:30", "13:45"));
	sd2.addSection("113", times2);

	vector<ClassTime> times3;
	times3.push_back(ClassTime(MONDAY, "12:30", "13:45"));
	times3.push_back(ClassTime(THURSDAY, "12:30", "13:45"));
	sd2.addSection("115", times3);


	Course comm = Course("Data Communications", 4);
	vector<ClassTime> ctimes;
	ctimes.push_back(ClassTime(MONDAY, "14:00", "15:15"));
	ctimes.push_back(ClassTime(THURSDAY, "12:30", "15:15"));
	ctimes.push_back(ClassTime(FRIDAY, "11:00", "12:15"));
	comm.addSection("111", ctimes);

	vector<ClassTime> ctimes2;
	ctimes2.push_back(ClassTime(MONDAY, "17:45", "21:00"));
	comm.addSection("113", ctimes2);


	Course data = Course("Database Management", 4);
	vector<ClassTime> dtimes;
	dtimes.push_back(ClassTime(MONDAY, "14:00", "15:15"));
	dtimes.push_back(ClassTime(WEDNESDAY, "14:00", "15:15"));
	dtimes.push_back(ClassTime(THURSDAY, "14:00", "15:15"));
	data.addSection("114", dtimes);


	Course cyber = Course("Intro to Cybersecurity", 4);
	vector<ClassTime> cyTimes;
	cyTimes.push_back(ClassTime(TUESDAY, "12:30", "13:45"));
	cyTimes.push_back(ClassTime(FRIDAY, "12:30", "13:45"));
	cyber.addSection("111", cyTimes);

	schedule.addCourse(sd2);
	schedule.addCourse(comm);
	schedule.addCourse(data);
	schedule.addCourse(cyber);*/
}

void ScheduleCreator::startCreator(){
	getInput();
	createSchedule();
}

void ScheduleCreator::createSchedule(){
	cout << "Create Schedule" << endl;
	unordered_map<string, vector<ClassTime>> map;
	permutation(map, schedule.getCourses());

	int index = -1;
	for (unordered_map<string, vector<ClassTime>> map : combos){
		index++;
		if (isExtra(map, index)){
			continue;
		}
		cout << "\n***New Schedule***" << endl;
		for (auto it : map){
			cout << it.first << endl;
			for (ClassTime t : it.second){
				cout << t.getDay() << ": " << t.getStart().toString() << " --> " << t.getEnd().toString() << endl;
			}
		}
	}

	cout << "Would you like to save your results (Y/N)? ";
	string input; getline(cin, input);
	if (input == "Y" || input == "y"){
		saveData();
	}
}

bool ScheduleCreator::isExtra(unordered_map<string, vector<ClassTime>> currMap, int index){
	index--;
	for (int i = index; i >= 0; i--){
		unordered_map<string, vector<ClassTime>> map = combos.at(i);
		string same = "";
		for (auto it : map){
			if (currMap.count(it.first)){
				same += "1";
			}
			else{
				same += "0";
			}
		}

		int count = 0;
		for (int j = 0; j < same.length(); j++){
			if (same.at(j) == '0')
				count++;
		}
		if (count == 0)
			return true;
	}
	return false;
}

void ScheduleCreator::getInput(){
	cout << "Welcome to the Schedule Creator!" << endl;
	cout << "What time would you like classes to start (hh:mm)? ";
	string start; getline(cin, start);
	while (!verifyInput(start, "time")){
		getline(cin, start);
	}
	cout << "What time would you like classes to end (hh:mm)? ";
	string end; getline(cin, end);
	while (!verifyInput(end, "time")){
		getline(cin, end);
	}
	schedule = Schedule(Time(start), Time(end));

	string courseInput = "";
	do{
		cout << "Would you like to add a course (Y/N)? ";
		getline(cin, courseInput);
		if (courseInput == "Y" || courseInput == "y"){
			cout << "  What is the name of the course? ";
			string courseName; getline(cin, courseName);
			cout << "  How many credits? ";
			string numCredits; getline(cin, numCredits); 
			while (!verifyInput(numCredits, "number")){
				getline(cin, numCredits);
			}
			Course c = Course(courseName, stoi(numCredits));
			string sectionInput;
			do{
				cout << "  Would you like to add a section to " << courseName << " (Y/N)? ";
				getline(cin, sectionInput);
				if (sectionInput == "Y" || sectionInput == "y"){

					vector<ClassTime> ctimes;
					cout << "    What is the section number? ";
					string secNum; getline(cin, secNum);

					string classInput;
					do{
						cout << "    Would you like to add a class to section " << secNum << " (Y/N)? ";
						getline(cin, classInput);
						if (classInput == "Y" || classInput == "y"){
							cout << "      What day is the class time (U,M,T,W,R,F,S)? ";
							string day;	getline(cin, day);
							while (!verifyInput(day, "day")){
								getline(cin, day);
							}
							cout << "      What is the start time (hh:mm)? ";
							string startTime; getline(cin, startTime);
							while (!verifyInput(startTime, "time")){
								getline(cin, startTime);
							}
							cout << "      What is the end time (hh:mm)? ";
							string endTime; getline(cin, endTime);
							while (!verifyInput(endTime, "time")){
								getline(cin, endTime);
							}
							ctimes.push_back(ClassTime(day.at(0), startTime, endTime));
						}
						else if (classInput != "N" && classInput != "n"){
							cout << "** Invalid Input **" << endl;
						}
					} while (classInput != "N" && classInput != "n");
					c.addSection(secNum, ctimes);
				}
				else if (sectionInput != "N" && sectionInput != "n"){
					cout << "** Invalid input **" << endl;
				}
			} while (sectionInput != "N" && sectionInput != "n");
			schedule.addCourse(c);
		}
		else if (courseInput != "N" && courseInput != "n"){
			cout << "** Invalid input **" << endl;
		}
	} while (courseInput != "N" && courseInput != "n");
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

void ScheduleCreator::saveData(){
	ofstream file ("save.txt");
	if (file.is_open()){
		int index = -1;
		for (unordered_map<string, vector<ClassTime>> map : combos){
			index++;
			if (isExtra(map, index)){
				continue;
			}
			file << "\n***New Schedule***" << endl;
			for (auto it : map){
				file << it.first << endl;
				for (ClassTime t : it.second){
					file << t.getDay() << ": " << t.getStart().toString() << " --> " << t.getEnd().toString() << endl;
				}
			}
		}
		file.close();
	}else{
		cout << "Unable to write to file" << endl;
	}
}

bool ScheduleCreator::verifyInput(string input, string type){
	if (type == "number"){
		try{
			stoi(input);
		}
		catch (exception){
			cout << "** Invalid Input. Please enter a number. ** -> ";
			return false;
		}
	}
	else if (type == "time"){
		if (input.length() > 5 || input.length() < 4){
			cout << "** Invalid Input. Use (hh:mm) ** -> ";
			return false;
		}
		string str = input.substr(0, input.find_first_of(":"));
		if (str.length() < 1 || str.length() > 2){
			cout << "** Invalid Input. Use (hh:mm) ** -> ";
			return false;
		}
		string str2 = input.substr(input.find_first_of(":") + 1);
		if (str2.length() != 2){
			cout << "** Invalid Input. Use (hh:mm) ** -> ";
			return false;
		}
	}
	else if (type == "day"){
		for (char c : days){
			if (input.at(0) == c){
				return true;
			}
		}
		cout << "** Invalid Input. Specify a day ** -> ";
		return false;
	}
	return true;
}