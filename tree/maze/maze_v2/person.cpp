#include "public.h"
#include "person.h"
#include "map.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

MazePerson::MazePerson(char s)
{
	m_strPerson = s;
}

MazePerson::~MazePerson()
{

}

bool MazePerson::setInitPosition(MazeMap &mp, int x, int y)
{
	if(MazeMap::isWall(mp, x, y)) {
		cout << endl;
		cout << "初始位置是墙，请重新开始" << endl;
		cout << endl;
		return false;
	}
	if (x < 0 || y < 0 || x >= (int)(mp.getMapCol) || y >= (int)(mp.getMapRow)) {
		cout << endl;
		cout << "初始位置是墙，请重新开始" << endl;
		cout << endl;
		return false;
	}
	
	m_iXPre = x;
	m_iYPre = y;
	m_iXNow = x;
	m_iYNow = y;

	return true;
}
bool MazePerson::setInitDirection(int * d)
{
	int i;
	for (i = 0; i < 4; i++) {
		if (d[i] != EAST && d[i] != WEST && d[i] != SOUTH && d[i] != NORTH) {
			cout << endl;
			cout << "初始方向设置有误，请重新开始" << endl;
			cout << endl;
			return false;
		}
	}

	for (i = 0; i < 4; i++) {
		m_iDirection[i] = *d;
		d++;
	}
	return true;
}
bool MazePerson::setSpeed(int sp)
{
	if (sp != FAST && sp != NORMAL && sp != SLOW) {
		cout << endl;
		cout << "初始速度设置有误，请重新开始" << endl;
		cout << endl;
	}
	m_iSpeed = sp;
	return true;
}


void MazePerson::gotoXY(int x, int y)
{
	COORD cd;
	cd.X = x;
	cd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}
void MazePerson::drawPerson(MazeMap &mp, int x, int y)
{
	// 先擦除原来位置的字符，再在原来的位置上补上路的字符
	gotoXY(m_iXPre, m_iYPre);
	cout << ' ';
	//gotoXY(m_iXPre, m_iYPre);
	//cout << (char)(mp.getRoadStr);

	//先将下一个点的字符擦除，再在该处补上人的字符
	//gotoXY(x, y);
	//cout << ' ';
	gotoXY(x, y);
	cout << m_strPerson;
}

