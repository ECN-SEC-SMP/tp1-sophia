#include "lexique.hpp"
#include "utilitaire.hpp"
#include <iostream>
#include <string>

int main() {

    //Fichiers à lire
    std::string nomFichier_1 = "_lesMiserables_A.txt"; // Nom du fichier à lire
    Lexique lexique_1(nomFichier_1);      // Création d'une instance de Lexique
    lexique_1.construireDepuisFichier(nomFichier_1); // Construction du lexique à partir du fichier

    std::string nomFichier_2 = "_notreDameDeParis_A.txt";
    Lexique lexique_2(nomFichier_2);
    lexique_2.construireDepuisFichier(nomFichier_2);


    // lexique_1.afficher() ; // Affichage du lexique 1
    std::cout << lexique_2; // Affichage du contenu du lexique 2 via l'opérateur <<

    std::cout << "Lexique construit à partir du fichier: " << lexique_1.getNom() << std::endl;
    std::cout << "Nombre de mots différents: " << lexique_1.nombreMotsDifferents() << std::endl;


    // Exemple de recherche d'occurrences pour un mot spécifique
    std::string motRecherche = "étoiles"; // Remplacez par le mot que vous voulez rechercher
    int occurrences = lexique_1.nombreOccurrences(motRecherche);
    std::cout << "Le mot '" << motRecherche << "' apparaît " << occurrences << " fois." << std::endl;

    // Exemple de suppression d'un mot
    lexique_1.supprimerMot(motRecherche);
    int new_occurrences = lexique_1.nombreOccurrences(motRecherche);
    std::cout << "Le mot '" << motRecherche << "' apparaît " << new_occurrences << " fois. Il a été supprimé" << std::endl;

    // Exemple de fusion de deux lexiques
    Lexique fusionner = Lexique::fusionner(lexique_1, lexique_2);
    fusionner.afficher(); // Affichage du lexique fusionné
    
    
    return 0;
}