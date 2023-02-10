/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef __COUCHE_H__
#define __COUCHE_H__

#define STATE_HIDDEN 0 // Couche active (peut-etre modifiee)
#define STATE_ACTIVE 1 // Couche inactive (non modifiable)
#define STATE_INITIALIZED 2 // Couche cachee (non affichee)
#define STATE_INACTIVE 3 // Couche affichee

#include "vecteur.h"
#include "forme.h"

class Couche {
  private:
    int     state;
    Vecteur<Forme*> vecteur;
  public:
    Couche();
    ~Couche();
    int    getEtat();
    Forme  *getForme(int index);
    double aire();
    void   afficher(ostream &s);
    bool   changerEtat(int newState);
    bool   translater(int deltaX, int deltaY);
    bool   ajouterForme(Forme *f);
    Forme  *supprimerForme(int index);
    bool   reinitialiser();
};

// list of chars for state
static const char *stateChars = "caix";

#endif
