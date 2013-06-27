#include "SpaceShipFactory.h"

// If SpaceShips.h would be not included, the SpaceShip's destructor would be unknown.
// This leads normally to a warning
#include "SpaceShips.h"
typedef std::function<std::shared_ptr<SpaceShip>(const std::string& parameter)> CreateSpaceShipFunc;

// TODO

std::shared_ptr<SpaceShip> SpaceShipFactory::buildSpaceShip(const std::string& spaceShipTypeName, const std::string& parameter){
	std::unordered_map<std::string, CreateSpaceShipFunc>::const_iterator got = m_createSpaceShipFuncRegister.find (spaceShipTypeName);
	std::shared_ptr<SpaceShip> ship;
	if ( got == m_createSpaceShipFuncRegister.end() )
		return NULL;
	else
		ship = got->second(parameter);

	return ship;
}

void SpaceShipFactory::registerSpaceShip(const std::string& spaceShipTypeName, const CreateSpaceShipFunc& createSpaceShipFunc){
	std::pair<std::string, CreateSpaceShipFunc> ship (spaceShipTypeName ,createSpaceShipFunc);
	m_createSpaceShipFuncRegister.insert(ship);
}