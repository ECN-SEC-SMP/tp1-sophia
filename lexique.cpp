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

void Lexique::construireDepuisFichier(const string& nomFichier) {
    string contenu;
    if (!util::readFileIntoString(nomFichier, contenu)) {
        cout << "Erreur : impossible de lire le fichier " << nomFichier << endl;
        return;
    }

    // On récupère une copie modifiable de la chaîne car strtok modifie le buffer
    char* buffer = contenu.data();  

    // Liste des délimiteurs (espace, ponctuation, retour à la ligne, etc.)
    const char* delims = " ,.;:!?()[]{}\"\n\r\t";

    // Premier mot
    char* token = strtok(buffer, delims);

    while (token != nullptr) {
        string mot(token);       // conversion char* -> std::string
        util::to_lower(mot);     // mettre en minuscules
        util::trim_punctuation(mot); // au cas où (nettoyage fin)
        if (!mot.empty())
            lexique[mot]++;      // ajout ou incrément
        // Mot suivant
        token = strtok(nullptr, delims);
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