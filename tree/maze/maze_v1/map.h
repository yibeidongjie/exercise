#pragma once

#define mapRowMax 50
#define mapColMax 50

class MazeMap
{
public:
	// 构造函数和析构函数
	MazeMap(int row, int col, char wall = '#', char road = ' ', int outX = 9, int outY = 2);
	~MazeMap();

	// 根据输入 map 设置地图的值
	void setMap(int *map);

	// 绘制地图
	void drawMap();

	
	// 静态链接函数，方便使用	
	
	// 判断是否为墙，注意：x是列，y是行（区分行列很重要）
	static bool isWall(MazeMap &mp, int x, int y);
	
	// 获得地图的行数
	static int getMapRow(MazeMap &mp);
	
	// 获得地图的列数
	static int getMapCol(MazeMap &mp);
	
	//获得地图的墙的符号
	static char getWallStr(MazeMap &mp);
	
	//获得地图路的符号
	static char getRoadStr(MazeMap &mp);
	
	//获取地图出口坐标
	static int getOutX(MazeMap &mp);
	static int getOutY(MazeMap &mp);

private:
	const char m_strWall;
	const char m_strRoad;
	const int m_iRow;
	const int m_iCol;
	const int m_iOutX;
	const int m_iOutY;
	char **m_strArr; //地图符号
};