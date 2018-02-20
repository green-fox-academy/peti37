
            using System;
            using System.Text;
            using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {

        public static void Main(string[] args)
        {
            var list = new List<object>();
            list.Add("Cupcake");
            list.Add(2);
            list.Add("Brownie");
            list.Add(false);

            // Accidentally we added "2" and "false" to the list.
            // Your task is to change from "2" to "Croissant" and change from "false" to "Ice cream"
            // No, don't just remove the lines
            // Create a method called Sweets() which takes the list as a parameter.

            Console.WriteLine(Sweets(list));
            Console.ReadLine();
            // Expected output: "Cupcake", "Croissant", "Brownie", "Ice cream"
        }
        public static string Sweets(List<object> cookies)
        {
            cookies[1] = "Croissant";
            cookies[3] = "Ice cream";

            
            string JoinedString = string.Join(", ", cookies.ToArray());
            return JoinedString;
        }
    }
        
}