#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Cstudent 
{
	friend double getAvgScore(Cstudent Cstu[]);
private:
	const int m_stuId;
	string m_stuName;
	int m_stuScore;
	static int m_stuCount;
public:
	//Construction Function
	Cstudent(int m_stuId,string m_stuName,int m_stuScore) :m_stuId(m_stuId)
	{
		this->m_stuName = m_stuName;
		this->m_stuScore = m_stuScore;
		addm_stuCount();
	}

	//Copy Construction Function
	Cstudent(const Cstudent &cs):m_stuId(cs.m_stuId)
	{
		m_stuName = cs.m_stuName;
		m_stuScore = cs.m_stuScore;
	}
	//getter
	int getm_stuId()
	{
		return m_stuId;
	}

	string getm_stuName()
	{
		return m_stuName;
	}

	int getm_stuScore()
	{
		return m_stuScore;
	}

	int getm_stuCount()
	{
		return m_stuCount;
	}
	//setter
	void setm_stuName(string m_stuName)
	{
		this->m_stuName = m_stuName;
	}

	void setm_stuScore(int m_stuScore)
	{
		this->m_stuScore = m_stuScore;
	}

	void setm_stuCount(int m_stuCount)
	{
		m_stuCount = 0;
	}

	void addm_stuCount()
	{
		m_stuCount++;
	}

};
int Cstudent::m_stuCount = 0;

double getAvgScore(Cstudent Cstu[])
{
	int sumScore = 0;
	for (int i = 0; i < Cstu[0].m_stuCount; i++)
	{
		sumScore += Cstu[i].m_stuScore;
	}
	return double(sumScore / Cstu[0].m_stuCount);
}

double getAvgScore(Cstudent Cstu[], int m_stuCount)
{
	int sumScore = 0;
	for (int i = 0; i < m_stuCount; i++)
	{
		sumScore += Cstu[i].getm_stuScore();
	}
	return double(sumScore / m_stuCount);
}

int main()
{
	Cstudent stuArray[10] = 
	{
		{1,"a",90},
		{2,"b",88},
		{3,"c",92},
		{4,"d",90},
		{5,"e",95},
		{6,"f",85},
		{7,"g",90},
		{8,"h",98},
		{9,"j",82},
		{10,"k",90}
	};
	cout << "平均成绩为：" << getAvgScore(stuArray) << endl;
	cout << "=======================" << endl;
	cout << "平均成绩为：" << getAvgScore(stuArray,10) << endl;
	vector<Cstudent> stuVector;
	while (true)
	{
		char flagChar;
		cin >> flagChar;
		if (flagChar == '#')
			break;
		cin.clear();
		cin.sync();
		int m_stuId;
		string m_stuName;
		int m_stuScore;
		cout << "依次输入学号、姓名、成绩，以空格隔开" << endl;
		cin >> m_stuId >> m_stuName >> m_stuScore;
		Cstudent tempCstu(m_stuId, m_stuName, m_stuScore);
		stuVector.push_back(tempCstu);
	}
	int sumScore = 0;
	for (int i = 0; i < stuVector.size(); i++)
	{
		sumScore += stuVector[i].getm_stuScore();
	}
	double avgScore = sumScore / stuVector.size();
	cout << "平均成绩为：" << avgScore << endl;

	return 0;
}
