#ifndef LEXIQUE_HPP
#define LEXIQUE_HPP

#include <string>
#include <map>
#include <ostream>

class Lexique {
private:
    std::string nom;                      // Nom du lexique (ex: nom du fichier)
    std::map<std::string, int> lexique;   // Conteneur clé=mot, valeur=occurrence

public:

    // Constructeur //
    Lexique(const std::string& nomFichier);

    // Getters //
    const std::string& getNom() const ;
    const std::map<std::string, int>& getLexique() const;


    // Methodes // 

    // Construit le lexique à partir d’un fichier texte
    void construireDepuisFichier(const std::string& nomFichier);

    // Sauvegarde du contenu du lexique dans un fichier de sortie
    void sauvegarderDansFichier(const std::string& nomFichier) const;

    // Affiche le contenu du lexique
    void afficher() const;

    // Retourne le nombre de mots différents
    int nombreMotsDifferents() const;

    // Retourne le nombre d'occurrences d'un mot
    int nombreOccurrences(const std::string& mot) const;

    // Supprime un mot du lexique
    void supprimerMot(const std::string& mot);


    // Fusionne 2 lexiques
    static Lexique fusionner(const Lexique& a, const Lexique& b);
};

//Affiche en utilisant l'opérateur <<
std::ostream& operator<<(std::ostream& out, const Lexique& l);

#endif
