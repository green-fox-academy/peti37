using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Petrol_Station
{
    public class Station
    {
        public int gasAmount = 500;

        public void Refill(Car car)
        {
            car.gasAmountCar += 100;
            gasAmount -= car.CapacityCar;
            Console.WriteLine($"You refilled your car\n Station's gas amount:{gasAmount}\n Car's gas amount:{car.gasAmountCar}\n");
            car.FullCar();

        }
    }
}
