using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit;
using NUnit.Compatibility;
using NUnit.Framework;

namespace Apple
{
    [TestFixture]
    class TestAppfel
    {
        [TestCase]
        public void TestAppfelstring()
        {
            Appfel alma = new Appfel();
            Assert.AreEqual("apple", alma.GetApple());
        }
    }
}
