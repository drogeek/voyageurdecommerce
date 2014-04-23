#include <iostream>
#include <cstdlib>

#include "Probleme.hpp"

// Constructeurs
AlgoGenetique::AlgoGenetique(Probleme& _p, float eug = 0.2): p(_p), T(NULL), PopSize(0), Eugenism(eug), taille(_p.len()) {}

// initialisation
void AlgoGenetique::init(int _PopSize){
	PopSize = _PopSize;
	T = new Chromosome[PopSize];
	for(int i = 0;i<PopSize;i++)
		T[i] = Chromosome::rand();
}

/* Avance d'une itération dans l'algorithme */
void AlgoGenetique::step(){
	std::sort(T, T+PopSize);
	
	Chromosome NewPop = new Chromosome[PopSize];
	int i = PopSize*Eugenism;
	/* on va garder les i meilleurs elements */
	std::copy(T, T+i, NewPop);
	/* puis, pour le reste */
	for(; i < PopSize; i++){
		int  j, i = std::rand()%PopSize,
			k = std::rand()%size;
		do{
			j = std::rand()%PopSize;
		}while(i == j);
		NewPop[i] = T[i].melange(T[j], k);
	}
	delete[] T;
	T = NewPop;
}

/* renvoit le meilleur individu à l'étape courante */
Chromosome AlgoGenetique::best() const {
	return *std::min_element(T, T+PopSize);
}

/* simple wrapper pour accéder à la distance entre deux villes. */
coord_t AlgoGenetique::distance(int i, int j) const {
	return p.distance(i, j);
}
};
