#include "Interface.hpp"

Interface::Interface(AlgoGenetique& _A, Probleme& _P): i(0), A(_A), P(_P) {}

void Point(const Ville& v, callback_point C){
	coord_t x = v.content[0],
		y = v.content[1];
	C(x, y);
}

void Segment(const Ville& a, const Ville& b, callback_segment C){
	coord_t x1 = a.content[0],
		y1 = a.content[1],
		x2 = b.content[0],
		y2 = b.content[1];
	C(x1, y1, x2, y2);
}
