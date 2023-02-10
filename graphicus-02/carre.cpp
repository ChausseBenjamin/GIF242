#include "carre.h"

Carre::Carre(int x, int y, int cote) : Rectangle(x, y, cote, cote) {
};

Carre::~Carre() {
};

void Carre::afficher(ostream &s) {
    s << "K " << getAncrage().x
      << " " << getAncrage().y
      << " " << getLargeur();
};
