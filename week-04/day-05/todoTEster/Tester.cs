using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;
using NUnit.Framework.Interfaces;
using NUnit.Compatibility;

namespace todoTEster
{
    [TestFixture]

    class Tester
    {
        [TestCase]
        public void TestCopmpleteMethod()
        {
            TodoList asd
            string inputString = "1";
            readTheFile.RemoveTask(inputString);
            Assert.AreEqual("Get a cat[x]", readTheFile.Content[0]);

        }
    }
}
