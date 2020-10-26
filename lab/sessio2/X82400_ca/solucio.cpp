#ifndef _CUA_HPP
#define _CUA_HPP
#include <cstddef>
using namespace std;

template <typename T>
class cua {
private: 
  struct node {
    T info;
    node* seg;
  };
  node* _cua;

  node* copiar(node* n, node* fi, node* ini);

public:
  // Construeix una cua buida.
  cua();

  // Tres grans: constructora per còpia, operador d'assignació i destructora.
  cua(const cua<T> &c);
  cua<T>& operator=(const cua<T> &c);
  ~cua() throw();

  // Afegeix un element al final de la cua. 
  void encuar(const T &x);

  // Treu el primer element de la cua. Llança un error si la cua és buida.
  void desencuar();

  // Obté el primer element de la cua. Llança un error si la cua és buida.
  const T& primer() const;

  // Consulta si la cua és buida o no.
  bool es_buida() const throw();

  static const int CuaBuida = 310;
};

#endif
template <typename T>
cua<T>::cua() : _cua(NULL) {   
}

template <typename T>
cua<T>::cua(const cua<T> &c) : _cua(NULL) {
  if (c._cua != NULL) {
    _cua = new node;
    try {
      _cua->info = c._cua->info;
      _cua->seg = copiar(c._cua->seg, c._cua, _cua);
    }
    catch (...) {
      delete(_cua);
      throw;
    }
  }
}

template <typename T>
typename cua<T>::node* cua<T>::copiar(node* n, node* fi, node* ini) {
  node* aux;
  if (n != fi) {
    aux = new node;
    try {
      aux->info = n->info;
      aux->seg = copiar(n->seg, fi, ini); 
    }
    catch (...) {
      delete aux;
      throw;
    }
  }
  else {
    aux = ini;
  }
  return aux;
}

template <typename T>
cua<T>& cua<T>::operator=(const cua<T> &c) {
  if (this != &c) {
    cua<T> caux(c);
    node* naux = _cua;
    _cua = caux._cua;
    caux._cua = naux;
  }
  return *this;
}

template <typename T>
cua<T>::~cua() throw() {
  if (_cua != NULL) {
    node* fi = _cua;
    _cua = _cua->seg;
    while (_cua != fi) {
      node* aux = _cua;
      _cua = _cua->seg;
      delete aux;
    }
    delete(_cua);
  }
}

template <typename T>
void cua<T>::encuar(const T &x) {
  node* p = new(node); 
  try {
    p->info = x;
  }
  catch (...) {
    delete p;
    throw;
  }
  if (_cua == NULL) {
    p->seg = p;  // cua amb un únic element que s’apunta 
  }              // a sí mateix
  else {
    p->seg = _cua->seg;
    _cua->seg = p;
  }
  _cua = p;
}

template <typename T>
void cua<T>::desencuar() { 
  if (_cua==NULL) {
    throw CuaBuida;
  }
  node* p = _cua->seg;
  if (p == _cua) {
    _cua = NULL; // desencuem una cua que tenia un únic 
  }              // element
  else {  
    _cua->seg = p->seg;
  }
  delete(p);
}

template <typename T>
const T& cua<T>::primer() const { 
  if (_cua==NULL) { 
    throw CuaBuida;
  }
  return (_cua->seg->info);
}

template <typename T>
bool cua<T>::es_buida() const throw() {  
  return (_cua==NULL);
}
#include <iostream>
#include <sstream>

using namespace std;


void eliminar_suma_major_cua(int &j, cua<int> &q1, cua<int> &q2){
// Pre: cert
// Post: afegeix els elements de q1 a q2 si son mayor a igual a j, on j es igual a j+q1.primer, q1 es quedara buit 
    if (not q1.es_buida()){
        
        int now = q1.primer();
        if (j >= now){
            q2.encuar(now);
        }

        j+=now;

        q1.desencuar();
        eliminar_suma_major_cua(j,q1,q2);
        // Post: afegeix els elements de q1-1 a q2 si son mayor a igual a j, on j es igual a j+q1.primer, q1 es quedara buit 
        //Fita: mida de q1

    }

}


int main (){

    string s;

    while (getline(cin,s)){
        istringstream ss(s);

        int x;
        cua<int> q1;
        cua<int> q2;
        while (ss >> x){
            q1.encuar(x);
        }
        x = 0;
        eliminar_suma_major_cua(x,q1,q2);

        while (not q2.es_buida()){
            cout << q2.primer();
            //if (q2.size() != 1) 
            q2.desencuar(); 
            if (not q2.es_buida())
                cout << " ";
        }
        cout << endl;
    }
}

