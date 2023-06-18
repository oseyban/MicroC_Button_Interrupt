#define ChipSelect GPIO_ODR.B3

void ButtonKesme() iv IVT_INT_EXTIO ics ICS_AUTO{
EXTI_PR=1;
GPIO_ODR=0;
sayi=RNG_DR; //RNG_DR registerýný  sayi deðiþkenine yükle-rastgele sayý(long)
sayi=sayi%6+1;
}

void main() {
    Kurulum();
    while(1){
       if(sayi==1) GPIO_ODR.B1=1;
       if(sayi==2) GPIO_ODR.B2=1;
       if(sayi==3) GPIO_ODR.B3=1;
       if(sayi==4) GPIO_ODR.B4=1;
       if(sayi==5) GPIO_ODR.B5=1;
       if(sayi==6) GPIO_ODR.B6=1;
    }
}

void Kurulum(){
GPIO_Digital_Input(&GPIOA_IDR, _GPIO_PINMASK_0);
GPIO_Digital_Input(&GPIOD_IDR, _GPIO_PINMASK_ALL);
GPIO_Digital_Input(&GPIO_IDR, _GPIO_PINMASK_3);


}
RCC_AHB2ENR|=0x40;
RNG_CR_0x4;

SYSCFG_EXTICR1=0;
EXTI_PR=1;
EXTI_FTSR














