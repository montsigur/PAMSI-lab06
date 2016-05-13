// Wojciech Michałowski
// nr albumu 218705

#ifndef KOPIEC_HPP
#define KOPIEC_HPP
#include <iostream>
#include "krawedz.hpp"
#include "EmptyHeapException.hpp"
using namespace std;

class wezel {

public:

  wezel* lewySyn;
  wezel* prawySyn;
  wezel* ojciec;
  krawedz* klucz;
  
  wezel(krawedz* k) {

    lewySyn = prawySyn = ojciec = NULL;
    klucz = k;
    
  }
};

class kopiec {

  int wysokosc;
  wezel* korzen;
  wezel* ostatni;
  wezel* nowy;

  void uaktualnijOstatniPoDodaniu();

  void uaktualnijOstatniPoUsunieciu();

  void uaktualnijOstatniPrzedUsunieciem();

  void naprawWGore();

  void naprawWDol(wezel* &w);

  bool jestLisciem(wezel* w);

  void przejdzPoprzecznie(wezel* w);

public:

  kopiec();

  void dodaj(krawedz* k);

  krawedz* zdejmijMinimalny();

  void zawartosc();

  bool pusty();
};

#endif
