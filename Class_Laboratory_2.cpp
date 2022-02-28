// OOP - facultate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Student {

private:
	string name;
	float EngGrade = -1, HistoryGrade = -1, MathGrade = -1; // if the value is -1 the grade is not set 

public:
	/// <summary>
	/// The Student class constructor that sets the  initial grades to the student entity 
	/// </summary>
	/// <param name="EngGrade">The English grade </param>
	/// <param name="MathGrade">The Math grade </param>
	/// <param name="HistoryGrade">The History grade</param>
	Student(float EngGrade, float MathGrade, float HistoryGrade, string name)
	{
		this->name = name;
		this->EngGrade = EngGrade;
		this->HistoryGrade = HistoryGrade;
		this->MathGrade = MathGrade;

	}

	void setName(string val)
	{
		this->name = name;

	}

	string  getName()
	{

		return this->name;

	}
	void setENG(float val)
	{
		/// <summary>
		/// Method  set the English grades of the student 
		/// </summary>
		/// <param name="val"> The value to be set </param>
		if (val < 10 && val > 1)
		{
			this->EngGrade = val;


		}

		else { cout << "The grade couldn't be set !" << endl; }

	}
	/// <summary>
	/// A method to retrieve the grade of the student 
	/// </summary>
	float  getEng() {

		if (this->EngGrade != -1) return this->EngGrade;

		else cout << "The grade couldn't be retrieved " << endl;


	}
	void setHist(float val)
	{
		//method to set the English grades of the student 
		if (val < 10 && val > 1)
		{
			this->HistoryGrade = val;


		}

		else { cout << "The grade couldn't be set !" << endl; }

	}

	float  getHist() {

		if (this->HistoryGrade != -1) return this->HistoryGrade;

		else cout << "The grade couldn't be retrieved " << endl;


	}

	void setMath(float val)
	{
		//method to set the English grades of the student 
		if (val < 10 && val > 1)
		{
			this->MathGrade = val;


		}

		else { cout << "The grade couldn't be set !" << endl; }

	}

	float  getMath() {

		if (this->MathGrade != -1) return this->MathGrade;

		else cout << "The grade couldn't be retrieved " << endl;


	}
	/// <summary>
	/// A method to compute the average grade of the student 
	/// </summary>
	/// <returns></returns>
	float AverageGrade()
	{

		return  (this->HistoryGrade + this->EngGrade + this->MathGrade) / 3;


	}



};


int compareName(Student &s1, Student &s2) {
	 
	string name1 = s1.getName();
	string name2 = s2.getName();
	
	if (name1 == name2) return 0;
	else if (name1 < name2) return -1;
	else return 1;

}


int  compareHistGrade(Student& s1, Student& s2)
{

	float  val1 = s1.getHist();
	float  val2 = s2.getHist();
	if (val1 == val2) return 0;
	else if (val1 > val2) return 1;
	else return -1;

	
}


int  compareEngGrade(Student& s1, Student& s2)
{

	float  val1 = s1.getEng();
	float  val2 = s2.getEng();
	if (val1 == val2) return 0;
	else if (val1 > val2) return 1;
	else return -1;

}

int  compareMathGrade(Student& s1, Student& s2)
{

	float   val1 = s1.getMath();
	float  val2 = s2.getMath();
	if (val1 == val2) return 0;
	else if (val1 > val2) return 1;
	else return -1;
}

int compareAverage(Student& s1, Student& s2)
{

	int val1 = s1.AverageGrade();
	int val2 = s2.AverageGrade();

	if (val1 == val2) return 0;
	else if (val1 > val2) return 1;
	else return -1;

}


int main()
{

	Student std1(5, 7, 8, "gigel1");
	Student std2(5, 7, 8, "gigel");
   
	//driver code to be completed ... 
	
}




