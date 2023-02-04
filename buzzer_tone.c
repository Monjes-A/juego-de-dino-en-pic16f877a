/* #include <buzzer_tone.c>
*
* Creada por: Ing. Abiezer Hernandez O.
* Fecha de creacion: 22/05/2020
* Electronica y Circuitos
*
*/

void do_delay(int ms_delay, int num_ms, int us_delay, int num_us)
{
   int i;

 for(i=0;i<num_ms;i++)
  delay_ms(250);
 delay_ms(ms_delay);
 for(i=0;i<num_us;i++)
  delay_us(250);
 delay_us(us_delay);
}

void generate_tone(int8 pin_tone, long frequency, long duration)
{
   int32 total_delay_time;
   long total_ms_delay_time, total_us_delay_time;
   int num_us_delays, num_ms_delays, ms_delay_time, us_delay_time;
   long num_periods;

   total_delay_time = (1000000/frequency)/2-10;

   total_ms_delay_time = total_delay_time/1000;
   num_ms_delays = total_ms_delay_time/250;
   ms_delay_time = total_ms_delay_time%250;

   total_us_delay_time = total_delay_time%1000;
   num_us_delays = total_us_delay_time/250;
   us_delay_time = total_us_delay_time%250;

   num_periods = ((int32)duration*1000)/(1000000/frequency);

   while((num_periods--) != 0)
   {
      do_delay(ms_delay_time, num_ms_delays, us_delay_time, num_us_delays);
      output_high(pin_tone);
      do_delay(ms_delay_time, num_ms_delays, us_delay_time, num_us_delays);
      output_low(pin_tone);
   }
   return;
}