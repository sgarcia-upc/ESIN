#include "conjunt_2enters.hpp"

cj_2enters::cj_2enters() {
    head = NULL;
    size = 0;
}

// Les tres grans: Constructora per còpia, destructora, operador d'assignació
cj_2enters::cj_2enters(const cj_2enters &cj){
    copiar(cj);
}

cj_2enters& cj_2enters::operator=(const cj_2enters &cj){
    copiar(cj);
    return *this;
}

void cj_2enters::copiar(const cj_2enters &cj){
    if (this != &cj && cj.head != NULL){

        node *hd = new node;
        node *first = hd;
        node *cj_aux = cj.head;

        while (cj_aux != NULL){
            node *nw = new node;
            nw->info = cj_aux->info;
            nw->next = NULL;
            hd->next = nw;

            cj_aux = cj_aux->next;
            hd = hd->next;
        }

        head = first->next;
        size = cj.size;
        delete first;
    }
}


void cj_2enters::kill_me(){
    node *a = head;
    while (a != NULL){
        node *next = a->next;
        delete a;
        a = next;
    }
}

cj_2enters::~cj_2enters(){
    kill_me();
}


// Insereix la parella d'enters pe en el conjunt. No fa res si pe ja pertanyia al conjunt.
void cj_2enters::insereix(pair<int, int> pe){

    if (head == NULL){
        node *n = new node;
        n->info = pe;
        n->next = NULL;
        head=n;
        size++;
    } else {
        node *aux = head;
        if (aux->info.first > pe.first or (aux->info.first == pe.first and aux->info.second > pe.second)){
            node *n = new node;
            n->info = pe;
            n->next = aux;
            head = n;
            size++;
        } else {
            while (aux != NULL){
                if (aux->info.first < pe.first or (aux->info.first == pe.first and aux->info.second < pe.second)){
                    if (aux->next != NULL){
                        if (aux->next->info.first > pe.first or (aux->next->info.first == pe.first and aux->next->info.second > pe.second)){
                            node *n = new node;
                            n->next = aux->next;
                            n->info = pe;
                            aux->next = n;
                            size++;
                        }
                    } else {
                        node *n = new node;
                        n->info = pe;
                        n->next = NULL;
                        aux->next = n;
                        size++;
                    }
                }
                aux = aux->next;
            }
        }
    }
}

int cj_2enters::compare_pair(pair <int,int> a, pair<int,int> b){
    if (a.first < b.first or (a.first == b.first and a.second < b.second)){
        return -1;
    }
    else if (a.first > b.first or (a.first == b.first and a.second > b.second)){
        return 1;
    }

    return 0;
}

// Unió, intersecció i diferència de conjunts. Operen modificant el conjunt sobre el que
// s'aplica el mètode, usant el segon conjunt com argument. P.e.: a.restar(b) fa que el
// nou valor d'a sigui A - B, on A i B són els valors originals dels objectes a i b.
void cj_2enters::unir(const cj_2enters& B){
    // kill_me();

    //node *axxp = axx.head;
    //node *a = head;
    //node *b = B.head;

    //while (a != NULL and b != NULL){
    //    if (compare_pair(a->info, b->info) == -1){
    //        node *n = new node();
    //        n->info = a->info;
    //        axxp->next = n;
    //        a = a->next;

    //    } else if (compare_pair(a->info, b->info) == 1) {
    //        node *n = new node();
    //        n->info = b->info;
    //        axxp->next = n;
    //        b = b->next;

    //    } else if (compare_pair(a->info, b->info) == 0) {
    //        node *n = new node();
    //        n->info = a->info;
    //        axxp->next = n;
    //        a = a->next;
    //        b = b->next;

    //    }
    //}
}
void cj_2enters::intersectar(const cj_2enters& B){
    //cj_2enters aux;
    //int this_n = 0;
    //int B_n = 0;
    //
    //while (this_n < size and B_n < B.size){
    //    if (rcj[this_n].first < B.rcj[B_n].first or (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second < B.rcj[B_n].second)){
    //        this_n++;
    //    } else if (rcj[this_n].first > B.rcj[B_n].first or (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second > B.rcj[B_n].second)){
    //        B_n++;
    //    } else if (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second == B.rcj[B_n].second){
    //        //cout << " " << rcj[this_n].first << rcj[this_n].second;
    //        aux.rcj[aux.size] = rcj[this_n];
    //        aux.size++;
    //        this_n++;
    //        B_n++;
    //    }
    //}
    //for (int i=0; i < aux.size; i++){
    //    rcj[i] = aux.rcj[i];
    //}

    //size = aux.size;
}

