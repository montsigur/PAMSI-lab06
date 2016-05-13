// Wojciech Michałowski
// nr albumu 218705

#ifndef GENERUJGRAF_HPP
#define GENERUJGRAF_HPP
#include <ctime>
#include <cstdlib>
#include "graf.hpp"
#include "permutacje.hpp"
using namespace std;

int silnia(int n) {

  if (n < 0)
    return -1;
  
  else if (n < 2)
    return 1;

  else
    return n * silnia(n-1);
  
}


void polaczKlastry(wierzcholek* u, wierzcholek* v) {

  vector<wierzcholek*>* klaster_u = u->klaster;
  vector<wierzcholek*>* klaster_v = v->klaster;
  
  (*klaster_u)[0] = NULL;
  u->klaster = klaster_v;
  klaster_v->push_back(u);
  klaster_u->clear();
  
}

template <typename Graf>
bool czySpojny(Graf G) {

  srand(time(NULL));
  int indeks = rand() % G.wierzcholki.size();
  kopiec krawedzie;
  vector<wierzcholek*> wierzcholki_T;
  vector<krawedz*> krawedzie_T;
  wierzcholek *u, *v, *w;
  krawedz* k;

  w = G.wierzcholki[indeks];
  G.przepiszIncydentneNaKopiec(w, krawedzie);
  wierzcholki_T.push_back(w);
  
  while(wierzcholki_T.size() < G.wierzcholki.size()) {

    k = krawedzie.zdejmijMinimalny();
    u = k->koniec1;
    v = k->koniec2;
 
    if (u != w and u->klaster->size() == 1) {
      
      wierzcholki_T.push_back(u);
      polaczKlastry(u, v);
      G.przepiszIncydentneNaKopiec(u, krawedzie);
      krawedzie_T.push_back(k);

    }

    else if (v != w and v->klaster->size() == 1) {
      
      wierzcholki_T.push_back(v);
      polaczKlastry(v, u);
      G.przepiszIncydentneNaKopiec(v, krawedzie);
      krawedzie_T.push_back(k);
      
    }
  }

  for (int i=0; i<G.wierzcholki.size(); i++)
    G.wierzcholki[i]->indeks = i;

  if (krawedzie_T.size() < G.wierzcholki.size()-1)
    return false;

  else return true;
}

template <typename Graf>
void generujGraf(Graf &G, int n_wierzcholkow, double gestosc) {

  G.wyczysc();
  
  vector<string> permutacje, etykiety;
  vector<krawedz*> krawedzie;
  vector<wierzcholek*> wierzcholki;
  
  string znaki = string("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
  string uzyte_znaki;
  int n_znakow = 0, indeks, nty;
  int n_max_krawedzi = n_wierzcholkow * (n_wierzcholkow - 1) / 2;
  
  srand(time(NULL));

  while (silnia(n_znakow) < n_wierzcholkow) n_znakow++;
  
  uzyte_znaki = znaki.substr(rand() % 25, n_znakow);

  Permutacje(uzyte_znaki, n_znakow, permutacje);
  
  for (int i = 0; i < n_wierzcholkow; i++) {
    
    wierzcholki.push_back(new wierzcholek(permutacje[i]));
    G.dodajWierzcholek(wierzcholki[i]);

  }
  
  permutacje.clear();

  for (int i = 0; i < n_wierzcholkow-1; i++)
    for (int j = i+1; j < n_wierzcholkow; j++)
      krawedzie.push_back(new krawedz(wierzcholki[i], wierzcholki[j], rand() % 100 + 1));
  
  if (gestosc > 0.5 and gestosc < 1) {

    nty = 1 / (1-gestosc);
    
    for (int i = 0; i < n_max_krawedzi; i++)
      if ((i+1) % nty != 0)
	G.dodajKrawedz(krawedzie[i]);
  }
  
  else if (gestosc > 0 and gestosc <= 0.5) {

    nty = 1 / gestosc;

    for (int i = 0; i < n_max_krawedzi; i++)
      if ((i+1) % nty == 0)
	G.dodajKrawedz(krawedzie[i]);
  }

  else if (gestosc == 1)
    for (int i = 0; i < n_wierzcholkow * (n_wierzcholkow - 1) / 2; i++)
      G.dodajKrawedz(krawedzie[i]);
}

#endif
