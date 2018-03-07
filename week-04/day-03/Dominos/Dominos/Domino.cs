using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dominos;

namespace Dominos
{
    public class Domino: IComparable<Domino>, IPrintable
    {
        private readonly int[] Values;

        public Domino(int valueA, int valueB)
        {
            this.Values = new int[] { valueA, valueB };
        }

        public int CompareTo(Domino domino)
        {
            return this.Values[0].CompareTo(domino.Values[0]);
        }

        public int[] GetValues()
        {
            return Values;
        }

        public void PrintAllFields()
        {
            Console.Write($"[{GetValues()[0]},{GetValues()[1]}] ");
        }
    }
}