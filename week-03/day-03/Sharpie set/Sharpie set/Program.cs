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

            var listOfSharpies = new SharpieSet();
            var first = new Sharpie("red", 55);
            var second = new Sharpie("green", 50);
            var third = new Sharpie("blue", 15);
            var fourth = new Sharpie("black", 15);
            listOfSharpies.AddSharpie(first);
            listOfSharpies.AddSharpie(second);
            listOfSharpies.AddSharpie(third);
            listOfSharpies.AddSharpie(fourth);


            first.Use();
            first.Use();

            listOfSharpies.HowMany();





            Console.WriteLine(listOfSharpies.CountUsable());

            Console.ReadLine();
        }
    }
}
