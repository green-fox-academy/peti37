using System;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {
            // Define several things as a variable then print their values
            // Your name as a string
            // Your age as an integer
            // Your height in meters as a double
            // Whether you are married or not as a boolean
            String name = "Peter";
            int age = 25;
            Double height = 1.89;
            Boolean married = false;

            Console.WriteLine("Name: {0}, age: {1}, Height: {2}, Married: {3}", name, age, height, married);
            Console.ReadLine();
        }
    }
}