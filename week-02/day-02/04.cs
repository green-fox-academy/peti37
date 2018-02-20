using System;
using System.Text;
using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {

            
            StringBuilder todoText = new StringBuilder();
            todoText.Append("My todo:\n");
            todoText.Append("\t- Buy milk\n");
            todoText.Append("\t- Download games\n");
            todoText.Append("\t\t- Diablo");

            // Add "My todo:" to the beginning of the todoText
            // Add " - Download games" to the end of the todoText
            // Add " - Diablo" to the end of the todoText but with indention

            // Expected output:

            // My todo:
            //  - Buy milk
            //  - Download games
            //      - Diablo

            Console.WriteLine(todoText);
            Console.ReadLine();

        }


    }
}