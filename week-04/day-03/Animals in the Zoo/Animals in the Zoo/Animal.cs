using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animals_in_the_Zoo
{
    abstract class Animal
    {
       
        protected string name { get; set; }
        protected int age;
        protected int legs;
        protected string gender;

        public Animal(string name)
        {
            this.name = name;
        }

        public abstract void Greet();

        public abstract void WantChild();

        public abstract void Pair();

        public abstract string GetName();

    }
}
