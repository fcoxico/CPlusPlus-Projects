#include <iostream>
#include <windows.h>

/*
Um programa que cria uma lista encadeada, verifica se está vazia, insere um elemento 
no começo ou no fim, verifica o tamanho da lista, remove um elemento e apaga a lista. 

(A program that creates a linked list, checks if it is empty, inserts an element at 
the beginning or end, checks the size of the list, removes an element, and deletes the list.)
*/

using namespace std;

class No {
private:
    int v;
    No* prox;

public:

    //--------------------------------------------------------------------------

    /* Construtor	*/
    No(int v) {
        this-> v = v;
        this-> prox = NULL;

    }

    // Fim do construtor--------------------------------------------------------



    //--------------------------------------------------------------------------	

    int obterValor() {
        return v;
    }

    //--------------------------------------------------------------------------		

    No* obterProx() {
        return prox;
    }

    //--------------------------------------------------------------------------	

    void setProx(No* p) {
        prox = p;
    }

    //--------------------------------------------------------------------------
};

class Lista {
private:

    No* cabeca; // primeiro elemento
    No* cauda; // último elemento

public:

    //--------------------------------------------------------------------------

    Lista() {
        cabeca = NULL;
        cauda = NULL;
    }

    //--------------------------------------------------------------------------

    Lista(int v) {
        cabeca = new No(v);
        cauda = cabeca;
    }

    //--------------------------------------------------------------------------

    virtual ~Lista() {
        delete cabeca;
    }

    //--------------------------------------------------------------------------

    void mostrar() {
        cout << "\nImprimindo todos os elementos ...\n";
        No* c = cabeca;

        if (vazia())
            cout << "A lista NAO possui elementos !!\n";

        else {
            while (c) {
                cout << c-> obterValor() << endl;
                c = c->obterProx();
            }
            cout << endl;
        }
    }

    //--------------------------------------------------------------------------

    bool vazia() {
        return (cabeca == NULL);
    }

    //--------------------------------------------------------------------------

    void inserir_inicio(int v) {
        No* novo_no = new No(v);

        if (vazia()) {
            cabeca = novo_no;
            cauda = novo_no;
        } else {
            novo_no->setProx(cabeca);
            cabeca = novo_no;
        }

    }
    //--------------------------------------------------------------------------	  

    void inserir_final(int v) {
        No* novo_no = new No(v);

        if (vazia()) {
            cabeca = novo_no;
            cauda = novo_no;
        } else {
            cauda ->setProx(novo_no);
            cauda = novo_no;
        }

    }
    //--------------------------------------------------------------------------		

    int tamanho() {
        if (vazia())
            return 0;

        No* c = cabeca;
        int tam = 0;

        //Percorre a lista
        do {
            c = c->obterProx();
            tam++;
        } while (c);

        return tam;

    }
    //--------------------------------------------------------------------------

    bool existe(int v) {
        No* c = cabeca;
        while (c) {

            if (c->obterValor() == v)
                return true;
            c = c->obterProx();



        }
        return false;
    }

    void remover()//Remover do final
    {



        if (!vazia()) {
            //Se houver 1 elemento
            if (cabeca->obterProx() == NULL)
                cabeca = NULL;
            else if (cabeca->obterProx()->obterProx() == NULL) //Se houver 2 elementos

                cabeca->setProx(NULL);

            else //Se houver mais de 3 elementos
            {
                No* ant_ant = cabeca;
                No* ant = cabeca->obterProx();
                No* corrente = cabeca->obterProx()->obterProx();

                while (corrente) {
                    No* aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente = corrente->obterProx();
                }
                delete ant_ant->obterProx();
                ant_ant->setProx(NULL);
                cauda = ant_ant;
            }
        }
    }


    //------------------------------------------------------------------------------

    void inserir_verificaParImpar(int v) {
        
        int a;
        
        No* novo_no = new No(a);

        if (vazia()) {
            cabeca = novo_no;
            cauda = novo_no;
        } else if ((a % 2) == 0) {
            cabeca ->setProx(novo_no);
            cabeca = novo_no;
        } else {
            cauda ->setProx(novo_no);
            cauda = novo_no;
        }


    }


//------------------------------------------------------------------------------

};

int main(int argc, char *argv[]) {
    system("color 3f");
    Lista l;

    if (l.vazia())
        cout << "Lista vazia!!\n";
    else
        cout << "Lista NAO vazia!!\n";


    l.mostrar();

    if (l.existe(10))
        cout << "\nO elemento 10 existe na lista!!\n";
    else
        cout << "\nO elemento 10 NAO existe na lista!!\n";


    l.inserir_verificaParImpar(12);
    l.inserir_verificaParImpar(15);
    l.inserir_verificaParImpar(3);
    l.inserir_verificaParImpar(5);
    l.inserir_verificaParImpar(8);
    l.inserir_verificaParImpar(19);
    l.inserir_verificaParImpar(13);
    l.inserir_verificaParImpar(10);
    

    l.mostrar();

    if (l.vazia())
        cout << "Lista vazia!!\n";
    else
        cout << "Lista NAO vazia!!\n";

    if (l.existe(10))
        cout << "\nO elemento 10 existe na lista!!\n";
    else
        cout << "\nO elemento 10 NAO existe na lista!!\n";

    l.remover();

    l.mostrar();

    cout << "Tamanho da lista: " << l.tamanho() << endl;

    return 0;
}
