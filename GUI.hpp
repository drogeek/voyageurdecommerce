#include <iostream>
#include "Interface.hpp"
#include "cng.h"

class GUI: public Interface {
	static GUI* instance;

	void Afficher_Villes(void);
	void Afficher_Infos(void);
	int Avancer(void);

public:
	GUI(AlgoGenetique& _A, Probleme& _P, int* argc, char **argv, std::string _nom, int width, int height);
	void run(void);
};
