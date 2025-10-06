#include <string>
using namespace std;
class Lexique {
    private :
        string mot;
        int nbOccurences;

    public :
        // Constructor //
        Lexique(string m, int n) : mot(m), nbOccurences(n) {}

        // Getters //
        const string getMot() const { return mot; }
        const int getNbOccurences() const { return nbOccurences; }

        // Setters //
};