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

	int nVilles = (argc > 1) ? std::atoi(argv[1]) : 20;
	int nPop    = (argc > 2) ? std::atoi(argv[2]) : 1000;
	float eug   = (argc > 3) ? std::atof(argv[3]) : 0.2;

	Probleme P;
	if(argc > 4){
		ifstream f(argv[4]);
		f >> P;
	}else
		P = Probleme::rand(nVilles);

	AlgoGenetique A(P, nPop, eug);
	GUI G(A, P, &argc, argv, "Hello", 550, 650);
	G.run();

	return 0;
}
