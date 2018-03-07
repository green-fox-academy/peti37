using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dominos
{
    class Dominoes
    {
        public static void Main(string[] args)
        {
            var dominoes = new List<Domino>();
            dominoes.Add(new Domino(5, 2));
            dominoes.Add(new Domino(4, 6));
            dominoes.Add(new Domino(1, 5));
            dominoes.Add(new Domino(6, 7));
            dominoes.Add(new Domino(2, 4));
            dominoes.Add(new Domino(7, 1));

            dominoes.Sort();
            Console.WriteLine(dominoes[1].CompareTo(dominoes[0]));
            for (int i = 0; i < dominoes.Count; i++)
            {
                foreach (var item in dominoes[i].GetValues())
                {
                    Console.Write($"{item} ");
                }
            }

            Console.ReadLine();
            // the order of your dominoes should look like this: [[1,5], [2,4], [4,6], [5,2], [6,7], [7,1]]
        }
    }
}
