#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
class nodo_a{
public:
T info;
nodo_a<T>* hijos[2];

nodo_a(T info){
    this->info=info;
    hijos[0] =NULL;
    hijos[1] =NULL;
    }

};

template<typename T>
class Arbol{
public:
  nodo_a<T> *root;
  typedef T value_type;

    Arbol(){root=NULL;}

      bool find(T x,nodo_a<T>**&p){
        p=&root;
        while(*p && (*p)->info != x){
            p=&((*p)->hijos[(*p)->info < x]);
            }
        return *p;
        }

      bool insertar(T x){
        nodo_a<T>** p;
        if(find(x,p)){
            return 0;}
        *p=new nodo_a<T>(x);
        return 1;
        }



    nodo_a<T>** Intercambio(nodo_a<T>** q ){
        q = &(*q)->hijos[0];
        while ((*q)->hijos[1])
        {
            q = &((*q)->hijos[1]);
        }
        return q;
    }

     bool eliminar(T x){
        nodo_a<T>**p, **q;
        if (!find(x, p))
        {
            return 0;
        }
        if ((*p)->hijos[0] && (*p)->hijos[1])
        {
            q = Intercambio(p);
            (*p)->info = (*q)->info;
            p = q;
        }
        nodo_a<T>* t = *p;
        *p = (*p)->hijos[(*p)->hijos[1]!=0];
        delete t;
        return 1;
    }
};

#endif // TREE_H
