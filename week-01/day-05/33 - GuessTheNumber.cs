using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("A random number is generated between 1-50. Guess pls:");
            string scan = Console.ReadLine();
            int number;
            int.TryParse(scan, out number);
            Random rnd = new Random();
            int randomNumber = rnd.Next(1, 50);
            while (number != randomNumber)
            {
                if (number > randomNumber)
                {
                    Console.WriteLine("The stored number is lower");

                }
                else if (number < randomNumber)
                {
                    Console.WriteLine("The stored number is higher");

                }
            Console.WriteLine("Give me another number:");
            scan = Console.ReadLine();
            int.TryParse(scan, out number);

            }
            if (number == randomNumber)
            {
                Console.WriteLine("Congratulations!  The generated number was:" + randomNumber);
            }
            Console.ReadLine();

        }
    }
}