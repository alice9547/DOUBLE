#include<iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>


#define MAX 6
#define ESC 27
#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#define delay(n) Sleep(n)

using namespace std;

class Player {
	static int money;//���
	int batting;//���ñ�
	int selectmal;//�����Ѹ�

public:

	void Setmoney(int j) { money = j; }
	void Setbatting(int i) {
		batting = i;
	}
	int Getbatting() { return batting; }

	void Setmal(int j) {
		selectmal = j;
	}
	int Getmal() { return selectmal; }
	int Getmoney() { return money; }



};

int Player::money = 1000;

class mal {
	int x;
	int y;
	int oper;
	const char *ch_1;
	const char *ch_2;
	char ch[3];
	int nFrame;               // �ӵ�
	int nStay;				// �ӵ��� ���� ī��Ʈ
	bool RL;

public:
	mal() { RL = true; };
	mal operator --();
	mal operator ++();
	void gotomal(int x, int y) {
		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);


	};


	void Setgotoxy(int a, int b);
	void Setx(int a) { x = a; };
	void Sety(int b) { y = b; };
	int Getx() { return x; };
	int Gety() { return y; };
	void SetRL(bool a) { RL = a; };
	bool GetRL() { return RL; };
	//	void Setch_1(string ch = "o_") { ch_1 = ch; };
	void Setch_1(const char *a = "o_") { ch_1 = a; };
	void Getch_1() { puts(ch_1); }
	void Setch_2(const char *b = "_o") { ch_2 = b; };
	void Getch_2() { puts(ch_2); };
	void SetF(int a) { nFrame = a; };
	int GetF() { return nFrame; };
	void SetS(int a) { nStay = a; };
	int GetS() { return nStay; };
	void Setoper(int a) { oper = a; };
	int Getoper() { return oper; };

};

mal mal::operator ++()
{

	++oper;
	return *this;
}

mal mal::operator --()
{

	--oper;
	return *this;
}

class game :public Player, public mal {
	int x;
	int y;
	int goal1;
	int goal2;
public:
	game() { goal1 = -1; goal2 = -1; };
	void Setgoal1(int a) { goal1 = a; };
	int Getgoal1() { return goal1; };
	void Setgoal2(int a) { goal2 = a; };
	int Getgoal2() { return goal2; };
	void Setgotoxy(int a, int b);
	void gamemain();
	void endgame();
	void clrscr();
	void gamedelay();
};

void game::clrscr()
{
	system("cls");
}

void game::gamedelay()
{
	delay(1000 / 200);
}
void game::Setgotoxy(int a, int b)
{
	x = a;
	y = b;
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}

void game::gamemain()
{
	int battingm;
	int nowmoney;
	int playmal;
	char dab;
	cout << "\n";
	cout << "\t                   @@ ���� ����� �� @@                        " << "\n";
	cout << "\t*******************************************************************" << "\n";
	cout << "\t*          __  _                                                  *" << "\n";
	cout << "\t*      .-.'  `; `-._  __  _                                       *" << "\n";
	cout << "\t*     (_,         .-:'  `; `-. __     �� �� ��  �� �� �� �� ~ !   *" << "\n";
	cout << "\t*     ,'o-(        (_             )                               *" << "\n";
	cout << "\t*   (__,-'        ,'o-(            )>                             *" << "\n";
	cout << "\t*       (       (__,-'            )     �� �� �� ~ !              *" << "\n";
	cout << "\t*        `-'._.--._(             )                                *" << "\n";
	cout << "\t*           |||  |||`-'._.--._.-'                                 *" << "\n";
	cout << "\t*                      |||  |||    �� �� ��  �� �� �� �� ��~ !    *" << "\n";
	cout << "\t*                                                                 *" << "\n";
	cout << "\t*******************************************************************" << "\n";
	cout << "\t*   �������� ������ ���� ������ �������� �̿��Ͻ� �� �����ϴ�.    *" << "\n";
	cout << "\t*******************************************************************" << "\n";

	cout << "\n\n" << "���� ������ �ݾ�:" << Getmoney() << "\n";
	cout << "\n" << "�󸶸� ���� �Ͻðڽ��ϱ�??";
	cin >> battingm;
	while (battingm == Getmoney()) {
		cout << "�����ϸ� ���а� �˴ϴ�." << endl;
		cout << "\n" << "�� �����ε� "<<battingm<< "�� �¿�ðڽ��ϱ�? (y or n)";
		cin >> dab;
		if (dab == 'y')
		{
			Setbatting(battingm);
			nowmoney = Getmoney() - Getbatting();
			Setmoney(nowmoney);
			goto xx;
		}
		else
			cout << "\n" << "�󸶸� ���� �Ͻðڽ��ϱ�??";
			cin >> battingm;
			Setbatting(battingm);
	}
	

	while ((Getmoney() < Getbatting()) || (Getbatting() <= 0)) {
		cout << "\n" << "������ �ݾ��� �ùٸ��� �ʽ��ϴ�";
		cout << "�󸶸� �����Ͻðڽ��ϱ�?";
		cin >> battingm;
		Setbatting(battingm);
	}
	nowmoney = Getmoney() - Getbatting();
	Setmoney(nowmoney);

	xx: do {
		cout << "\n" << "������� �����Ͻðڽ��ϱ�?(1~6)";
		cin >> playmal;
		Setmal(playmal);
	} while ((Getmal() > 6) || (Getmal() < 1));
}
void game::endgame()
{
	clrscr();
	int bea;
	char restart;
	bea = random(5) + 2;

	if (Getmoney() <= 1) {
		cout << "���̻� ������ ������ ���� �����ϴ�" << endl;
		cout << "������ ����� �Ͻðڽ��ϱ�?(y,n)" << endl;
		cin >> restart;

		if (restart == 'y') {
			Setmoney(1000);
			clrscr();
		}
		else
			exit(0);
	}
	else {
		if (Getmal() == Getgoal1()) {
			cout << "   ���ϵ帳�ϴ�. ^^*" << endl;
			cout << "   ���ñݾ� :" << Getbatting() << endl;
			cout << "   ���� �ݾ� (���þ� *" << bea << "):" << Getbatting()*bea << endl;
			Setmoney(Getmoney() + Getbatting()*bea);
			cout << "   ����� : " << Getmoney() << endl;
		}
		else if (Getmal() == Getgoal2()) {
			cout << "   2���̱⿡ ����� �ݾ��� �����帳�ϴ�." << endl;
			cout << "   ���ñݾ� :" << Getbatting() << endl;
			cout << "   ���� �ݾ� (���þ� * 1) :" << Getbatting() << endl;
			Setmoney(Getmoney() + Getbatting());
			cout << "   ����� : " << Getmoney() << endl;
		}
		else {
			cout << "   ����� �ݾ��� �����̽��ϴ�" << endl;
			cout << "   ���ñݾ� : " << Getbatting() << endl;
			cout << "   ���� �ݾ� : " << Getbatting() << endl;
			cout << "   ����� : " << Getmoney() << endl;;
		}
	}

}



