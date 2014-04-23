#include <numeric>
#include <algorithm>
#include <vector>

#include "Probleme.hpp"

std::vector<Ville>::const_iterator Probleme::begin(void){
	return Tab.begin();
}

std::vector<Ville>::const_iterator Probleme::end(void){
	return Tab.end();
}

/* renvoit le nombre de villes. */
ssize_t Probleme::len() const { return Tab.size(); }

/* ajouter une ville. */
Probleme& Probleme::operator+=(const Ville& v){
	Tab.push_back(v);
	return *this;
}

/* lit un problème depuis un flux. */
std::istream& operator>>(std::istream& in, Probleme& p){
	while(! in.eof()){
		Ville v(in);
		p += v;
	}
	p.Tab.pop_back(); // correctif temporaire de bug.
	return in;
}

/* affiche un problème */
std::ostream& operator<<(std::ostream& out, Probleme& p){
	for(int i = 0;i<p.len();i++){
		out << p.Tab[i] << std::endl;
	}
	return out;
}

/* renvoit la distance entre deux villes. */
coord_t Probleme::distance(int i, int j) const {
	return Tab[i].distance(Tab[j]);
}

/* Génère une instance aléatoire du problème. */
Probleme Probleme::rand(ssize_t len){
	Probleme P;
	for(int i = 0;i<len;i++)
		P += Ville::rand();
	return P;
}

Ville& Probleme::operator[](int i){
	return Tab[i];
}
