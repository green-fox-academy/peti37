using System;

namespace Dominos
{
    public class Domino: IComparable<Domino>
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
    }
}