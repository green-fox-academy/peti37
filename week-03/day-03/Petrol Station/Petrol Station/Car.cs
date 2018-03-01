using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Petrol_Station
{
    public class Car
    {
        public int CapacityCar;
        public int gasAmountCar;

        public Car()
        {
            CapacityCar = 100;
            gasAmountCar = 0;
            
        }
        public void FullCar()
        {
            
            Console.WriteLine("Your car's gas tank is full");
            gasAmountCar = 100;
            Console.WriteLine($"Gas amount of the car:{gasAmountCar}\n");
            
        }
        public void UseCar()
        {
            
            if (gasAmountCar <= 0)
            {
                gasAmountCar = 0;
                Console.WriteLine("You need to refill!");
            }
            else
            {
                gasAmountCar -= 50;
                Console.WriteLine($"You went 50kms with your car.\n Your car's gas amount is {gasAmountCar}.\n");
                if (gasAmountCar == 0)
                {
                    Console.WriteLine("You should refill at a gas station.");
                }
            }
        }
            
        
    }
}
