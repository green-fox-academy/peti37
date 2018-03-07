using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model_stringed_instruments
{
    class Violin : StringedInstrument
    {
        public Violin() : base(4)
        {
            name = "Violin";
        }
        public override void Play()
        {
            Console.WriteLine($"{name}, a {numberOfStrings}-stringed instrument that {Sound()}");
        }

        public override string Sound()
        {
            return "Screech";
        }
    }
}
