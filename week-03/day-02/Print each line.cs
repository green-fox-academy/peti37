using System;
using System.IO;

namespace Divide_by_zero
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"my-file.txt";
            try
            {
                string[] content = File.ReadAllLines(path);
                foreach (var cont in content)
                {
                    Console.WriteLine(cont);

                }
            }
            catch (Exception)
            {
                Console.WriteLine("Unable to read file: my-file.txt");
            }

            Console.ReadLine();

        }
    }
}
