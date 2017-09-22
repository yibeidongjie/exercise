#pragma once

#define mapRowMax 50
#define mapColMax 50

class MazeMap
{
public:
	// ���캯������������
	MazeMap(int row, int col, char wall = '#', char road = ' ', int outX = 9, int outY = 2);
	~MazeMap();

	// �������� map ���õ�ͼ��ֵ
	void setMap(int *map);

	// ���Ƶ�ͼ
	void drawMap();

	
	// ��̬���Ӻ���������ʹ��	
	
	// �ж��Ƿ�Ϊǽ��ע�⣺x���У�y���У��������к���Ҫ��
	static bool isWall(MazeMap &mp, int x, int y);
	
	// ��õ�ͼ������
	static int getMapRow(MazeMap &mp);
	
	// ��õ�ͼ������
	static int getMapCol(MazeMap &mp);
	
	//��õ�ͼ��ǽ�ķ���
	static char getWallStr(MazeMap &mp);
	
	//��õ�ͼ·�ķ���
	static char getRoadStr(MazeMap &mp);
	
	//��ȡ��ͼ��������
	static int getOutX(MazeMap &mp);
	static int getOutY(MazeMap &mp);

private:
	const char m_strWall;
	const char m_strRoad;
	const int m_iRow;
	const int m_iCol;
	const int m_iOutX;
	const int m_iOutY;
	char **m_strArr; //��ͼ����
};