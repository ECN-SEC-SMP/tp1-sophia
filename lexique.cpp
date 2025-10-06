#include "lexique.hpp"
#include "utilitaire.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
// Constructeur //

Lexique::Lexique(const std::string& nomFichier)
    : nom(nomFichier) {}

    
// Getters //
const std::string& Lexique::getNom() const { return nom; }
const std::map<std::string, int>& Lexique::getLexique() const { return lexique; }


// Méthodes //

void Lexique::construireDepuisFichier(const std::string& nomFichier) {
    string content;
    void readFileIntoString(std::string_view path, std::string& content);
}

void Lexique::afficher() const
{
    for (const auto& paire : lexique) {
        cout << paire.first << ": " << paire.second << endl;
    }
}

int Lexique::nombreMotsDifferents() const
{
    return lexique.size();
}

int Lexique::nombreOccurrences(const std::string& mot) const
{
    auto it = lexique.find(mot);
    if (it != lexique.end()) {
        return it->second;
    }
    return 0;
}