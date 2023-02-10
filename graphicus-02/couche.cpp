/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"
#include "forme.h"

Couche::Couche() {
  state = STATE_INITIALIZED;
  Vecteur<Forme*> vecteur;
};

Couche::~Couche() {
  vecteur.vider();
};

int Couche::getEtat() {
  return state;
};

Forme *Couche::getForme(int index) {
  return vecteur[index];
};

double Couche::aire() {
  double aire = 0;
  for (int i = 0; i < vecteur.getTaille(); i++) {
    aire += vecteur[i]->aire();
  };
  return aire;
};

void Couche::afficher(ostream &s) {
    s << "L " << stateChars[state]
      << "\n";
    for (int i = 0; i < vecteur.getTaille(); i++) {
      vecteur[i]->afficher(s);
      s << "\n";
    };
};

bool Couche::changerEtat(int newState) {
  if (newState == state) return false;
  state = newState;
  return true;
};

bool Couche::translater(int deltaX, int deltaY) {
  if (state != STATE_ACTIVE) return false;
  for (int i = 0; i < vecteur.getTaille(); i++)
    vecteur[i]->translater(deltaX, deltaY);
  return true;
};

bool Couche::ajouterForme(Forme *f) {
  // Returns false if the layer is not active or initialized
  if (state != STATE_ACTIVE && state != STATE_INITIALIZED){
    return false;
  }
  return vecteur.ajouterElement(&f);
};

Forme *Couche::supprimerForme(int index) {
  if (state != STATE_ACTIVE) {
    return NULL;
  } else {
    return vecteur.supprimerElement(index);
  };
  return vecteur.supprimerElement(index);
};

bool Couche::reinitialiser() {
  state = STATE_ACTIVE;
  vecteur.vider();
  return true;
};


