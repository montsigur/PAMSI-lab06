// Wojciech Michałowski
// nr albumu 218705

#ifndef BELLMANFORD_HPP
#define BELLMANFORD_HPP
#include "graf.hpp"
using namespace std;

class struktura {

public:

  vector<wierzcholek*> poprzednie;
  vector<int> odleglosci;
  
};

void sciezkiDoPliku(string nazwa_pliku, struktura wynik) {

  ofstream plik(nazwa_pliku);
  wierzcholek* poprzedni;
  unsigned int n;

  for (unsigned int i=0; i<wynik.poprzednie.size(); i++) {

    plik << i << " ";
    poprzedni = wynik.poprzednie[i];
    n = 0;
    
    while(poprzedni != NULL) {

      plik << poprzedni->indeks << " ";
      poprzedni = wynik.poprzednie[poprzedni->indeks];
      if (n++ >= wynik.poprzednie.size()) break;

    }
    
    plik << wynik.odleglosci[i] << endl;
    
  }

  plik.close();
}

template <typename Graf>
struktura BellmanFord(Graf G, int indeks) {

  wierzcholek* s = G.wierzcholki[indeks];
  unsigned int ilosc_wierzcholkow = G.wierzcholki.size();
  krawedz* k;
  struktura wynik;

  for (unsigned int i=0; i<ilosc_wierzcholkow; i++) {
    
    wynik.poprzednie.push_back(NULL);
    wynik.odleglosci.push_back(30000);
    
  }
  wynik.odleglosci[s->indeks] = 0;
  
  for (unsigned int i=0; i<ilosc_wierzcholkow-1; i++)
    for (unsigned int j=0;
	 j<ilosc_wierzcholkow*(ilosc_wierzcholkow-1)/2; j++) {

      k = G.nastepnaKrawedz(j);
      if (k == NULL) break;
      if (wynik.odleglosci[k->koniec1->indeks]
	  > wynik.odleglosci[k->koniec2->indeks] + k->waga) {
	wynik.odleglosci[k->koniec1->indeks]
	  = wynik.odleglosci[k->koniec2->indeks] + k->waga;
	wynik.poprzednie[k->koniec1->indeks] = k->koniec2;
      
      }

      if (wynik.odleglosci[k->koniec2->indeks]
	  > wynik.odleglosci[k->koniec1->indeks] + k->waga) {
	wynik.odleglosci[k->koniec2->indeks]
	  = wynik.odleglosci[k->koniec1->indeks] + k->waga;
	wynik.poprzednie[k->koniec2->indeks] = k->koniec1;
	
      }
    }
  
  return wynik;
}

#endif
