using System;
using System.IO;

namespace Copy_file
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"my-file.txt";
            string pathAnotherfile = @"anotherfile.txt";

            Console.WriteLine(FileCopier(path, pathAnotherfile));

            Console.ReadLine();
        }
        private static bool FileCopier(string path, string path2)
        {
            string[] content = File.ReadAllLines(path);
            try
            {
                using (StreamWriter writer = new StreamWriter(path2))
                {
                    for (int i = 0; i < content.Length; i++)
                    {
                        writer.WriteLine(content[i]);
                    }
                }
            }
            catch (Exception)
            {
                return false;
            }
            return true;
        }
    }
}
