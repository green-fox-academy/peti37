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

        [TestCase]
        public void TestMyListWithNoElemets()
        {
            Summ summer = new Summ();
            var emptyList = new List<int>();
            Assert.AreEqual(0, summer.SumMyNumbersBitch(emptyList));
        }

        [TestCase]
        public void TestMyListWithOneElemet()
        {
            Summ summer = new Summ();
            var oneElementList = new List<int>();
            oneElementList.Add(15);
            Assert.AreEqual(15, summer.SumMyNumbersBitch(oneElementList));
        }

        [TestCase]
        public void TestMyListWithNull()
        {
            Summ summer = new Summ();
            var nullList = new List<int>();
            nullList = null;
            Assert.AreEqual(null, summer.SumMyNumbersBitch(nullList));
        }
    }
}
