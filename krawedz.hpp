// Wojciech Michałowski
// nr albumu 218705

#ifndef KRAWEDZ_HPP
#define KRAWEDZ_HPP
#include "wierzcholek.hpp"

class krawedz {

public:

  wierzcholek *koniec1, *koniec2;
  int waga;

  krawedz(wierzcholek* u, wierzcholek* v, int w) {

    koniec1 = u; koniec2 = v; waga = w;
    
  }
};

#endif
