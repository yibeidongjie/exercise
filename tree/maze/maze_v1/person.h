#pragma once
#include "map.h"
#include <string>

class MazePerson
{
public:
	// 构造函数和析构函数
	MazePerson(char s);
	~MazePerson();

	// 设置初始位置，初始方向，一定速度 以及检查合法性
	bool setInitPosition(MazeMap &mp, int x, int y);
	bool setInitDirection(int * d);
	bool setSpeed(int sp);

	// 将光标定位到坐标（x，y）处，x >= 0，会用到 Windows.h
	void gotoXY(int x, int y);

	// 绘制人，擦除前一步的残影
	void drawPerson(MazeMap &mp, int x, int y);

	//开始走迷宫
	void start(MazeMap &mp);
	
	// 左转，只是改变人的方向
	void turnLeft();
	
	// 右转，只是改变人的方向
	void turnRight();
	
	// 移动，并绘制
	void move();
	
	// 查看人相邻（前后左右四个方向）的四个点的坐标
	void lookFourPoints(MazeMap &mp);

private:
	// 人的符号，在程序中会根据移动改变
	char m_strPerson;
	
	// 当前坐标
	int m_iXNow, m_iYNow;
	
	//上一步的坐标
	int m_iXPre, m_iYPre;
	
	// 方向
	int m_iDirection[4];  // [0]前 [1]后 [2]左 [3]右
	
						  // 存放相邻四个点（前后左右四个方向）的坐标
	int m_iFourPoints[4][2]; // [0][]前 [1][]后 [2][]左 [3][]右
	int m_iSpeed;
};
