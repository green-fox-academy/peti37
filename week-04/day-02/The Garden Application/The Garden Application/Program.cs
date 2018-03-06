using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Program
    {
        static void Main(string[] args)
        {
            var myGarden = new Garden();
            myGarden.AddTree(new Tree("purple"));
            myGarden.AddTree(new Tree("orange"));
            myGarden.AddFlower(new Flower("yellow"));
            myGarden.AddFlower(new Flower("blue"));

            myGarden.CheckPlants();
            myGarden.Water(40);
            myGarden.CheckPlants();
            myGarden.Water(70);
            myGarden.CheckPlants();



            Console.ReadLine();
        }
    }
}
