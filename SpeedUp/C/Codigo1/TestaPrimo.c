//
//  TestaPrimo.c
//  TestaPrimo
//
//  Created by Ricardo de Carvalho Destro on 12/08/20.
//  Copyright © 2020 Ricardo de Carvalho Destro. All rights reserved.
//

#include "TestaPrimo.h"
#include <math.h>
#include <time.h>

int TestaPrimo(int n) {
    int EhPrimo = 1,
        d=2;
    if (n <= 1)
    EhPrimo = 0;

    while (EhPrimo == 1 && d <= n /2) {
    if (n % d  == 0)
        EhPrimo = 0;
    d = d + 1;
    }
    return EhPrimo;
}

int main(){
  int n = 7, i;
  float vetor[30], soma, media, dp, time;

  for(i=0 ; i<30 ; i++){
    //  Verifica o tempo de execução.
    clock_t tempo;
    tempo = clock();
    printf("%i\n", TestaPrimo(n));
    //TestaPrimo(n);
    time = ((clock() - tempo)*1000 / (double)CLOCKS_PER_SEC);

    printf("%f\n", time);
    vetor[i] = time;
    media += vetor[i];   
  }
  media = media/30;
  printf("Media: %f\n", media);

//  Calculo para o Desvio Padrão
  for(i=0 ; i<30 ; i++){
    soma+= pow(vetor[i] - media,2);
  }
  dp = sqrt(soma/30);
  printf("Desvio: %f\n", dp);
}