int main() {
	while (1) {
		mal playmal[MAX];
		game me;
		me.gamemain();
		me.clrscr();
		randomize();
		int i;
		//********************************************���ӽ��۸���*******************************************
		for (i = 0; i < MAX; i++) {

			//		memcpy(S[i].ch,ch_1,sizeof(ch_1));
			playmal[i].Setch_1();
			playmal[i].Setch_2();
			playmal[i].Setx(74);
			playmal[i].Sety((i * 3) + 3);
			me.Setgotoxy(76, playmal[i].Gety());
			//playmal[i].Getch_1();
			cout << i + 1 << endl;
			playmal[i].SetF(random(15) + 5);
			playmal[i].SetS(random(15) + 5);
			//me.Setgotoxy(74,playmal[i].Gety());		
		}
		me.Setgotoxy(50, 20);
		cout << "\n" << "\n" << "��������� ESCŰ �Դϴ�" << endl;
		me.Setgotoxy(50, 23);
		cout << "\n" << "���þ�:" << me.Getbatting() << " ����ȣ:" << me.Getmal() << endl;
		//******************************************���� ����****************************************************
		for (; me.Getgoal2() < 0;) {
			for (i = 0; i < MAX; i++) {
				// �������� �޸��� ���
				if (playmal[i].GetRL() == TRUE) {
					playmal[i].Setoper(playmal[i].GetS());
					--playmal[i];
					playmal[i].SetS(playmal[i].Getoper());

					if (playmal[i].GetS() == 0) {
						playmal[i].SetS(playmal[i].GetF());
						playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
						puts("  ");

						if (playmal[i].Getx() > 0) {
							playmal[i].Setoper(playmal[i].Getx());
							--playmal[i];
							playmal[i].Setx(playmal[i].Getoper());
							playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
							playmal[i].Getch_1();

						}
					}
				}

				//�������� �޸��� ���
				else if (playmal[i].GetRL() == FALSE) {
					if (playmal[i].GetF() == 0)
						continue;
					playmal[i].Setoper(playmal[i].GetS());
					--playmal[i];
					playmal[i].SetS(playmal[i].Getoper());
					if (playmal[i].GetS() == 0) {
						playmal[i].SetS(playmal[i].GetF());
						playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
						puts("  ");

						if (playmal[i].Getx() < 75) {
							playmal[i].Setoper(playmal[i].Getx());
							++playmal[i];
							playmal[i].Setx(playmal[i].Getoper());
							playmal[i].gotomal(playmal[i].Getx(), playmal[i].Gety());
							playmal[i].Getch_2();
						}

						//�������� Ȯ��
						else {
							if (me.Getgoal1() < 0) {
								me.Setgoal1(i + 1);
								me.Setgotoxy(9, 21);
								cout << "1����" << me.Getgoal1() << "������ �¸��� �����Ͽ����ϴ�" << endl;
								playmal[i].SetF(0);
							}
							else if (me.Getgoal2() < 0) {
								me.Setgoal2(i + 1);
								me.Setgotoxy(9, 22);
								cout << "2����" << me.Getgoal2() << "������ �¸��� �����Ͽ����ϴ�" << endl;
								//playmal[i].SetF(0);
								delay(1500);
							}
						}
					}
				}
				//��ȯ��������� Ȯ��
				if (playmal[i].GetRL() == TRUE) {
					if (playmal[i].Getx() == 1) {
						playmal[i].SetRL(FALSE);
						randomize();
						playmal[i].SetF(random(18) + 5);
						playmal[i].SetS(random(18) + 5);
					}
				}


			}delay(1000 / 100);

		}
		me.endgame();
	}
	return 0;
}