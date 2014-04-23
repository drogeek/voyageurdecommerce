#include "Chromosome.hpp"
#include "AlgoGenetique.hpp"
#include <algorithm>

// Constructeur vide non-initialisé
Chromosome::Chromosome(): MyArray(), fit(-1), parent(NULL) {}

// Constructeur avec seulement la taille
Chromosome::Chromosome(ssize_t _len): MyArray(_len), fit(-1), parent(NULL) {}

// Constructeur par copie
Chromosome::Chromosome(const Chromosome& c): MyArray(c), fit(c.fit), parent(c.parent) {}

/* opérateur d'affectation */
Chromosome& Chromosome::operator=(const Chromosome& c){
	if(&c != this){
		MyArray::operator=(c);
		parent = c.parent;
		fit = c.fit;
	} return *this;
}

/* opérateur de comparaison */
bool Chromosome::operator<(const Chromosome& c) const {
	return fit < c.fit;
}

bool Chromosome::operator==(const Chromosome& c) const {
	for(int i = 0;i<size();i++)
		if((*this)[i] != c[i]) return false;
	return true;
}

/* opérateur de croisement */
Chromosome Chromosome::operator+(const Chromosome& c){
	return melange(c);
}

/* Croise 2 Chromosomes pour en faire un troisième. */
Chromosome Chromosome::melange(const Chromosome& c, int pivot /* = -1 */) const {
	Chromosome d(*this);
	if(pivot == -1) pivot = std::rand() % size();
	std::copy(c.begin()+pivot, c.end(), d.begin()+pivot);
	d.supDoublons();
	d.fitness();
	return d;
}

/* mute un Chromosome en-place. */
void Chromosome::mutation(void){
	int i = std::rand()%size(),
	    j = std::rand()%size();
	std::swap((*this)[i], (*this)[j]);
}

/* surcharge de l'opérateur << pour afficher un Chromosome. */
std::ostream& operator<<(std::ostream& out, const Chromosome& c){
	return out << c.fit;
}

/* renvoit un Chromosome initialisé aléatoirement. */
Chromosome Chromosome::rand(AlgoGenetique* _parent, ssize_t _len){
	Chromosome c(_len);
	c.parent = _parent;
	for(int i = 0;i<_len;i++) c[i] = i;
	std::random_shuffle(c.begin(), c.end());
	c.fitness();
	return c;
}

void Chromosome::supDoublons(void){
	ssize_t len = size();
	std::vector<int>multiples,
			absents;
	char vus[len];
	/* on initialise vus */
	std::fill(vus, vus+len, 0);
	/* on marque les éléments en trop. */
	for(int i = 0;i < len;i++)
		if(++vus[(*this)[i]] > 1) multiples.push_back(i);
	/* on marque les éléments absents. */
	for(int i = 0;i < len;i++)
		if(vus[i] == 0)
			absents.push_back(i);
	/* on échange chaque élément en trop avec un manquant tiré au hasard */
	random_shuffle(absents.begin(), absents.end());
	for(int i = 0;i < (ssize_t)multiples.size();i++)
		(*this)[multiples[i]] = absents[i];
}
void Chromosome::fitness(){
	coord_t tmp = parent->distance((*this)[0], (*this)[size()-1]),
		sum = tmp*tmp;
	for(int i = 0;i<size()-1;i++){
		tmp = parent->distance((*this)[i], (*this)[i+1]);
		sum += tmp*tmp;
	}
	fit = sum;
}
