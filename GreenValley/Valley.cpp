#include "Valley.h"

Valley::Valley(int s, int g)
{
	snow_lvl = s;
	grid_info = g;
}

void Valley::grid_maker()
{
	for(int i=0;i<grid_info;i++)
	{
		std::vector<int>temp;
		for(int j=0;j<grid_info;j++)
		{
			int var = 0;
			std::cin >> var;
			temp.emplace_back(var);
		}
		theGrid.emplace_back(temp);
	}
}

void Valley::findElement()
{
	for(int i=0;i<grid_info;i++)
	{
		for(int j=0;j<grid_info;j++)
		{
			if (theGrid.at(i).at(j) <= snow_lvl && theGrid.at(i).at(j) > -1) 
			{
				Valley_insert.emplace_back(theGrid.at(i).at(j));
				theGrid.at(i).at(j) = -1;
				search_combo(i, j);
				valley_storage.emplace_back(Valley_insert);
				Valley_insert.clear();
			}
		}
	}
}

void Valley::search_combo(int first, int second)
{
	if (first >0) 
	{
		if (theGrid.at(first - 1).at(second) <= snow_lvl && theGrid.at(first - 1).at(second) > -1)
		{
			Valley_insert.emplace_back(theGrid.at(first - 1).at(second));
			theGrid.at(first - 1).at(second) = -1;
			search_combo(first - 1, second);
		}
	} 
	if(first<grid_info-1)
	{
		if (theGrid.at(first + 1).at(second) <= snow_lvl && theGrid.at(first + 1).at(second) > -1)
		{
			Valley_insert.emplace_back(theGrid.at(first + 1).at(second));
			theGrid.at(first + 1).at(second) = -1;
			search_combo(first + 1, second);
		}
	} 
	if (second > 0)
	{
		if (theGrid.at(first).at(second - 1) <= snow_lvl && theGrid.at(first).at(second - 1) > -1)
		{
			Valley_insert.emplace_back(theGrid.at(first).at(second - 1));
			theGrid.at(first).at(second - 1) = -1;
			search_combo(first, second - 1);
		}
	} 
	if (second < grid_info-1)
	{
		if (theGrid.at(first).at(second + 1) <= snow_lvl && theGrid.at(first).at(second + 1) > -1)
		{
			Valley_insert.emplace_back(theGrid.at(first).at(second + 1));
			theGrid.at(first).at(second + 1) = -1;
			search_combo(first, second + 1);
		}
	}
}

int Valley::theDeepest()
{
	if (valley_storage.size() == 0)
		return 0;
	else {
		std::vector<int>rez;
		int current_size = valley_storage.at(0).size();
		for(int i=1;i<valley_storage.size();i++)
		{
			if (valley_storage.at(i).size() > current_size)
				current_size = valley_storage.at(i).size();
		}
		for (int i = 0; i < valley_storage.size(); i++)
		{
			if (valley_storage.at(i).size() == current_size) 
			{
				std::sort(valley_storage.at(i).begin(), valley_storage.at(i).end());
				rez.emplace_back(valley_storage.at(i).at(0));
			}
		}
		std::sort(rez.begin(), rez.end());
		return rez.at(0);
	}
}
