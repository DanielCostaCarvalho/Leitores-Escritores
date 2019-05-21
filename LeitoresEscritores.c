#include <stdlib.h>
#include <stdio.h>

typedef struct fila{
  int conteudo[3];
  int primeiro;
  int ultimo;
  int nItens;
}Fila;

void exibir(Fila *f){
  int pode = 1;
  int e = f->primeiro;

  printf("Processos na fila:\n");
  for (int i = 0; i < f->nItens; i++) {
    if(e>2){
      e = 0;
    }
    printf("%d\n", f->conteudo[e++]);
  }
}

void incluir(Fila *f, int processo){
  int pode = 1;
  int e = f->primeiro;
  if((f->nItens <=2)){
    for (int i = 0; i < f->nItens; i++) {
      if(e>2){
        e = 0;
      }
      if(f->conteudo[e++] == processo){
      pode = 0;
      printf("Processo ja esta na fila\n");
      }
    }

    if(pode){
      f->conteudo[f->ultimo] = processo;
      f->nItens++;
      if(f->ultimo == 2){
        f->ultimo = 0;
      }
      else{
        f->ultimo++;
      }
    }
  }
}

int retirar(Fila *f){
  int posicao = 0;
  if(!f->nItens){
    return -1;
  }
  else{
    if(f->primeiro == 2){
      posicao = 2;
      f->primeiro = 0;
    }
    else{
      posicao = f->primeiro++;
    }
    f->nItens--;
    return f->conteudo[posicao];
  }
}

int main() {
  int opcao;
  int escritor = -1;
  Fila processos;
  int tempo = 0;
  processos.primeiro = 0;
  processos.ultimo = 0;
  processos.nItens = 0;

  while( 1 ){

		printf("\n1 - Solicitacao de leitura do processo 1\n2 - Solicitacao de leitura do processo 2\n3 - Solicitacao de leitura do processo 3\n4 - Passar turno\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1:
        if(escritor == 1){
            printf("Processo ja em escrita\n");
        }
        else{
				      incluir(&processos, 1);
        }
				break;

			case 2:
        if(escritor == 2){
            printf("Processo ja em escrita\n");
        }
        else{
              incluir(&processos, 2);
        }
				break;

			case 3:
        if(escritor == 3){
            printf("Processo ja em escrita\n");
        }
        else{
              incluir(&processos, 3);
        }
				break;

      case 4:
        printf("Passagem de turno...\n");
				break;

			default:
				printf("\nOpcao Invalida\n\n");
      }
      exibir(&processos);
      if(escritor == -1){
        escritor = retirar(&processos);
        tempo = 5;
        printf("Sem processos em escrita\n");
      }
      else{
        printf("Processo %d em escrita\n", escritor);
        if(tempo <=0){
          escritor = -1;
        }
        tempo--;
      }
  }

  return 0;
}
