//Parte 1
#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
int contPlane = 0;
int vagas;
typedef struct TipoItem{
  int codAviao, qntvagas ;
  char nomePassageiro[81];
  char *destino;
  char *origem;
} TipoItem;
typedef struct TipoItemPassageiro{
    char nomePassageiro[81];
    int codAviao;
    int dia, mes, ano;
    char *destino;
    char *origem;
    int horaEmbarque;
}TipoItemPassageiro;
typedef struct TipoElemento *Apontador;
typedef struct TipoElemento{
  TipoItem item;
  struct TipoElemento *prox;
} TipoElemento;
typedef struct TipoLista{
  Apontador primeiro;
  Apontador ultimo;
} TipoLista;

typedef struct TipoElementoPassageiro *ApontadorPassageiro;
typedef struct TipoElementoPassageiro{
  TipoItemPassageiro item;
  struct TipoElementoPassageiro *prox;
} TipoElementoPassageiro;
typedef struct TipoListaPassageiro{
  ApontadorPassageiro primeiro;
  ApontadorPassageiro ultimo;
} TipoListaPassageiro;
void CriarListaVazia(TipoLista *lista){
  lista->primeiro = (Apontador) malloc (sizeof (TipoElemento));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
}
bool VerificaListaVazia(TipoLista * lista){
  if(lista->primeiro == lista->ultimo){
      return true;
  }else{
      return false;
  }
}
void InsereListaUltimo(TipoLista *lista, TipoItem *item){
  lista->ultimo->prox = (Apontador) malloc (sizeof (TipoElemento));
  lista->ultimo = lista->ultimo->prox;
  lista->ultimo->item = *item;
  lista->ultimo->prox = NULL;
}
void CriarListaVaziaPassageiro(TipoListaPassageiro *lista){
  lista->primeiro = (ApontadorPassageiro) malloc (sizeof (TipoElementoPassageiro));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
}
bool VerificaListaVaziaPassageiro(TipoListaPassageiro * lista){
  if(lista->primeiro == lista->ultimo){
      return true;
  }else{
      return false;
  }
}
void InsereListaUltimoPassageiro(TipoListaPassageiro *lista, TipoItemPassageiro *item){
  lista->ultimo->prox = (ApontadorPassageiro) malloc (sizeof (TipoElementoPassageiro));
  lista->ultimo = lista->ultimo->prox;
  lista->ultimo->item = *item;
  lista->ultimo->prox = NULL;
}
void ImprimeListaPassageiro(TipoListaPassageiro *lista){
    ApontadorPassageiro pAux;

    pAux = lista->primeiro->prox;
    while (pAux != NULL)
    {
        printf("Avião: %d\n", pAux->item.codAviao);
        printf("Passageiro: %s\n", pAux->item.nomePassageiro);
        printf("Embarque dia: %d %d %d\n", pAux->item.dia,pAux->item.mes, pAux->item.ano);
        printf("Origem: %s\n", pAux->item.origem);
        printf("Destino: %s\n", pAux->item.destino);
        printf("Hora do Embarque: ", pAux->item.horaEmbarque);
        pAux = pAux->prox;
    }
}
bool confereAviao(TipoLista *lista, TipoItem *item, int codAviao, bool y){
    Apontador x = lista -> primeiro -> prox;
    bool controle = false;
    while(x != NULL){
        if (codAviao == x->item.codAviao && x->item.qntvagas != 0){
                if (y == true){
                    x -> item.qntvagas= x -> item.qntvagas -1;
                }else{
                    *item = x -> item;
                }
            controle = true;
            break;
    }
        x = x -> prox;
    }
    return controle;

}
void Passageiro(TipoListaPassageiro *lista, TipoItemPassageiro *item){
    printf("\nConsultar por Passageiro\n");
    scanf("%s",item->nomePassageiro);
    bool passageiro = false;
    ApontadorPassageiro y = lista -> primeiro -> prox;
    while(y != NULL){
        if (strcmp(item->nomePassageiro, y -> item.nomePassageiro ) == 0){
            printf("Avião: %d\n", y->item.codAviao);
            printf("Passageiro: %s\n", y->item.nomePassageiro);
            printf("Embarque dia: %d %d %d\n", y->item.dia, y->item.mes, y->item.ano);
            printf("Origem: \n", y->item.origem);
            printf("Destino: \n", y->item.destino);
            passageiro = true;

        }
        y = y -> prox;
    }
    if (passageiro ==  false){
    printf("Passageiro não encontrado");
    }
}
void Aviao(TipoLista *lista, TipoItem item, TipoListaPassageiro *listaPassageiro){
    int x;
    bool y = false;
    printf("\nConsultar por avião\n");
    scanf("%d", &item.codAviao);
    x = confereAviao(lista, &item, item.codAviao, y);
    if(x == true){
        printf("Vagas restantes: %i\n", item.qntvagas);
        printf("Origem Origem : GVR- Coronel Altino Machado de Oliveira\n");
        printf("Destino: %s\n", item.destino);

    }
    ImprimeListaPassageiro(listaPassageiro);
}

