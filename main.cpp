#include "lexique.hpp"
#include "utilitaire.hpp"
#include <iostream>
#include <string>

int main() {
    std::string nomFichier = "_lesMiserables_A.txt"; // Nom du fichier à lire
    Lexique lexique(nomFichier);      // Création d'une instance de Lexique

    lexique.construireDepuisFichier(nomFichier); // Construction du lexique à partir du fichier

    lexique.afficher(); // Affichage du contenu du lexique

    std::cout << "Lexique construit à partir du fichier: " << lexique.getNom() << std::endl;
    std::cout << "Nombre de mots différents: " << lexique.nombreMotsDifferents() << std::endl;


    // Exemple de recherche d'occurrences pour un mot spécifique
    std::string motRecherche = "étoiles"; // Remplacez par le mot que vous voulez rechercher
    int occurrences = lexique.nombreOccurrences(motRecherche);
    std::cout << "Le mot '" << motRecherche << "' apparaît " << occurrences << " fois." << std::endl;

    // Exemple de suppression d'un mot
    lexique.supprimerMot(motRecherche);
    int new_occurrences = lexique.nombreOccurrences(motRecherche);
    std::cout << "Le mot '" << motRecherche << "' apparaît " << new_occurrences << " fois. Il a été supprimé" << std::endl;

    return 0;
}