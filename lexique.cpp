#include "lexique.hpp"
#include "utilitaire.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

Lexique::Lexique(const std::string& nomFichier)
    : nom(nomFichier) {}

void Lexique::construireDepuisFichier(const std::string& nomFichier) {
    string content;
    void readFileIntoString(std::string_view path, std::string& content);
}


int Lexique::nombreOccurrences(const std::string& mot) const
{
    auto it = lexique.find(mot);
    if (it != lexique.end()) {
        return it->second;
    }
    return 0;
}