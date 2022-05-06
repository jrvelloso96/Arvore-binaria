#include <iostream>
#include <conio.h>
#include "Arvore binaria.h"


using namespace std;

int main()
{   char valor;
    Arvore * raiz;
      cout << "ANTES DE INICIAR, POR FAVOR INSIRA A UM DADO PARA RAIZ: ";
      cin>> valor;
      raiz = novaArvore(valor);


     int menu;
     cout << "\n           MENU\n\n";
     cout << "[1] INSERIR DADOS NA ARVORE \n[2] MOSTRAR DADOS EM ORDEM \n[3] MOSTRAR DADOS EM PRE-ORDEM\n[4] MOSTRAR DADOS EM POS-ORDEM\n[5] MOSTRAR DADOS EM NIVEL\n[6] REMOVER DADOS DA ARVORE\n[7] SAIR\n\n\n\n";


   do{
        cin >> menu;
       if (menu > 7){
            cout << "\nInforme um opcao valida\n"<<endl;
        }

        if (menu == 1){

        recebeDado (raiz, valor);

        cout << "\nproximo comando ou digite 7 para sair"<<endl;
        }

        if (menu == 2){
        cout << "Visualizando em ordem: \n"<<endl;
        mostraOrdem( raiz );

        cout << "\nproximo comando ou digite 7 para sair\n"<<endl;
        }

        if (menu == 3){
         cout << "Visualizando em pre ordem: \n"<<endl;
        mostraPreOrdem( raiz );

        cout << "\nproximo comando ou digite 7 para sair\n"<<endl;
        }

        if (menu == 4){
        cout << "Visualizando em pos ordem: \n"<<endl;
        mostraPosOrdem( raiz );

        cout << "\nproximo comando ou digite 7 para sair\n"<<endl;
        }

        if (menu == 5){
        cout << "Visualizando em nivel: \n"<<endl;
        mostraNivel( raiz );

        cout << "proximo comando ou digite 7 para sair\n";
        }

        if (menu == 6){
        searchdestroy (raiz, valor);
        Arvore *subarvore = searchArvore(raiz, valor);

        cout << "proximo comando ou digite 7 para sair\n";
        }

     }while (menu!=7);



   return 0;
}
