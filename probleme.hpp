/* représente une instance du problème du voyageur de commerce. */
/* les coordonnées sont des couples d'ints par défaut. */
template<typename coord_t = int, int dim = 2>class Probleme {
	class Ville {
		coord_t C[dim];
		string nom;

	public:
		/* calcule la distance entre 2 villes. */
		coord_t distance(const Ville&) const;

		/* affiche une ville. */
		friend std::ostream& operator<<(std::ostream&, const Ville&);

		/* lit une ville. */
		friend std::istream& operator>>(std::istream&, Ville&);
	};

	/* liste de Ville du problème. */
	std::vector<Ville> Tab;

public:
	/* ajouter une ville. */
	Probleme& operator+=(const Ville&);

	/* lit un problème depuis un flux. */
	friend std::istream& operator>>(std::istream&, Probleme&);
