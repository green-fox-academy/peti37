using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals_in_the_Zoo
{
    class Program
    {
        static void Main(string[] args)
        {
            Mammal kecske = new Mammal("Kecske");
            Console.WriteLine(kecske.GetName()); 
            kecske.Greet();

            Console.ReadLine();
        }
    }
}
