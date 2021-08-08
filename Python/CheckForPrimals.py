import PrimalNumberKeeper
import math

class CheckForPrimal:
        #Проверка простое ли число.
        @classmethod
        def IsPrimal(self, number, memoryForKeeper):
                keeper=memoryForKeeper.GetKeeper
                #Вычислить корень один раз.
                sqrtNumber = math.sqrt(number);
                #Пройтись по списку уже найденых чисел.
                for i in range(0, len(keeper)):
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
        @classmethod
        def RangeCheck(self, numberStart, rangeIn, memoryForKeeper):
                keeper=memoryForKeeper.GetKeeper
                #Посчитать максимум
                numberMax = numberStart + rangeIn
                #Довести до значения 5
                currentNumber = numberStart
                if currentNumber % 2 == 0:
                        currentNumber+=1
                while (not(currentNumber % 2 == 1 and currentNumber % 5 == 0)):
                        if IsPrimal(currentNumber, memoryForKeeper):
                                keeper.append(currentNumber)
                        currentNumber += 2
                
                #Теперь currentNumber не делится на 2, а на 5 делится
                i=currentNumber
                while (i < numberMax):
                        #XXX7
                        if (IsPrimal(i + 2, memoryForKeeper)):
                                keeper.append(i+2)
                        #XXX9
                        if (IsPrimal(i + 4, memoryForKeeper)):
                                keeper.append(i+4)
                        #XXX1
                        if (IsPrimal(i + 6, memoryForKeeper)):
                                keeper.append(i+6)
                        #XXX3
                        if (IsPrimal(i + 8, memoryForKeeper)):
                                keeper.append(i+8)
                        i+=10
                memoryForKeeper.SetKeeper(keeper)

        #Проверка на простоту всех чисел в диапазоне и возвращение их отдельным списком.
        @classmethod
        def GetListPrimalNumbers(self, numberStart, rangeIn, memoryForKeeper):
                #Посичтать максимум
                numberMax = numberStart + rangeIn;
                #завести локальный список для найденых простых чисел
                localKeeper=[]
                #Довести до значения 5
                currentNumber = numberStart
                if currentNumber % 2 == 0:
                        currentNumber+=1
                while( not(currentNumber % 2 == 1 and currentNumber % 5 == 0)):
                        if IsPrimal(currentNumber, memoryForKeeper):
                                localKeeper.append(Number)
                        currentNumber+=2
                #Теперь currentNumber не делится на 2, а на 5 делится.
                i=currentNumber
                while (i < numberMax):
                        #XXX7
                        if (IsPrimal(i + 2, memoryForKeeper)):
                                localKeeper.append(i+2)
                        #XXX9
                        if (IsPrimal(i + 4, memoryForKeeper)):
                                localKeeper.append(i+4)
                        #XXX1
                        if (IsPrimal(i + 6, memoryForKeeper)):
                                localKeeper.append(i+6)
                        #XXX3
                        if (IsPrimal(i + 7, memoryForKeeper)):
                                localKeeper.append(i+8)
                        i+=10
                return localKeeper


memoryForKeeper = PrimalNumberKeeper.Memory()
memoryForKeeper.CreateKeeper()
CheckForPrimal.RangeCheck(1, 10000, memoryForKeeper)
