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
            var dominoes = InitializeDominoes();
            // You have the list of Dominoes
            // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
            // Create a function to write the dominous to the console in the following format
            // eg: [2, 4], [4, 3], [3, 5] ...

           
            orderedDominoList(dominoes);
            for (int i = 0; i < orderedDominoList(dominoes).Count; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (j % 2 == 0)
                    {
                        Console.Write("[" + orderedDominoList(dominoes)[i].GetValues()[j] + ",");

                    }
                    else if (j % 2 == 1)
                    {
                        Console.Write(orderedDominoList(dominoes)[i].GetValues()[j] + "] ");
                    }
                }
            }

            Console.ReadLine();
        }

        private static List<Domino> orderedDominoList(List<Domino> implentedList)
        {
            var OrderedList = new List<Domino>();
            OrderedList.Add(implentedList[0]);
            for (int i = 0; i < implentedList.Count - 1; i++)
            {
                for (int j = 0; j < implentedList.Count; j++)
                {
                    if (OrderedList[i].GetValues()[1] == implentedList[j].GetValues()[0])
                    {
                        OrderedList.Add(implentedList[j]);
                    }

                }
            }
            return OrderedList;
        }

        public static List<Domino> InitializeDominoes()
        {
            var dominoes = new List<Domino>();
            dominoes.Add(new Domino(5, 2));
            dominoes.Add(new Domino(4, 6));
            dominoes.Add(new Domino(1, 5));
            dominoes.Add(new Domino(6, 7));
            dominoes.Add(new Domino(2, 4));
            dominoes.Add(new Domino(7, 1));
            return dominoes;
        }
    }
}
