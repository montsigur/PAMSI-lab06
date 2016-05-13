// Wojciech Michałowski
// nr albumu 218705

#ifndef PERMUTACJE_HPP
#define PERMUTACJE_HPP
#include <string>
#include <vector>
using namespace std;

void Permutacje(string &ciag_znakow, unsigned int n, vector<string> &permutacje) {

  if (n == 1)
    permutacje.push_back(ciag_znakow);

  else {

    for (unsigned int i = 0; i < n-1; i++) {

      Permutacje(ciag_znakow, n-1, permutacje);
      
      if (n % 2 == 0) {

        string znak = ciag_znakow.substr(n-1, 1);
	ciag_znakow.replace(n-1, 1, ciag_znakow.substr(i, 1));
	ciag_znakow.replace(i, 1, znak);
	
      }
      
      else {
	
	string znak = ciag_znakow.substr(n-1, 1);
	ciag_znakow.replace(n-1, 1, ciag_znakow.substr(0, 1));
	ciag_znakow.replace(0, 1, znak);
	
      }
    }
    
    Permutacje(ciag_znakow, n-1, permutacje);
  }
}

#endif
