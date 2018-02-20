
using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace GreenFox
{
    class Program
    {

        public static void Main(string[] args)
        {
            string output = "";
            int[] notSoCrypticMessage = { 1, 12, 1, 2, 11, 1, 7, 11, 1, 49, 1, 3, 11, 1, 50, 11 };

            var map = new Dictionary<int, string>();

            map.Add(7, "run around and desert you");
            map.Add(50, "tell a lie and hurt you ");
            map.Add(49, "make you cry, ");
            map.Add(2, "let you down");
            map.Add(12, "give you up, ");
            map.Add(1, "Never gonna ");
            map.Add(11, "\n");
            map.Add(3, "say goodbye ");
            Console.WriteLine(map[1]+map[12]+map[1]+map[2]+map[11]+map[1]+map[7]+map[11]+map[1]+map[49]+map[1]+map[3]+map[11]+map[1]+map[50]+map[11]);

            // Things are a little bit messed up
            // Your job is to decode the notSoCrypticMessage by using the hashmap as a look up table
            // Assemble the fragments into the out variable

            Console.WriteLine(output);
            Console.ReadLine();
        }
    }

}