template<ssize_t size, typename coord_t = int>class AlgoGenetique{
public:
	template<ssize_t len>class Chromosome {
		int *T;
		coord_t fit;
		AlgoGenetique* parent;

	public:
		/* Constructeurs */
		// Constructeur vide non-initialisé
		Chromosome(): T(NULL), fit(-1), parent(NULL) {}

		// Constructeur par copie
		Chromosome(const Chromosome& c): fit(c.fit), parent(c.parent) {
			T = new int[len];
			std::copy(c.T, c.T+len, T);
		}

		/* Destructeur */
		~Chromosome(){ delete[] T; }

		/* opérateur d'affectation */
		Chromosome& operator=(const Chromosome& c){
			if(c != this){
				parent = c.parent;
				fit = c.fit;
				if(T) delete[] T;
				T = new int[len];
				std::copy(c.T, c.T+len, T);
			} return *this;
		}

		/* opérateur de comparaison */
		bool operator<(const Chromosome& c) const {
			return fit < c.fit;
		}

		/* Croise 2 Chromosomes pour en faire un troisième. */
		Chromosome melange(const Chromosome& c, int pivot = -1) const {
			Chromosome d(*this);
			if(pivot == -1) pivot = rand() % len;
			std::copy(c.T+pivot, c.T+len, d.T);
			d.supDoublons();
			d.fitness();
			return d;
		}

		/* mute un Chromosome en-place. */
		void mutation(void){
			int i = rand()%len,
			    j = rand()%len;
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
			for(int i = 0;i<len;i++) c.T[i] = i;
			random_shuffle(c.T, c.T+len);
			c.fitness();
			return c;
		}

	private:
		/* méthode privées */
		void supDoublons(void){
			std::vector<int>multiples,
					absents;
			char vus[len];
			/* on initialise vus */
			std::fill(vus, vus+len, 0);
			/* on marque les éléments en trop. */
			for(int i = 0;i < len;i++)
				if(++vus[T[i]] > 1) multiples.push_back(i);
			/* on marque les éléments absents. */
			for(int i = 0;i < len;i++)
				if(vus[i] == 0)
					absents.push_back(i);
			/* on échange chaque élément en trop avec un manquant tiré au hasard */
			random_shuffle(absents.begin(), absents.end());
			for(int i = 0;i < (ssize_t)multiples.size();i++)
				T[multiples[i]] = absents[i];
		}
		void fitness(){
			coord_t tmp = parent->distance(T[0], T[len-1]),
				sum = tmp*tmp;
			for(int i = 0;i<len-1;i++){
				tmp = parent->distance(T[i], T[i+1]);
				sum += tmp*tmp;
			}
			fit = sum;
		}
	};
private:
	Probleme<>& p;
	Chromosome<size> *T;
	ssize_t len;

public:
	void init(){}
	void step(){}
	Chromosome<size> best(){}
	coord_t distance(int i, int j){
		return p.distance(i, j);
	}
};
