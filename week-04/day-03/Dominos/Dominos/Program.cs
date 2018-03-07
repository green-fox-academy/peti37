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

            for (int i = 0; i < dominoes.Count; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (j % 2 == 0)
                    {
                        Console.Write("[" + dominoes[i].GetValues()[j] + ",");

                    }
                    else if (j % 2 == 1)
                    {
                        Console.Write(dominoes[i].GetValues()[j] + "] ");
                    }
                }
            }
                Console.ReadLine();
            // the order of your dominoes should look like this: [[1,5], [2,4], [4,6], [5,2], [6,7], [7,1]]
        }
    }
}
