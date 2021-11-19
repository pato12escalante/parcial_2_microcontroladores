/*
 * File:   main.c
 * Author: Patricio Escalante
 *
 * Created on 12 de noviembre de 2021, 07:31 PM
 */


#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdbool.h>
#include "configbits.h"
#include "duckylib.h"

#define _XTAL_FREQ 4000000

#define modo1Alarma 0
#define modo2LedsSec1 1
#define modo2LedsSec2 2
#define modo2LedsSec3 3


#define boton_modo PORTAbits.RA1
#define boton_modo_led PORTAbits.RA2

char flag=0, estado=0;
int on_off=0, flag2=0;



void modo1(){
    int var_1, num;

    LCD_Set_Cursor(0,0); 
    LCD_putrs("Modo 1: Alarma");
    LCD_Set_Cursor(1,0); 
    LCD_putrs("                    ");
    LCD_Set_Cursor(2,0); 
    LCD_putrs("                    ");
    LCD_Set_Cursor(3,0); 
    LCD_putrs("                    ");
        
    var_1=analogRead(_AN0);
    
    
    num=map(var_1,0,1023,1,8);

    if(num==1){
        LATB=0b10000000;
    }
    if(num==2){
        LATB=0b11000000;
    }
    if(num==3){
        LATB=0b11100000;
    }
    if(num==4){
        LATB=0b11110000;
    }
    if(num==5){
        flag2=1;
        LATB=0b11111000;
    }
    if(num==6){
        LATB=0b11111100;
        if(flag2==1){
            pwmON(1800,50);
            __delay_ms(100);
            pwmOFF();
            flag2=0;
            
        }
        
    }
    if(num==7){
        flag2=1;
        LATB=0b11111110;
    }
    if(num>7){
        LATB=0b11111111;
        pwmON(2000,50);
        __delay_ms(1000);
        pwmOFF();
        __delay_ms(1000);
    }
    
}

void modo2sec1(){
    
    LCD_Set_Cursor(0,0); 
    LCD_putrs("Modo 2: Leds      ");
    LCD_Set_Cursor(1,0); 
    LCD_putrs("-Secuencia 1");
    LCD_Set_Cursor(2,0); 
    LCD_putrs(" Secuencia 2"); 
    LCD_Set_Cursor(3,0); 
    LCD_putrs(" Secuencia 3");
    
    LATB=255;
    __delay_ms(200);
    LATB=0;
    __delay_ms(800);


    
}

void modo2sec2(){
    LCD_Set_Cursor(0,0); 
    LCD_putrs("Modo 2: Leds      ");
    LCD_Set_Cursor(1,0); 
    LCD_putrs(" Secuencia 1");
    LCD_Set_Cursor(2,0); 
    LCD_putrs("-Secuencia 2"); 
    LCD_Set_Cursor(3,0); 
    LCD_putrs(" Secuencia 3");
    

    

    LATB=0b10000000;
    __delay_ms(50);
    LATB=0b11000000;
    __delay_ms(50);
    LATB=0b11100000;
    __delay_ms(50);
    LATB=0b01110000;
    __delay_ms(50);
    LATB=0b00111000;
    __delay_ms(50);
    LATB=0b00011100;
    __delay_ms(50);
    LATB=0b00001110;
    __delay_ms(50);
    LATB=0b00000111;
    __delay_ms(50);
    LATB=0b00000011;
    __delay_ms(50);
    LATB=0b00000001;
    __delay_ms(50);
}

void modo2sec3(){
    LCD_Set_Cursor(0,0); 
    LCD_putrs("Modo 2: Leds      ");
    LCD_Set_Cursor(1,0); 
    LCD_putrs(" Secuencia 1");
    LCD_Set_Cursor(2,0); 
    LCD_putrs(" Secuencia 2"); 
    LCD_Set_Cursor(3,0); 
    LCD_putrs("-Secuencia 3");
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_us(500);
        LATB=0;
        __delay_us(500);
        __delay_ms(9);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(1);
        LATB=0;
        __delay_ms(9);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(1);
        __delay_us(500);
        LATB=0;
        __delay_ms(8);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(2);
        LATB=0;
        __delay_ms(8);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(2);
        __delay_us(500);
        LATB=0;
        __delay_ms(7);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(3);
        LATB=0;
        __delay_ms(7);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(3);
        __delay_us(500);
        LATB=0;
        __delay_ms(6);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(4);
        LATB=0;
        __delay_ms(6);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(4);
        __delay_us(500);
        LATB=0;
        __delay_ms(5);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(5);
        LATB=0;
        __delay_ms(5);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(5);
        __delay_us(500);
        LATB=0;
        __delay_ms(4);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(6);
        LATB=0;
        __delay_ms(4);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(6);
        __delay_us(500);
        LATB=0;
        __delay_ms(3);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(7);
        LATB=0;
        __delay_ms(3);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(7);
        __delay_us(500);
        LATB=0;
        __delay_ms(2);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(8);
        LATB=0;
        __delay_ms(2);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(8);
        __delay_us(500);
        LATB=0;
        __delay_ms(1);
        __delay_us(500);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(9);
        LATB=0;
        __delay_ms(1);
    }
    
    for(char k=0; k<8; k++){
        LATB=255;
        __delay_ms(9);
        __delay_us(500);
        LATB=0;
        __delay_us(500);
    }
}


void main() {
    PWMinit();

    ADCinit(1);

    
    TRISAbits.RA1=1;
    TRISAbits.RA2=1;
    TRISB=0;
    
    LCD lcd = { &PORTD, 5, 4, 0, 1, 2, 3 }; // PORT, RS, EN, D4, D5, D6, D7
    LCD_Init(lcd);
    LCD_Clear(); //LIMPIAR LCD
    
    
    char input_mode=0, input_led=0;
    
    while(1){

        input_mode=boton_modo;
        input_led=boton_modo_led;
        
        if(input_mode==0 && input_led==0){
            flag=0;
        }
        
        input_mode=boton_modo;
        if(input_mode==1 && flag==0 && estado==modo1Alarma){
            flag=1;
            estado=modo2LedsSec1;
          
        }
        
        input_mode=boton_modo;
        if(input_mode==1 && flag==0 && estado==modo2LedsSec1){
            flag=1;
            estado=modo1Alarma;
          
        }
        
        input_mode=boton_modo;
        if(input_mode==1 && flag==0 && estado==modo2LedsSec2){
            flag=1;
            estado=modo1Alarma;
          
        }
        
        input_mode=boton_modo;
        if(input_mode==1 && flag==0 && estado==modo2LedsSec3){
            flag=1;
            estado=modo1Alarma;
          
        }

        input_led=boton_modo_led;
        if(input_led==1 && flag==0 && estado==modo2LedsSec1){
            flag=1;
            estado=modo2LedsSec2;
          
        }
        
        input_led=boton_modo_led;
        if(input_led==1 && flag==0 && estado==modo2LedsSec2){
            flag=1;
            estado=modo2LedsSec3;
          
        }
        
        input_led=boton_modo_led;
        if(input_led==1 && flag==0 && estado==modo2LedsSec3){
            flag=1;
            estado=modo2LedsSec1;
          
        }
        
        

        if(estado==modo2LedsSec1){
            modo2sec1();
        }
        
        if(estado==modo2LedsSec2){
            modo2sec2();
        }
        
        if(estado==modo2LedsSec3){
            modo2sec3();
        }
        
        if(estado==modo1Alarma){
            modo1();
        }
        
      
        
    
        
        
 
    }
    
}
