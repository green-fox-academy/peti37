using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals_in_the_Zoo
{
    class Mammal : Animal
    {
        public Mammal(string name) :base("")
        {
            this.name = name;
        }

        public override string GetName()
        {
            return name;
        }

        public override void Greet()
        {
            Console.WriteLine("Kah-Kaah!");
        }

        public override void Pair()
        {
            throw new NotImplementedException();
        }

        public override void WantChild()
        {
            throw new NotImplementedException();
        }
    }
}
