#include "latexconverter.h"
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

string toLatexString(vector<int> temps , vector<int> n, bool logScale) {
    //mise en page
    string latexConv = "\\\\begin{minipage}[p]{0.5'\\\\textwidth}\n";
    latexConv.append("\\\\begin{tikzpicture}\n");
    // GRAPHIQUE :
    if(logScale) {
        latexConv.append("\\\\begin{axis}[ \n");
        latexConv.append(" xlabel={$n$ (taille du vecteur) }, \n");
        latexConv.append(" ylabel={temps [nanosecondes] },\n");
        latexConv.append(" ymode=log, \n");
        latexConv.append(" log basis y={2} , \n");
        latexConv.append(" y tick label style={/pgf/number format/.cd,sci,precision=5} \n");
        latexConv.append(" ] \n");
    } else {
        latexConv.append("\\\\begin{axis}[ \n");
        latexConv.append(" xlabel={$n$ (taille du vecteur) }, \n");
        latexConv.append(" ylabel={temps [nanosecondes] },\n");
        latexConv.append(" ] \n");
    }
    latexConv.append(" \\\\addplot+[smooth,mark=*] plot coordinates\n");
    latexConv.append("{") ;
    for (size_t i = 0;i < temps.size();++i){
        latexConv.append("(");
        latexConv += to_string(n.at(i));
        latexConv.append(",");
        latexConv += to_string(temps.at(i));
        latexConv.append(") ");
    }
    latexConv.append("}; ");
    latexConv.append(" \\\\end{axis}\n");
    latexConv.append("\\\\end{tikzpicture}\n\n");

    latexConv.append("\\\\end{minipage}\n");
    // Tableau :
    latexConv.append("\\\\begin{minipage}[p]{0.5\\textwidth}\n");
    latexConv.append("\\\\begin{tabular}{ | l | l | l |} \n");
    latexConv.append("\\\\hline \n");
    latexConv.append(" mesure & nombre elements & temps [nanosecondes] \\\\\\\\ \\\\hline \n");
    for(size_t i = 0; i < temps.size(); ++i) {
        latexConv += to_string(i);
        latexConv.append(" & ");
        latexConv += to_string(n.at(i));
        latexConv.append(" & ");
        latexConv += to_string(temps.at(i));
        latexConv.append(" \\\\\\\\ \\\\hline\n");
    }
    latexConv.append("\\\\end{tabular} \n" );

    latexConv.append("\\\\end{minipage}\n");;
    return latexConv;
}

void writeFile(const string& s, const string& cheminFichier, bool overide){

    ofstream toWrite (cheminFichier.c_str(), ios::out | (overide ? ios::trunc : ios::app));

    if (toWrite){
        toWrite << s << endl;
    } else
        cout << "impossible d'ouvrir le fichier" << endl;
}
