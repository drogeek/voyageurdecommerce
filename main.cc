#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "AlgoGenetique.hpp"
#include "Chromosome.hpp"

using namespace std;

void afficher_mat(Probleme& P){
	for(int i = 0;i<P.len();i++){
		for(int j = 0;j<P.len();j++)
			printf("%3d  ", P.distance(i, j));
		putchar('\n');
	}
}


	

int main(void){
	srand(time(NULL));
	int nVilles = 5;
	Probleme P = Probleme::rand(nVilles);

	ifstream f("villes.txt");
	Probleme P2;

	f >> P2;
	AlgoGenetique A(P2, 1000);
	for(int i = 0;i<10;i++){
		for(int j = 0;j<10;j++) A.step();
		cout << A.best() << endl;
	}

	return 0;
}
