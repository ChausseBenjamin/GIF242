#include "cercle.h"

Cercle::Cercle(int x, int y, int r):Forme(x,y) {
  setRayon(r);
};

Cercle::~Cercle() {
};

void Cercle::setRayon(int r) {
  rayon = r;
};

int Cercle::getRayon() {
  return rayon;
};

double Cercle::aire() {
  return M_PI*pow(rayon,2);
};

double Cercle::getPerimetre() {
  return 2*M_PI*rayon;
};

void Cercle::afficher(ostream & s) {
  s << "C " << getAncrage().x
    << " "  << getAncrage().y
    << " "  << getRayon();
};
