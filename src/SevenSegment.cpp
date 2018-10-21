#include "SevenSegment.h"

SevenSegment::SevenSegment(PinName ser, PinName clk) {
        reg = new ShiftReg(ser, clk);
        reg->off();
    }

SevenSegment::~SevenSegment(){ delete reg; }

void SevenSegment::displayOneNum(const int num){
    for(int i = 8; i >= 0; i--){
        if(segment[num][i] == 1){
            reg->on();
            printf("%d -> on \n\r", i);
        }
        else {
            reg->off();
            printf("%d -> off \n\r", i);
        }
    }
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
    reg->off();
    displayOneNum(digi2);
    reg->off();
    displayOneNum(digi3);
    reg->off();
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
    reg->off();
    displayOneNum(digi2);
    return true;
}

bool SevenSegment::clear() {
    for (int i = 0; i < 33; i++){
       reg->off();
    }
    return true;
}
void SevenSegment::on(){
    reg->on();
}
void SevenSegment::off(){
    reg->off();
}