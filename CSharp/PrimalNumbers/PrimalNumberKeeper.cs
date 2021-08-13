using System.Collections.Generic;

namespace PrimalNumbers
{
    class Memory
    {
        private List<ulong> keeper;
        public Memory()
        {
            CreateKeeper();
        }

        private void CreateKeeper()
        {
            keeper = new List<ulong> { 3, 5, 7 };
        }
        
        public void AddKeeper(List<ulong> addList)
        {
            keeper.AddRange(addList);
        }

        public List<ulong> GetKeeper()
        {
            return keeper;
        }

        public void SetKeeper(List<ulong> newKeeper)
        {
            if (keeper == newKeeper)
                return;
            if (newKeeper.Count > keeper.Count)
                keeper = newKeeper;
        }
    }
}
