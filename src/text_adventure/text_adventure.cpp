#include <iostream>
#include "adventure1.h"
#include "adventure2.h"

int main(int argc, char** argv)
{
	int choice = 0;
	adventure1* adv1;
	adventure2* adv2;
	while(1){
		std::cout << "Welches Abenteuer moechtest du spielen? \n 1: Wald \n 2: Gebirge \n 3: Ist mir egal \n";
		std::cin >> choice;
		switch(choice){
			case 1: adv1->start(); break;
			case 2: adv2->start(); break;
			case 3: std::cout << "Dann spiel halt garnicht \n \n";
			default: break;
		}
	}
	return 0;
}