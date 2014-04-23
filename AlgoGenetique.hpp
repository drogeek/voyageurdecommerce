#include <iostream>
#include <cstdlib>

#include "Probleme.hpp"

template<ssize_t size>class AlgoGenetique{
public:
	class Chromosome {
		int *T;
		coord_t fit;
		AlgoGenetique* parent;

	public:
		/* Constructeurs */
		// Constructeur vide non-initialisé
		Chromosome(): T(NULL), fit(-1), parent(NULL) {}

		// Constructeur par copie
		Chromosome(const Chromosome& c): fit(c.fit), parent(c.parent) {
			T = new int[size];
			std::copy(c.T, c.T+size, T);
		}

		/* Destructeur */
		~Chromosome(){ delete[] T; }

		/* opérateur d'affectation */
		Chromosome& operator=(const Chromosome& c){
			if(c != this){
				parent = c.parent;
				fit = c.fit;
				if(T) delete[] T;
				T = new int[size];
				std::copy(c.T, c.T+size, T);
			} return *this;
		}

		/* opérateur de comparaison */
		bool operator<(const Chromosome& c) const {
			return fit < c.fit;
		}

		/* Croise 2 Chromosomes pour en faire un troisième. */
		Chromosome melange(const Chromosome& c, int pivot = -1) const {
			Chromosome d(*this);
			if(pivot == -1) pivot = std::rand() % size;
			std::copy(c.T+pivot, c.T+size, d.T);
			d.supDoublons();
			d.fitness();
			return d;
		}

		/* mute un Chromosome en-place. */
		void mutation(void){
			int i = rand()%size,
			    j = rand()%size;
			std::swap(T[i], T[j]);
		}

		/* surcharge de l'opérateur << pour afficher un Chromosome. */
		friend std::ostream& operator<<(std::ostream& out, const Chromosome& c){
			return out << c.fit;
		}

		/* renvoit un Chromosome initialisé aléatoirement. */
		static Chromosome rand(AlgoGenetique& _parent){
			Chromosome c;
			c.parent = _parent;
			for(int i = 0;i<size;i++) c.T[i] = i;
			random_shuffle(c.T, c.T+size);
			c.fitness();
			return c;
		}

	private:
		/* méthode privées */
		void supDoublons(void){
			std::vector<int>multiples,
					absents;
			char vus[size];
			/* on initialise vus */
			std::fill(vus, vus+size, 0);
			/* on marque les éléments en trop. */
			for(int i = 0;i < size;i++)
				if(++vus[T[i]] > 1) multiples.push_back(i);
			/* on marque les éléments absents. */
			for(int i = 0;i < size;i++)
				if(vus[i] == 0)
					absents.push_back(i);
			/* on échange chaque élément en trop avec un manquant tiré au hasard */
			random_shuffle(absents.begin(), absents.end());
			for(int i = 0;i < (ssize_t)multiples.size();i++)
				T[multiples[i]] = absents[i];
		}
		void fitness(){
			coord_t tmp = parent->distance(T[0], T[size-1]),
				sum = tmp*tmp;
			for(int i = 0;i<size-1;i++){
				tmp = parent->distance(T[i], T[i+1]);
				sum += tmp*tmp;
			}
			fit = sum;
		}
	};
private:
	Probleme& p;
	Chromosome *T;
	ssize_t PopSize;
	float Eugenism;

public:
	// Constructeurs
	AlgoGenetique(Probleme& _p, float eug = 0.2): p(_p), T(NULL), PopSize(0), Eugenism(eug) {}

	// initialisation
	void init(int _PopSize){
		PopSize = _PopSize;
		T = new Chromosome[PopSize];
		for(int i = 0;i<PopSize;i++)
			T[i] = Chromosome::rand();
	}

	/* Avance d'une itération dans l'algorithme */
	void step(){
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
	Chromosome best() const {
		return *std::min_element(T, T+PopSize);
	}

	/* simple wrapper pour accéder à la distance entre deux villes. */
	coord_t distance(int i, int j) const {
		return p.distance(i, j);
	}
};
