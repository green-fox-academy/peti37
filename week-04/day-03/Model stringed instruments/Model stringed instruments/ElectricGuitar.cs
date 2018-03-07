using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model_stringed_instruments
{
    class ElectricGuitar : StringedInstrument
    {
        public ElectricGuitar() : base(6)
        {
            name = "Electric Guitar";
        }
        public ElectricGuitar(int numberOfStrings) : base(numberOfStrings)
        {
            name = "Electric Guitar";
            this.numberOfStrings = base.numberOfStrings;
        }

        public override void Play()
        {
            Console.WriteLine($"{name}, a {numberOfStrings}-stringed instrument that {Sound()}");
        }

        public override string Sound()
        {
            return "Twang";
        }
    }
}
