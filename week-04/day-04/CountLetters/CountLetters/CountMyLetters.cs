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
            for (int i = 0; i < inputWord.Length; i++)
            {
                if (dic.ContainsKey(inputWord[i]))
                {
                    dic[inputWord[i]]++;
                }
                else
                {
                    dic.Add(inputWord[i], 1);
                }
            }
            return dic;
        }
    }
}
