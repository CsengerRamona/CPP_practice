#pragma once
#include <vector>
#include <iostream>

enum Shapes
{
	Block,
	Boat,
	Blinker,
	Beacon,
	Pulsar,
	Glider
};

class Matrix
{
private:
	size_t column_count;
	size_t line_count;
	std::vector<std::vector<char>> matrixData;

public:
	Matrix(size_t numColumnsX, size_t numLinesY);

	void initialState(int x, int y);

	int liveCellNumber(int x, int y, int row, int col);

	void nextTransition(int x, int y);

	void drawShape(Shapes, int x, int y);

	void print();

};


