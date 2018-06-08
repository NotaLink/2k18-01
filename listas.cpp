#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

class nodo{
public:
    nodo *next;
    int data;

    nodo(){
        data = NULL;
        next = NULL;
    }

    nodo(int data_){
        data = data_;
        next = NULL;
    }

    void borrarTodos(){
        if (next)
            next->borrarTodos();
        delete this;
    }

    void print(){
        //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
        cout << data << "-> ";
    }
};

class lista{
private:
    nodo *head;
    int elementos;
public:

    lista(){
        elementos = 0;
        head = NULL;
    }

    void add_head(int data_){
        nodo *new_nodo = new nodo (data_);
        nodo *temp = head;

        if (!head) {
            head = new_nodo;
        } else {
            new_nodo->next = head;
            head = new_nodo;

            while (temp) {
                temp = temp->next;
            }
        }
        elementos++;
    }

    void add_end(int data_){
        nodo *new_nodo = new nodo (data_);
        nodo *temp = head;

        if (!head) {
            head = new_nodo;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_nodo;
        }
        elementos++;
    }

    void add_sorted(int data_){
    nodo *new_nodo = new nodo(data_);
    nodo *temp = head;
    if (!head) {
        head = new_nodo;
    } else {
        if (head->data > data_) {
            new_nodo->next = head;
            head = new_nodo;
        } else {
            while ((temp->next != NULL) && (temp->next->data < data_)) {
                temp = temp->next;
            }
            new_nodo->next = temp->next;
            temp->next = new_nodo;
        }
    }
    elementos++;
    }

    void sorted(){
        int temp_data;
        nodo *aux_nodo = head;
        nodo *temp = aux_nodo;

        while (aux_nodo) {
            temp = aux_nodo;

            while (temp->next) {
                temp = temp->next;

                if (aux_nodo->data > temp->data) {
                    temp_data = aux_nodo->data;
                    aux_nodo->data = temp->data;
                    temp->data = temp_data;
                }
            }

            aux_nodo = aux_nodo->next;
        }
    }

    void borrarTodos(){
        head->borrarTodos();
        head = 0;
    }

    void delData(int data_){
        nodo *temp = head;
        nodo *temp1 = head->next;

        int cont = 0;

        if (head->data == data_) {
            head = temp->next;
        } else {
            while (temp1) {
                if (temp1->data == data_) {
                    nodo *aux_node = temp1;
                    temp->next = temp1->next;
                    delete aux_node;
                    cont++;
                    elementos--;
                }
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
    }

    void circular(){
        nodo *temp = head;
        while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = head;
    }

    void search1(int data_){
        nodo *temp = head;
        int cont = 1;
        int cont2 = 0;

        while (temp) {
            if (temp->data == data_) {
                cout << "El dato se encuentra en la posicion: " << cont << endl;
                cont2++;
            }
            temp = temp->next;
            cont++;
        }

        if (cont2 == 0) {
            cout << "No existe el dato " << endl;
        }
        cout << endl << endl;
    }

    void print(){
        nodo *temp = head;
        if (!head) {
            cout << "La Lista esta vacia " << endl;
        } else {
            while (temp) {
                temp->print();
                if (!temp->next) cout << "NULL";
                    temp = temp->next;
            }
      }
      cout << endl << endl;
    }

    void usuarioLlena(int dim){
        int ele;
        for (int i = 0; i < dim; i++) {
            cout << "Ingresa el elemento " << i + 1 << endl;
            cin >> ele;
            add_end(ele);
        }
    }

    void randomLlena(int dim){
        srand(time(NULL));
        for (int i = 0; i < dim; i++) {
            add_end(rand() % 100);
        }
    }
};

int main()
{
    lista lista1;
    int ele;

    int dim;
    int pos;
    string file_with_list;

    cout << "Ingresa la dimension de la lista: " << endl;
    cin >> dim;

    lista1.randomLlena(dim);

    cout << "Lista1 al inicio: " << endl;
    lista1.print();

    cout << "Agrega un elemento ordenado: " << endl;
    cin >> ele;
    lista1.add_sorted(ele);
    lista1.print();

    lista1.sorted();
    lista1.print();

    lista1.search1(3);

    lista1.borrarTodos();
    lista1.print();

    return 0;
}


