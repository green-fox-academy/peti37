using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Anagram
{
    public class AnagramStrings
    {
        public bool Anagrammer(string firstWord, string secondWord)
        {
            char[] charedWord = firstWord.ToCharArray();
            char[] charedWord2 = secondWord.ToCharArray();
            Array.Sort(charedWord);
            Array.Sort(charedWord2);
            string joinedWord = (string.Join("", charedWord));
            string joinedWord2 = (string.Join("", charedWord2));


            if (joinedWord == joinedWord2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
