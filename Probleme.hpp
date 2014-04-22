#include <numeric>
#include <algorithm>

/* représente une instance du problème du voyageur de commerce. */
/* les coordonnées sont des couples d'ints par défaut. */
template<typename coord_t = int, int dim = 2>class Probleme {
	/* liste de Ville du problème. */
	std::vector<Ville> Tab;

public:
	class Ville {
		coord_t C[dim];
		string nom;

	public:
		/* Constructeurs */
		// Depuis un flux.
		Ville(std::istream& in){ /* depuis un flux */
			for(int i = 0;i<dim;i++) in >> C[i];
			in >> nom;
		}
		// Depuis un tableau.
		Ville(coord_t _C[dim], string s = "undefined"): nom(s) {
			std::copy(_C, _C+dim, C);
		}
		// Depuis rien.
		Ville(): nom("undefined"){
			std::fill(C, C+dim, (coord_t)0);
		}
		// Depuis une autre ville.
		Ville(const Ville& v){
			std::copy(v.C, v.C+dim, C); nom = v.nom;
		}
		
		/* calcule la distance entre 2 villes. */
		coord_t distance(const Ville& v) const {
			coord_t sum = 0;
			for(int i = 0;i<dim;i++){
				int delta = C[i] - v.C[i];
				sum += delta*delta;
			}
			return sum;
		}

		/* affiche une ville. */
		friend std::ostream& operator<<(std::ostream& out, const Ville& v){
			for(int i = 0;i<dim-1;i++){
				out << C[i] << ", ";
			}
			out << C[dim-1] << " => " << nom;
			return out;
		}
	};

	/* renvoit le nombre de villes. */
	ssize_t len() const { return Tab.size(); }

	/* ajouter une ville. */
	Probleme& operator+=(const Ville& v){
		Tab.push_back(v);
		return *this;
	}

	/* lit un problème depuis un flux. */
	friend std::istream& operator>>(std::istream& in, Probleme& p){
		while(! in.eof()){
			Ville v(in);
			p += v;
		}
	}

	/* renvoit la distance entre deux villes. */
	coord_t distance(int i, int j) const {
		return Tab[i].distance(Tab[j]);
	}
};
