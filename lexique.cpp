#include <string>
#include <map>
using namespace std;

class Lexique {

    private :
        string nom; //nom du lexique
        std::map<std::string, int> lexique; // conteneur clé=mot, valeur=occurrence

    public :
        // Constructor //
        Lexique(string m) : mot(m) {}

        // Getters //
        const string getMot() const { return mot; }
        const int getNbOccurences() const { return nbOccurences; }

        // Setters //
};