void MazePerson::start(MazeMap &mp)
{
	bool notComeOut = true;
	int nStep = 0;
	bool frontIsWall;
	bool leftIsWall;

	gotoXY(5, MAP_ROW_MAX + 1);
	cout << "                                                  ";
	gotoXY(5, MAP_ROW_MAX + 1);
	cout << "Input direction(w s a d):";

	while (notComeOut && nStep <= STEP_MAX) {
		if ( m_iXNow == OUT_X && m_iYNow == OUT_Y ) {
			notComeOut = false;
			cout << endl;
			cout << "恭喜你走出迷宫，共走了" << nStep << "步" << endl;
			cout << endl;
		}
		else {
			

			// 实现交互 wsad 或者 WSAD 或者 箭头
			bool inputIsGood = true;
			
			
			char tmpChar;
			//tmpChar = cin.get();
			tmpChar = getch();

			gotoXY(30, MAP_ROW_MAX + 1);
			cout << tmpChar;

			if (tmpChar == 'W' || tmpChar == 'w') {
				m_iDirection[0] = NORTH;
				m_iDirection[1] = SOUTH;
				m_iDirection[2] = EAST;
				m_iDirection[3] = WEST;
			}
			else if (tmpChar == 'S' || tmpChar == 's') {
				m_iDirection[0] = SOUTH;
				m_iDirection[1] = NORTH;
				m_iDirection[2] = WEST;
				m_iDirection[3] = EAST;
			}
			else if (tmpChar == 'A' || tmpChar == 'a') {
				m_iDirection[0] = EAST;
				m_iDirection[1] = WEST;
				m_iDirection[2] = SOUTH;
				m_iDirection[3] = NORTH;
			} 
			else if (tmpChar == 'D' || tmpChar == 'd') {
				m_iDirection[0] = WEST;
				m_iDirection[1] = EAST;
				m_iDirection[2] = NORTH;
				m_iDirection[3] = SOUTH;
			}
			else {
				inputIsGood = false;				
			}

			if (inputIsGood) {
				lookFourPoints(mp);
				frontIsWall = mp.isWall(mp, m_iFourPoints[0][0], m_iFourPoints[0][1]);
				if (!frontIsWall) {
					move();
					drawPerson(mp, m_iXNow, m_iYNow);
					nStep++;
					gotoXY(35, MAP_ROW_MAX + 1);
					cout << "                     ";
				}
				else {
					gotoXY(35, MAP_ROW_MAX + 1);
					cout << "输入的方向前面是墙壁";
				}
			
				gotoXY(0, MAP_ROW_MAX + 1); cout << nStep;
				Sleep(m_iSpeed);
			}

			

		}
				
	}

	if (notComeOut) {
		cout << endl;
		cout << "抱歉，超时了，你共走了" << nStep << "步" << endl;
		cout << endl;
	}

}
void MazePerson::turnLeft()
{
	int tmp;
	tmp = m_iDirection[0];
	m_iDirection[0] = m_iDirection[2];
	m_iDirection[2] = m_iDirection[1];
	m_iDirection[1] = m_iDirection[3];
	m_iDirection[3] = tmp;
}
void MazePerson::turnRight()
{
	int tmp;
	tmp = m_iDirection[0];
	m_iDirection[0] = m_iDirection[3];
	m_iDirection[3] = m_iDirection[1];
	m_iDirection[1] = m_iDirection[2];
	m_iDirection[2] = tmp;
}
void MazePerson::move()
{
	m_iXPre = m_iXNow;
	m_iYPre = m_iYNow;

	if (m_iDirection[0] == NORTH) {
		m_iYNow--;
	}
	else if (m_iDirection[0] == SOUTH) {
		m_iYNow++;
	}
	else if (m_iDirection[0] == EAST) {
		m_iXNow--;
	}
	else {
		m_iXNow++;
	}

}
void MazePerson::lookFourPoints(MazeMap &mp)
{
	if (m_iDirection[0] == NORTH) {
		m_strPerson = '^';
		if (m_iYNow - 1 >= 0) {
			m_iFourPoints[0][0] = m_iXNow;
			m_iFourPoints[0][1] = m_iYNow - 1;
		}

		if (m_iYNow + 1 < (int)mp.getMapRow) {
			m_iFourPoints[1][0] = m_iXNow;
			m_iFourPoints[1][1] = m_iYNow + 1;
		}
		
		if (m_iXNow - 1 >= 0) {
			m_iFourPoints[2][0] = m_iXNow - 1;
			m_iFourPoints[2][1] = m_iYNow;
		}
		
		if (m_iXNow + 1 < (int)mp.getMapCol) {
			m_iFourPoints[3][0] = m_iXNow + 1;
			m_iFourPoints[3][1] = m_iYNow;
		}
		
	}
	else if (m_iDirection[0] == SOUTH) {
		m_strPerson = 'v';
		if (m_iYNow + 1 < (int)mp.getMapRow) {
			m_iFourPoints[0][0] = m_iXNow;
			m_iFourPoints[0][1] = m_iYNow + 1;
		}

		if (m_iYNow - 1 >= 0) {
			m_iFourPoints[1][0] = m_iXNow;
			m_iFourPoints[1][1] = m_iYNow - 1;
		}

		if (m_iXNow + 1 < (int)mp.getMapCol) {
			m_iFourPoints[2][0] = m_iXNow + 1;
			m_iFourPoints[2][1] = m_iYNow;
		}

		if (m_iXNow - 1 >= 0) {
			m_iFourPoints[3][0] = m_iXNow - 1;
			m_iFourPoints[3][1] = m_iYNow;
		}
	}
	else if (m_iDirection[0] == EAST) {
		m_strPerson = '<';
		if (m_iXNow - 1 >= 0) {
			m_iFourPoints[0][0] = m_iXNow - 1;
			m_iFourPoints[0][1] = m_iYNow;
		}

		if (m_iXNow + 1 < (int)mp.getMapCol) {
			m_iFourPoints[1][0] = m_iXNow + 1;
			m_iFourPoints[1][1] = m_iYNow;
		}

		if (m_iYNow + 1 < (int)mp.getMapRow) {
			m_iFourPoints[2][0] = m_iXNow;
			m_iFourPoints[2][1] = m_iYNow + 1;
		}

		if (m_iYNow - 1 >= 0) {
			m_iFourPoints[3][0] = m_iXNow;
			m_iFourPoints[3][1] = m_iYNow - 1;
		}
	}
	else {
		if (m_iXNow + 1 < (int)mp.getMapCol) {
			m_strPerson = '>';
			m_iFourPoints[0][0] = m_iXNow + 1;
			m_iFourPoints[0][1] = m_iYNow;
		}

		if (m_iXNow - 1 >= 0) {
			m_iFourPoints[1][0] = m_iXNow - 1;
			m_iFourPoints[1][1] = m_iYNow;
		}

		if (m_iYNow - 1 >= 0) {
			m_iFourPoints[2][0] = m_iXNow;
			m_iFourPoints[2][1] = m_iYNow - 1;
		}

		if (m_iYNow + 1 < (int)mp.getMapRow) {
			m_iFourPoints[3][0] = m_iXNow;
			m_iFourPoints[3][1] = m_iYNow + 1;
		}
	}
}







