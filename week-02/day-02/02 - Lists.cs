
            using System;
            using System.Text;
            using System.Collections.Generic;

namespace GreenFox
{ 
        class Program
        {
            static void Main(string[] args)
            {


                var girls = new List<string> { "Eve", "Ashley", "Bözsi", "Kat", "Jane" };
                var boys = new List<string> { "Joe", "Fred", "Béla", "Todd", "Neef", "Jeff" };





                // Write a method that joins the two lists by matching one girl with one boy into a new list
                // Exepected output: "Eve", "Joe", "Ashley", "Fred"...
                
                Console.WriteLine(MakingMatches(boys, girls));
                Console.ReadLine();
            }
            public static string MakingMatches(List<string> boysList, List<string> girlsList)
            {
                var paired = new List<string>();
                for (int i = 0; i < girlsList.Count; i++)
                {
                    if (i % 2 == 0)
                    {
                        paired.Add(boysList[i]);
                        paired.Add(girlsList[i]);
                    }

                }
                for (int i = 0; i < girlsList.Count; i++)
                {
                    if (i % 2 == 1)
                    {
                        paired.Add(boysList[i]);
                        paired.Add(girlsList[i]);
                    }

                }
                string JoinedString = string.Join(", ", paired.ToArray());

                return JoinedString;
            }
        }
    
}