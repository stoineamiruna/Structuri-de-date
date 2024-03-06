#include <iostream>

using namespace std;

struct Nod {
    int info;
    Nod* ant;
    Nod* urm;
};

class Deque {
private:
    Nod* st;
    Nod* dr;

public:
    Deque() {
        st=NULL;
        dr=NULL;
    }

    bool empty() {
        return (st==NULL && dr==NULL);
    }

    void pushStanga(int x) {
        Nod* p = new Nod;
        p->info = x;
        p->ant = NULL;
        p->urm = st;

        if (st==NULL&&dr==NULL) {
            dr=p;
        } else {
            st->ant = p;
        }

        st=p;
    }

    void pushDreapta(int x) {
        Nod* p = new Nod;
        p->info =x;
        p->ant =dr;
        p->urm =NULL;

        if (st==NULL&&dr==NULL) {
            st = p;
        } else {
           dr->urm = p;
        }

        dr= p;
    }

    int popStanga() {
        if (empty()) {
            cout << "\nCoada este goala\n";
            return -1;
        }

        Nod* pn = st;
        int pv = pn->info;

        if (st == dr) {
            st=NULL;
            dr=NULL;
        } else {
            st=st->urm;
            st->ant =NULL;
        }

        delete pn;
        return pv;
    }

    int popDreapta() {
        if (empty()) {
            cout << "\nCoada este goala";
            return -1;
        }

        Nod* pn = dr;
        int pv = pn->info;

        if (st==dr) {
            st=NULL;
            dr=NULL;
        } else {
            dr=dr->ant;;
           dr->urm=NULL;
        }

        delete pn;
        return pv;
    }
    ~Deque() {
        while (st!=NULL) {
            Nod* aux= st;
            st = st->urm;
            delete aux;
        }
        while (dr!=NULL) {
            Nod* aux =dr;
            dr=dr->urm;
            delete aux;
        }
    }
};

struct Nodp {
   int p;
   int info;
   struct Nodp* urm;
};

class Priority_Queue {
private:
    Nodp* prim;

public:
    Priority_Queue() {
        prim= NULL;
    }

    void Insert(int i, int p) {
        Nodp* t, * q;
        t = new Nodp;
        t->info = i;
        t->p = p;
        if (prim == NULL || p < prim->p) {
            t->urm = prim;
            prim = t;
        } else {
            q = prim;
            while (q->urm != NULL && q->urm->p <= p)
                q = q->urm;
            t->urm = q->urm;
            q->urm = t;
        }
    }

    void Extract() {
        Nodp* t;
        if (prim == NULL)
            cout << "Coada este goala\n";
        else {
            t = prim;
            cout << "Nodul sters este: " << t->info <<"\n";
            prim = prim->urm;
            free(t);
        }
    }

    void Afisare() {
        Nodp* ptr;
        ptr = prim;
        if (prim == NULL)
            cout << "Coada este goala\n";
        else {
            cout << "Coada este:\n";
            while (ptr != NULL) {
                cout << ptr->p << " " << ptr->info <<"\n";
                ptr = ptr->urm;
            }
        }
    }
    ~Priority_Queue() {
        Nodp *ptr;
        while (prim != NULL) {
            ptr = prim;
            prim = prim->urm;
            delete ptr;
        }
    }
};
int main() {

    cout<<"Coada cu lista dublu inlantuita:\n";

    Deque deque;

    // Adaugam elemente la stanga
    deque.pushStanga(5);
    deque.pushStanga(3);
    deque.pushStanga(1);

    // Adaugam elemente la dreapta
    deque.pushDreapta(2);
    deque.pushDreapta(4);
    deque.pushDreapta(6);

    // Extragem elemente de la stanga si le afisam
    cout << "Adaugate la stanga: ";
    while (!deque.empty()) {
        cout << deque.popStanga() << " ";
    }
    cout<<"\n";

    // Adaugam alte elemente la stanga
    deque.pushStanga(9);
    deque.pushStanga(7);
    deque.pushStanga(5);

    // Extragem elemente de la dreapta si le afisam
    cout << "Adaugate la dreapta: ";
    while (!deque.empty()) {
        cout << deque.popDreapta() << " ";
    }

    cout<<"\nCoada de prioritate:\n";
    Priority_Queue pq;

    pq.Insert(10, 3);
    pq.Insert(20, 1);
    pq.Insert(30, 2);
    pq.Insert(40, 2);
    pq.Insert(50, 1);

    pq.Afisare();

    pq.Extract();
    pq.Extract();

    pq.Afisare();

    return 0;
}
