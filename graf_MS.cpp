// Wojciech Michałowski
// nr albumu 218705

#include "graf_MS.hpp"
using namespace std;

void graf_MS::dodajKrawedz(krawedz* k) {

  wierzcholek* u = k->koniec1;
  wierzcholek* v = k->koniec2;

  dodajWierzcholek(u);
  dodajWierzcholek(v);

  macierzSasiedztwa[u->indeks][v->indeks] = k;
  macierzSasiedztwa[v->indeks][u->indeks] = k;
}

void graf_MS::dodajWierzcholek(wierzcholek* w) {

  if (!juzDodany(w)) {
    
    wierzcholki.push_back(w);
    for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
      macierzSasiedztwa[i].push_back(NULL);
    w->indeks = ++indeks;
    macierzSasiedztwa.push_back(vector<krawedz*>());
    for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
      macierzSasiedztwa[indeks].push_back(NULL);
    
  }
}
  
void graf_MS::zapiszDoPliku(const char* nazwa) {

  ofstream plik(nazwa);
  
  for (unsigned int i=0; i<wierzcholki.size(); i++)
    plik << wierzcholki[i]->etykieta << " ";

  plik << endl;

  for (unsigned int i=0; i<macierzSasiedztwa.size()-1; i++)
    for (unsigned int j=i+1; j<macierzSasiedztwa.size(); j++)
      if (macierzSasiedztwa[i][j] != NULL)
	plik << macierzSasiedztwa[i][j]->koniec1->indeks << " "
	     << macierzSasiedztwa[i][j]->koniec2->indeks << " "
	     << macierzSasiedztwa[i][j]->waga << endl;
  
  plik.close();
  
}

bool graf_MS::czySasiaduja(wierzcholek* u, wierzcholek* v) {

  int i = u->indeks;
  int j = v->indeks;

  if (macierzSasiedztwa[i][j] != NULL)
    return true;

  else
    return false;

}

int graf_MS::wagaKrawedzi(wierzcholek* u, wierzcholek* v) {

  int i = u->indeks;
  int j = v->indeks;

  if (macierzSasiedztwa[i][j] != NULL)
    return macierzSasiedztwa[i][j]->waga;

  else
    return 0;

}

void graf_MS::wyswietlKrawedzie() {

  for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
    for (unsigned int j=0; j<i; j++)
      if (macierzSasiedztwa[i][j] != NULL)
	cout << wierzcholki[i]->etykieta << ", " << wierzcholki[j]->etykieta
	     << ": " << macierzSasiedztwa[i][j]->waga << endl;

}

void graf_MS::przepiszNaKopiec(kopiec &K) {

  for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
    for (unsigned int j=0; j<i; j++)
      if (macierzSasiedztwa[i][j] != NULL)
	K.dodaj(macierzSasiedztwa[i][j]);

}

void graf_MS::przepiszIncydentneNaKopiec(wierzcholek* w, kopiec &K) {

  int i = w->indeks;
  krawedz* k;

  for (unsigned int j=0; j < macierzSasiedztwa[i].size(); j++)
    if ((k = macierzSasiedztwa[i][j]) != NULL and
	((w == k->koniec1 and w->klaster != k->koniec2->klaster) or
	 (w == k->koniec2 and w->klaster != k->koniec1->klaster)))
      K.dodaj(k);

}

krawedz* graf_MS::nastepnaKrawedz(int indeks) {
  
  while (m < wierzcholki.size() and macierzSasiedztwa[m][n] == NULL) {

    n++; 
    if (n == m) { m++; n = 0; }
    
  }

  if (m >= wierzcholki.size()) {
    
    m = 1; n = 0;
    return NULL;

  }

  else {

    krawedz* k = macierzSasiedztwa[m][n];
    n++;
    if (n == m) { m++; n = 0; }
    return k;

  }
}

void graf_MS::wyczysc() {

  wierzcholki.clear();
  for (unsigned int i=0; i<macierzSasiedztwa.size(); i++)
    macierzSasiedztwa[i].clear();
  macierzSasiedztwa.clear();
  indeks = -1;
  
}
