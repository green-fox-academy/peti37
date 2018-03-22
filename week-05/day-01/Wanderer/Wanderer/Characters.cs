using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace Wanderer
{
    public static class Characters
    {

        private static List<Character> characters = new List<Character>();

        public static void AddToList(Character character)
        {
            characters.Add(character);
        }

        public static List<Character> GetList()
        {
            return characters;
        }

        public static void Occupied(Canvas canvas, Character character)
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

        public static void DrawAllMonsters(Canvas canvas)
        {
            foreach (var monster in characters)
            {
                
                monster.DrawMonster(canvas);
            }

        }

        public static void MoveMonsters(Canvas canvas)
        {
            Hero hero = new Hero();
            Random rnd = new Random();
            if (hero.keyToggleCounter % 2 == 0)
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
