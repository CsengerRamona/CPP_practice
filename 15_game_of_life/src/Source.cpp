#include "Header.h"
#include <string>
#include <Windows.h>


Matrix::Matrix(size_t numColumnsX, size_t numLinesY) : column_count{ numColumnsX }, line_count{ numLinesY }
{
	matrixData.resize(numColumnsX, std::vector<char>(numLinesY));
}

void Matrix::print()
{
	for (int i = 0; i < line_count; i++)
	{
		for (int j = 0; j < column_count; j++)
		{
			std::cout << (matrixData[i][j] - 0)<< " ";
		}
		std::cout << std::endl;

	}
}

void Matrix::initialState(int x, int y)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			matrixData[i][j] = rand() % 2;
		}
	}
}

int Matrix::liveCellNumber(int x, int y, int row, int col)
{
	int counter{ 0 };
	for (int i = row - 1; i <= row + 1; i++)
	{
		for (int j = col - 1; j <= col + 1; j++)
		{
			if ((i == row && j == col) || (i < 0 || j < 0) || (i >= x || j >= y))
				continue;
			if (matrixData[i][j] == 1)
				counter++;
		}
	}
	return counter;
}

void Matrix::nextTransition(int x, int y)
{
	int liveCells{ 0 };

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			liveCells = liveCellNumber(x, y, i, j);
			if (matrixData[i][j] == 1)
			{
				if (liveCells < 2)
					matrixData[i][j] = 0;
				if((liveCells == 2) || (liveCells == 3))
					matrixData[i][j] = 1;
				if(liveCells > 4)
					matrixData[i][j] = 0;
			}
			else if((matrixData[i][j] == 0) && (liveCells == 3))
				matrixData[i][j] = 1;
			else
				matrixData[i][j] = 0;
		}
	}	
}

void Matrix::drawShape(Shapes shape, int x, int y)
{
	switch (shape)
	{
	case Block:
		matrixData[x][y] = 1;
		matrixData[x][y+1] = 1;
		matrixData[x+1][y] = 1;
		matrixData[x+1][y+1] = 1;
		break;
	case Boat:
		matrixData[x][y] = 1;
		matrixData[x][y + 1] = 1;
		matrixData[x][y + 2] = 0;
		matrixData[x + 1][y] = 1;
		matrixData[x + 1][y + 1] = 0;
		matrixData[x + 1][y + 2] = 1;
		matrixData[x + 2][y] = 0;
		matrixData[x + 2][y + 1] = 1;
		matrixData[x + 2][y + 2] = 0;
		break;
	case Blinker:
		matrixData[x][y] = 1;
		matrixData[x][y + 1] = 1;
		matrixData[x][y + 2] = 1;
		Sleep(1000);
		matrixData[x][y] = 0;
		matrixData[x][y + 1] = 0;
		matrixData[x][y + 2] = 0;
		Sleep(1000);
		matrixData[x][y] = 0;
		matrixData[x][y + 1] = 0;
		matrixData[x][y + 2] = 0;

		break;
	case Beacon:
		break;
	case Pulsar:
		break;
	case Glider:
		break;
	default:
		break;
	}
}

