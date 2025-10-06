#include "lexique.hpp"
#include <iostream>

int main() {
    // Nom du fichier texte à analyser - sophia
    std::string fichier = "/workspaces/tp1-sophia/tp1-Lexique-fichiers-20251006/tp1-Lexique-fichiers/lesMiserables_A.txt";
    // Nom du fichier texte à analyser - annabelle
    std::string fichier = "inserer chemin";

    // Création de l'objet Lexique
    Lexique lexique(fichier);

    // Construction du lexique à partir du fichier
    lexique.construireDepuisFichier(fichier);

    // Affichage du contenu complet du lexique (mot : occurrences)
    std::cout << "=== Contenu du lexique ===" << std::endl;
    lexique.afficher();

    // Affichage du nombre de mots différents
    std::cout << std::endl
              << "Nombre de mots différents : "
              << lexique.nombreMotsDifferents() << std::endl;

    // Exemple : chercher le nombre d'occurrences d’un mot spécifique
    std::string motRecherche = "love";
    std::cout << "Occurrences du mot \"" << motRecherche << "\" : "
              << lexique.nombreOccurrences(motRecherche) << std::endl;

    return 0;
}
