#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Valley
{
	int snow_lvl,grid_info;
	std::vector<std::vector<int>>theGrid;
	std::vector<std::vector<int>>valley_storage;
	std::vector<int> Valley_insert;
	void search_combo(int first, int second);
public:
	Valley(int s, int g);
	void grid_maker();
	void findElement();
	int theDeepest();

};

