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
                using (StreamWriter writer = new StreamWriter(path))
                {
                    writer.WriteLine("Peter Nemeth");
                }
            }
            catch (Exception)
            {
                Console.WriteLine("Unable to write file: my-file.txt");
            }
            string[] content = File.ReadAllLines(path);
            Console.WriteLine(content[0]);
            Console.ReadLine();
        }
    }
}
