//Aluno: Samuel Rech Cassanego
//Primeiro trabalho - Cálculo IRRF
#include <stdio.h>
int main()
{
  double salario;
  float aliquota = 0.0, deduParcela = 0.0, imposto;
  printf("Digite seu salário: ");
  scanf("%lf", &salario);

  if(salario <= 1903.98){
    printf("%.2f\n", imposto);
  }
  else if((salario >= 1903.99) && (salario <= 2826.65)){
    aliquota = 0.075;
    deduParcela = 142.80;
    imposto = (salario*aliquota)-deduParcela;
    printf("%.2f\n", imposto);
  }else if((salario >= 2826.66) && (salario <= 3751.05)){
    aliquota = 0.15;
    deduParcela = 354.80;
    imposto = (salario*aliquota)-deduParcela;
    printf("%.2f\n", imposto);
  }else if((salario >= 3751.06) && (salario <= 4664.68)){
    aliquota = 0.225;
    deduParcela = 636.13;
    imposto = (salario*aliquota)-deduParcela;
    printf("%.2f\n", imposto);
  }else{
    aliquota = 0.275;
    deduParcela = 869.36;
    imposto = (salario*aliquota)-deduParcela;
    printf("%.2f\n", imposto);
  }

}
