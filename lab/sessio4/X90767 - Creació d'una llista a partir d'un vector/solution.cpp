#include "llista.hpp"
#include <iostream>
using namespace std;

Llista::Llista(const vector<int> &v){
    _long = v.size();
    if (v.size() >= 1){
        node *n = new node;
        n->info = v[0];
    
        _prim = n;

        node *aux = _prim;
        for (unsigned int i = 1; i < v.size(); i++){
            node *nv = new node;
            nv->info = v[i];
            aux->seg = nv;
            aux = aux->seg;
       }
    }
}
