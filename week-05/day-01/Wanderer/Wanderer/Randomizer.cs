using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Wanderer
{
    public static class Randomizer
    {
        static Random rNumber = new Random();
        public static int Rander()
        {
            return rNumber.Next(0, 10);
        }
    }
}
