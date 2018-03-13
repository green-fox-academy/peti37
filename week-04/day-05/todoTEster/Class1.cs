using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TodoAppv2;
namespace todoTEster
{
    [TestFixture]
    class Class1
    {
        [Test]
        TodoList asd = new TodoList();
        string inputString = "1";
        readTheFile.RemoveTask(inputString);
        Assert.AreEqual("Get a cat[x]", readTheFile.Content[0]);
    }
}
