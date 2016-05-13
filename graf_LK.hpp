// Wojciech Michałowski
// nr albumu 218705

#ifndef GRAF_LK_HPP
#define GRAF_LK_HPP
#include "graf.hpp"
using namespace std;

class graf_LK: public graf {
  
public:

  vector<krawedz*> krawedzie;

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
