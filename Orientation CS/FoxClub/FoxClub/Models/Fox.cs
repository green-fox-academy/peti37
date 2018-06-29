using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace FoxClub.Models
{
    public class Fox
    {
        public string name { get; set; }
        public string food { get; set; }
        public string drink { get; set; }
        public List<string> Pictures = new List<string> { "https://cdn.dribbble.com/users/580699/screenshots/2766009/eevee.gif", "http://i0.kym-cdn.com/photos/images/original/001/110/864/4fc.gif", "https://media.giphy.com/media/tFmXVU7ibsb28/200.gif", "https://zippy.gfycat.com/HandsomeCompleteBoilweevil.gif", "https://synergyroleplay.com/uploads/monthly_2018_01/Eevee_877608_6213300.gif.edaa1a919c4cf01a21c493f4294f3c91.gif" };
        public List<string> Foods = new List<string>();
        public List<string> Drinks = new List<string>();
        public List<string> Tricks = new List<string>();
        public List<string> KnownTricks = new List<string>();

        public void GetName(string name)
        {
            this.name = name;
        }

        public void AddFood(string food)
        {
            Foods.Add(food);
        }

        public void AddDrink(string drink)
        {
            Drinks.Add(drink);
        }

        public void BasicFoods()
        {
            Foods.Add("kolbasz");
            Foods.Add("vajaskenyér");
        }

        public void BasicDrinks()
        {
            Drinks.Add("Limonádé");
            Drinks.Add("Szörp");
        }

        public void TricksToLearn()
        {
            KnownTricks.Add("Semmit");
            KnownTricks.Add("Tigris ugrani");
            KnownTricks.Add("Kacsint");
            KnownTricks.Add("Kacsává változni");
            KnownTricks.Add("Aludni");
        }

    }
}
