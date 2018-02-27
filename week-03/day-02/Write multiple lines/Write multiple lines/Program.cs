using System;
using System.IO;

namespace Write_Multiple_Lines
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"my-file.txt";
            string word = "apple";
            int number = 15;
            MultipleLines(path, word, number);



            Console.ReadLine();
        }
        private static void MultipleLines(string path, string word, int number)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(path))
                {
                    for (int i = 0; i < number; i++)
                    {
                        writer.WriteLine(word);
                    }
                }
            }
            catch (Exception)
            {

            }
            string[] content = File.ReadAllLines(path);
            foreach (var cont in content)
            {
                Console.WriteLine(cont);
            }
        }
    }
}
