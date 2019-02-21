#ifndef LATEXCONVERTER_H
#define LATEXCONVERTER_H
#include <string>
#include <vector>

std::string toLatexString(std::vector<int> temps , std::vector<int> n, bool logScale);
/**
 * @brief writeFile, remplit un fichier txt au chemin en param avec la string en param
 * @param s, la string à insérer dans le fichier
 * @param cheminFichier, le chemin vers le fichier
 * @param overide, bool permettant de choisir si on override le fichier avec la nouvel string
 *          ou si on append seulement
 */
void writeFile(const std::string& s, const std::string& cheminFichier, bool overide);


#endif // LATEXCONVERTER_H
