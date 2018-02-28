using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Counter
{
    public class Counter
    {
        public int start = 0;

        public Counter(int value)
        {
            this.start = value;
        }

        public void Add(int number)
        {
            start += number;
        }
        public void Add()
        {
            start++;
        }
        public void Get()
        {
            start.ToString();
        }
        public void Reset()
        {
            start = 0;
        }
    }

}
