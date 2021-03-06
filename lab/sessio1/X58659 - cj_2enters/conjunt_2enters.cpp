#include "conjunt_2enters.hpp"

cj_2enters::cj_2enters() {
    size = 0;
}

// Les tres grans: Constructora per còpia, destructora, operador d'assignació
cj_2enters::cj_2enters(const cj_2enters &cj){
    for (int i=0; i < cj.size; i++){
        rcj[i] = cj.rcj[i];
    }

    size = cj.size;
}

cj_2enters& cj_2enters::operator=(const cj_2enters &cj){
    for (int i=0; i < cj.size; i++){
        rcj[i] = cj.rcj[i];
    }
    size = cj.size;

    return *this;
}

cj_2enters::~cj_2enters(){
}


// Insereix la parella d'enters pe en el conjunt. No fa res si pe ja pertanyia al conjunt.
void cj_2enters::insereix(pair<int, int> pe){

    if (!conte(pe)){
        int i; 
        for (i = size - 1; (i >= 0 && (rcj[i].first > pe.first || (rcj[i].first == pe.first && rcj[i].second > pe.second))); i--)
            rcj[i + 1] = rcj[i];
        
        rcj[i + 1] = pe;
        size++;
    }

}

// Unió, intersecció i diferència de conjunts. Operen modificant el conjunt sobre el que
// s'aplica el mètode, usant el segon conjunt com argument. P.e.: a.restar(b) fa que el
// nou valor d'a sigui A - B, on A i B són els valors originals dels objectes a i b.
void cj_2enters::unir(const cj_2enters& B){
//    cj_2enters aux;
//    
//    int this_n = 0;
//    int B_n = 0;
//    int aux_n = 0;
//    while (this_n < size or B_n < B.size){
//        if (rcj[this_n].first < B.rcj[B_n].first or (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second < B.rcj[B_n].second)){
//            aux.rcj[aux_n] = rcj[this_n];
//            aux_n++;
//            this_n++;
//        }
//        if (rcj[this_n].first > B.rcj[B_n].first or (rcj[this_n].first == B.rcj[B_n].first and rcj[this_n].second > B.rcj[B_n].second)){
//            aux.rcj[aux_n] = rcj[B_n];
//            aux_n++;
//            B_n++;
//        }
//    }
//
//    while (B_n < B.size){
//        aux.rcj[aux_n] = B.rcj[B_n];
//        aux_n++;
//        B_n++;
//    }
//
//    while (this_n < size){
//        aux.rcj[aux_n] = rcj[this_n];
//        aux_n++;
//        this_n++;
//    }
//
//    for (int i=0; i < aux.size; i++){
//        rcj[i] = aux.rcj[i];
//    }
//    size = aux.size;
//    
}

void cj_2enters::intersectar(const cj_2enters& B){
//    cj_2enters result;
//    for (int i=0; i < size; i++){
//        if (rcj[i].first > B.max().first && rcj[i].second > B.max().second){
//            break;
//        }
//        for (int x=0; x < B.size; x++){
//            if (rcj[i].first == B.rcj[x].first && rcj[i].second == B.rcj[x].second){
//                result.insereix(rcj[i]);
//                break;
//            }
//        }
//    }
//
//    for (int i=0; i < result.size; i++){
//        rcj[i] = result.rcj[i];
//    }
//    size = result.size;
}

void cj_2enters::restar(const cj_2enters& B) {
//    cj_2enters result;
//    for (int i=0; i < size; i++){
//        if (rcj[i].first > B.max().first && rcj[i].second > B.max().second){
//            break;
//        }
//        for (int x=0; x < B.size; x++){
//            if (rcj[i].first == B.rcj[x].first && rcj[i].second == B.rcj[x].second){
//                result.insereix(rcj[i]);
//                break;
//            }
//        }
//    }
//
//    for (int i=0; i < result.size; i++){
//        rcj[i] = result.rcj[i];
//    }
//    size = result.size;
}

// Unió, intersecció i diferència de conjunts. Operen creant un nou conjunt sense
// modificar el conjunt sobre el que s'aplica el mètode. La suma de conjunts correspon
// a la unió, la resta a la diferència i el producte a la intersecció.

cj_2enters cj_2enters::operator+(const cj_2enters& B) const{
    cj_2enters result(*this);
//   result.unir(B);
    return result;
}

cj_2enters cj_2enters::operator*(const cj_2enters& B) const {
    cj_2enters result(*this);
//    result.intersectar(B);
    return result;
}

cj_2enters cj_2enters::operator-(const cj_2enters& B) const{
    cj_2enters result(*this);
//    result.restar(B);
    return result;
}

// Retorna cert si i només si pe pertany al conjunt.
bool cj_2enters::conte(pair<int, int> pe) const{
    for (int x=0; x < size; x++)
        if (rcj[x] == pe)
            return true;
    return false;
}

// Retornen els elements màxim i mínim del conjunt, respectivament.
// El seu comportament no està definit si el conjunt és buit.
// pe1 és major que pe2 si el 1er enter de pe1 és major que el 1er enter de pe2. En cas
// que siguin iguals, si el 2on enter de pe1 és major que el 2on enter de pe2.
pair<int, int> cj_2enters::max() const {
    if (size > 0){
        return rcj[size-1];
    }
    return pair<int, int>();
}

pair<int, int> cj_2enters::min() const{
    if (size > 0){
        return rcj[0];
    }
    return pair<int, int>();
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

    for (int i=0; i < B.size; i++){
        if (rcj[i].first != B.rcj[i].first || rcj[i].second != B.rcj[i].second){
            return false;
        }
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
    if (size > 0){
            os << "[";
        for (int i=0; i < size; i++){
            os << rcj[i].first << "," << rcj[i].second;
            if (i < size-1){
                os << " ";
            }
        }
        os << "]";
    } else {
        os << "[]";
    }
}

