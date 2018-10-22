#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


void Fumante (int []);
void NaoFumante(int[]);
void ImprimeLugar(int[]);

int verificaFumante = 0, verificaNaoFumante = 0,fumante,posicao,resposta,i,troca,lugares[11];


void ImprimeLugar(int lugar[]) {
     for (i=1;i<=10;++i) {  //Imprime lugares
               if (lugares[i] == 0) //Acento livre
                  printf ("%d(L)   ",i);
               else  //Acento Reservado
                   printf ("%d(R)   ",i);
               if (i == 5) 
                  printf(" <-- Area dos fumantes\n");
           }
           printf ("<-- Area dos  nao fumantes.");
}     
void Fumante (int lugar[]) {
     if (verificaFumante + verificaNaoFumante != 10) {
      if (verificaFumante != 5 ) {
                          printf ("%d",verificaFumante);
                     printf ("\n\n\n      !!!!AREA DOS FUMANTES!!!!\n\n\n");
                     printf ("Qual cadeira voce deseja comprar?(1-5)");
                     scanf ("%d",&posicao);
                     system("cls");
                     if (posicao >= 1 && posicao <= 5) {
                               if (lugares[posicao] == 0) {
                                   lugares[posicao] = 1;
                                   printf ("|||||ACENTO RESERVADO COM SUCESSO|||||");
                                   ++verificaFumante;
                               }
                               else
                                   printf ("|||||ACENTO OCUPADO|||||");
                     }
                     else {
                          system("cls");
                          printf ("|||||ACENTO INVALIDO|||||");               
                     }
      }
      else {
            printf ("Deseja ir para um acento de Nao Fumantes?(SIM-1-    NAO-2-):  ");
            scanf ("%d",&troca);
            if (troca == 1) {
                    NaoFumante(lugares);
            }
            else {
                   printf ("O proximo voo sai daqui a 3 horas.");  
                   system("cls");
            }
      }
     }
     else {
          printf ("\n\n&&&&&&&&&&&&&&&Voo lotado&&&&&&&&&&&&&&&\n\n");

     }
               
}

void NaoFumante (int lugar[]) {
   if (verificaNaoFumante + verificaFumante != 10) {
     if (verificaNaoFumante != 5) {
        printf ("%d",verificaNaoFumante);
        printf ("\n\n\n          !!!!AREA DOS NAO FUMANTES!!!!\n\n\n");
        printf ("Qual cadeira voce deseja comprar?(6-10)");
        scanf ("%d",&posicao);
        system("cls");
        if (posicao >= 6 && posicao <=10) {
                 if (lugares[posicao] == 0)  {
                                      lugares[posicao] = 1;
                                      printf ("|||||ACENTO RESERVADO COM SUCESSO|||||");
                                      ++verificaNaoFumante;
                 }
                 else
                     printf ("|||||ACENTO OCUPADO|||||");
        }
        else {
          system("cls");
          printf ("|||||ACENTO INVALIDO|||||");
        }   
     }  
     else {
            printf ("Deseja ir para um acento de Fumantes?(SIM-1-    NAO-2-):  ");
            scanf ("%d",&troca);
            if (troca == 1) {
                    Fumante(lugares);
            }
            else {
                   printf ("O proximo voo sai daqui a 3 horas.");  
                   system("cls");
            }  
      }    
   }   
   else {
          printf ("\n\n&&&&&&&&&&&&&&&Voo lotado&&&&&&&&&&&&&&&\n\n");
 
   }
}
                  
main (){
     for (i=0;i<=11;++i) //Zerando array
         lugares[i] = 0;
     printf ("Deseja comprar passagens?(SIM-1-   NAO-2-): ");
     scanf ("%d", &resposta);
     while (resposta == 1) { //Confirmação de compra
           system("cls");
           printf ("|||||COMPRA DE PASSAGENS|||||\n\n\n");
           ImprimeLugar(lugares);
           printf ("\n\nVoce e Fumante(1) ou NAO Fumante(2)?");
           scanf ("%d",&fumante);
           if (fumante == 1) {
                       Fumante(lugares);
           }
           else {
                if (fumante == 2) 
                       NaoFumante(lugares);
                else {
                     system("cls");
                     printf ("|||||DIGITOU UM CARACTERE INVALIDO|||||\n");
                }
           }  
           
           printf ("\n\n\n");
           ImprimeLugar(lugares);         
           printf ("\n\nDeseja comprar mais passagens?(SIM-1-   NAO-2-): ");
           scanf ("%d",&resposta);
     }
     system("cls");
     printf ("$$$VOLTE SEMPRE$$$"); 
     getch();
}
         
         
