using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace Wanderer
{
    class Characters
    {

        private List<Character> characters = new List<Character>();

        public void AddToList(Character character)
        {
            characters.Add(character);
        }

        public void RemoveFromList(Character character)
        {
            characters.Remove(character);
        }

        public List<Character> GetList()
        {
            return characters;
        }

        public bool HeroIsOnMonster(Hero hero)
        {
            for (int i = 0; i < GetList().Count; i++)
            {
                if (GetList()[i].GetPosition(GetList()[i].PosX, GetList()[i].PosY) == hero.GetPosition(hero.PosX, hero.PosY))
                {
                    return true;
                }
            }
            return false;
        }

        public void Occupied(Canvas canvas, Character character)
        {
            Random randi = new Random();
            foreach (var chari in characters)
            {
                while (chari.PosX == character.PosX && chari.PosY == character.PosY && chari != character)
                {
                    character.Move(canvas, randi.Next(1, 5));
                }
            }
        }

        public void DrawAllMonsters(Canvas canvas)
        {
            foreach (var monster in characters)
            {
                monster.DrawMonster(canvas);
            }
        }

        public void MoveMonsters(Canvas canvas, Hero hero)
        {
            Random rnd = new Random();
            if (hero.stepCounter % 2 == 0)
            {
                foreach (var monster in characters)
                {
                    monster.Move(canvas, rnd.Next(1, 5));
                }
            }
            foreach (var monster in characters)
            {
                FoxDraw foxDraw = new FoxDraw(canvas);
                foxDraw.AddImage("img/skeleton.png", monster.PosX, monster.PosY);
            }
           
        }
    }
}
