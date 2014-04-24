#include "Ville.hpp"
#include "AlgoGenetique.hpp"

typedef void (*callback_point)(coord_t, coord_t);
typedef void (*callback_segment)(coord_t, coord_t, coord_t, coord_t);

/* classe virtuelle/interface pour l'UI du programme. */
class Interface {
	unsigned int i;

public:
	AlgoGenetique& A;
	Probleme& P;

	Interface(AlgoGenetique& _A, Probleme& _P);
	virtual void run(void) = 0;

	/* Gestion des points */
	void Point(const Ville& v, callback_point C); // applique la callback sur les coordonnées du point.

	/* Gestion des segments */
	void Segment(const Ville&, const Ville&, callback_segment C);
};
