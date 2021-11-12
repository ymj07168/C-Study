#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class BallGame {
private:
	// people {home, pos1, pos2, pos3}
	vector<int> people = { 1, 0, 0, 0 };
	vector<int> ballTypes;
	int ballNum = 0;
	int lossNum = 0;
public:
	BallGame(vector<int> ballTypes) {
		this->ballTypes = ballTypes;
	}
	void movePeople(int ballTypes) {
		// �� & ���� �´� ��
		if (ballTypes == 1 || ballTypes == 2) {
			if (ballTypes == 1) ballNum++;
			if (ballNum == 4 || ballTypes == 2) {
				if (people[1] && people[2] && people[3]) {
					people[3] = 0;
					lossNum++;
				}
				if (people[1] && people[2]) {
					people[3] = people[2];
					people[2] = 0;
				}
				if (people[1]) {
					people[2] = people[1];
					people[1] = 0;
				}
				people[1] = people[0];
				ballNum = 0;
			}
		}
		// ����
		else if (ballTypes == 3) {
			ballNum++;
			if (people[3]) {
				people[3] = 0;
				lossNum++;
			}
			if (people[2]) {
				people[3] = people[2];
				people[2] = 0;
			}
			if (people[1]) {
				people[2] = people[1];
				people[1] = 0;
			}
			// 4��° ���� ����
			if (ballNum == 4) {
				people[1] = people[0];
				ballNum = 0;
			}
		}
	}
	int getLoss() {
		for (int i = 0; i < ballTypes.size(); i++) {
			movePeople(ballTypes[i]);
		}
		return lossNum;
	}
};

int main(void) {
	int N;
	int ballType;
	vector<int> ballTypes;

	cout << "���� ���� ��: ";
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ballType;
		ballTypes.push_back(ballType);
	}

	BallGame ballgame(ballTypes);

	cout << ballgame.getLoss() << endl;
}
