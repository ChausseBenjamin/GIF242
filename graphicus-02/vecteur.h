#include <iostream>

#define FUNC template <class E>

FUNC
class Vecteur {
 public:
  Vecteur();
  ~Vecteur();
  E &operator[](int index);
  Vecteur &operator+=(const E &element);
  Vecteur &operator++();
  Vecteur operator++(int);
  Vecteur &operator--();
  Vecteur operator--(int);
  // prototype of the << operator
    friend std::ostream & operator<<(std::ostream & os, const Vecteur<E> & v) {
      for (int i = 0; i < v.size; i++) {
        os << v.elements[i] << std::endl;
      }
      return os;
    }
  /* friend std::ostream &operator<<(std::ostream &os, const Vecteur &v){ */
  /*   for (int i = 0; i < v.size; i++) { */
  /*     os << v.elements[i]; */
  /*     // Only add a space if it's not the last element */
  /*     if (i != v.size - 1) os << "\n"; */
  /*   } */
  /*   return os; */
  /* } */
  // prototype of the >> operator // TODO: Check if this is correct
  friend std::istream &operator>>(std::istream &is, Vecteur &v){
    E element;
    while (is >> element) v += element;
    return is;
  }
  bool isEmpty();
  int getTaille();
  int getCapacite();
  /* void  afficher(std::ostream &s); */
  E&  ajouterElement(E *e);
  E&  supprimerElement(int i);
  void vider();

 private:
  int size;
  int capacity;
  int current;
  E *elements;
  void doubleCapacity();
};

FUNC
Vecteur<E>::Vecteur() {
  size = 0;
  capacity = 1;
  current = -1;
  elements = new E[capacity];
}

FUNC
Vecteur<E>::~Vecteur() {
  for (int i = 0; i < size; i++) delete elements[i];
}

FUNC
E &Vecteur<E>::operator[](int index) {
  if (index < 0 || index >= size) throw "Index out of bounds";
  return elements[index];
}

FUNC
Vecteur<E> &Vecteur<E>::operator+=(const E &element) {
  if (size == capacity) doubleCapacity();
  elements[++current] = element;
  size++;
  return *this;
}

FUNC
void Vecteur<E>::doubleCapacity() {
  capacity *= 2;
  E *newElements = new E[capacity];
  for (int i = 0; i < size; i++) newElements[i] = elements[i];
  delete[] elements;
  elements = newElements;
}

FUNC
Vecteur<E> &Vecteur<E>::operator++() {
  if (size == capacity) doubleCapacity();
  elements[++current] = 0;
  size++;
  return *this;
}

FUNC
Vecteur<E> Vecteur<E>::operator++(int) {
  Vecteur<E> temp = *this;
  if (size == capacity) doubleCapacity();
  elements[++current] = 0;
  size++;
  return temp;
}

FUNC
Vecteur<E> &Vecteur<E>::operator--() {
  if (size == 0) throw "Cannot decrement an empty vector";
  size--;
  current--;
  return *this;
}

FUNC
Vecteur<E> Vecteur<E>::operator--(int) {
  Vecteur<E> temp = *this;
  if (size == 0) throw "Cannot decrement an empty vector";
  size--;
  current--;
  return temp;
}

FUNC
bool Vecteur<E>::isEmpty() {
  return size == 0;
}

FUNC
int Vecteur<E>::getTaille(){
    return size;
}

FUNC
int Vecteur<E>::getCapacite(){
    return capacity;
}

FUNC
E& Vecteur<E>::ajouterElement(E *e){
    if (size == capacity) doubleCapacity();
    elements[++current] = *e;
    size++;
    return elements[current];
}

FUNC
void Vecteur<E>::vider(){
    current = -1;
    for (int i = 0; i < size; i++) delete elements[i];
    size = 0;
}

FUNC
E& Vecteur<E>::supprimerElement(int i){
    if (i < 0 || i >= size) throw "Index out of bounds";
    E *newElements = new E[capacity];
    for (int j = 0; j < i; j++) newElements[j] = elements[j];
    for (int j = i; j < size - 1; j++) newElements[j] = elements[j + 1];
    delete[] elements;
    elements = newElements;
    size--;
    current--;
    return elements[i];
}
