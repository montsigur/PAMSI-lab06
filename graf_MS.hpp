// Wojciech Michałowski
// nr albumu 218705

#ifndef GRAF_MS_HPP
#define GRAF_MS_HPP
#include "graf.hpp"
using namespace std;

class graf_MS: public graf {

  unsigned int m, n;
  
public:

  graf_MS() {indeks = -1; m = 1; n = 0; }
  
  vector< vector<krawedz*> > macierzSasiedztwa;

  void dodajWierzcholek(wierzcholek* w);

  void dodajKrawedz(krawedz* k);

  void zapiszDoPliku(const char* nazwa);

  bool czySasiaduja(wierzcholek* u, wierzcholek* v);

  int wagaKrawedzi(wierzcholek* u, wierzcholek* v);

  void wyswietlKrawedzie();

  void przepiszNaKopiec(kopiec &K);

  void przepiszIncydentneNaKopiec(wierzcholek* w, kopiec &K);

  krawedz* nastepnaKrawedz(int indeks);
  
  void wyczysc();

};

#endif
