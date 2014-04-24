#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "AlgoGenetique.hpp"
#include "Chromosome.hpp"
#include "GUI.hpp"

using namespace std;

int main(int argc, char **argv){
	srand(time(NULL));
	int nVilles = 10;
	Probleme P = Probleme::rand(nVilles);

	//ifstream f("villes.txt");
	//Probleme P2;

	//f >> P2;

	AlgoGenetique A(P, 1000);
	GUI G(A, P, &argc, argv, "Hello", 550, 650);
	G.run();

	return 0;
}
