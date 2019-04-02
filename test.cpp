void add_sortedd(int data_){
    nodo *new_nodo = new nodo(data_);
    nodo *temp = head;
    nodo **nextn = new_nodo.next;
    nodo **tempa = temp.next;
    if (!head) {
        head = new_nodo;
    } else {
        if (head->data > data_) {
            nextn = head;
            head = new_nodo;
        } else {
            while ((tempa != NULL) && (tempa->data < data_)) {
                temp = tempa;
            }
            nextn = tempa;
            tempa = new_nodo;
        }
    }
    elementos++;
}
