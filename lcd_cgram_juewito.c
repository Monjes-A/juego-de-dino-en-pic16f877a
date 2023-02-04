// Proyecto de Lcd , Tercera  practica. realizado por Mi . Jesus Monsalve

#include <16F877A.h>
#fuses XT, NOWDT, NOPUT, NOBROWNOUT, NOLVP, NOCPD, NOWRT, NOPROTECT, NODEBUG
#use delay(clock = 4000000)

#include <lcd2.c>
#include <buzzer_tone.c>

#define LED1 PIN_B2
#define button PIN_B0
#define buzzer PIN_B1

int16 ctf = 1000;

int8 random;

lcd_init();

//---------SE GENERAN LAS FIGURAS CON CGRAM---------

// dinosaurio sin pata izquierda
void dino1(int8 x, int8 y)
{
   int dinosaurio1[8] = {7, 23, 22, 31, 14, 2, 3, 0}; // creamos el c gram
   lcd_set_cgram_char(1, dinosaurio1);                // guardamos el c gram
   lcd_gotoxy(x, y);                                  // ubicamos cursor
   lcd_putc(1);                                       // dibujamos segundo dinosaurio1
}

// dinosaurio sin pata derecha
void dino2(int8 x, int8 y)
{
   int dinosaurio2[8] = {7, 23, 22, 31, 14, 8, 12, 0}; // creamos el c gram
   lcd_set_cgram_char(2, dinosaurio2);                 // guardamos el c gram
   lcd_gotoxy(x, y);                                   // ubicamos cursor
   lcd_putc(2);                                        // dibujamos
}

// cactus grande
void cact1(int8 x, int8 y)
{
   int cactus1[8] = {6, 22, 22, 30, 30, 6, 6, 31}; // creamos el c gram
   lcd_set_cgram_char(3, cactus1);                 // guardamos el c gram
   lcd_gotoxy(x, y);                               // ubicamos cursor
   lcd_putc(3);                                    // dibujamos
}

// cactus chico
void cact2(int8 x, int8 y)
{
   int cactus2[8] = {0, 0, 12, 13, 15, 12, 12, 31};
   lcd_set_cgram_char(4, cactus2); // guardamos el c gram
   lcd_gotoxy(x, y);               // ubicamos cursor
   lcd_putc(4);                    // dibujamos
}

// sol 1
void sole1(int8 x, int8 y)
{
   int sol1[8] = {29, 28, 25, 2, 20, 0, 0, 0};
   lcd_set_cgram_char(5, sol1); // guardamos el c gram
   lcd_gotoxy(x, y);            // ubicamos cursor
   lcd_putc(5);                 // dibujamos
}

// sol 2
void sole2(int8 x, int8 y)
{
   int sol2[8] = {28, 29, 24, 2, 8, 0, 0, 0};
   lcd_set_cgram_char(6, sol2); // guardamos el c gram
   lcd_gotoxy(x, y);            // ubicamos cursor
   lcd_putc(6);                 // dibujamos
}

/* ////////////////////////hacemos la funcion animacion INICIO///////////////////////////////


void RunDinoInic(int16 t){
      lcd_putc("\f");//borramos pantalla
      lcd_gotoxy(1,1); //ubicamos cursor
      lcd_putc(1);//dibujamos segundo dinosaurio2
      lcd_gotoxy(3,1); //ubicamos cursor
      lcd_putc("DALE AL BOTON!");
      delay_ms(t*2); //esperamos
      lcd_putc("\f");//borramos pantalla
      lcd_gotoxy(1,1); //ubicamos cursor
      lcd_putc(2);//dibujamos segundo dinosaurio2
      lcd_gotoxy(3,1); //ubicamos cursor
      lcd_putc("DALE AL BOTON!");
      lcd_gotoxy(2,2); //ubicamos cursor
      lcd_putc("YO SE Q QUIERES!!");
      delay_ms(t*2);//esperamos

}


////////////////////////hacemos la funcion animacion de dinosaurio corriendo///////////////////////////////
void RunDino(){
      //lcd_putc("\f");//borramos pantalla
      lcd_gotoxy(2,2); //ubicamos cursor
      lcd_putc(1);//dibujamos segundo dinosaurio2
     // lcd_putc("\f");//borramos pantalla
      lcd_gotoxy(2,2); //ubicamos cursor
      lcd_putc(2);//dibujamos segundo dinosaurio2
}
///////////////////////////HACEMOS EL SOL//////////////////////////////////////////////////////////////////7
 void Solecito (){
      lcd_gotoxy(1,1); //ubicamos cursor
      lcd_putc(5);//dibujamos segundo al sol
      lcd_gotoxy(1,1);
      lcd_putc(6);//dibujamos segundo al sol3

 } */

void main()
{

   DISABLE_INTERRUPTS(GLOBAL);
   OUTPUT_LOW(led1);
   delay_ms(333);
   lcd_init();
   // ENABLE_INTERRUPTS(INT_EXT);
   // ENABLE_INTERRUPTS(GLOBAL);
   lcd_gotoxy(1, 1);
   printf(lcd_putc, "holis");
   lcd_gotoxy(1, 2);
   printf(lcd_putc, "000000000000000");
   delay_ms(ctf);
   lcd_putc("\f"); // borramos pantalla
   // generate_tone(buzzer, 64, 500);

   while (input_state(button) == 0)
   {
      lcd_putc("\f");   // borramos pantalla
      dino1(1, 1);      // dibujamos segundo dinosaurio1
      lcd_gotoxy(3, 1); // ubicamos cursor para texto
      lcd_putc("DALE AL BOTON!");
      delay_ms(ctf / 2); // esperamos
      dino2(1, 1);
      ;                  // dibujamos segundo dinosaurio2
      delay_ms(ctf / 2); // esperamos
      lcd_putc("\f");    // borramos pantalla
      dino1(1, 1);
      ;                 // dibujamos segundo dinosaurio2
      lcd_gotoxy(3, 1); // ubicamos cursor
      lcd_putc("DALE AL BOTON!");
      delay_ms(ctf / 2); // esperamos
      dino2(1, 1);
      ;                 // dibujamos segundo dinosaurio2
      lcd_gotoxy(2, 2); // ubicamos cursor
      lcd_putc("YO SE Q QUIERES!!");
      delay_ms(ctf); // esperamos
   }

   int8 sr = 10;

   while (input_state(button) == 1)
   {

      generate_tone(buzzer, 500, 64);
      delay_ms(CTF); // esperamos

      // RunDino(ctf/5);
   }
   lcd_putc("\f"); // borramos pantalla
   lcd_putc("AYYY PAPAA!! XD");
   lcd_gotoxy(4, 2); // ubicamos cursor
   lcd_putc("ARRANCAMOS");
   delay_ms(CTF);  // esperamos
   lcd_putc("\f"); // borramos pantalla

   while (TRUE)
   { // HACEMOS UN CICLO INFINITO

      lcd_gotoxy(9, 1); // ubicamos cursor
      lcd_putc("P=");
      lcd_gotoxy(11, 1); // ubicamos cursor
      printf(lcd_putc "%d" ,sr);

   } // FIN DEL CICLO

} // fin de main
