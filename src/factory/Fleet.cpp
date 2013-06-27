#include "Fleet.h"
#include "SpaceShipFactory.h"

#include <fstream>
#include <assert.h>
#include <vector>

Fleet::Fleet(const std::string& fleetFilename)
{

	// TODO:
	// * Open textfile in "fleetFilename"
	// * Parse line by line:
	// ** Seperate in shipname and parameter at the first ' '
	// ** call SpaceShipFactory::getInstance().buildSpaceShip
	// ** push into m_spaceShips if a new ship was successfully created
	std::string file;
	std::string temp;
	std::fstream myfile;
	myfile.open(fleetFilename);
	while (getline(myfile, temp)) {  
		file.append(temp);
		file.append(""+'\n');
		//std::cout << file << std::endl << std::endl;
    }
	myfile.close();
	int i;
	std::shared_ptr<SpaceShip> ship;
	while (file.size > 0){
		i = file.find_first_of('\n');
		temp = file.substr(0, i-1);
		file.erase(0, i);
		i = temp.find_first_of(' ');
		ship = SpaceShipFactory::getInstance().buildSpaceShip(temp.substr(0, i-1), temp.substr(i+1, temp.size()));
		if (ship != NULL) m_spaceShips.push_back(ship);
	}
}