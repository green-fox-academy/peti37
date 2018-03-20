using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Wanderer
{
    class CharacterList
    {
        List<Character> characters;

        public CharacterList()
        {
            characters = new List<Character>();
        }
        public void AddHero(Hero hero)
        {
            characters.Add(hero);
        }
        public void AddMonster(Monster monster)
        {
            characters.Add(monster);
        }
        public void AddBoss(Boss boss)
        {
            characters.Add(boss);
        }
        public void SamePoz(Boss boss, Monster monster)
        {
           
        }
    }
}