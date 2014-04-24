#include "GUI.hpp"

GUI::GUI(AlgoGenetique& _A, Probleme& _P, int *argc, char **argv, std::string _nom, int width, int height):
	Interface(_A, _P){
		char nom[_nom.size()+1];
		std::copy(_nom.c_str(), _nom.c_str()+_nom.size(), nom);
		instance = this;
		cng_init_window(argc, argv, nom, width, height);
		cng_display_func([]() -> void { GUI::instance->Afficher_Villes();
						GUI::instance->Afficher_Infos();
						cng_swap_screen(); });
		cng_assoc_key(cng_a, []() -> int { return GUI::instance->Avancer(); });
}

void GUI::Afficher_Villes(void){
	for(int i = 0;i<P.len();i++)
		Point(P[i], [](coord_t x, coord_t y){ cng_circle(x, y, 4); });
}

void GUI::Afficher_Infos(void){
	int x = 60, y = 600;
	cng_current_color(1, 1, 1);
	cng_draw_string("MENU", x, y);
	cng_draw_string("[a] chemin suivant", x+5, y+15);
}

int GUI::Avancer(void){
	Afficher_Villes();
	Afficher_Infos();
	A.step();
	Chromosome& meilleur = A.best();
	cng_current_color(0, 1, 0);
	int j = meilleur.size()-1;
	for(int i = 0;i<meilleur.size();j = i++)
		Segment(P[meilleur[i]], P[meilleur[j]], cng_line);
	cng_swap_screen();
	return 0;
}	

void GUI::run(void){
	cng_main_loop();
}
