/**************************************************************
 *
 *    CNG : Campus Naked Graphic
 *
 *    Copyright (c) 2008 Christian Nguyen
 *
 *    This program is free software; you can redistribute it 
 *    and/or modify it under the terms of the GNU General 
 *    Public License as published by the Free Software 
 *    Foundation (version 2 of the License).
 *
 *    This program is distributed in the hope that it will 
 *    be useful, but WITHOUT ANY WARRANTY; without even the 
 *    implied warranty of MERCHANTABILITY or FITNESS FOR A 
 *    PARTICULAR PURPOSE.  See the GNU General Public License 
 *    for more details.
 *
 *    For a copy of the GNU General Public License, write to the 
 *    Free Software Foundation, Inc., 675 Mass Ave, Cambridge, 
 *    MA 02139, USA.
 **************************************************************/

/**************************************************************
 *    Bibliotheque minimaliste s'appuyant sur OpenGL
 *    pour la realisation des TP d'infographie de 2ieme cycle
 **************************************************************/

#ifndef __CNG_H__
#define __CNG_H__

/* C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ */
#ifdef __cplusplus
extern "C" {
#else
typedef enum {FALSE, TRUE} bool;
#endif
/* C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ */

#include <GL/glut.h>

typedef enum {cng_a, cng_b, cng_c, cng_d, cng_e, cng_f, cng_g, cng_h, cng_i, cng_j, cng_k, cng_l, cng_m, cng_n, cng_o, cng_p, cng_q, cng_r, cng_s, cng_t, cng_u, cng_v, cng_w, cng_x, cng_y, cng_z} touche_alpha;

/* Gestion de la fenetre graphique
   ======================================================== */

/* constructeur : parametres du main(), nom, largeur, hauteur de la fenetre */
void cng_init_window(int*, char**, char*, int, int);

/* definition de la "display function" */
void cng_display_func(void (*g)(void));

/* gestion manuelle du double buffer image */
void cng_swap_screen(void);

/* affiche sur stderr des informations sur l'environnement graphique */
void cng_video_info(void);

/* boucle d'attente des evenements */
void cng_main_loop(void);

/* definition de la "idle function" */
void cng_idle_func(void (*g)(void));

/* destructeur */
void cng_destroy_window(void);

/* efface l'ecran de travail (en noir) */
void cng_clear_screen(void);

/* positionne la couleur dans laquelle on va dessiner
   code : r rouge, v vert et b bleu dans [0, 1] */
  void cng_current_color(GLfloat, GLfloat, GLfloat);


/* Fonctions graphiques de base
   ======================================================== */

/* dessine un point de la couleur courante en (x, y) */
void cng_put_pixel(int x, int y);

/* dessine une ligne de la couleur courante de (x1,y1) a (x2,y2) */
void cng_line(int x1, int y1, int x2, int y2);

/* dessine une ligne de la couleur courante de la position courante a (x,y) */
void cng_line_to(int x, int y);

/* initialise la position courante */
void cng_move_to(int x, int y);

/* dessine le contour d'un cercle */
void cng_circle(int posx, int posy, int r);


/* Fonctions de gestion du texte
   ======================================================== */

/* affichage du texte a la position (x,y) */
void cng_draw_string(const char* texte, int x, int y);


/* Fonctions de gestion des E/S
   ======================================================== */

/* association d'une touche avec une fonction de la forme "int f()" */
void cng_assoc_key(touche_alpha k, int (*g)(void));

/* association d'un bouton (0 ou 2) avec une fonction de la forme "int f()" */
void cng_assoc_button(int bid, int (*g)(void));

/* association du deplacement souris avec une fonction de la forme "int f()"
   ce deplacement se fait bouton 0 presse pour des raisons d'efficacite */
void cng_assoc_motion(int (*g)(void));

/* retourne la position en X (resp. Y) du curseur de la souris */
int cng_get_mouse_x(void);
int cng_get_mouse_y(void);

/* Fonctions de traitement d'images
   ======================================================== */

/* recupere la couleur du pixel */
void cng_get_pixel(int, int, float*, float*, float*);

/* recuperation du nombre de plan de l'ecran de travail */
int cng_get_bpp(void);

/* Fonctions diverses
   ======================================================== */

/* demarrage du chrono (mesure de temps) */
void cng_start_clock(void);

/* recuperation du temps en millisecondes (ms) */
double cng_get_time(void);

/* delais d'attente en millisecondes */
void cng_delay(int ms);

/* C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ */
#ifdef __cplusplus
}
#endif
/* C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ C++ */

#endif /* __CNG_H__ */
