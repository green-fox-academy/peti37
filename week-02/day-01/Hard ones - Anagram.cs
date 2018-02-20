using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {

            string first = "kacsa";
            string second = "acska";

            Console.WriteLine(anagram(first, second)); 



            Console.ReadLine();
        }
        public static bool anagram(string firstWord, string secondWord)
            {
            char[] charedWord = firstWord.ToCharArray();
            char[] charedWord2 = secondWord.ToCharArray();
            Array.Sort(charedWord);
            Array.Sort(charedWord2);
            string joinedWord = (string.Join("", charedWord));
            string joinedWord2 = (string.Join("", charedWord2));


            if (joinedWord == joinedWord2)
            {
               return  true;
            }
            else
            {
               return  false;
            }
            
        }


    }
}