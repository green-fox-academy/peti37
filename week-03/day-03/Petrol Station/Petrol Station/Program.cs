using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Petrol_Station
{
    class Program
    {
        static void Main(string[] args)
        {
            Car Volvo = new Car();
            Station MolGas = new Station();

            Volvo.UseCar();
            Volvo.UseCar();

            MolGas.Refill(Volvo);

            Volvo.UseCar();
            Volvo.UseCar();
            Volvo.UseCar();

            Console.ReadLine();
        }
    }
}
