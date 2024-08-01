//
// Created by MinseokK on 24. 7. 31.
//
#include <stdio.h>

// 인터페이스
typedef void (*radio_source_function)();

// 전략
void AM(){
    printf("AM 모드 입니다.\n");
}

void FM(){
    printf("FM 모드 입니다.\n");
}

void Bluetooth(){
    printf("Bluetooth 모드 입니다.\n");
}

// Context
void SwitchAudioSource(radio_source_function source_strategy){
    source_strategy();
}

// main
int main(){
    radio_source_function source_strategy = AM;

    SwitchAudioSource(source_strategy);

    return 0;
}