//Aluno: Samuel Rech Cassanego
//Segundo Trabalho: "Ex 21. Altere para imprimir quantos s�o os fatores primos de cada valor. Por exemplo, ao decompor 20, dizer 2x2 1x5 e n�o 2 2 5." 
#include <stdio.h>
#include <stdbool.h>
/* Fun��o criada 
para verificar se o n�mero digitado � primo ou n�o, como argumentos "int n" que � o numero que ser� analisado se � primo ou n�o,
a fun��o retorna para a main uma resultado booleano (true ou false) */
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
/*fun��o main faz a decomposi��o dos n�meros primos e imprime quantos s�o os fatores primos de cada valor, n�o possui argumentos, ela retorna os fatores primos
de cada valor. */
int main()
{
  int n;       /* numero dado */
  int fator;   /* candidato a fator do numero dado */
  int mult;    /* multiplicidade de fator */
  bool vf;     /* vari�vel para verificar se � primo ou n�o*/
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
