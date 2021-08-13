using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace PrimalNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            //Создание экземпляра таймера
            Stopwatch sw = new Stopwatch();

            Console.WriteLine("До какого числа искать? (печатается каждый последний из 100 000 найденных.)");
            ulong maxNumber = 0;
            UInt64.TryParse(Console.ReadLine(), out maxNumber);

            //Выдать первоначальные значения хранителю
            Memory memoryForKeeper = new Memory();

            //Диапазон для проверки и текущий номер
            //Он обязательно должен быть кратен 10
            const ulong rangeForCheck = 100_000;
            ulong currentNumber = 8;

            sw.Start();

            while (maxNumber > currentNumber)
            {
                List<ulong> keeper = memoryForKeeper.GetKeeper();

                if (keeper[keeper.Count - 1] < rangeForCheck)
                    CheckForPrimals.RangeCheck(currentNumber, rangeForCheck, memoryForKeeper);
                else
                    memoryForKeeper.AddKeeper(CheckForPrimals.GetListPrimalNumbers(currentNumber, rangeForCheck, memoryForKeeper));
                Console.WriteLine(keeper[keeper.Count - 1]);
                currentNumber += rangeForCheck;
            }

            sw.Stop();
            Console.WriteLine("Выполнение заняло: " + sw.Elapsed);
            Console.ReadKey();
        }
    }
}
