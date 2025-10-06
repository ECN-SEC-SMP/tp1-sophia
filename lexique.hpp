#ifndef LEXIQUE_HPP
#define LEXIQUE_HPP

#include <string>
#include <map>

class Lexique {
private:
    std::string nom;                      // Nom du lexique (ex: nom du fichier)
    std::map<std::string, int> lexique;   // Conteneur clé=mot, valeur=occurrence

public:
    // Constructeur
    explicit Lexique(const std::string& nomFichier);

    // Construit le lexique à partir d’un fichier texte
    void construireDepuisFichier(const std::string& nomFichier);

    // Affiche le contenu du lexique
    void afficher() const;

    // Retourne le nombre de mots différents
    int nombreMotsDifferents() const;
};

#endif
