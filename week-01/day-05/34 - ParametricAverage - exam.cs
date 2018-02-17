using System;

namespace GreenFox
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            {
                int HowManyNumbers;
                double Summed = 0;
                double Avarage;

                Console.WriteLine("Please enter how many numbers would like to work with: ");
                HowManyNumbers = int.Parse(Console.ReadLine());


                for (int i = 1; i <= HowManyNumbers; i++)
                {
                    Console.WriteLine(i + ". number: ");
                    Summed = double.Parse(Console.ReadLine()) + Summed;
                }
                Avarage = Summed / HowManyNumbers;
                Console.WriteLine("Sum: " + Summed + ", " + "Avarage: " + Avarage + ",");
                Console.ReadLine();
            }
        }
    }
}
