using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Garden_Application
{
    class Garden
    {
        List<Plant> plants;

        public Garden()
        {
            
            plants = new List<Plant>();
        }


        public void AddTree(Tree tree)
        {
            plants.Add(tree);
        }

        public void AddFlower(Flower flower)
        {
            plants.Add(flower);
        }

        public List<Plant> ThirstyPlants()
        {
            List<Plant> locsi = new List<Plant>();
            foreach (Plant plant in plants)
            {
                if (plant.waterAmount < plant.waterLevel)
                {
                    locsi.Add(plant);
                }
                else
                {
                    locsi.Remove(plant);
                }
            }
            return locsi;
        }

        public void Water(double amountOfWater)
        {
            Console.WriteLine("Watering with " + amountOfWater);

            foreach (Plant plant in plants)
            {
                if (plant.ReadyForWatering() == true)
                {
                    plant.waterAmount += amountOfWater / ThirstyPlants().Count * plant.absorbLevel;
                }
            }
        }

        public void CheckPlants()
        {
            foreach (var plant in plants)
            {
                if (plant.waterAmount < plant.waterLevel)
                {
                    Console.WriteLine($"The {plant.color} {plant.name} needs water");
                }
                else
                {
                    Console.WriteLine($"The {plant.color} {plant.name} doesn't need water");
                }
            }
        }
    }
}
