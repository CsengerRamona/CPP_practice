#include <iostream>
#include <string>
#include <vector>

/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count;
	size_t line_count;
	//std::string data;
	std::vector<std::string> matrixData;

	// TODO: store the data
	// hints: you can use std::string, std::vectors + string, char**, vector<vector<char>>, etc
public:
	Matrix(size_t numColumnsX, size_t numLinesY) : column_count{numColumnsX}, line_count{numLinesY}
		// TODO: add functionality
	{
		matrixData.resize(numLinesY);
		// TODO: add functionality
	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& data)
	{
		if (line_number < matrixData.size())
			matrixData[line_number] = data;
	}

	//OPTIONAL
	char getCellXY(size_t x, size_t y)
	{
		// TODO: add functionality
		char cell_content = matrixData[y][x];
		return cell_content;
	}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1                     
		 |       0,2                      
		 .                             
		 .                             
		 .                             
		 |       0, H-1     ...          W-1, H-1           
		 V

		 Height
	*/
	void setCellXY(size_t x, size_t y, char cell_content)
	{
		// TODO: add functionality
		if((y < line_count) && (x < column_count))
			matrixData[y][x] = cell_content;
	}

	void print()
	{
		// print all lines and columns
		for (int i = 0; i < line_count; i++)
		{
			std::cout << matrixData[i] << std::endl;
		}
		std::cout << std::endl;
		// TODO: add functionality
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");

	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/
	matrix.setCellXY(2, 1, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellXY(3, 7, 'O');
	matrix.print();
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
---O---------------X
------------------X-
-----------------X--
*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellXY(3, 11, 'O');

	std::cout << matrix.getCellXY(1, 1);
	return 0;
}