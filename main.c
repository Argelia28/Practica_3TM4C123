#include "lib/include.h"

char *read_name(char delimitador, int *final){
    char x;
    char arreglo[50];
    int contador=0;
    x=readChar();
    while (x != delimitador){
        arreglo[contador]=x;
        x=readChar();
        contador ++;
    }
    *final=strlen(arreglo); //longitud
    return &arreglo[0];
}

char *invertir(char *nombre, int longitud){
    char nombre_m[20];
    int contador=0;
    int posicion=0;
    for (int i=longitud; i>0; i--){
        nombre_m[contador]=*(nombre + (i-1));
        nombre_m[contador + 1] = posicion + '0';
        posicion ++;
        contador = contador + 2;
    }
    nombre_m[contador-1]='\n';
    return &nombre_m[0];
}

int main(void)
{
    uint16_t valor = 0;
    char c='5';
    //char b='a';
    Configurar_PLL(_10MHZ);  //Confiuracion de velocidad de reloj
    Configurar_UART4();// FCLK 10MHZ Baudrate 4800

    //Experimento 1
    //  Configurar_UART1(); //Jorge,Alberto,Navarro,Saul,Fabela -fclk 25MHZ Baud-rate 57600
    //  Configurar_UART7(); //Angel,Fernanda,Sonia,Aleidis,Monse -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART4(); //Argelia,Roxana,Yesica,Vanesa,Christian,Abiu -fclk 10MHZ Baud-rate 4800
    //  Configurar_UART2(); //Brizet,Monse,Luis,Majo,Alonso -fclk 40MHZ Baud-rate 115200
    //  Configurar_UART3(); //Jesus,Yesica,Carlos,Dulce,Rodolfo,Leonardo -fclk 80MHZ Baud-rate 19200
    //  Configurar_UART2(); //Andrea,Avila,Pamela,Paulina -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART5(); //Hector,Cecilia,Carolina,Jozzafat -fclk 40MHZ Baud-rate 28800
    Configurar_GPIO();
    
    int longitud_nombre;
    longitud_nombre = 0;
    char *inicio= read_name('.',&longitud_nombre);
    char *nombre_m=invertir(inicio,longitud_nombre);
    printString(&nombre_m[0]);

    while(1)
    {
         c = readChar();
         switch(c)
         {
             case 'r':
                 //GPIODATA port F 662
                 printChar('a');
                 GPIOF->DATA = (1<<1);
                 break;
             case 'b':
                 //GPIODATA port F 662
                 printChar('b');
                 GPIOF->DATA = (1<<2);
                 break;
             case 'g':
                 //GPIODATA port F 662
                 printChar('c');
                 GPIOF->DATA = (1<<3);
                 break;
             case 'y':
                 //GPIODATA port F 662
                 printChar('d');
                 GPIOF->DATA = (1<<3) | (1<<2);
                 break;
             default:
                 printChar((char)valor);
                 GPIOF->DATA = (0<<1) | (0<<2) | (0<<3);
                 break;
         }
    }
}
