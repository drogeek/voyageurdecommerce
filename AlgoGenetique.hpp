#include <iostream>
#include <cstdlib>

#include "Probleme.hpp"

class AlgoGenetique{
	Probleme& p;
	ssize_t taille;

	Chromosome *T;
	ssize_t PopSize;
	float Eugenism;

public:
	// Constructeurs
	AlgoGenetique(Probleme& _p, float eug = 0.2);

	// initialisation
	void init(int _PopSize);

	/* Avance d'une itération dans l'algorithme */
	void step();
		
	/* renvoit le meilleur individu à l'étape courante */
	Chromosome best() const;

	/* simple wrapper pour accéder à la distance entre deux villes. */
	coord_t distance(int i, int j) const;
};
