using System;
using System.Collections.Generic;

namespace PrimalNumbers
{
    static class CheckForPrimals
    {
        /// <summary>
        /// Проверка простое ли число
        /// </summary>
        /// <param name="number"></param>
        /// <param name="memoryForKeeper"></param>
        /// <returns></returns>
        static bool IsPrimal(ulong number, Memory memoryForKeeper)
        {
            //Была проведена замена ulong на int из-за большого количества
            //приведений, влияющих на производительность (выигрыш около 10-15%)

            List<ulong> keeper = memoryForKeeper.GetKeeper();

            //Вычислить корень один раз.
            //ulong sqrtNumber = (ulong)Math.Sqrt(number);
            int sqrtNumber = (int)Math.Sqrt(number);
            //ulong keeperSize = (ulong)keeper.Count;
            int keeperSize = keeper.Count;

            //Пройтись по списку уже найденых чисел.
            //for (ulong i = 0; i < keeperSize; i++)
            for (int i = 0; i < keeperSize; i++)
            {
                //Если делится - отстой.
                //if (number % keeper[(int)i] == 0)
                if (number % keeper[i] == 0)
                    return false;
                //Если корень был пройден, то дальше нет смысла смотреть - все ок.
                //if (sqrtNumber < keeper[(int)i])
                if (sqrtNumber < (int)keeper[i])
                    return true;
            }
            //Требование компилятора
            return true;
        }
        /// <summary>
        /// Проверка на простоту всех чисел в диапазоне и добавление их в список-хранитель.
        /// </summary>
        /// <param name="numberStart"></param>
        /// <param name="range"></param>
        /// <param name="memoryForKeeper"></param>
        static public void RangeCheck(ulong numberStart, ulong range, Memory memoryForKeeper)
        {
            List<ulong> keeper = memoryForKeeper.GetKeeper();
            //Посчитать максимум
            ulong numberMax = numberStart + range;
            //Довести до значения 5
            ulong currentNumber = numberStart;

            if (currentNumber % 2 == 0)
                ++currentNumber;
            while (!(currentNumber % 2 == 1 && currentNumber % 5 == 0))
            {
                if (IsPrimal(currentNumber, memoryForKeeper))
                    keeper.Add(currentNumber);
                currentNumber += 2;
            }
            //Теперь currentNumber не делится на 2, а на 5 делится.
            for (ulong i = currentNumber; i < numberMax; i+=10)
            {
                if (IsPrimal(i + 2, memoryForKeeper)) keeper.Add(i + 2);
                if (IsPrimal(i + 4, memoryForKeeper)) keeper.Add(i + 4);
                if (IsPrimal(i + 6, memoryForKeeper)) keeper.Add(i + 6);
                if (IsPrimal(i + 8, memoryForKeeper)) keeper.Add(i + 8);
            }
            memoryForKeeper.SetKeeper(keeper);
        }
        /// <summary>
        /// Проверка на простоту всех чисел в диапазоне и возвращение их отдельным списком.
        /// </summary>
        /// <param name="numberStart"></param>
        /// <param name="range"></param>
        /// <param name="memoryForKeeper"></param>
        /// <returns></returns>
        static public List<ulong> GetListPrimalNumbers(ulong numberStart, ulong range, Memory memoryForKeeper)
        {
            //Посичтать максимум
            ulong numberMax = numberStart + range;
            //завести локальный список для найденых простых чисел
            List<ulong> localKeeper = new List<ulong>();
            //Довести до значения 5
            ulong currentNumber = numberStart;

            if (currentNumber % 2 == 0)
                ++currentNumber;
            while (!(currentNumber % 2 == 1 && currentNumber % 5 == 0))
            {
                if (IsPrimal(currentNumber, memoryForKeeper))
                    localKeeper.Add(currentNumber);
                currentNumber += 2;
            }
            //Теперь currentNumber не делится на 2, а на 5 делится.
            for (ulong i = currentNumber; i < numberMax; i += 10)
            {
                if (IsPrimal(i + 2, memoryForKeeper)) localKeeper.Add(i + 2);
                if (IsPrimal(i + 4, memoryForKeeper)) localKeeper.Add(i + 4);
                if (IsPrimal(i + 6, memoryForKeeper)) localKeeper.Add(i + 6);
                if (IsPrimal(i + 8, memoryForKeeper)) localKeeper.Add(i + 8);
            }
            return localKeeper;
        }
    }
}
