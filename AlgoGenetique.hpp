#ifndef _ALGOGENETIQUE_H
#define _ALGOGENETIQUE_H

#include <iostream>
#include <cstdlib>

#include "Probleme.hpp"

class Chromosome;

class AlgoGenetique: public MyArray<Chromosome> {
	Probleme& p;
	const ssize_t taille;

	float Eugenism;

public:
	// Constructeurs
	AlgoGenetique(Probleme& _p, ssize_t PopSize, float eug = 0.2);

	/* Avance d'une itération dans l'algorithme */
	void step();
		
	/* renvoit le meilleur individu à l'étape courante */
	Chromosome best() const;

	/* simple wrapper pour accéder à la distance entre deux villes. */
	coord_t distance(int i, int j) const;
};

#endif
