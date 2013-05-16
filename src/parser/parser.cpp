#include "Functions.h"
#include <fstream>
#include <iostream>
#include <regex>

std::string readFileToString(const std::string& filename)
{
	std::string file;
	std::string temp;
	std::fstream myfile;
	myfile.open(filename);
	while (getline(myfile, temp)) {  
		file.append(temp);
		//std::cout << file << std::endl << std::endl;
    }
	myfile.close();
	return file;
}

Table itemArrayFromCSV(const std::string& csv)
{
	Table table;
	std::vector<std::string> cell;
	std::regex e ("([A-Z])([a-z]*)|[[:digit:]]|(\\x2d)");
	std::sregex_iterator rit ( csv.begin(), csv.end(), e );
	std::sregex_iterator rend;
	while(rit!=rend) {
		if (rit->str()[0] == '1' || rit->str()[0] == '2' || rit->str()[0] == '3') {
			table.push_back(cell);
			cell.clear();
			//std::cout << std::endl;
		}
		cell.push_back(rit->str());
		//std::cout << rit->str() << " | ";
		++rit;
	}
	
	return table;
}

void printTable(const Table& table)
{
	for (int x = 0; x<table.size(); x++){
		for (int y = 0; y<table[0].size(); y++){
			std::cout << table[x][y] << " | ";
		}
		std::cout <<std::endl;
	}
}