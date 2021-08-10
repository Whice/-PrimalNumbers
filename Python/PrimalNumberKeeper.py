#Класс памяти, который содержит хранителя чисел и методы для него.
class Memory():
        
        #Список для хранения простых чисел.
        _keeper=[]
        
        #Заполнить хранителя(список для хранения) первыми значениями.
        @classmethod
        def CreateKeeper(self):
                self._keeper = [ 3, 5, 7 ]

        
        #Добавить к концу хранителя список чисел.
        @classmethod
        def AddKeeper(self, addList):
            for i in addList:
                self._keeper.append(i)

        #Получить хранителя(список найдены протых чисел).
        @classmethod
        def GetKeeper(self):
                return self._keeper

        #Получить хранителя(список найдены протых чисел).
        @classmethod
        def SetKeeper(self, newKeeper):
                if len(newKeeper)>len(self._keeper):
                        self._keeper=newKeeper
