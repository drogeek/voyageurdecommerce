#include "Interface.hpp"

class CLI: public Interface {
public:
	CLI(AlgoGenetique& _A, Probleme& _P);
	void run(void);
};
