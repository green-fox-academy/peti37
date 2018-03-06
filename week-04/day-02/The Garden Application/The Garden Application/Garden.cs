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
            foreach (Flower flower in plants)
            {
                if (flower.waterAmount < 5)
                {
                    locsi.Add(flower);
                }
                else if (flower.waterAmount >= 5)
                {
                    locsi.Remove(flower);
                }
            }
            foreach (Tree tree in plants)
            {
                if (tree.waterAmount < 5)
                {
                    locsi.Add(tree);
                }
                else if (tree.waterAmount >= 5)
                {
                    locsi.Remove(tree);
                }
            }
            return locsi;
        }

        public void Water(double amountOfWater)
        {
            foreach (Plant plant in plants)
            {
                if (plant.ReadyForWatering() == true)
                {
                    plant.waterAmount += amountOfWater / ThirstyPlants().Count * plant.absorbLevel;
                }
            }
        }
    }
}
