using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CountLetters
{
    public class CountMyLetters
    {
        public Dictionary<char, int> Counter(string inputWord)
        {
            var dic = new Dictionary<char, int>();
            char[] inputWordArray = inputWord.ToCharArray();
            int charCount = 1;
            for (int i = 0; i < inputWordArray.Length; i++)
            {
                dic.Add(inputWordArray[i], charCount);
                
            }
            return dic;
        }
    }
}
