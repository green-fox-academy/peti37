using System;
using System.Collections.Generic;

namespace FleetOfThings
{
    public class FleetOfThings
    {
        public static void Main(string[] args)
        {
            var fleet = new Fleet();
            fleet.Add( new Thing("Get milk"));
            fleet.Add(new Thing("Remove the obstacles"));
            fleet.Add(new Thing("Stand up"));
            fleet.Add(new Thing("Eat lunch"));
            fleet.Add(new Thing("Done with this task"));

            fleet.List()[2].Complete();
            fleet.List()[3].Complete();
            fleet.List()[4].Complete();


            Nyomtass(fleet.List());
            Console.ReadLine();

            // Create a fleet of things to have this output:
            // 1. [ ] Get milk
            // 2. [ ] Remove the obstacles
            // 3. [x] Stand up
            // 4. [x] Eat lunch
            // Hint: You have to create a Print method also
        }

        public static void Nyomtass(List<Thing> Lista)
        {
            foreach (var item in Lista)
            {
                if (item.PublicComplete())
                {
                    Console.WriteLine("[x]" + item.PublicName());
                }
                else
                {
                    Console.WriteLine("[ ]" + item.PublicName());
                }
            }
        }
    }
}