#include "SevenSegment.h"

SevenSegment::SevenSegment(PinName ser, PinName srclk, PinName rclk) : DSERIAL(ser), RCLK(rclk), SRCLK(srclk) { }


SevenSegment::~SevenSegment(){}

void SevenSegment::displayOneNum(const int num){
    writeArray(segment[num]);
    return;
}

bool SevenSegment::displayFourNums(const int num){
    int digi1 = 0;
    int digi2 = 0;
    int digi3 = 0;
    int digi4 = 0;
    digi4 = num/1000;
    digi3 = num/100;
    digi2 = num/10;
    digi1 = num - (digi1*1000 + digi2*100 + digi3*10);
    displayOneNum(digi1);
    writeBit(0);
    displayOneNum(digi2);
    writeBit(0);
    displayOneNum(digi3);
    writeBit(0);
    displayOneNum(digi4);
    return true;
}

bool SevenSegment::displayTwoNums(const int num){
    int digi1 = 0;
    int digi2 = 0;
    if((num/10) > 1){
        digi2 = num/10;
    }
    digi1 = num - (digi2*10);
    displayOneNum(digi1);
    writeBit(0);
    displayOneNum(digi2);
    return true;
}

bool SevenSegment::clear() {
    for (int i = 0; i < 33; i++){
       writeBit(0);
    }
    return true;
}
void SevenSegment::on(){
    writeBit(1);
}
void SevenSegment::off(){
    writeBit(0);
}


//Pulses the register
void SevenSegment::updateRegister(){
    SRCLK = 1;
    wait_us(.01);
    SRCLK = 0;    
}
//Updates the output register
void SevenSegment::updateOutput(){
    RCLK = 1;
    wait_us(.01);
    RCLK = 0;    
}
//Writes a bit to the shift register
void SevenSegment::writeBit(unsigned char bit){
    DSERIAL = bit & 0x01;
    updateRegister();
    updateOutput();
    } 

void SevenSegment::writeArray(char arr[8*REGISTER_CNT]){
    for(int i = (8*REGISTER_CNT)-1; i >= 0; i--) {
        writeBit(arr[i]);
    }       
    updateRegister();
}