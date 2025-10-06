#include <string>
#include <map>

using namespace std;
class Lexique {
    private :
        string nom;
        std::map<std::string, int> lexique; // conteneur clé=mot, valeur=occurrence
    public :
        // Constructor //
        Lexique(string m, int n) : mot(m), nbOccurences(n) {}

        // Getters //
        const string getMot() const { return mot; }
        const int getNbOccurences() const { return nbOccurences; }

        // Setters //
};