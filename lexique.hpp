#ifndef LEXIQUE_HPP
#define LEXIQUE_HPP

#include <string>
#include <map>

class Lexique {
private:
    std::string nom;                      // Nom du lexique (ex: nom du fichier)
    std::map<std::string, int> lexique;   // Conteneur clé=mot, valeur=occurrence

public:

    // Constructeur //
    Lexique(const std::string& nomFichier);

    // Getters //
    const std::string& getNom() const { return nom; }
    const std::map<std::string, int>& getLexique() const { return lexique; }


    // Methodes // 
    // Construit le lexique à partir d’un fichier texte
    void construireDepuisFichier(const std::string& nomFichier);

    // Affiche le contenu du lexique
    void afficher();

    // Retourne le nombre de mots différents
    int nombreMotsDifferents();

    // Retourne le nombre d'occurrences d'un mot
    int nombreOccurrences(const std::string& mot);
};

#endif
