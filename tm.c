#include "tm.h"

uint32_t tempo_medio(uint32_t acesso_l1, float t_miss_l1, uint32_t acesso_l2, float t_miss_l2, uint32_t acesso_l3, float t_miss_l3, uint32_t acesso_mem){
    uint32_t tMedio = 0;
    float aux = 0;

    //Conferir se os t_miss são maiores que 100 ou negativos
    if(t_miss_l1 < 0 || t_miss_l1 > 100)
      return 0;
    if(t_miss_l2 < 0 || t_miss_l2 > 100)
      return 0;
    if(t_miss_l3 < 0 || t_miss_l3 > 100)
        return 0;

    if(acesso_l1){  // primeiro nível é maior que 0
      if(acesso_l2){ // segundo nível é maior que 0
        if(acesso_l3){  // todos os níveis são usados
          aux = acesso_l1 + ((t_miss_l1/100) * (acesso_l2 + ((t_miss_l2/100) * (acesso_l3 + ((t_miss_l3/100) * acesso_mem)))));
        }//if
        else{ // primeiro e segundo nivel são usados
          aux = acesso_l1 + ((t_miss_l1/100) * (acesso_l2 + ((t_miss_l2/100) * acesso_mem)));
        }//else
      }//if
      else{ // somente primeior nível é usado
        aux = acesso_l1 + ((t_miss_l1/100) * acesso_mem);
      }//else

    }//if
    else{   // Somente memória principal é usada
      return acesso_mem;
    }//else

    tMedio = (uint32_t) aux;

    if((float) aux - tMedio != 0)
      tMedio++;

    return tMedio;
}//tempo_medio
