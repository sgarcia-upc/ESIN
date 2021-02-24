#include <iostream>
#include <sstream>
#include "arbre.hpp"

using namespace std;
int main()
{
    string s;
    while (getline(cin, s)) {
        istringstream ss(s);
        int n_nodes;
        ss >> n_nodes;

        Arbre<int> a(400);

        for (int i = 0; i < n_nodes; i++){
            int nom;
            ss>>nom;
            int fills;
            ss>>fills;

            if (i==0){
                a = Arbre<int>(nom);
            } 

            while (ss>>nom){
                ss>>fills;

                if (fills == 0){
                    Arbre<int> nou(nom);
                    a.afegir_fill(nou);
                } else {
                    
                }

            }


        }
    }

}


