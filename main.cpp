// Wojciech Michałowski
// nr albumu 218705

#include "graf_MS.hpp"
#include "graf_LK.hpp"
#include "generujGraf.hpp"
#include "BellmanFord.hpp"
#include "./timer/src/Timer.h"
using namespace std;

int main() {

  string nazwa_pliku;
  char buffer[40];
  Timer timer;
  struktura wynik;
  
  for (double gestosc : {0.25, 0.5, 0.75, 1.0}) {

    double gestosc_procent = gestosc * 100;
    
    sprintf(buffer, "./pomiary/pomiar_MS_%3.1f%%.txt", gestosc_procent);
    nazwa_pliku = string(buffer);
    ofstream plik_MS(nazwa_pliku);

    sprintf(buffer, "./pomiary/pomiar_LK_%3.1f%%.txt", gestosc_procent);
    nazwa_pliku = string(buffer);
    ofstream plik_LK(nazwa_pliku);
    
    for (int n_wierzcholkow : {10, 50, 100, 500, 1000}) {

      graf_MS G_MS;
      graf_LK G_LK;

      generujGraf<graf_LK>(G_LK, n_wierzcholkow, gestosc);     
      generujGraf<graf_MS>(G_MS, n_wierzcholkow, gestosc);

      timer.start();
      wynik = BellmanFord<graf_LK>(G_LK, 0);
      timer.stop();
      plik_LK << timer.getElapsedTimeInMilliSec() << endl;
      sprintf(buffer, "./sciezki/sciezka_LK_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      sciezkiDoPliku(nazwa_pliku, wynik);
      
      timer.start();
      wynik = BellmanFord<graf_MS>(G_MS, 0);
      timer.stop();
      plik_MS << timer.getElapsedTimeInMilliSec() << endl;
      sprintf(buffer, "./sciezki/sciezka_MS_%d_%3.1f%%.txt",
      	      n_wierzcholkow, gestosc_procent);
      nazwa_pliku = string(buffer);
      sciezkiDoPliku(nazwa_pliku, wynik);
      
    }

    plik_MS.close();
    plik_LK.close();
  }
  
  return 0;

}
