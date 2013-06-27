#include "SpaceShipFactory.h"
#include "SpaceShips.h"
#include "Fleet.h"

int main()
{
	// Register SpaceShips by using the SpaceShipFactory::getInstance().registerSpaceShip with lambda functions.

	// TODO: Register TieFighter with SpaceShipFactory::getInstance().registerSpaceShip
	// The string parameter contains the pilot.
	SpaceShipFactory::getInstance().registerSpaceShip("TieFighter", TieFighter("Vader"));
	// TODO: Register DeathStar
	// The string parameter has to be interpreted a float, determining its buildProgress
	SpaceShipFactory::getInstance().registerSpaceShip("DeathStar", DeathStar(66.66));
	// TODO: Register Destroyer
	// The string parameter has to be interpreted a int, determining the number of lasers
	// Note that the a appropriate parameterized instance of the "Destroyer"-class should be created.
	SpaceShipFactory::getInstance().registerSpaceShip("Destroyer", Destroyer(false, 5));
	// TODO: Register LargeDestroyer
	// The string parameter has to be interpreted a int, determining the number of lasers.
	// Note that the a appropriate parameterized instance of the "Destroyer"-class should be created.
	SpaceShipFactory::getInstance().registerSpaceShip("Destroyer", Destroyer(true, 10));

	// Loads fleet from file
	Fleet imperialFleet("imperialships.txt");
}