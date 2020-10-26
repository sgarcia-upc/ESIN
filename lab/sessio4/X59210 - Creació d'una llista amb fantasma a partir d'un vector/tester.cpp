#include <iostream>
#include "conjunt_2enters.hpp"

using namespace std;

int main (){
    cj_2enters a;
    a.print(cout);
    pair<int,int> p (1,2);
    a.insereix(p);
    a.print(cout);

    pair<int,int> p1 (2,2);
    a.insereix(p1);
    cout << endl;
    a.print(cout);

    cout << endl;
    a.print(cout);
    cj_2enters b;
    b.print(cout);
    //pair<int,int> p2 (1,5);
    //a.insereix(p2);
    //a.print(cout);
    //pair<int,int> p3 (3,5);
    //a.insereix(p3);
    //a.print(cout);

    //cout << a.conte(p3);
    //pair<int,int> p4 (4,5);
    //cout << a.conte(p4) <<endl;
    //
    //cout << a.max().first << "," << a.max().second<<endl;
    //cout << a.min().first << "," << a.min().second<<endl;

}

