using System;
using System.IO;

namespace Count_lines
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"my-file.txt";
            LineCounter(path);


            Console.ReadLine();

        }

        private static void LineCounter(string path)
        {
            try
            {
                string[] content = File.ReadAllLines(path);
                Console.WriteLine(content.Length);
            }
            catch (Exception)
            {
                Console.WriteLine("0");
            }
        }
    }
}
