/*
24-02-11 23:41 ~ 24:01

새롭게 알게된 내용
- sort함수에서 compare 함수 작성 : https://atomic0x90.github.io/c++/2020/02/22/c++-sort.html
- tuple 자료구조 : https://www.acmicpc.net/source/73259070
- compare 함수의 리팩토링 : https://www.acmicpc.net/source/73202542
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
};

Student students[100001];

bool compare(const Student& a, const Student& b) {
	if (a.korean > b.korean) {
		return true;
	}
	if (a.korean == b.korean) {
		if (a.english < b.english) {
			return true;
		}
		if (a.english == b.english) {
			if (a.math > b.math) {
				return true;
			}
			if (a.math == b.math) {
				if (a.name < b.name) {
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		Student& s = students[i];
		cin >> s.name >> s.korean >> s.english >> s.math;
	}
	
	sort(students, students + N, compare);

	for (int i = 0; i < N; i++) {
		Student& s = students[i];
		cout << students[i].name << "\n";
		//cout << s.name << s.korean << s.english << s.math << "\n";
	}

	return 0;
}