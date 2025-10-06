#include "lexique.hpp"
#include "utilitaire.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
// Constructeur //

Lexique::Lexique(const std::string& nomFichier) : nom(nomFichier) {}


// Getters //
const std::string& Lexique::getNom() const { return nom; }
const std::map<std::string, int>& Lexique::getLexique() const { return lexique; }


// Méthodes //


// Construit le lexique à partir d’un fichier texte
void Lexique::construireDepuisFichier(const string& nomFichier) {
    string contenu;
    if (!util::readFileIntoString(nomFichier, contenu)) {
        cerr << "Erreur lors de la lecture du fichier: " << nomFichier << endl;
        return;
    }

    istringstream stream(contenu);
    string mot;
    while (stream >> mot) {
        util::to_lower(mot);
        util::trim_punctuation(mot);
        if (!mot.empty()) {
            lexique[mot]++;
        }
    }
}


void Lexique::afficher() const
{
        // Boucle qui parcourt toutes les paires (clé, valeur) de lexique
    for (const auto& paire : lexique) {
        cout << paire.first << ": " << paire.second << endl; // Affiche la clé (mot) et la valeur (occurrence)
    }
}

int Lexique::nombreMotsDifferents() const
{
    return lexique.size(); // La taille de la map correspond au nombre de mots différents
}

int Lexique::nombreOccurrences(const std::string& mot) const
{
    // On cherche dans la map si le mot existe
    auto it = lexique.find(mot);
    if (it != lexique.end()) {
        return it->second;
    }
    return 0;
}