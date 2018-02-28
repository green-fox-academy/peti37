using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharpie
{
    class Program
    {
        static void Main(string[] args)
        {
            Sharpie Capeti = new Sharpie("blue", 100);
            Capeti.Use();
            Capeti.Use();
            Capeti.Use();
            Capeti.Use();
            Capeti.Use();
            Capeti.Use();
            Console.ReadLine();

        }
    }
}
