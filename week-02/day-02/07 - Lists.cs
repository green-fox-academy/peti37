
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
            var list = new List<string> { "What", "I", "do", "create,", "I", "cannot", "not", "understand." };

            // Accidentally I messed up this quote from Richard Feynman.
            // Two words are out of place
            // Your task is to fix it by swapping the right words with code
            // Create a method called QuoteSwap().

            // Also, print the sentence to the output with spaces in between.
            Console.WriteLine(QuoteSwap(list));
            Console.ReadLine();
            // Expected output: "What I cannot create I do not understand." 
        }
        public static string QuoteSwap(List<string> theListInput)
        {
            string temp = theListInput[2];
            theListInput[2] = theListInput[5];
            theListInput[5] = temp;

            string JoinedString = string.Join(" ", theListInput.ToArray());
            return JoinedString;

        }
    }

}