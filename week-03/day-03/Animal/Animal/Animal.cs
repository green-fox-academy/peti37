using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animal
{
    public class Animal
    {
        int hunger;
        int thirst;
        

        public Animal(int hunger = 50, int thirst = 50)
        {
            this.hunger = hunger;
            this.thirst = thirst;

        }
        public void eat()
        {
            hunger--;
            Console.WriteLine("The animal just ate something, hunger is: " + hunger);
        }
        public void drink()
        {
            thirst--;
            Console.WriteLine("The animal just drank a bit, thirst is: " + thirst);
        }
        public void play()
        {
            thirst++;
            hunger++;
            Console.WriteLine($"The animal just played a bit, hunger and thirst are: {hunger}, {thirst}");
        }

    }
}