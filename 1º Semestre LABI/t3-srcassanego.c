//Aluno: Samuel Rech Cassanego
//Terceiro Trabalho: Soma de vetores de caracteres com digitos decimais
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define TAMANHO 101

//preenche de zeros o menor vetor, para igualar as casas decimais.
void preencher (char vet[], int vetMenorTam, int diferencaMaiorMenor)
{ 
  int i,aux;
  for(i = 0; i<diferencaMaiorMenor; i++){
    vet[vetMenorTam]='0';
    vetMenorTam++;  
    if(vet[i]>=vet[vetMenorTam-1])
    {
      aux = vet[i];
      vet[i] = vet[vetMenorTam-1];
      vet[vetMenorTam-1] = vet[i+1];
      vet[i+1] = aux;
	}
  }
}
//Realiza a soma dos vetores e guarda o resultado no vetSoma e também imprime.
char soma(char vet1[], char vet2[], char vetSoma[],int vetTam)
{
  int i;
  for(i = 0; i < vetTam; i++)
  {
    vetSoma[i] = (vet1[i] + vet2[i]) - '0';
  }  
  if(strlen(vetSoma) > 100)
  {
  	printf("capacidade de cálculo excedida\\n");
  }
  else
  {
    for(i = 0; i < vetTam; i++)
    {
      printf("%c",vetSoma[i]);
    }
    printf("\\n");	
  }
}
//Faz a leitura da sequencia de caracter e coloca os digitos decimais nos vetores.
int main()
{
  char vetSeq[TAMANHO], vet1[TAMANHO],vet2[TAMANHO],vetSoma[TAMANHO];
  int i, contador = 0, popula = 1,diferencavets = 0;
  fgets(vetSeq,TAMANHO,stdin);
  for(i = 0; i < strlen(vetSeq); i++)
  {
    if(vetSeq[i] >= 48 && vetSeq[i] <= 57)
	{
	  do
	  {
	    if(popula == 1)
		{
		  vet1[contador] = vetSeq[i];
		  contador++;	
		}
		else if (popula == 2)
		{
		  vet2[contador] = vetSeq[i];
		  contador++;	
		}
		i++;
	  }while(vetSeq[i] >= 48 && vetSeq[i] <= 57);
	  popula = 2;
	  contador = 0;	
	}
  }
  if(strlen(vet1) > strlen(vet2))
  {
    diferencavets = strlen(vet1)-strlen(vet2);
    preencher(vet2,strlen(vet2),diferencavets);
    soma(vet1,vet2,vetSoma,strlen(vet1));
  }
  else if(strlen(vet2) > strlen(vet1))
  {
  	diferencavets = strlen(vet2)-strlen(vet1);
    preencher(vet1,strlen(vet1),diferencavets);
    soma(vet1,vet2,vetSoma,strlen(vet2));
  }
  else
  {
  	soma(vet1,vet2,vetSoma,strlen(vet1));
  }
}
