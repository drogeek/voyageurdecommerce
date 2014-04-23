#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

/* les coordonnées sont des couples d'ints par défaut. */
typedef unsigned int coord_t;
#define DIM 2

class Ville {
	coord_t content[DIM];
	std::string nom;

public:
	/* Constructeurs */

	// Depuis un flux.
	Ville(std::istream& in);

	// Depuis un tableau.
	Ville(coord_t _content[DIM], std::string s = "undefined");

	// Depuis rien.
	Ville();

	// Depuis une autre ville.
	Ville(const Ville& v);
	
	// opérateur d'affectation.
	Ville& operator=(const Ville& v);

	/* calcule la distance entre 2 villes. */
	coord_t distance(const Ville& v) const;

	/* affiche une ville. */
	friend std::ostream& operator<<(std::ostream& out, const Ville& v);

	/* génère une ville au hasard */
	static Ville rand();

	friend class Interface;
};
