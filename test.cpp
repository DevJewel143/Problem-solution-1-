#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::string;

struct Student {
	string SID, CID;
	string name;

	int rank, position, numberOfPassed;
	double sum, average;

	int score[4]; // 0->Chinese, 1->Math, 2->English, 3->Program

	Student(string SID, string CID, string name, int *score) : SID(SID), CID(CID), name(name), rank(0), sum(0), average(0) {
		for (int i = 0; i < 4; i++) this->score[i] = score[i];
		for (int i = 0; i < 4; i++) this->sum += this->score[i];
		this->average = this->sum / 4.0;
		this->position = 0;
		numberOfPassed = 0;
	}

	bool operator<(const Student &a) const {
		return sum > a.sum;
	}

	void calc() {
		for (int i = 0; i < 4; i++) if (score[i] >= 60) numberOfPassed++;
	}
};

std::vector<Student> v;
std::set<string> s;

void printMenu() {
	using namespace std;

	cout << "Welcome to Student Performance Management System (SPMS)." << endl << endl;
	cout << "1 - Add" << endl;
	cout << "2 - Remove" << endl;
	cout << "3 - Query" << endl;
	cout << "4 - Show ranking" << endl;
	cout << "5 - Show Statistics" << endl;
	cout << "0 - Exit" << endl << endl;
}

void add() {
	using namespace std;

	while (true) {
		cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
		string SID, CID;
		string name;
		int score[4];

		cin >> SID;
		if (SID == "0") break;

		cin >> CID >> name;
		for (int i = 0; i < 4; i++) {
			cin >> score[i];
		}

		if (s.count(SID)) cout << "Duplicated SID." << endl;
		else  {
			Student x(SID, CID, name, score);
			x.calc();
			v.push_back(x);
			s.insert(SID);
		}
	}
}

void remove() {
	using namespace std;
	while (true) {
		cout << "Please enter SID or name. Enter 0 to finish." << endl;

		string tmp;
		cin >> tmp;

		if (tmp == "0") break;

		int sum = 0;

		vector<int> deleted;
		for (vector<Student>::iterator it = v.begin(); it != v.end(); it++) {
			if (it->SID == tmp || it->name == tmp) {
				deleted.push_back(it - v.begin());
				sum++;
			}
		}

		for (vector<int>::iterator it = deleted.begin(); it != deleted.end(); it++) {
			v.erase(v.begin() + *it);
			s.erase((v.begin() + *it)->SID);
		}
		cout << sum << " student(s) removed." << endl;
	}
}

void query() {
	using namespace std;
	while (true) {
		cout << "Please enter SID or name. Enter 0 to finish." << endl;

		string tmp;
		cin >> tmp;

		if (tmp == "0") break;

		vector<Student> rank;
		for (vector<Student>::iterator it = v.begin(); it != v.end(); it++) {
			if (it->SID == tmp || it->name == tmp) {
				it->position = it - v.begin();
				// rank.push_back(*it);
			}
			rank.push_back(*it);
		}

		stable_sort(rank.begin(), rank.end());
		for (vector<Student>::iterator it = rank.begin(); it != rank.end(); it++) {
			if (it == rank.begin()) v[it->position].rank = 1;
			else if (it->sum == (it - 1)->sum) v[it->position].rank = v[(it - 1)->position].rank;
			else v[it->position].rank = it - rank.begin() + 1;
		}

		for (vector<Student>::iterator it = v.begin(); it != v.end(); it++) {
			if (it->SID == tmp || it->name == tmp) {
				cout << it->rank << " ";
				cout << it->SID << " " << it->CID << " " << it->name << " ";
				for (int i = 0; i < 4; i++) cout << it->score[i] << " ";
				cout << it->sum << " " ;
				printf("%.2lf\n", it->average);
			}
		}
	}
}

