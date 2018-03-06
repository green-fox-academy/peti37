using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Program
    {
        static void Main(string[] args)
        {
            var myGarden = new Garden();
            var violet = new Flower() { color = "red" };
            var appleTree = new Tree() { color = "yellow" };

            Console.ReadLine();
        }
    }
}
