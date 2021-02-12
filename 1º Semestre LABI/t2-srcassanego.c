//Aluno: Samuel Rech Cassanego
//Segundo Trabalho: "Ex 21. Altere para imprimir quantos são os fatores primos de cada valor. Por exemplo, ao decompor 20, dizer 2x2 1x5 e não 2 2 5." 
#include <stdio.h>
#include <stdbool.h>
/* Função criada 
para verificar se o número digitado é primo ou não, como argumentos "int n" que é o numero que será analisado se é primo ou não,
a função retorna para a main uma resultado booleano (true ou false) */
bool primo (int n)
{
  bool condicao = true;
  int i;
  for (i=2; i < n; i++) 
  {
    if ( n%i == 0) 
	{ 
      condicao = false;
      break;
    }
  }
  return condicao;
}
/*função main faz a decomposição dos números primos e imprime quantos são os fatores primos de cada valor, não possui argumentos, ela retorna os fatores primos
de cada valor. */
int main()
{
  int n;       /* numero dado */
  int fator;   /* candidato a fator do numero dado */
  int mult;    /* multiplicidade de fator */
  bool vf;     /* variável para verificar se é primo ou não*/
  scanf("%d", &n);
  vf = primo(n);
  if(vf == true)
  {
    printf("1 x %d \n", n);
  }
  else
  {  
    fator = 2;
    while (n > 1) 
    {
      mult = 0;
      while (n % fator == 0) 
      {
        mult ++;
        n = n / fator; 
      }
      if (mult != 0) 
      {
        printf(" %d x %d \n", mult, fator);	   
      } 
    fator++; 
    }
  }
  return 0;
}
