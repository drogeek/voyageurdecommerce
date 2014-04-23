#include <fstream>
#include <iostream>

#include "AlgoGenetique.hpp"
#include "Chromosome.hpp"

using namespace std;

int main(void){
	ifstream f("villes.txt");
	Probleme P;

	f >> P;

	cout << P;

	AlgoGenetique A(P, 100, 0.2);
	for(i = 0;i<100;i++){
		A.step();
		cout << A.best();
	}

	return 0;
}
