using System;
using System.Text;
using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {

            string quote = "Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.";
            StringBuilder quotes = new StringBuilder();
            quotes.Append(quote);
            quotes.Insert(21, "always takes longer than ");
          

            

            // When saving this quote a disk error has occured. Please fix it.
            // Add "always takes longer than" to the StringBuilder (quote) between the words "It" and "you"
            // Using pieces of the quote variable (instead of just redefining the string)

            Console.WriteLine(quotes);
            Console.ReadLine();

        }


    }
}