#include "CLI.hpp"

CLI::CLI(AlgoGenetique& _A, Probleme& _P): Interface(_A, _P) {}

void CLI::run(void){
	for(int i = 0;i<1000;i++)
		std::cout << A.best() << std::endl;
}
