using System;
using System.Text;
using System.Collections.Generic;

namespace GreenFox
{
    class Program
    {
        static void Main(string[] args)
        {


            var planetList = new List<string> { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Uranus", "Neptune" };


            // Saturn is missing from the planetList
            // Insert it into the correct position
            // Create a method called PutSaturn() which has list parameter and returns the correct list.

            // Console.WriteLine(PutSaturn(planetList));
            foreach (var item in PutSaturn(planetList))
            {
                Console.Write(item);
            }
            Console.ReadLine();
        }
        public static List<string> PutSaturn(List<string> planets)
        {

            planets.Add("Saturn");
            return planets;

        }
    }
}