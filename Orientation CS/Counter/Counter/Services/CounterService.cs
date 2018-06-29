using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Counter.Services
{
    public class CounterService : ICounter
    {
        private int countOfClicks = 0;
        private string Name = "Joe";

        public string GetName()
        {
            return Name;
        }

        public int GetNumber()
        {
            return countOfClicks;
        }

        public void Increase()
        {
            countOfClicks++;
        }

        public void SetName(string name)
        {
            Name = name;
        }
    }
}
