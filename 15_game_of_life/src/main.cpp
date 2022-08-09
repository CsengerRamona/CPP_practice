#include <iostream>
#include <string>
#include <Windows.h>
#include "Header.h"

void clear_screen(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}


int main()
{
	int x{};
	int y{};
	bool flag = true;
	int ticks{};

	while (flag) {
		std::cout << "Enter the number of cells from the x axis: ";
		std::cin >> x;

		std::cout << "Enter the number of cells from the y axis: ";
		std::cin >> y;
		if ((x < 20) || (y < 20)) {
			std::cout << "Enter a number bigger than 20!" << std::endl;
		}
		else {
			flag = false;
			std::cout << "Choose the number of ticks: ";
			std::cin >> ticks;
		}
	}



	clear_screen();

	Matrix matrix(x, y);
	matrix.initialState(x, y);
	matrix.print();
	Sleep(5000);

	//std::cout << matrix.liveCellNumber(20, 20);


	while (ticks != 0)
	{
		matrix.nextTransition(x, y);
		clear_screen();
		matrix.print();
		Sleep(5000);
	}

	//std::cout << std::endl;
	//matrix.drawShape(Block, 0, 0);
	//matrix.print();

	//std::cout << std::endl;
	//matrix.drawShape(Boat, 0, 0);
	//matrix.print();

	//std::cout << std::endl;
	//matrix.drawShape(Blinker, 0, 0);
	//matrix.print();
	return 0;
}