#pragma once
#include <string>
#include <vector>

class Student
{
public:
	void addStudent(int id, std::string name);
	void GradeStudents(int grade);
	void GetAverage();
	void GetStudents();

private:
	int m_id;
	std::string m_name;
	
};