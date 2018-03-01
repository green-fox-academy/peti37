using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharpie_set
{
    class Program
    {
        static void Main(string[] args)
        {
            Sharpie First = new Sharpie("red", 101);
            First.Use();
            var listOfSharpies = new SharpieSet();
            listOfSharpies.AddSharpie(new Sharpie("green", 50));
            listOfSharpies.AddSharpie(new Sharpie("blue", 15));


            Console.WriteLine(listOfSharpies.CountUsable());

            Console.ReadLine();
        }
    }
}
