#include <iostream>
#include "Valley.h"
#include <memory>

int main()
{
	int snow_line = 0, grid_lenght = 0;
	std::cout << "Insert an integer H representing the height of the snow line \n";
	std::cin >> snow_line;
	std::cout << "Insert an integer N for the length of one side of the map.\n";
	std::cin >> grid_lenght;
	std::unique_ptr<Valley>theValley = std::make_unique<Valley>(snow_line, grid_lenght);
	std::cout << "Create the map(shape of a square and it has the side of lenght " << grid_lenght << std::endl;
	theValley->grid_maker();
	theValley->findElement();
	std::cout << "The deepest point of the largest valley is: ";
	std::cout << theValley->theDeepest() << std::endl;
}


