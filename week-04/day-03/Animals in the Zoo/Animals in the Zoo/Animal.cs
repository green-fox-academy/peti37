using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals_in_the_Zoo
{
    abstract class Animal
    {

        protected string name;
        public int age;
        public int legs;
        public string gender;

        public Animal(string name)
        {
            this.name = name;
        }

        public abstract void Greet();

        public abstract string WantChild();

        public abstract string GetName();

    }
}
