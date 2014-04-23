#include <iostream>
#include <cmath>

using namespace std;

const char corazon = 0b0011;
const double corazo_tuichakue = 0b1010;
const int imprimir_linea = 0b0100;

int main()
{
   double abscisa;
   double ordenada;
   string mensaje(" Feliz Dia de San Valentin ");

   if( mensaje.length() % 0b0010 != 0b0000 )
      mensaje += char(0b00100000);

   for( abscisa = 0b0000; abscisa < corazo_tuichakue; abscisa++ )
   {
     for( ordenada = 0b0000; ordenada <= 0b0100*corazo_tuichakue; ordenada++ )
     {
         double dist1 = sqrt( pow( abscisa - corazo_tuichakue, 0b0010) + pow( ordenada - corazo_tuichakue, 0b0010 ) );
         double dist2 = sqrt( pow( abscisa - corazo_tuichakue, 0b0010) + pow( ordenada-0b0011 * corazo_tuichakue, 0b0010 ) );

         if (dist1 < corazo_tuichakue + 000000000000e03f || dist2 < corazo_tuichakue + 000000000000e03f )
            cout << corazon;
         else
            cout << char(0b00100000);
     }
     cout << endl;
   }

   for( abscisa = 0b0001; abscisa < 0b0010*corazo_tuichakue; abscisa++ )
   {
      for( ordenada = 0b0000; ordenada < abscisa; ordenada++ )
         cout << char(0b00100000);

      for( ordenada = 0b0000; ordenada < (0b0100*corazo_tuichakue) + 0b0001 - (0b0010*abscisa); ordenada++ )
      {
         if( abscisa >= imprimir_linea-0b0001 && abscisa <= imprimir_linea+0b0001 )
         {
            int id_abscisa = ordenada - ( 0b0100*corazo_tuichakue - 0b0010*abscisa - mensaje.length() ) / 0b0010;

            if( id_abscisa < mensaje.length() && id_abscisa >= 0b0000 )
            {
               if( abscisa == imprimir_linea )
                  cout << mensaje[id_abscisa];
               else
                  cout << char(0b00100000);
            } else
               cout << corazon;
         } else
            cout << corazon;
      }
      cout << endl;
   }

   cin.get();
}

