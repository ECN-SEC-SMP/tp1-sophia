#include "lexique.hpp"
#include "utilitaire.hpp"
#include <iostream>
#include <string>

int main() {
    std::string nomFichier = "lesMiserables_A.txt"; // Nom du fichier à lire
    Lexique lexique(nomFichier);      // Création d'une instance de Lexique

    lexique.construireDepuisFichier(nomFichier); // Construction du lexique à partir du fichier

    std::cout << "Lexique construit à partir du fichier: " << lexique.getNom() << std::endl; // Affichage du nom du lexique
    std::cout << "Nombre de mots différents: " << lexique.nombreMotsDifferents() << std::endl;

    lexique.afficher(); // Affichage du contenu du lexique

    // test de recherche d'occurrences pour un mot spécifique
    std::string motRecherche = "bonjour"; // Remplacez par le mot que vous voulez rechercher
    int occurrences = lexique.nombreOccurrences(motRecherche);
    std::cout << "Le mot '" << motRecherche << "' apparaît " << occurrences << " fois." << std::endl;

    return 0;
}