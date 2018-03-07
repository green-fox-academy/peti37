using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model_stringed_instruments
{
    class BassGuitar : StringedInstrument
    {
        public BassGuitar() : base(4)
        {
            name = "Bass Guitar";
        }

        public BassGuitar(int numberOfStrings) : base(numberOfStrings)
        {
            name = "Bass Guitar";
            this.numberOfStrings = base.numberOfStrings;
        }

        public override void Play()
        {
            Console.WriteLine($"{name}, a {numberOfStrings}-stringed instrument that {Sound()}");
        }

        public override string Sound()
        {
            return "Duum-duum-duum";
        }
    }
}