int retornaTamanho(TipoLista *lista){
    Apontador x = lista -> primeiro -> prox;
    int i=0;
    while(x != NULL){
        i++;
    }
    printf("%d ", i);
    return i;
}
int main(){
    setlocale(LC_ALL, "portuguese");
    TipoLista lista;
    TipoListaPassageiro listaPassageiro;
    TipoItem item;
    TipoItemPassageiro itemPassageiro;
    CriarListaVazia(&lista);
    CriarListaVaziaPassageiro(&listaPassageiro);
    int res = 0,x, pos, op=0, cont=0, op1=0;
    while(op != 10){
    printf("Menu\n");
    switch(op){
    case 0:
        printf("--> Cadastrar novo avião\n");
        printf("    Reservar passagem\n");
        printf("    Consultar por avião\n");
        printf("    Consultar por passageiro\n");
        printf("    Sair");
            break;
    case 1:
        printf("    Cadastrar novo avião\n");
        printf("--> Reservar passagem\n");
        printf("    Consultar por avião\n");
        printf("    Consultar por passageiro\n");
        printf("    Sair");
            break;
    case 2:
        printf("    Cadastrar novo avião\n");
        printf("    Reservar passagem\n");
        printf("--> Consultar por avião\n");
        printf("    Consultar por passageiro\n");
        printf("    Sair");
            break;
    case 3:
        printf("    Cadastrar novo avião\n");
        printf("    Reservar passagem\n");
        printf("    Consultar por avião\n");
        printf("--> Consultar por passageiro\n");
        printf("    Sair");
            break;
    case 4:
        printf("    Cadastrar novo avião\n");
        printf("    Reservar passagem\n");
        printf("    Consultar por avião\n");
        printf("    Consultar por passageiro\n");
        printf("--> Sair");
            break;

    }
    char t = _getch();
    int i;
       switch (t)
        {
        case 13: //Enter
            if (op == 0){
                printf("\nCadastro de Aviões\n");
                    printf("\nCódigo do avião: ");
                    scanf("%i", &item.codAviao);
                    printf("\nQuantidade de Assentos: ");
                    scanf("%i", &item.qntvagas);
                    if(item.qntvagas > 101){
                            while(item.qntvagas > 101){
                            printf("Valor não permitido. Digite um valor menor ou igual a 100:\n");
                            scanf("%d", &item.qntvagas);
                            }

                    }

                    printf("Origem : GVR- Coronel Altino Machado de Oliveira\n");
                    //printf("Destino: \n");
                    while(op1 != 8){
                        printf("Destino: \n");
                        switch(op1){
                        case 0:
                            printf("--> Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 1:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("--> São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;

                        case 2:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("--> São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 3:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("--> Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 4:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("--> Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 5:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("--> Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 6:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("--> Sair");
                                break;
                        }
                    char j = _getch();
                    int k;
                    switch(j){
                            case 13: //Enter
                                if(op1 == 0){
                                    printf("\nDestino Belo Horizonte Confins CNF\n");
                                    item.destino ="Belo Horizonte Confins CN";
                                    system("pause");
                                   op1 = 8;
                                    break;

                                }else if(op1 == 1){
                                    printf("\nDestino São Paulo Campinas VCP\n ");
                                    item.destino = "São_Paulo_Campinas_VCP";
                                    system("pause");
                                    op1 = 8;

                                }else if(op1 == 2){
                                    printf("\nSão Paulo Viracopos VCP\n");
                                    item.destino = "São_Paulo_Viracopos_VCP";
                                    system("pause");
                                   op1 = 8;
                                    break;


                                }else if(op1 == 3){
                                    printf("\nParaná Curitiba CWB\n");
                                    item.destino = "Paraná_Curitiba_CWB";
                                    system("pause");
                                   op1 = 8;
                                   break;

                                }else if(op1 == 4){
                                    printf("\nPernanbuco Recife REC\n");
                                    item.destino = "Pernanbuco_Recife_REC";
                                    system("pause");
                                   op1 = 8;
                                   break;

                                }else if(op1 == 5){
                                    printf("\nRio de Janeiro Santos Dumond SDU\n");
                                    item.destino = "Pernanbuco_Recife_REC";
                                    system("pause");
                                    op1 = 8;
                                    break;

                                }else if(op1 == 6){
                                    op1 = 8;
                                }

                            case 72: // Seta cima
                                op1--;
                                if (op1 < 0)
                                    op1 = 6;
                                break;

                            case 80: //Seta baixo
                                op1++;
                                if (op1 > 6)
                                    op1 = 0;
                                break;


                            }
                    //op1=8;
                    system("cls");
                    }

                    InsereListaUltimo(&lista, &item);

            }
            else if (op == 1){ //Reservar passagem
                bool y = true;
               // printf("\nCódigo do avião: ");
               // scanf("%d", &item.codAviao);
                printf("Origem : GVR- Coronel Altino Machado de Oliveira\n");
                x = confereAviao(&lista, &item, item.codAviao, y);
                if (x == true){
                    printf("\nNome do Passageiro:\n");
                    scanf("%s", &itemPassageiro.nomePassageiro);
                    printf("\n Data do Embarque:\n--Dia/Mês/Ano--\n");
                    printf("Dia:\t");
                    scanf("%d", &itemPassageiro.dia);
                    if(itemPassageiro.dia<0 || itemPassageiro.dia>31){
                        while(itemPassageiro.dia<0 || itemPassageiro.dia>31){
                            printf("Data não permitida. Digite novamente:\n");
                            scanf("%d", &itemPassageiro.dia);
                        }
                    }
                    printf("Mês:\t");
                    scanf("%d",&itemPassageiro.mes);
                    if(itemPassageiro.mes<0 || itemPassageiro.mes>13){
                        while(itemPassageiro.mes<0 || itemPassageiro.mes>13){
                            printf("Data não permitida. Digite novamente:\n");
                            scanf("%d", &itemPassageiro.mes);
                        }
                    }
                      printf("Ano:\t");
                    scanf("%d",&itemPassageiro.ano);
                    if(itemPassageiro.ano<2020){
                        while(itemPassageiro.ano<2020){
                            printf("Data não permitida. Digite novamente:\n");
                            scanf("%d", &itemPassageiro.ano);
                        }
                    }
                    ;
                    printf("Destino: \n");
                    int op2=0;
                     while(op2 != 8){
                        printf("Destino: \n");
                        switch(op2){
                        case 0:
                            printf("--> Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 1:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("--> São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;

                        case 2:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("--> São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 3:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("--> Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 4:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("--> Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 5:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("--> Rio de Janeiro Santos Dumond SDU\n");
                            printf("    Sair");
                                break;
                        case 6:
                            printf("    Belo Horizonte Confins CNF\n");
                            printf("    São Paulo Campinas VCP \n");
                            printf("    São Paulo Viracopos VCP\n");
                            printf("    Paraná Curitiba CWB\n");
                            printf("    Pernanbuco Recife REC\n");
                            printf("    Rio de Janeiro Santos Dumond SDU\n");
                            printf("--> Sair");
                                break;
                        }
                    char j = _getch();
                    int k;
                    switch(j){
                            case 13: //Enter
                                if(op2 == 0){
                                  //  printf("\nDestino Belo Horizonte Confins CNF\n");
                                    itemPassageiro.destino ="Belo Horizonte Confins CN";
                                    if(itemPassageiro.destino == item.destino){
                                       itemPassageiro.codAviao = item.codAviao;
                                       printf("%d", itemPassageiro.codAviao);
                                    }
                                    system("pause");
                                    op2 = 8;

                                }else if(op2 == 1){
                                   // printf("\nDestino São Paulo Campinas VCP\n ");
                                    itemPassageiro.destino = "São_Paulo_Campinas_VCP";
                                    if(itemPassageiro.destino == item.destino){
                                       itemPassageiro.codAviao = item.codAviao;
                                       printf("%d", itemPassageiro.codAviao);
                                    }
                                    system("pause");
                                  op2 = 8;

                                }else if(op2 == 2){
                                  //  printf("\nSão Paulo Viracopos VCP\n");
                                    itemPassageiro.destino = "São_Paulo_Viracopos_VCP";
                                    if(itemPassageiro.destino == item.destino){
                                       itemPassageiro.codAviao = item.codAviao;
                                       printf("%d", itemPassageiro.codAviao);
                                    }
                                    system("pause");
                                   op2 = 8;

                                }else if(op2 == 3){
                                   // printf("\nParaná Curitiba CWB\n");
                                    itemPassageiro.destino = "Paraná_Curitiba_CWB";
                                    if(itemPassageiro.destino == item.destino){
                                       itemPassageiro.codAviao = item.codAviao;
                                       printf("%d", itemPassageiro.codAviao);
                                    }
                                    system("pause");
                                    op2 = 8;

                                }else if(op2 == 4){
                                  //  printf("\nPernanbuco Recife REC\n");
                                    itemPassageiro.destino = "Pernanbuco_Recife_REC";
                                    if(itemPassageiro.destino == item.destino){
                                       itemPassageiro.codAviao = item.codAviao;
                                       printf("%d", itemPassageiro.codAviao);
                                    }
                                    system("pause");
                                    op2 = 8;

                                }else if(op2 == 5){
                                   // printf("\nRio de Janeiro Santos Dumond SDU\n");
                                    itemPassageiro.destino = "Pernanbuco_Recife_REC";
                                    if(itemPassageiro.destino == item.destino){
                                       itemPassageiro.codAviao = item.codAviao;
                                       printf("%d", itemPassageiro.codAviao);
                                    }
                                    system("pause");
                                    op2 = 8;

                                }else if(op2 == 6){
                                    op2 = 8;
                                }

                            case 72: // Seta cima
                                op2--;
                                if (op2 < 0)
                                    op2 = 6;
                                break;

                            case 80: //Seta baixo
                                op2++;
                                if (op2 > 6)
                                    op2 = 0;
                                break;


                            }
                    op1=8;
                    system("cls");
                    }
                    scanf("%s", &itemPassageiro.destino);
                    printf("Hora Embarque h:");
                    scanf("%d", &itemPassageiro.horaEmbarque);
                    InsereListaUltimoPassageiro(&listaPassageiro, &itemPassageiro);
                    printf("Passagem reservada com sucesso!\n");
                    ImprimeListaPassageiro(&listaPassageiro);
                }
                system("pause");
            }
            else if (op == 2){ //Consultar por avião
                Aviao(&lista, item, &listaPassageiro);
                system("pause");
                }

            else if (op == 3){ //Consultar por passageiro

                Passageiro(&listaPassageiro, &itemPassageiro);
                system("pause");
            }
            else if(op == 4){// comando de saída
                op = 10;
            //printf("\n");
            //system("pause");
            }
                break;
        case 72: // Seta cima
            op--;
            if (op < 0)
                op = 4;
            break;
        case 80: //Seta baixo
            op++;
            if (op > 4)
                op = 0;
            break;
        }
    system ("cls");
    }
}

