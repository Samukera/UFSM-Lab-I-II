//Aluno: Samuel Rech Cassanego
//Quarto trabalho: Jogo da Velha torto
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//VERIFICA SE ALGUEM GANHOU O JOGO, DEPOIS DISSO ENVIA PARA A MAIN A RESPOSTA.
bool verificaVitoria (char jogo[3][3], char simbol)
{
int i;
for(i=0; i<2;i++){
  if(jogo[i][0] == simbol && jogo[i+1][2] == simbol)
  {
    if(jogo[i][1] == simbol || jogo[i+1][1] == simbol)
	{
      return true;
      break;
    }
  }
  if(jogo[0][i] == simbol && jogo[2][i+1] == simbol)
  {
    if(jogo[1][i] == simbol || jogo[1][i+1]== simbol)
	{
      return true;
      break;
    }
  }
}
for(i=2; i>0;i--){
  if(jogo[i][0] == simbol && jogo[i-1][2] == simbol)
  {
    if(jogo[i][1] == simbol || jogo[i-1][1] == simbol)
	{
      return true;
      break;
    }
  }
  if(jogo[2][i-1] == simbol && jogo[0][i] == simbol)
  {
    if(jogo[1][i] == simbol || jogo[1][i-1]== simbol)
	{
      return true;
      break;
    }
  }
}
return false;
}
//FAZ A TROCA DOS JOGADORES, DETERMINA A VEZ DE CADA UM
int trocaJogador(int aVez)
{
  if(aVez == 1)
  {
    aVez = 2;
  }
  else
  {
	aVez = 1;
  }
  return aVez;
}
//IMPRIME O JOGO DA VELHA, E SEU ESTADO CONFORME SAO FEITAS AS JOGADAS
void imprime(char matriz[3][3])
{
  int i,j;
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
	{
	  printf("%c",matriz[i][j]);
	}
	printf("\n");
  }
}
//CONVERTE A JOGADA INFORMADA PELO JOGADOR
bool converte_jogada(char jogada[], int *lin, int *col)
{
  int i, j;
  bool certifica = false, certifica2 = false;
  for(i = 0; jogada[i] != '\0'; i++)
  {
    if(jogada[i] >= 'A' && jogada[i] <= 'C' || jogada[i] >= 'a' && jogada[i] <= 'c')
	{
	  certifica2 = true;
      switch (jogada[i])
	  {
        case ('A'): *lin=0;
        break;
        case ('B'): *lin=1;
        break;
        case ('C'): *lin=2;
        break;
        case ('a'): *lin = 0;
        break;
        case ('b'): *lin = 1;
        break;
        case ('c'): *lin = 2;
        break;
        default: return false;
      }
    }
    for(j = 0; jogada[j] != '\0'; j++)
    {
      if(jogada[j]>='1' && jogada[j]<='3' && certifica2 == true)
	  {
        certifica = true;
        switch(jogada[j])
		{
          case('1'): *col=0;
          break;
          case('2'): *col=1;
          break;
          case('3'): *col=2;
          break;
          default: return false;
        }
      }
    }
  }
  return certifica;
}
//CHAMA AS FUNÇOES AUXILIARES, EXECUTA O JOGO, AVISA EMPATE OU O VENCEDOR
int main()
{
  int i, j,linha,coluna,*lin = &linha, *col = &coluna, aVez = 1, maxJogadas = 0;
  bool acabou = false;
  char jogador1[100], jogador2[100],jogo[3][3] = {"---","---","---"};
  char simbolo, jogada[100];
  printf("Qual o nome do jogador 1: ");
  scanf(" %[^\n]s",jogador1);
  printf("Qual o nome do jogador 2: ");
  scanf(" %[^\n]s",jogador2);
  printf("%s\n", jogador1);
  printf("%s\n", jogador2);
  printf("INICIO DO JOGO:\n");
  imprime(jogo);
  while(acabou != true)
  {
    printf("%s = X, %s = O\n", jogador1, jogador2);
	if(aVez == 1)
	{
	  printf("%s informe sua jogada: ",jogador1);
	  simbolo = 'X';
	}
	else
	{
	  printf("%s informe sua jogada: ",jogador2);
	  simbolo = 'O';
	}
	scanf(" %[^\n]s",jogada);
	if(converte_jogada(jogada,&linha,&coluna) == true)
	{
	  if(jogo[linha][coluna] == '-')
	  {
	    jogo[linha][coluna] = simbolo;
	    imprime(jogo);
	    aVez = trocaJogador(aVez);
	    printf("\njogada aceita!\n");
	    maxJogadas++;
	  }
	  else
	  {
	    printf("\nPosicao ja ocupada, jogue novamente!\n");
	  }
    }
    else
	{
	  printf("\njogada invalida, jogue novamente!\n");
	}
    if(verificaVitoria(jogo,simbolo))
	{
	  if(simbolo == 'X')
	  {
	    printf("Vencedor: %s", jogador1);
	    acabou = true;
	  }
	  else
	  {
	    printf("Vencedor: %s", jogador2);
	    acabou = true;
	  }
	}
	if(maxJogadas == 9)
	{
	  printf("\nEmpatou!");
	  acabou = true;
	}
  }
}
