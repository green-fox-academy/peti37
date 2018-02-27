using System;
using System.IO;

namespace Tic_Tac_Toe
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Results("win-x.txt"));
            Console.WriteLine(Results("win-o.txt"));
            Console.WriteLine(Results("draw.txt"));



            Console.ReadLine();
        }

        private static string Results(string fileName)
        {
            string[] content = File.ReadAllLines(fileName);
            try
            {
                if (content[0][0] == content[1][0] && content[0][0] == content[2][0] || 
                    content[0][0] == content[1][1] && content[0][0] == content[2][2])
                {
                    string result = content[0][0].ToString();
                    return result;
                }
                else
                {
                    return "draw";
                }
            }
            catch (Exception)
            {
                return "Something went wrong, ask Peti for help!";
            }

        }
    }
}
