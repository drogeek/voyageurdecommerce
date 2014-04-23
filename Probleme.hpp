#ifndef _PROBLEME_H
#define _PROBLEME_H

#include <numeric>
#include <algorithm>
#include <vector>

#include "Ville.hpp"

/* représente une instance du problème du voyageur de commerce. */
class Probleme {
	/* liste de Ville du problème. */
	std::vector<Ville> Tab;

public:
	/* renvoit un itérateur constant sur Tab */
	std::vector<Ville>::const_iterator begin(void);
	std::vector<Ville>::const_iterator end(void);

	/* renvoit le nombre de villes. */
	ssize_t len() const;

	/* ajouter une ville. */
	Probleme& operator+=(const Ville& v);

	/* lit un problème depuis un flux. */
	friend std::istream& operator>>(std::istream& in, Probleme& p);

	/* affiche un problème */
	friend std::ostream& operator<<(std::ostream& out, Probleme& p);

	/* renvoit la distance entre deux villes. */
	coord_t distance(int i, int j) const;

	/* Génère une instance aléatoire du problème. */
	static Probleme rand(ssize_t len);

	Ville& operator[](int i);
};

#endif
