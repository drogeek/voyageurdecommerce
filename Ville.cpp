#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>

#include "Ville.hpp"

// Depuis un flux.
Ville::Ville(std::istream& in){ /* depuis un flux */
	for(int i = 0;i<DIM;i++) in >> content[i];
	in >> nom;
}

// Depuis un tableau.
Ville::Ville(coord_t _content[DIM], std::string s /* = "undefined" */): nom(s) {
	std::copy(_content, _content+DIM, content);
}

// Depuis rien.
Ville::Ville(): nom("undefined"){
	std::fill(content, content+DIM, (coord_t)0);
}

// Depuis une autre ville.
Ville::Ville(const Ville& v){
	std::copy(v.content, v.content+DIM, content); nom = v.nom;
}
	
// opérateur d'affectation.
Ville& Ville::operator=(const Ville& v){
	std::copy(v.content, v.content+DIM, content); nom = v.nom;
	return *this;
}

/* calcule la distance entre 2 villes. */
coord_t Ville::distance(const Ville& v) const {
	coord_t sum = 0;
	for(int i = 0;i<DIM;i++){
		int delta = content[i] - v.content[i];
		sum += delta*delta;
	}
	return sqrt(sum);
}

/* affiche une ville. */
std::ostream& operator<<(std::ostream& out, const Ville& v){
	for(int i = 0;i<DIM;i++){
		out << v.content[i] << " ";
	}
	return out << v.nom;
}

/* génère une ville au hasard */
Ville Ville::rand(){
	Ville v;
	for(int i = 0;i<DIM;i++) v.content[i] = std::rand()%500;
	v.nom = "undefined";
	return v;
}
