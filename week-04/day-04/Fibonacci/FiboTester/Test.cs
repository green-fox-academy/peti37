using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Fibonacci;

namespace FiboTester
{
    [TestFixture]
    public class Test
    {
        [TestCase]
        public void TestingFiboIndexes()
        {
            Fiber seventeen = new Fibonacci.Fiber();
            int seventeenth = 17;
            Assert.AreEqual(1597, seventeen.NFibo(seventeenth));
        }
    }
}
