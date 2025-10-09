# Compte Rendu TP1 - Lexique
###Annabelle & Sophia

Le but de ce TP était de réaliser un lexique à partir d'un texte. Dans ce lexique, on retrouve la liste de tous les mots du texte avec leur nombre d'occurence.

### Classe Lexique :
```C
class Lexique {

    private:
        std::string nom;                      // Nom du lexique
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
};
```
Voici les fonctions associées à la classe les plus importantes :

```C
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

// Renvoie le nombre d'occurence d'un mot en particulier
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
```

On a utilisé le compteneur map car il nous permet d'avoir un système clés valeur. Ici on a, clés = mot et valeur = nb occurences.


### Jeu de Test :

Dans notre main on a effectué un test avec le mot étoiles :

```C
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
```

Resultat :

```T
(...)
étoiles: 1
étonne: 1
étrange: 1
être: 2
ô: 1

Lexique construit à partir du fichier: _lesMiserables_A.txt
Nombre de mots différents: 26133
Le mot 'étoiles' apparaît 1 fois.
Le mot 'étoiles' apparaît 0 fois. Il a été supprimé
```

### Surchage d'opérateurs :

Opérateur << pour l'affichage :

Opérateur += pour la fusion : 


### Jeu d'essai 

Affichage :
```C
int main() {

    //Fichiers à lire
    std::string nomFichier_1 = "_lesMiserables_A.txt"; // Nom du fichier à lire
    Lexique lexique_1(nomFichier_1);      // Création d'une instance de Lexique
    lexique_1.construireDepuisFichier(nomFichier_1); // Construction du lexique à partir du fichier

    std::cout << lexique_1; // Affichage du contenu du lexique 1 via l'opérateur <<

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

    
    return 0;
}
```
Resultat :
```T
```


Fusion : 
```C
int main() {

    //Fichiers à lire
    std::string nomFichier_1 = "_lesMiserables_A.txt";
    Lexique lexique_1(nomFichier_1);      // Création d'une instance de Lexique
    lexique_1.construireDepuisFichier(nomFichier_1); // Construction du lexique à partir du fichier

    std::string nomFichier_2 = "_notreDameDeParis_A.txt";
    Lexique lexique_2(nomFichier_2);
    lexique_2.construireDepuisFichier(nomFichier_2);



    lexique_1.afficher() ; // Affichage du lexique 1

    std::cout << "Lexique construit à partir du fichier: " << lexique_1.getNom() << std::endl;

    // Exemple de fusion de deux lexiques
    Lexique fusionner = Lexique::fusionner(lexique_1, lexique_2);
    fusionner.afficher(); // Affichage du lexique fusionné
    
    
    return 0;
}
```
Resultat :
```T
```
