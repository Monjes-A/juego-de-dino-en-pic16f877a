// Proyecto de Lcd , Tercera  practica. realizado por Mi . Jesus Monsalve

#include <16F877A.h>
#fuses XT, NOWDT, NOPUT, NOBROWNOUT, NOLVP, NOCPD, NOWRT, NOPROTECT, NODEBUG
#use delay(clock = 4000000)

#include <lcd2.c>
#include <stdlib.h>
#include <buzzer_tone.c>

#define button PIN_B0
#define buzzer PIN_B1
#define vida1 PIN_B2
#define vida2 PIN_B3
#define vida3 PIN_B4

int16 ctf = 1000;

int8 random;
int1 dp;
int8 st;
int1 pas;
int cuen;
unsigned int16 sr;

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

void vel_juego()
{
   //----------------------------------------------velocidad del juego-----------------------------------------------------------------------
   if (sr <= 10)
   {                 // velocidad del ciclo
      delay_ms(200); ////va aumentabndo la velocidad mientas aunmemnta la puntuacion "pun"
   }
   if (sr > 10 && sr < 20)
   {
      delay_ms(150);
   }
   if (sr >= 20 && sr < 30)
   {
      delay_ms(80);
   }
   if (sr >= 30 && sr < 50)
   {
      delay_ms(70);
   }
   if (sr >= 50 && sr < 100)
   {
      delay_ms(60);
   }
   if (sr < 100)
   {
      delay_ms(50);
   }
}
void main()
{

   DISABLE_INTERRUPTS(GLOBAL);
   OUTPUT_LOW(vida1);
   OUTPUT_LOW(vida2);
   OUTPUT_LOW(vida3);
   delay_ms(333);
   lcd_init();
   // ENABLE_INTERRUPTS(INT_EXT);
   // ENABLE_INTERRUPTS(GLOBAL);
   lcd_gotoxy(1, 1);
   printf(lcd_putc, " Mini Dino w.w !");
   lcd_gotoxy(1, 2);
   printf(lcd_putc, " PRESENTADO POR!");
   OUTPUT_HIGH(vida1);
   OUTPUT_HIGH(vida2);
   OUTPUT_HIGH(vida3);
   delay_ms(1500);
   OUTPUT_LOW(vida1);
   OUTPUT_LOW(vida2);
   OUTPUT_LOW(vida3);
   delay_ms(1500);

   lcd_gotoxy(1, 1);
   printf(lcd_putc, "JESUS A MONSALVE");
   lcd_gotoxy(1, 2);
   printf(lcd_putc, "     ZERPA.     ");
   OUTPUT_HIGH(vida1);
   OUTPUT_HIGH(vida2);
   OUTPUT_HIGH(vida3);
   delay_ms(1500);
   OUTPUT_LOW(vida1);
   OUTPUT_LOW(vida2);
   OUTPUT_LOW(vida3);
   delay_ms(1500);

   lcd_gotoxy(1, 1);
   printf(lcd_putc, "   NO MATES AL  ");
   lcd_gotoxy(1, 2);
   printf(lcd_putc, "   DINOSAURIO.  ");

menu:
   /// saludamos con los leds
   OUTPUT_HIGH(vida1);
   OUTPUT_HIGH(vida2);
   OUTPUT_HIGH(vida3);
   delay_ms(ctf / 2);
   OUTPUT_LOW(vida1);
   OUTPUT_LOW(vida2);
   OUTPUT_LOW(vida3);
   delay_ms(ctf / 2);
   OUTPUT_HIGH(vida1);
   OUTPUT_HIGH(vida2);
   OUTPUT_HIGH(vida3);
   delay_ms(ctf / 2);
   OUTPUT_LOW(vida1);
   OUTPUT_LOW(vida2);
   OUTPUT_LOW(vida3);
   delay_ms(ctf / 2);
   OUTPUT_HIGH(vida1);
   OUTPUT_HIGH(vida2);
   OUTPUT_HIGH(vida3);
   delay_ms(ctf / 2);
   OUTPUT_LOW(vida1);
   OUTPUT_LOW(vida2);
   OUTPUT_LOW(vida3);
   while (input_state(button) == 0)
   {
      dino1(1, 1);      // dibujamos segundo dinosaurio1
      lcd_gotoxy(2, 1); // ubicamos cursor para texto
      lcd_putc("DALE AL BOTON!!!");
      lcd_gotoxy(1, 2); // ubicamos cursor para texto
      lcd_putc("                ");
      delay_ms(500);
      dino2(1, 1);      // dibujamos segundo dinosaurio2
      lcd_gotoxy(1, 2); // ubicamos cursor
      lcd_putc("YO SE Q QUIERES!!");
      delay_ms(500);
   }

   while (input_state(button) == 1)
   {

      generate_tone(buzzer, 500, 64);
      delay_ms(CTF);

      generate_tone(buzzer, 500, 64);
      delay_ms(CTF);

      generate_tone(buzzer, 1000, 80);
      delay_ms(CTF);

      // RunDino(ctf/5);
   }
   lcd_putc("\f"); // borramos pantalla
   lcd_putc("AYYY PAPAA!! XD");
   lcd_gotoxy(4, 2); // ubicamos cursor
   lcd_putc("ARRANCAMOS");
   delay_ms(CTF);  // esperamos
   lcd_putc("\f"); // borramos pantalla

   cuen = 19;
   sr = 0;
   int vida = 3;

   while (TRUE)
   { // HACEMOS UN CICLO INFINITO

      lcd_gotoxy(9, 1);           // ubicamos cursor
      lcd_putc("P=");             // dibujamos la puntuacion
      lcd_gotoxy(11, 1);          // ubicamos cursor
      printf(lcd_putc "%ld", sr); // iniciciamos puntuacion

      if (vida == 3)
      {
         OUTPUT_HIGH(vida1);
         OUTPUT_HIGH(vida2);
         OUTPUT_HIGH(vida3);
      }

      if (vida == 2)
      {
         OUTPUT_HIGH(vida1);
         OUTPUT_HIGH(vida2);
         OUTPUT_LOW(vida3);
      }
      if (vida == 1)
      {
         OUTPUT_HIGH(vida1);
         OUTPUT_LOW(vida2);
         OUTPUT_LOW(vida3);
      }

      if (vida == 0)
      {
         OUTPUT_LOW(vida1);
         OUTPUT_LOW(vida2);
         OUTPUT_LOW(vida3);
      }

      if (input(button) == 1)
      {
         if (st == 0)
         {
            generate_tone(buzzer, 800, 128);
         }
         dp = 1;
         st++;
         if (st > 4)
         {
            dp = 0;
            st = 0;
         }
      }
      else
      {
         dp = 0;
         st = 0;
      }

      if (pas == 0)
      {
         dino1(2, dp);
         pas = 1;
         sole1(1, 1);
      }
      else
      {
         dino2(2, dp);
         pas = 0;
         sole2(1, 1);
      }

      if (random >= 0 && random < 10)
      {
         ///------------------comienza el juego con un solo captus------------------------------------------------------------------------------------------
         cact1(cuen, 2);

         vel_juego();

         //--------------------------------------------Condicion de fin de juego---------------------------------------------
         cuen--;
         if (cuen == 2 && dp == 0)
         {
            if (vida == 0)
            {
               generate_tone(buzzer, 400, 150); /// Reproduce sonido
               delay_ms(500);
               generate_tone(buzzer, 400, 150); /// Reproduce sonido
               delay_ms(500);
               generate_tone(buzzer, 150, 300); /// Reproduce sonido
               delay_ms(500);
               lcd_gotoxy(1, 1); // ubicamos cursor
               lcd_putc("uy x.x se murio ");
               delay_ms(2000);
               lcd_gotoxy(1, 1); // ubicamos cursor
               lcd_putc("tus pts perrooo!");
               lcd_gotoxy(5, 2); // ubicamos cursor
               printf(lcd_putc "p="
                               "%ld",
                      sr);
               delay_ms(4000); /// y se resetea el pic despues de un segundo
               goto menu;
            }
            generate_tone(buzzer, 500, 80); /// Reproduce sonido
            vida--;
            cuen = 19;
            lcd_gotoxy(1, 1); // ubicamos cursor
            lcd_putc("  uy!   -1  vida");
            delay_ms(1000);
         }

         if (cuen == 0)
         {
            cuen = 19;
            sr++;
            random = rand() % 31;
         }
         lcd_putc("\f");
      } // fin de primer captus

      if (random >= 10 && random < 20)
      {
         ///------------------comienza el juego con dos captus------------------------------------------------------------------------------------------
         cact1(cuen, 2);
         cact2(cuen - 1, 2);

         vel_juego();

         //--------------------------------------------Condicion de fin de juego---------------------------------------------
         cuen--;
         if ((cuen == 1 && dp == 0) || (cuen == 2 && dp == 0)) /////si coinciden el dinosaurio y el cactus en la misma posicion el juego termina
         {
            if (vida == 0)
            {
               generate_tone(buzzer, 400, 150); /// Reproduce sonido
               delay_ms(500);
               generate_tone(buzzer, 400, 150); /// Reproduce sonido
               delay_ms(500);
               generate_tone(buzzer, 150, 300); /// Reproduce sonido
               delay_ms(500);
               lcd_gotoxy(1, 1); // ubicamos cursor
               lcd_putc("uy x.x se murio ");
               delay_ms(2000);
               lcd_gotoxy(1, 1); // ubicamos cursor
               lcd_putc("tus pts perrooo!");
               lcd_gotoxy(5, 2); // ubicamos cursor
               printf(lcd_putc "p="
                               "%ld",
                      sr);
               delay_ms(4000); /// y se resetea el pic despues de un segundo
               goto menu;
            }
            generate_tone(buzzer, 500, 80); /// Reproduce sonido
            vida--;
            cuen = 19;
            lcd_gotoxy(1, 1); // ubicamos cursor
            lcd_putc("  uy!   -1  vida");
            delay_ms(1000);
         }

         if (cuen == 0)
         {
            cuen = 19;
            sr++;
            random = rand() % 31;
         }
         lcd_putc("\f");
      } // fin de primer captus

      if (random >= 20 && random < 30)
      {
         ///------------------comienza el juego------------------------------------------------------------------------------------------
         cact1(cuen - 1, 2);
         cact2(cuen - 2, 2);
         cact1(cuen, 2);

         vel_juego();

         //--------------------------------------------Condicion de fin de juego---------------------------------------------
         cuen--;
         if ((cuen == 1 && dp == 0) || (cuen == 2 && dp == 0) ||
             (cuen == 3 && dp == 0)) /////si coinciden el dinosaurio y el cactus en la misma posicion el juego termina
         {
            if (vida == 0)
            {
               generate_tone(buzzer, 400, 150); /// Reproduce sonido
               delay_ms(500);
               generate_tone(buzzer, 400, 150); /// Reproduce sonido
               delay_ms(500);
               generate_tone(buzzer, 150, 300); /// Reproduce sonido
               delay_ms(500);
               lcd_gotoxy(1, 1); // ubicamos cursor
               lcd_putc("uy x.x se murio ");
               delay_ms(2000);
               lcd_gotoxy(1, 1); // ubicamos cursor
               lcd_putc("tus pts perrooo!");
               lcd_gotoxy(5, 2); // ubicamos cursor
               printf(lcd_putc "p="
                               "%ld",
                      sr);
               delay_ms(4000); /// y se resetea el pic despues de un segundo
               goto menu;
            }
            generate_tone(buzzer, 500, 80); /// Reproduce sonido
            vida--;
            cuen = 19;
            lcd_gotoxy(1, 1); // ubicamos cursor
            lcd_putc("  uy!   -1  vida");
            delay_ms(1000);
         }

         if (cuen == 0)
         {
            cuen = 19;
            sr++;
            random = rand() % 31;
         }

         lcd_putc("\f");
      } // fin de primer captus

   } // FIN DEL CICLO

} // fin de main
