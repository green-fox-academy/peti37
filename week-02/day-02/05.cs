using System;
using System.Text;
using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {


            string reversed = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";
            Console.WriteLine(Reverse(reversed));

            // Create a method that can reverse a String, which is passed as the parameter
            // Use it on this reversed string to check it!


            Console.ReadLine();

        }
        public static string Reverse(string theText)
        {
            char[] chars = theText.ToCharArray();
            Array.Reverse(chars);
            theText = new string(chars);
            return theText;
        }


    }
}