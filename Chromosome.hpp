#ifndef _CHROMOSOME_H
#define _CHROMOSOME_H

#include <iostream>
#include <cstdlib>

class Chromosome;

#include "AlgoGenetique.hpp"
#include "MyArray.hpp"

class Chromosome: public MyArray<int> {
	coord_t fit;
	AlgoGenetique* parent;

public:
	/* Constructeurs */
	// Constructeur vide non-initialisé
	Chromosome();

	// Constructeur avec seulement la taille
	Chromosome(ssize_t _len);

	// Constructeur par copie
	Chromosome(const Chromosome& c);

	/* opérateur d'affectation */
	Chromosome& operator=(const Chromosome& c);

	/* opérateur de comparaison */
	bool operator<(const Chromosome& c) const;

	/* Croise 2 Chromosomes pour en faire un troisième. */
	Chromosome melange(const Chromosome& c, int pivot /* = -1 */) const;

	/* mute un Chromosome en-place. */
	void mutation(void);

	/* surcharge de l'opérateur << pour afficher un Chromosome. */
	friend std::ostream& operator<<(std::ostream& out, const Chromosome& c);

	/* renvoit un Chromosome initialisé aléatoirement. */
	static Chromosome rand(AlgoGenetique* _parent, ssize_t _len);

private:
	/* méthode privées */
	void supDoublons(void);

	void fitness();
};

#endif
