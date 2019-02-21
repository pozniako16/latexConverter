#include <stdlib.h>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>
#include <cmath>
#include <iomanip>
#include "latexconverter.h"


using namespace std;

void trier( vector<int>& v );

int main()
{
    using namespace std::chrono;

    srand(time(NULL));
    vector<vector<int>> toSort;
    vector<int> sizesVec;
    vector<int> timeData;
    for (int i = 0; i < 5; i++){
        vector<int> toInsert;
        for (int j = 0; j < 250*(pow(i+1,2)); j++){
            toInsert.push_back(rand()%500);
        }

        toSort.push_back(toInsert);
    }
    for (vector<int>& v : toSort){
        //cout << "\n vecteur, taille = " << v.size() ;
        //prendre le moment de départ
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        //exécuter les opérations à chronométrer ici
        trier(v);
        //prendre le moment d’arrivée
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        double temps = duration_cast<nanoseconds>( t2 - t1 ).count();
        //cout << "fonction trier, temps d'exe: " << setprecision(3) << temps << endl;
        sizesVec.push_back(v.size());
        timeData.push_back(temps);
        cout << "k" << endl;
    }
    cout << "done" << endl;
    string latexFile = toLatexString(timeData, sizesVec, true);
    string test2 = "123";
    string cheminFichier = "C:/Users/Lev Pozniakoff/Documents/Cours HEIG-VD/divers/latextest.txt";
    writeFile(latexFile, cheminFichier, true);
}

/**
 * Trie un vector.
 *
 * Pour la complexité, on considère le nombre de comparaisons (>)
 *
 * @param v vector à trier
 */
void trier( vector<int>& v ) {
  if(v.empty()) return;

  for(int a : v) {
    auto j = v.begin();
    auto k = j++;
    for(; j != v.end(); k = j++ )
      if(*k > *j )
        swap(*k, *j);
  }
}

