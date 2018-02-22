using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Please type in the expression:" ); 
            string input = Console.ReadLine();
            var inputList = new List<string>();
            inputList  = input.Split(' ').ToList();

            int firstNumber;
            int secondNumber;
            int.TryParse(inputList[1], out firstNumber);
            int.TryParse(inputList[2], out secondNumber);

            if (inputList[0] == "+")
            {

                Console.WriteLine(firstNumber + secondNumber);
            }
            if (inputList[0] == "-")
            {

                Console.WriteLine(firstNumber - secondNumber);
            }
            if (inputList[0] == "*")
            {

                Console.WriteLine(firstNumber * secondNumber);
            }
            if (inputList[0] == "/")
            {

                Console.WriteLine(firstNumber / secondNumber);
            }
            if (inputList[0] == "%")
            {

                Console.WriteLine(firstNumber % secondNumber);
            }
            Console.ReadLine();
        }
    }
}