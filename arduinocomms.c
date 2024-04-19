#include "arduinocomms.h"
#include "MKL25Z4.h"

void digitalWrite(int PIN, int ESTADO){
    PTE -> PSOR|= (ESTADO << PIN);
}

char digitalRead(int PIN){
    if(PTE -> PDIR&(1u<<PIN) == 0){
        return 'i';
    }else{
        return 'a';
    }
}