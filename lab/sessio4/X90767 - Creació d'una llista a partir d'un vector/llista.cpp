#include <iostream>
#include "llista.hpp"

Llista::Llista() {
    _prim = NULL;
    _long = 0;
}

Llista::~Llista() {
  node *p = _prim, *pelim;
  while (p != NULL) {
    pelim = p;
    p = p->seg;
    delete pelim;
  }
}

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

nat Llista::longitud() const {
  return _long;
}

void Llista::mostra() const {
  node *p = _prim;
  cout << "[";
  while (p != NULL){
    cout << p->info << " ";
    p = p->seg;
  }
  cout << "]" << endl;
}
