using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model_stringed_instruments
{
    abstract class Instrument
    {
        public string name;
        abstract public void Play();
    }
}
