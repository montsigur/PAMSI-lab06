// Wojciech Michałowski
// nr albumu 218705

#ifndef GRAF_HPP
#define GRAF_HPP
#include "krawedz.hpp"
#include "kopiec.hpp"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class graf {

protected:

  bool juzDodany(wierzcholek* w);

  int indeks;
  
public:

  vector<wierzcholek*> wierzcholki;
  
  ~graf() { wyczysc(); }

  graf() { indeks = -1; }
  
  virtual void dodajWierzcholek(wierzcholek* w) = 0;

  virtual void dodajKrawedz(krawedz* k) = 0;

  void wczytajZPliku(const char* nazwa);

  virtual void zapiszDoPliku(const char* nazwa) = 0;
  
  virtual bool czySasiaduja(wierzcholek* u, wierzcholek* v) = 0;

  virtual int wagaKrawedzi(wierzcholek* u, wierzcholek* v) = 0;

  virtual void wyswietlKrawedzie() = 0;

  virtual void przepiszNaKopiec(kopiec &K) = 0;

  virtual void przepiszIncydentneNaKopiec(wierzcholek* w, kopiec &K) = 0;

  void wyswietlWierzcholki();

  virtual void wyczysc();
};

#endif
