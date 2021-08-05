import CheckForPrimals
import PrimalNumberKeeper
from datetime import datetime

#Выдать первоначальные значения хранителю
keeper = PrimalNumberKeeper.CreateKeeper();

#Диапазон для проверки и текущий номер
#Он обязательно должен быть кратен 10
rangeForCheck = 1_000_000
currentNumber = 3

#Запомнить время запуска.
start = datetime.now();

while (10_000_000 > currentNumber):
    #Пребор и проверка
        if (keeper[-1] < rangeForCheck):
                CheckForPrimals.RangeCheck(currentNumber, rangeForCheck)
        else:
        #добавить к хранителю все числа диапазона, которые оказались простыми.
                PrimalNumberKeeper.AddKeeper(CheckForPrimals.GetListPrimalNumbers(currentNumber, rangeForCheck))
                println(keeper[-1])
                currentNumber += rangeForCheck;
        end = datetime.now();
        println("Выполнение заняло: " +  (end-start))


