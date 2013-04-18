#include "adventure1.h"
#include <iostream>

adventure1::adventure1(){

}

void adventure1::start(){
	int choice;
	std::cout << "Du bist in einem Wald und kannst dich an nichts erinnern. Wo gehst du hin? \n 1: Nach Hause \n 2: Auf einen Baum \n 3: Du wartest einfach \n";
	std::cin >> choice;
	switch(choice){
			case 1: std::cout << "Du weißt garnicht wo das ist, du Dummi. Um die Welt vor deiner Dummheit zu bewahren tötest du dich selbst. Ende. \n \n"; break;
			case 2: std::cout << "Du kletterst auf einen Baum und fällst herunter. Du bist tot. Ende. \n \n"; break;
			case 3: std::cout << "Tage vergehen und es kommt keine Rettung. Du stirbst. Ende. \n \n"; break;
			default: std::cout << "Das zählt nicht, ab zum Anfang mit dir! \n \n"; break;
	}
}
