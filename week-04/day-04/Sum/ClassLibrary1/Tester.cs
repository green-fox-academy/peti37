using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Summa;

namespace TestLib
{
    [TestFixture]
    public class Tester
    {
        [TestCase]
        public void TestMySumaOfList()
        {
            Summ summer = new Summ();
            var szamosLista = new List<int>();
            szamosLista.Add(15);
            szamosLista.Add(15);
            szamosLista.Add(5);
            szamosLista.Add(18);

            Assert.AreEqual(53, summer.SumMyNumbersBitch(szamosLista));

        }
    }
}
