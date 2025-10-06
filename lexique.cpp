#include "Lexique.hpp"
#include "utilitaire.hpp"  // pour readFileIntoString, trim_punctuation, to_lower
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Lexique::Lexique(const std::string& nomFichier)
    : nom(nomFichier) {}

Lexique::construireDepuisFichier(const std::string& nomFichier) {
    string content;
    readFileIntoString(std::string_view path, std::string& content);
}
