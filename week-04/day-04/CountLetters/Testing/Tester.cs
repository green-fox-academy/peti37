﻿using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CountLetters;

namespace Testing
{
    [TestFixture]
    public class Tester
    {
        [TestCase]
        public void TestCounter()
        {
            CountMyLetters first = new CountMyLetters();
            string input = "fiiirst";

            Assert.AreEqual(3, first.Counter(input)['i']);


        }
    }
}
