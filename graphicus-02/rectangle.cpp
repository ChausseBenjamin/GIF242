#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h):Forme(x, y){
  setLargeur(w);
  setHauteur(h);
};

Rectangle::~Rectangle(){
};

int Rectangle::getLargeur(){
  return largeur;
};

int Rectangle::getHauteur(){
  return hauteur;
};

Coordonnee Rectangle::getAncrageForme(){
  return getAncrage();
};

void Rectangle::setLargeur(int l){
  largeur=l;
};

void Rectangle::setHauteur(int h){
  hauteur=h;
};

double Rectangle::aire(){
  return largeur*hauteur;
};

void Rectangle::afficher(ostream &s){
  s << "R " << getAncrageForme().x
    << " "  << getAncrageForme().y
    << " "  << getLargeur()
    << " "  << getHauteur();
};
