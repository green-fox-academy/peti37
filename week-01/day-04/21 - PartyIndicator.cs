using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("How many girls are coming?");
            string input = Console.ReadLine();
            Console.WriteLine("How many boys are coming?");
            string input2 = Console.ReadLine();
            int number;
            int number2;
            Int32.TryParse(input, out number);
            Int32.TryParse(input2, out number2);


            if (number == number2 && number + number2 > 20)
            {
                Console.WriteLine("The party is exellent!");
            }
            else if (number != number2 && number + number2 > 20)
            {
                Console.WriteLine("Quite cool party!");
            }
            else if (number + number2 < 20 && number != 0)
            {
                Console.WriteLine("Avarage party...");
            }
            if (number == 0)
            {
                Console.WriteLine("Sausage party");
            }
            Console.ReadLine();


        }
    }
}