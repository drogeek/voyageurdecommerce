#include <fstream>
#include <iostream>

#include "AlgoGenetique.hpp"
#include "Chromosome.hpp"

using namespace std;

int main(void){
	Probleme P = Probleme::rand(20);

	cout << P;

	AlgoGenetique A(P, 100, 0.2);
	for(int i = 0;i<100;i++){
		A.step();
		cout << A.best() << endl;
	}

	return 0;
}