void calcWhole(int lesson, double &average, int &passed, int &notPassed) {
	using namespace std;
	int sum = 0;
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++) {
		sum += it->score[lesson];
		if (it->score[lesson] >= 60) passed++;
		else notPassed++;
	}
	average = (double)(sum) / v.size();
}

void printLesson(int i) {
	using namespace std;
	if (i == 0) cout << "Chinese" << endl;
	if (i == 1) cout << "Mathematics" << endl;
	if (i == 2) cout << "English" << endl;
	if (i == 3) cout << "Programming" << endl;
}

void statistics() {
	using namespace std;
	cout << "Please enter class ID, 0 for the whole statistics." << endl;
	string tmp;
	cin >> tmp;

	if (tmp == "0") {
		for (int i = 0; i < 4; i++) {
			int passed = 0, notPassed = 0;
			double average = 0;

			calcWhole(i, average, passed, notPassed);

			printLesson(i);

			printf("Average Score: %.2lf\n", average);
			cout << "Number of passed students: " << passed << endl;
			cout << "Number of failed students: " << notPassed << endl << endl;
		}

		int passedThree = 0, passedTwo = 0, passedOne = 0, failedALL = 0, passedAll = 0;
		for (vector<Student>::iterator it = v.begin(); it != v.end(); it++) {
			if (it->numberOfPassed >= 1) passedOne++;
			if (it->numberOfPassed >= 2) passedTwo++;
			if (it->numberOfPassed >= 3) passedThree++;
			if (it->numberOfPassed == 4) passedAll++;
			if (it->numberOfPassed == 0) failedALL++;
		}

		cout << "Overall:" << endl;
		cout << "Number of students who passed all subjects: " << passedAll << endl;
		cout << "Number of students who passed 3 or more subjects: " << passedOne << endl;
		cout << "Number of students who passed 2 or more subjects: " << passedTwo << endl;
		cout << "Number of students who passed 1 or more subjects: " << passedThree << endl;
		cout << "Number of students who failed all subjects: " << failedALL << endl << endl;
	} else {
		for (int i = 0; i < 4; i++) {
			int sum = 0, passed = 0, notPassed = 0;
			double average = 0;

			int numberOfStudents = 0;
			for (vector<Student>::iterator it = v.begin(); it != v.end(); it++) {
				if (it->CID == tmp || it->SID == tmp) {
					numberOfStudents++;
					sum += it->score[i];
					if (it->score[i] >= 60) passed++;
					else notPassed++;
				}
			}

			average = sum / (double)(numberOfStudents);

			printLesson(i);

			printf("Average Score: %.2lf\n", average);
			cout << "Number of passed students: " << passed << endl;
			cout << "Number of failed students: " << notPassed << endl << endl;
		}

		int passedThree = 0, passedTwo = 0, passedOne = 0, failedALL = 0, passedAll = 0;
		for (vector<Student>::iterator it = v.begin(); it != v.end(); it++) {
			if (it->CID == tmp || it->SID == tmp) {
				if (it->numberOfPassed >= 1) passedOne++;
				if (it->numberOfPassed >= 2) passedTwo++;
				if (it->numberOfPassed >= 3) passedThree++;
				if (it->numberOfPassed == 4) passedAll++;
				if (it->numberOfPassed == 0) failedALL++;
			}
		}

		cout << "Overall:" << endl;
		cout << "Number of students who passed all subjects: " << passedAll << endl;
		cout << "Number of students who passed 3 or more subjects: " << passedOne << endl;
		cout << "Number of students who passed 2 or more subjects: " << passedTwo << endl;
		cout << "Number of students who passed 1 or more subjects: " << passedThree << endl;
		cout << "Number of students who failed all subjects: " << failedALL << endl << endl;
	}
}

int main() {
	while (true) {
		printMenu();
		int x;
		std::cin >> x;
		if (x == 1) add();
		if (x == 2) remove();
		if (x == 3) query();
		if (x == 4) std::cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << std::endl;
		if (x == 5) statistics();
		if (x == 0) break;
	}

	return 0;
}
