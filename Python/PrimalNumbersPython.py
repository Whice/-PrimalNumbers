import CheckForPrimals
import PrimalNumberKeeper
from datetime import datetime


print("До какого числа искать? (печатается каждый последний из 100 000 наденых.)")
maxNumber=int(input())

memoryForKeeper = PrimalNumberKeeper.Memory()
memoryForKeeper.CreateKeeper()
#Выдать первоначальные значения хранителю
keeper = memoryForKeeper.GetKeeper();

#Диапазон для проверки и текущий номер
#Он обязательно должен быть кратен 10
rangeForCheck = 100_000
currentNumber = 8

#Запомнить время запуска.
start = datetime.now();

while (maxNumber > currentNumber):
        #Пребор и проверка
        if ( keeper[-1]< rangeForCheck):
                CheckForPrimals.CheckForPrimal.RangeCheck(currentNumber, rangeForCheck, memoryForKeeper)
                currentNumber += rangeForCheck;
                print(keeper[-1])
        else:
        #добавить к хранителю все числа диапазона, которые оказались простыми.
                memoryForKeeper.AddKeeper(CheckForPrimals.CheckForPrimal.GetListPrimalNumbers(currentNumber, rangeForCheck, memoryForKeeper))
                print(keeper[-1])
                currentNumber += rangeForCheck;

end = datetime.now();
print("Выполнение заняло: " +  str(end-start))
'''for i in memoryForKeeper.GetKeeper():
    print(i)'''

