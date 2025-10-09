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

// Sauvegarde du contenu du lexique dans un fichier de sortie
void Lexique::sauvegarderDansFichier(const std::string& nomFichier) const {
    ofstream fichier(nomFichier);
    if (!fichier) {
        cerr << "Erreur lors de l'ouverture du fichier pour l'écriture: " << nomFichier << endl;
        return;
    }

    // Boucle qui parcourt toutes les paires (clé, valeur) de lexique
    for (const auto& paire : lexique) {
        fichier << paire.first << ": " << paire.second << endl; // Écrit chaque mot et son occurrence dans le nouveau fichier
    }
    fichier.close();
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

void Lexique::supprimerMot(const std::string& mot)
{
    lexique.erase(mot);
}



// Operateurs //

std::ostream& operator<<(std::ostream& out, const Lexique& l)
{
    for (const auto& paire : l.getLexique()) {
        out << paire.first << ": " << paire.second << endl;
    }
    return out;
}

Lexique Lexique::fusionner(const Lexique& a, const Lexique& b)
{
    Lexique resultat = a; // copie du lexique a (nom + map)

    // Additionne les occurrences de b dans le lexique a
    for (const auto& paire : b.getLexique()) {
        resultat.lexique[paire.first] += paire.second;
    }

    return resultat;
}