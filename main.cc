#include <fstream>
#include <iostream>
#include "Probleme.hpp"
#include "AlgoGenetique.hpp"

using namespace std;
int main(void){
	ifstream f("villes.txt");
	Probleme<> P;

	f >> P;

	cout << P;

	return 0;
}
