#include "adventure2.h"
#include <iostream>

adventure2::adventure2(){

}

void adventure2::start(){
	int choice;
	std::cout << "Du m�chtest einen Berg erklimmen. Wo gehst du lang? \n 1: Du folgst dem angelegten Pfad \n 2: Du kleterst an einer Steilwand hoch \n 3: Du gehst wieder nach Hause \n";
	std::cin >> choice;
	switch(choice){
			case 1: std::cout << "Auf dem Weg trifst du einen wilden B�ren, der dich t�tet. Ende. \n \n"; break;
			case 2: std::cout << "Beim klettern verlierst du den Halt und st�rzt in die Tiefe. Du bist tot. Ende \n \n"; break;
			case 3: std::cout << "Du lebst zufrieden bis an das Ende deiner Tage. Ende. \n \n"; break;
			default: std::cout << "Das z�hlt nicht, ab zum Anfang mit dir! \n \n"; break;
	}
}
