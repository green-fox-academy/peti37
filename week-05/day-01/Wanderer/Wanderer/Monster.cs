using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Input;

namespace Wanderer
{
    class Monster : Character
    {
        public override void Move(object sender, KeyEventArgs e, Canvas canvas)
        {
            Hero hero = new Hero();
            Skeleton skeleton = new Skeleton();
            Map map = new Map();

            int skeletonPosX = 0;
            int skeletonPosY = 0;

            if (hero.keyToggleCounter % 2 == 0 && map.content[skeletonPosY + 1][skeletonPosX] == '0')
            {
                skeletonPosY++;
                skeleton.PosY += 50;
                skeleton.DrawSkeleton(canvas);
            }
            if (hero.keyToggleCounter % 2 == 1 || hero.keyToggleCounter % 2 == 0)
            {
                skeleton.DrawSkeleton(canvas);
            }
        }
    }
}
