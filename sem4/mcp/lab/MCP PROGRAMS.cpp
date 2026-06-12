MCP LAB PROGRAMS

//4
// note: GORB(GO RedBull) : PD 12 13 14 15 for green orange red blue led respectively

//a: led toggling
#include "main.h"
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    while(1){
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
        HAL_Delay(1000);
        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
        HAL_Delay(1000);
    }
}

//b: 7 segment display for 0-9
//PA1-PA7 for a-g segments respectively
//anode type. on is reset and off is set
#include "main.h"
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    while(1){
        //0
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
        HAL_Delay(1000);

        //1
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7,GPIO_PIN_SET);
        HAL_Delay(1000);

        //do similarly for 2-9
    }
}

//OR using for loop
//PA0 to PA6 for a-g segments respectively

#include "main.h"
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    uint16_t segments[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //hex values for 0-9

    while(1){
        for(int i=0; i<10; i++){
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_SET); //turn off all segments
            HAL_GPIO_WritePin(GPIOA, segments[i], GPIO_PIN_RESET); //turn on required segments
            // segments[i] : PA0 to PA6 for a-g segments respectively
            // (segments[i]<<1) : shift left by 1 to align with PA1 to PA7
            HAL_Delay(1000);

            //OR: register level
            GPIOA->ODR &= ~(0x7F); //clear prev output //0x7F = 0111 1111 for PA0 to PA6
            // GPIOA->ODR &= ~(0xFE); //if using PA1 to PA7, 0xFE = 1111 1110
            GPIOA->ODR |= (segments[i]); // send segment data to PA0 to PA6
            // GPIOA->ODR |= (segments[i]<<1); // if using PA1 to PA7
            HAL_Delay(1000);
        }
    }
}

//c: push button to toggle 
//pa0 for button, if on: toggle orange and blue led else toggle green and red led
#include "main.h"
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    while(1){
        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET){ //button pressed
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_SET); //turn on leds
            HAL_Delay(500);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_RESET); //turn off leds
            HAL_Delay(500);
        } else {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14, GPIO_PIN_SET); //turn on leds
            HAL_Delay(500);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14, GPIO_PIN_RESET); //turn off leds
            HAL_Delay(500);
        }
    }
}

//5 stepper motor
//a: if button pressed, rotate anticlockwise else rotate clockwise
//PA0 for button, PD12 TO 15 for stepper motor control pins

#include "main.h"

void Step_Sequence1(void);
void Step_Sequence2(void);
void Step_Sequence3(void);
void Step_Sequence4(void);

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    while(1){
        if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET){ //button pressed
            Step_Sequence1();
            HAL_Delay(50);
            Step_Sequence2();
            HAL_Delay(50);
            Step_Sequence3();
            HAL_Delay(50);
            Step_Sequence4();
            HAL_Delay(50);
        }
        else{
            Step_Sequence4();
            HAL_Delay(50);
            Step_Sequence3();
            HAL_Delay(50);
            Step_Sequence2();
            HAL_Delay(50);
            Step_Sequence1();
            HAL_Delay(50);
        }
    }
}
void Step_Sequence1(){ //Coil A: PD12
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
}
void Step_Sequence2(){ //Coil D: PD15
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);
}
void Step_Sequence3(){ //Coil B: PD13
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
}
void Step_Sequence4(){ //Coil C: PD14
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15, GPIO_PIN_RESET);
}

//b rotate motor 180 in clockwise direction, step angle is 1.8 degree. 4 step rotation.

//for 180, 180/(1.8*4) = 25 steps

//code same as a except while

int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    int i=25;
    while(i>0){
        Step_Sequence1();
        HAL_Delay(50);
        Step_Sequence2();
        HAL_Delay(50);
        Step_Sequence3();
        HAL_Delay(50);
        Step_Sequence4();
        HAL_Delay(50);
        i--;
    }
}

//6
//a: adc

#include "main.h"

ADC_HandleTypeDef hadc1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

uint32_t analogValue;
int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();

    while(1){
        HAL_ADC_Start(&hadc1);
        if(HAL_ADC_PollForCoversion(&hadc1,1)==HAL_OK)
            analogValue = HAL_ADC_GetValue(&hadc1);
        else
            analogValue = 0;
    }
}

// b: adc with pwm wave on pd9

#include "main.h"

ADC_HandleTypeDef hadc1;
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();

    while(1){
        HAL_ADC_Start(&hadc1);
        if(HAL_ADC_PollForCoversion(&hadc1,1)==HAL_OK)
            analogValue = HAL_ADC_GetValue(&hadc1);
        else
            analogValue = 0;

        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
        for(i=0;i<analogValue;i++);
        for(i=0;i<analogValue;i++);

        analogValue = (~analogValue) & 0x0FFF;

        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
        for(i=0;i<analogValue;i++);
        for(i=0;i<analogValue;i++);
    }
}

//7 dac

#include "main.h"

ADC_HandleTypeDef hadc1;
DAC_HandleTypeDef hdac;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_DAC_Init(void);

uint16_t analogValue;
int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_DAC_Init();

    while(1){
        HAL_ADC_Start(&hadc1);
        if(HAL_ADC_PollForCoversion(&hadc1,1)==HAL_OK)
            analogValue = HAL_ADC_GetValue(&hadc1);
        else
            analogValue = 0;

        HAL_DAC_SetValue(&hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,analogValue);
        HAL_DAC_Start(&hdac,DAC_CHANNEL_1);
    }
}

//EXTRA QUESTIONS

//1. counter from 0 -99 using 2 seven segments (asume cathode type)
//PA0-PA6 for segments a-g of first display
//PB0-PB6 for segments a-g of second display

#include "main.h"
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    uint16_t segments[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; //hex values for 0-9

    while(1){
        for(int i=0;i<10;i++){
            GPIOA->ODR &= ~(0x7F);
            GPIOA->ODR |= segments[i];
            for(int j=0;j<10;j++){
                GPIOB->ODR &= ~(0x7F);
                GPIOB->ODR |= segments[j];
                HAL_Delay(1000);
            }
        }

    }
}