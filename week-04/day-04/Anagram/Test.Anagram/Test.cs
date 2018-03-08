using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Anagram;

namespace Test.Anagram
{
    [TestFixture]
    public class Test
    {
        [Test]
        public void TestMyAnagram()
        {
            AnagramStrings First = new AnagramStrings();
            string firstWord = "hard";
            string secondWord = "dhar";

            Assert.AreEqual(true, First.Anagrammer(firstWord, secondWord));
        }
    }
}
