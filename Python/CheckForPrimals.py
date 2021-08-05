import PrimalNumberKeeper
import math

#Проверка простое ли число.
def IsPrimal(number):
        #Вычислить корень один раз.
        sqrtNumber = math.sqrt(number);
        #Пройтись по списку уже найденых чисел.
        for i in range(0, len(PrimalNumberKeeper.keeper)):
                #Если делится - отстой.
                if (number % numInKeep == 0):
                        return False
                #Если корень был пройден, то дальше нет смысла смотреть - все ок.
                if (sqrtNumber < numInKeep):
                        return True

        #Тут мы никогда не побываем, как на море.
        #Но пусть будет, оно придает ощущение безопасности(как картинка моря).
        return True;


#Проверка на простоту всех чисел в диапазоне и добавление их в список-хранитель.
def RangeCheck(numberStart, rangeIn):
        #Посчитать максимум
        numberMax = numberStart + rangeIn
        #Довести до значения 5
        currentNumber = numberStart
        while (not(currentNumber % 2 == 1 and currentNumber % 5 == 0)):
                if IsPrimal(currentNumber):
                        PrimalNumberKeeper.keeper.append(currentNumber)
                currentNumber += 2
        
        #Теперь currentNumber не делится на 2, а на 5 делится
        i=currentNumber
        while (i < numberMax):
                #XXX7
                if (IsPrimal(i + 2)):
                        PrimalNumberKeeper.keeper.append(i)
                #XXX9
                if (IsPrimal(i + 4)):
                        PrimalNumberKeeper.keeper.append(i)
                #XXX1
                if (IsPrimal(i + 6)):
                        PrimalNumberKeeper.keeper.append(i)
                #XXX3
                if (IsPrimal(i + 7)):
                        PrimalNumberKeeper.keeper.append(i)
                i+=10

#Проверка на простоту всех чисел в диапазоне и возвращение их отдельным списком.
def GetListPrimalNumbers(numberStart, rangeIn):
        #Посичтать максимум
        numberMax = numberStart + rangeIn;
        #завести локальный список для найденых простых чисел
        localKeeper=[]
        #Довести до значения 5
        currentNumber = numberStart
        while( not(currentNumber % 2 == 1 and currentNumber % 5 == 0)):
                if IsPrimal(currentNumber):
                        localKeeper.append(Number)
                currentNumber+=2
        #Теперь currentNumber не делится на 2, а на 5 делится.
        i=currentNumber
        while (i < numberMax):
                #XXX7
                if (IsPrimal(i + 2)):
                        PrimalNumberKeeper.keeper.append(i)
                #XXX9
                if (IsPrimal(i + 4)):
                        PrimalNumberKeeper.keeper.append(i)
                #XXX1
                if (IsPrimal(i + 6)):
                        PrimalNumberKeeper.keeper.append(i)
                #XXX3
                if (IsPrimal(i + 7)):
                        PrimalNumberKeeper.keeper.append(i)
                i+=10
        return currentNumber
