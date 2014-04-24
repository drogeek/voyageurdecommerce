#include <iostream>
#include <cstdlib>
#include <cassert>

#include "Probleme.hpp"
#include "MyArray.hpp"
#include "AlgoGenetique.hpp"

// Constructeurs
AlgoGenetique::AlgoGenetique(Probleme& _p, ssize_t PopSize, float eug /* = 0.2 */):
	MyArray(PopSize), p(_p), taille(_p.len()), Eugenism(eug) {
		for(int i = 0;i<PopSize;i++)
			(*this)[i] = Chromosome::rand(this, taille);
}

/* Avance d'une itération dans l'algorithme */
void AlgoGenetique::step(){
	std::sort(begin(), end());

	MyArray<Chromosome> NewPop(size());
	int i = size()*Eugenism;
	/* on va garder les i meilleurs elements */
	std::copy(begin(), begin()+i, NewPop.begin());
	/* puis, pour le reste */
	for(; i < size(); i++){
		int  j, k = std::rand()%size();
		do{
			j = std::rand()%size();
		}while(k == j);
		NewPop[i] = (*this)[j] + (*this)[k];
	}
	MyArray<Chromosome>::operator=(NewPop);
}

/* renvoit le meilleur individu à l'étape courante */
Chromosome& AlgoGenetique::best() const {
	return *std::min_element(begin(), end());
}

/* simple wrapper pour accéder à la distance entre deux villes. */
coord_t AlgoGenetique::distance(int i, int j) const {
	return p.distance(i, j);
}
