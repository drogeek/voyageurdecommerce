/* Classe générique d'algorithme pour la résolution
	du problème du voyageur de commerce. */
class Algo {
	Probleme& p;

public:
	/* Constructeur générique. */
	virtual Algo(Probleme&);

	/* Méthode virtuelle d'initialisation. */
	virtual init(){}

	/* Méthode virtuelle d'itération de l'Algorithme. */
	virtual step() = 0;

	
