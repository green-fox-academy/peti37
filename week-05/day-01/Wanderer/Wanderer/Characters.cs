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

        public void MoveMonsters(Canvas canvas)
        {
            Random rnd = new Random();
            foreach (var monster in characters)
            {
                monster.Move(canvas, rnd.Next(1, 5));
                FoxDraw foxDraw = new FoxDraw(canvas);
                foxDraw.AddImage("img/skeleton.png", monster.PosX, monster.PosY);
            }
        }

        public void StayMonsters(Canvas canvas)
        {
            foreach (var monster in characters)
            {
                monster.Move(canvas, 0);
                FoxDraw foxDraw = new FoxDraw(canvas);
                foxDraw.AddImage("img/skeleton.png", monster.PosX, monster.PosY);
            }
        }
    }
}