void cj_2enters::restar(const cj_2enters& B) {
    //cj_2enters aux;
    //int this_n = 0;
    //int B_n = 0;
    //
    //while (this_n < size and B_n < B.size){
    //    if (rcj[this_n].first < B.rcj[B_n].first or (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second < B.rcj[B_n].second)){
    //        //cout << " " << rcj[this_n].first << rcj[this_n].second;
    //        aux.rcj[aux.size] = rcj[this_n];
    //        aux.size++;
    //        this_n++;
    //    } else if (rcj[this_n].first > B.rcj[B_n].first or (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second > B.rcj[B_n].second)){
    //        //cout << " " << B.rcj[B_n].first << B.rcj[B_n].second;
    //        B_n++;
    //    } else if (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second == B.rcj[B_n].second){
    //        //cout << " " << rcj[this_n].first << rcj[this_n].second;
    //        this_n++;
    //        B_n++;
    //    }
    //}

    //while (this_n < size){
    //    aux.rcj[aux.size] = rcj[this_n];
    //    aux.size++;
    //    this_n++;
    //}

    //for (int i=0; i < aux.size; i++){
    //    rcj[i] = aux.rcj[i];
    //}

    //size = aux.size;

}

// Unió, intersecció i diferència de conjunts. Operen creant un nou conjunt sense
// modificar el conjunt sobre el que s'aplica el mètode. La suma de conjunts correspon
// a la unió, la resta a la diferència i el producte a la intersecció.

cj_2enters cj_2enters::operator+(const cj_2enters& B) const{
    cj_2enters result(*this);
    //result.unir(B);
    return B;
}

cj_2enters cj_2enters::operator*(const cj_2enters& B) const {
    cj_2enters result(*this);
    result.intersectar(B);
    return result;
}

cj_2enters cj_2enters::operator-(const cj_2enters& B) const{
    cj_2enters result(*this);
    result.restar(B);
    return result;
}

// Retorna cert si i només si pe pertany al conjunt.
bool cj_2enters::conte(pair<int, int> pe) const{
    node *aux = head;
    while (aux != NULL and aux->info.first <= pe.first){
        if (aux->info.first == pe.first and aux->info.second == pe.second){
            return true;
        }

        aux = aux->next;
    }
    return false;
}

// Retornen els elements màxim i mínim del conjunt, respectivament.
// El seu comportament no està definit si el conjunt és buit.
// pe1 és major que pe2 si el 1er enter de pe1 és major que el 1er enter de pe2. En cas
// que siguin iguals, si el 2on enter de pe1 és major que el 2on enter de pe2.
pair<int, int> cj_2enters::max() const {
    node *aux = head;
    while (aux->next != NULL){
        aux = aux->next;
    }
    return aux->info;
    return pair<int,int>();
}

pair<int, int> cj_2enters::min() const{
    return head->info;
}

// Retorna el nombre d'elements (la cardinalitat) del conjunt.
int cj_2enters::card() const{
    return size;
}

// Operadors relacionals. == retorna cert si i només si els dos conjunts
// (el paràmetre implícit i B) contenen els mateixos elements;
// != retorna cert si i només si els conjunts són diferents.
bool cj_2enters::operator==(const cj_2enters& B) const{
    if (size != B.size){
        return false;
    }

    node *a = head;
    node *b = B.head;
    while (a != NULL and b != NULL){
        if (a->info.first != b->info.first and a->info.second != b->info.second){
            return false;
        }
        a = a->next;
        b = b->next;
    }

    return true;
}

bool cj_2enters::operator!=(const cj_2enters& B) const{
    return !this->operator==(B);
}

// Imprimeix el conjunt de parelles d'enters, ordenats en ordre ascendent, sobre
// el canal de sortida os; el format és [pe1 pe2 ... pen], és a dir, amb
// espais entre els elements i tancant la seqüència amb claudàtors.
// Els dos enters de la parella d'enters estan separats amb una coma.
void cj_2enters::print(ostream& os) const {
    os << "[";
    node *aux = head;
    while ( aux != NULL ){
        os << aux->info.first << "," << aux->info.second;
        if (aux->next != NULL){
            os << " ";
        }
        aux = aux->next;
    }
    os << "]";
}

