using System;

namespace Dice
{
    public class Dice
    {
        //    You have a Dice class which has 6 dice
        //    You can roll all of them with Roll()
        //    Check the current rolled numbers with GetCurrent()
        //    You can reroll with Reroll()
        //    Your task is to get where all dice is a 6
        static Random RandomValue;
        static int[] Dices = new int[6];

        public int[] Roll()
        {
            for (int i = 0; i < Dices.Length; i++)
            {
                Dices[i] = RandomValue.Next(1, 7);
            }
            return Dices;
        }

        public int[] GetCurrent()
        {
            return Dices;
        }

        public int GetCurrent(int i)
        {
            return Dices[i];
        }

        public void Reroll()
        {
            for (int i = 0; i < Dices.Length; i++)
            {
                Dices[i] = RandomValue.Next(1, 7);
            }
        }

        public void Reroll(int k)
        {
            Dices[k] = new Random().Next(1, 7);
        }

        public static void Main(string[] args)
        {
            RandomValue = new Random();
            Dice myDice = new Dice();
            int counter = 0;

            myDice.Roll();
            for (int i = 0; i < Dices.Length; i++)
            {
                while (myDice.GetCurrent(i) != 6)
                {
                    myDice.Reroll(i);
                    counter++;
                }
            }

            Console.WriteLine("Results are:");
            for (int i = 0; i < Dices.Length; i++)
            {
                Console.WriteLine(myDice.GetCurrent(i));
            }
            Console.WriteLine("and its dropped for the " + counter + ". times");
            Console.ReadLine();
            //myDice.GetCurrent();
            //myDice.Roll();
            //myDice.GetCurrent();
            //myDice.GetCurrent(5);
            //myDice.Reroll();
            //myDice.GetCurrent();
            //myDice.Reroll(4);
            //myDice.GetCurrent();
        }
    }
}