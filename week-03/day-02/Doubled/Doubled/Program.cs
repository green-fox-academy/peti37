using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Doubled
{
    class Program
    {
        static void Main(string[] args)
        {
            string log = "duplicated-chars.txt";
            Decrypt(log);
            Console.ReadLine();
        }

        private static void Decrypt(string log)
        {
            string[] content = File.ReadAllLines(log);
            var contentList = new List<char>();
            foreach (var item in content)
            {
                for (int i = 0; i < item.Length; i++)
                {
                    if (i % 2 == 0)
                    {
                        contentList.Add(item[i]);
                    }
                }

            }

            foreach (var item in contentList)
            {
                Console.Write(item);
            }


        }
    }
}
