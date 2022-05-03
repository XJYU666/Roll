#include<\\192.168.2.2\xjyu\Develop\lib\cpp_head\stdc++.h>
#define random(x) rand()%(x)
using namespace std;

bool Roll_Answer[100] = { 0 };
int Roll(int faceNumber_Int, int times_Int, bool flagRecur_Bool) {
	int turnPlace_Int = 0,rollTemp = 0;
	bool flagtemp_Bool = true;
	srand((int)time(0));
	if(faceNumber_Int>0){
		if (flagRecur_Bool) {
			if (faceNumber_Int >= times_Int) {
				while (turnPlace_Int < times_Int) {
					rollTemp = random(faceNumber_Int);
					flagtemp_Bool = true;
					for (int i = 0; i <= times_Int; i++) {
						if (Roll_Answer[i] == rollTemp) {
							flagtemp_Bool = false;
							break;
						}
					}
					if (flagtemp_Bool) {
						if (rollTemp == 0) {
							rollTemp = faceNumber_Int;
						}
						Roll_Answer[turnPlace_Int] = rollTemp;
						turnPlace_Int++;
					}
				}
				return true;
			}else {
				return false;
			}
		}else{
			for (int i = 0; i <= times_Int; i++) {
				rollTemp = random(faceNumber_Int);
				if (rollTemp == 0) {
					rollTemp = faceNumber_Int;
				}
				Roll_Answer[i] = rollTemp;
			}
			return true;
		}
	}else{
		return false;
	}
}

int main() {
	int faceNumber_Int = 0, times_Int = 0, flagRecur_Bool = true;
	char faceNumber_Char;
	cout << "骰子面数：";
	cin >> faceNumber_Int;
	cout << endl;
	cout << "投骰次数：";
	cin >> times_Int;
	cout << endl;
	cout << "是否查重(y/n)：";
	cin >> faceNumber_Char;
	cout << endl;
	switch (faceNumber_Char) {
	case 'y':
		flagRecur_Bool = true;
		break;
	case 'n':
		flagRecur_Bool = false;
		break;
	default:
		cout << "Error" << endl;
		exit(-1);
	}

	if (Roll(faceNumber_Int, times_Int, flagRecur_Bool)) {
		Roll(faceNumber_Int, times_Int, flagRecur_Bool);
	}else {
		cout << "Error" << endl;
		exit(-1);
	}

	for (int i = 0; i <= times_Int; i++) {
		if (i > 0) {
			cout << ',';
		}
		cout << Roll_Answer[i];
	}
	cout << endl;
	system("pause");
	return 0;
}