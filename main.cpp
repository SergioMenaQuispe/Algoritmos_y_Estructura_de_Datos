#include"lista.cpp"
#include<iostream>
using namespace std;


int main(){
    Lista<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(6);
    l.push_back(5);
    l.push_back(7);
    l.push_back(4);

    l.print_reverse();

    l.max();
    int a = l.getHead()->getDato();
    l.max_recursive(a,l.getHead());
    return 0;
}