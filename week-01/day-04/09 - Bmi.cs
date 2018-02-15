using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            // Print the Body mass index (BMI) based on these values
            double massInKg = 81.2;
            double heightInM = 1.78;
            double square = heightInM * heightInM;

            Console.WriteLine(massInKg / square);
            Console.ReadLine();

        }
    }
}
