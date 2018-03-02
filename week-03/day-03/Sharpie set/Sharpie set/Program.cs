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
            listOfSharpies.AddSharpie(new Sharpie("green", 50));
            listOfSharpies.AddSharpie(new Sharpie("blue", 15));
            listOfSharpies.AddSharpie(new Sharpie("black", 15));





            Console.WriteLine(listOfSharpies.CountUsable());

            Console.ReadLine();
        }
    }
}
