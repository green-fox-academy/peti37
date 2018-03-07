using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model_stringed_instruments
{
    abstract class StringedInstrument : Instrument
    {
        public int numberOfStrings;

        public StringedInstrument(int numberOfStrings)
        {
            this.numberOfStrings = numberOfStrings;
        }
        public abstract string Sound();

    }
}
