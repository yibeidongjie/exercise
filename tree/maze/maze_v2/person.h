#pragma once
#include "map.h"
#include <string>

class MazePerson
{
public:
	// ���캯������������
	MazePerson(char s);
	~MazePerson();

	// ���ó�ʼλ�ã���ʼ����һ���ٶ� �Լ����Ϸ���
	bool setInitPosition(MazeMap &mp, int x, int y);
	bool setInitDirection(int * d);
	bool setSpeed(int sp);

	// ����궨λ�����꣨x��y������x >= 0�����õ� Windows.h
	void gotoXY(int x, int y);

	// �����ˣ�����ǰһ���Ĳ�Ӱ
	void drawPerson(MazeMap &mp, int x, int y);

	//��ʼ���Թ�
	void start(MazeMap &mp);
	
	// ��ת��ֻ�Ǹı��˵ķ���
	void turnLeft();
	
	// ��ת��ֻ�Ǹı��˵ķ���
	void turnRight();
	
	// �ƶ���������
	void move();
	
	// �鿴�����ڣ�ǰ�������ĸ����򣩵��ĸ��������
	void lookFourPoints(MazeMap &mp);


private:
	// �˵ķ��ţ��ڳ����л�����ƶ��ı�
	char m_strPerson;
	
	// ��ǰ����
	int m_iXNow, m_iYNow;
	
	//��һ��������
	int m_iXPre, m_iYPre;
	
	// ����
	int m_iDirection[4];  // [0]ǰ [1]�� [2]�� [3]��
	
						  // ��������ĸ��㣨ǰ�������ĸ����򣩵�����
	int m_iFourPoints[4][2]; // [0][]ǰ [1][]�� [2][]�� [3][]��
	int m_iSpeed;

	char m_strDirectionInput;
};
