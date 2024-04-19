#include "arduinocomms.h"
#include "MKL25Z4.h"

int main(){
    SIM -> SCGC5|= SIM_SCGC5_PORTE_MASK;
    PORTE ->PCR[0] |= PORT_PCR_MUX(0);
    PORTE ->PCR[1] |= PORT_PCR_MUX(0);
    for (int i = 0; i < 4; i++){
        PORTE ->PCR[i] |= PORT_PCR_MUX(1);
    }
    
    while (1){
        char btn1= digitalRead(0);
        char btn2= digitalRead(1);

        if (btn1 == 'i' && btn2 == 'i'){
            digitalWrite(2,1);
            digitalWrite(3,0);
            digitalWrite(4,0);
            digitalWrite(5,0);
        }else if (btn1 == 'i' && btn2 == 'a'){
            digitalWrite(2,0);
            digitalWrite(3,1);
            digitalWrite(4,0);
            digitalWrite(5,0);
        }else if (btn1 == 'a' && btn2 == 'i'){
            digitalWrite(2,0);
            digitalWrite(3,0);
            digitalWrite(4,1);
            digitalWrite(5,0);
        }else if (btn1 == 'a' && btn2 == 'a'){
            digitalWrite(2,0);
            digitalWrite(3,0);
            digitalWrite(4,0);
            digitalWrite(5,1);
        }
    }
}
