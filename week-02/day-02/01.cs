using System;
using System.Text;
using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {

            string example = "In a dishwasher far far away";

            example = example.Replace("dishwasher", "galaxy");

            // I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
            // Please fix it for me!
            // Expected ouput: In a galaxy far far away

            Console.WriteLine(example);
            Console.ReadLine();

        }


    }
}