#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
using namespace std; 
float alg(int live, int death, int time)
{
   int floors = live + death; 
   float SchanseLiveFloors = float(live)/floors;
   float SchanseDeathFloars = 1 - SchanseLiveFloors; // получаем процент неблагоприятных этажей
   float SchanseDeathFirstFloars = SchanseDeathFloars*SchanseDeathFloars; // шанс откиснуть за первые 2 месяца
   float SchanseDeathSecondFloars = SchanseDeathFloars*SchanseDeathFloars*SchanseDeathFloars + SchanseDeathFloars*SchanseDeathFloars*SchanseLiveFloors*2;
   float inflazia1 = (SchanseDeathSecondFloars*8) - 2 * (SchanseDeathFirstFloars*4); // число, которое мы прибавляем и увеличиваем в последовательности, например 1, 0.36, 1,185
   float inflazia = inflazia1; // копия числа выше
   float ScoreDeathFloors = SchanseDeathFirstFloars * 4; // если при 50% на втором месяца у нас шанс откиснуть 25% (0.25), то мы получаем число 1/4 умнажением 0.25 на 4
                                                         // так если шанс не 50 а 70 на плохой этаж, мы умнажаем 0.49 на 4
                                                         // таким образом последовательность (как 1, 3, 8, 19) начинается не с 1 а с 1,96
   if (time == 1)
   {
      return 0; // понятно, 1 месяц ноль шансов откиснуть
   }
   if (time == 2) // что бы не мешать циклу нормальго работать, отдельно выписал варианты для 2 и 3 месяца, тем более выше уже посчитал их
   {
      return SchanseDeathFirstFloars*100;
   }
   if (time == 3)
   {
      return SchanseDeathSecondFloars*100;
   }
   if (time <= 0)
   {
      return -3; // если какой то умник ввел вреия меньше одного, то даю ретерн минус 3, и в основной функции если я получу в ретерне отсюда минус 3, то там выведет отдельно сообщение
   }
   for (int i = 2; i < time; i++)
   {
      ScoreDeathFloors = ScoreDeathFloors * 2 + inflazia1;
      inflazia1 = inflazia1 + inflazia;
   }
   return ScoreDeathFloors/(pow(2, time))*100;
}
int main()
{
   cout<<"enter a number of months: ";
   int months;
   int OkFloors;
   int NotOkFloors;
   cin>>months;
   cout<<"enter a number of floors with eat: ";
   cin>>OkFloors;
   cout<<"enter a numbers of floors without eat: ";
   cin>>NotOkFloors;
   if (alg(OkFloors, NotOkFloors, months) != -3)
   {
      cout << "schance of death " <<alg(OkFloors, NotOkFloors, months) << "%"<< endl;
   }
   else
   {
      cout << "dyra4ek? otrizatelbHoe Brem9l?" << endl;
   }
   return 0;
}