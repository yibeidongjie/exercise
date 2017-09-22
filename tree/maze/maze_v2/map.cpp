#include "public.h"
#include "map.h"
#include <iostream>
#include <string>
using namespace std;


MazeMap::MazeMap(int row, int col, char wall, char road, int outX, int outY) : m_strWall(wall), m_strRoad(road), m_iRow(row), m_iCol(col), m_iOutX(outX), m_iOutY(outY)
{
	// �����ڴ档ע�⣺һ��Ҫ�ڹ��캯���������ڴ棨����������Ա�����������ڴ棩�����ܱ�֤�����������ͷ��ڴ��ʱ�򲻻����
	int i;
	m_strArr = new char *[m_iRow];
	for (i = 0; i < m_iRow; i++) {
		m_strArr[i] = new char[m_iCol];
	}
	//ע�������ڴ���ͷ��ڴ�ķ�ʽ����ʱ������������
}

MazeMap::~MazeMap()
{
	int i;
	for (i = 0; i < m_iRow; i++) {
		delete[] m_strArr[i];
		m_strArr[i] = nullptr;
	}
	delete[] m_strArr;
	m_strArr = nullptr;
}

void MazeMap::setMap(int *map)
{
	int i, j;
	for (i = 0; i < m_iRow; i++) {
		for (j = 0; j < m_iCol; j++) {
			if (WALL == *map) {
				m_strArr[i][j] = m_strWall;
			}
			else {
				m_strArr[i][j] = m_strRoad;
			}
			map++;
		}
	}
}

void MazeMap::drawMap()
{
	int i, j;	
	for (i = 0; i < m_iRow; i++) {
		for (j = 0; j < m_iCol; j++) {
			cout << m_strArr[i][j];
		}
		cout << endl;
	}
}



bool MazeMap::isWall(MazeMap &mp, int x, int y)
{
	// ע�� x ���У� y ����
	if (mp.m_strWall == mp.m_strArr[y][x]) {
		return true;
	}
	else {
		return false;
	}
}

int MazeMap::getMapRow(MazeMap &mp)
{
	return mp.m_iRow;
}
int MazeMap::getMapCol(MazeMap &mp)
{
	return mp.m_iCol;
}
char MazeMap::getWallStr(MazeMap &mp)
{
	return mp.m_strWall;
}
char MazeMap::getRoadStr(MazeMap &mp)
{
	return mp.m_strRoad;
}
int MazeMap::getOutX(MazeMap &mp)
{
	return mp.m_iOutX;
}
int MazeMap::getOutY(MazeMap &mp)
{
	return mp.m_iOutY;
}