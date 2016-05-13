// Wojciech Michałowski
// nr albumu 218705

#include "graf.hpp"
using namespace std;

bool graf::juzDodany(wierzcholek* w) {

  if (w->indeks < 0)
    return false;

  else
    return true;

}

void graf::wyswietlWierzcholki() {

  for (unsigned int i=0; i<wierzcholki.size(); i++)
    cout << wierzcholki[i]->etykieta << endl;

}

void graf::wczytajZPliku(const char* nazwa) {

  wyczysc();
  
  char c;
  vector<string> etykiety, linia;
  int ilosc_wierzcholkow, n = 0, indeks_u, indeks_v, waga;
  string bufor, bufor_int;
  
  ifstream plik(nazwa);
  
  getline(plik, bufor);

  for (unsigned int i=0; i<bufor.size();) {

    if ((c = bufor[i]) != ' ') {
      etykiety.push_back(string()); n++;
    }
    
    else i++;
    
    while (i < bufor.size() and (c = bufor[i++]) != ' ')
      etykiety[n-1] += c;
  }

  ilosc_wierzcholkow = n;
    
  for (unsigned int i = 0; i<ilosc_wierzcholkow; i++)
    dodajWierzcholek(new wierzcholek(etykiety[i]));
  
  while (bufor != string("")) {

    bufor.clear();
    linia.clear();
    getline(plik, bufor);
    n = 0;

    for (unsigned int j=0; j<bufor.size();) {
      
      if ((c = bufor[j]) != ' ') {
	linia.push_back(string()); n++;
      }
      
      else j++;
      
      while (j < bufor.size() and (c = bufor[j++]) != ' ')
        linia[n-1] += c;
    }

    if (linia.size() > 2) {

      indeks_u = stoi(linia[0]);
      indeks_v = stoi(linia[1]);
      waga = stoi(linia[2]);

      dodajKrawedz(new krawedz(wierzcholki[indeks_u], wierzcholki[indeks_v], waga));
      
    }
  }

  plik.close();
}

void graf::wyczysc() {

  wierzcholki.clear();
  indeks = -1;

}
