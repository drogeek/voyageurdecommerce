#include <numeric>
#include <algorithm>
#include <vector>

/* représente une instance du problème du voyageur de commerce. */
/* les coordonnées sont des couples d'ints par défaut. */
template<typename coord_t = int, int dim = 2>class Probleme {
public:
	class Ville {
		coord_t content[dim];
		std::string nom;

	public:
		/* Constructeurs */
		// Depuis un flux.
		Ville(std::istream& in){ /* depuis un flux */
			for(int i = 0;i<dim;i++) in >> content[i];
			in >> nom;
		}
		// Depuis un tableau.
		Ville(coord_t _content[dim], std::string s = "undefined"): nom(s) {
			std::copy(_content, _content+dim, content);
		}
		// Depuis rien.
		Ville(): nom("undefined"){
			std::fill(content, content+dim, (coord_t)0);
		}
		// Depuis une autre ville.
		Ville(const Ville& v){
			std::copy(v.content, v.content+dim, content); nom = v.nom;
		}
		
		// opérateur d'affectation.
		Ville& operator=(const Ville& v){
			std::copy(v.content, v.content+dim, content); nom = v.nom;
			return *this;
		}

		/* calcule la distance entre 2 villes. */
		coord_t distance(const Ville& v) const {
			coord_t sum = 0;
			for(int i = 0;i<dim;i++){
				int delta = content[i] - v.content[i];
				sum += delta*delta;
			}
			return sum;
		}

		/* affiche une ville. */
		friend std::ostream& operator<<(std::ostream& out, const Ville& v){
			for(int i = 0;i<dim;i++){
				out << v.content[i] << " ";
			}
			return out << v.nom;
		}

		/* génère une ville au hasard */
		static Ville rand(){
			Ville v;
			for(int i = 0;i<dim;i++) v.content[i] = rand();
			v.nom = "undefined";
		}
		friend class Interface;
	};

private:
	/* liste de Ville du problème. */
	std::vector<Ville> Tab;

public:
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
		p.Tab.pop_back(); // correctif temporaire de bug.
		return in;
	}

	/* affiche un problème */
	friend std::ostream& operator<<(std::ostream& out, Probleme& p){
		for(int i = 0;i<p.Tab.size();i++){
			out << p.Tab[i] << std::endl;
		}
		return out;
	}

	/* renvoit la distance entre deux villes. */
	coord_t distance(int i, int j) const {
		return Tab[i].distance(Tab[j]);
	}

	static Probleme rand(ssize_t len){
		Probleme P;
		for(int i = 0;i<len;i++)
			P += Ville::rand();
		return P;
	}

	Ville& operator[](int i){
		return Tab[i];
	}
};
