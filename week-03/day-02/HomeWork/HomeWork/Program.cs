using System;
using System.Collections.Generic;

namespace HomeWork
{
    class Program
    {
        static void Main(string[] args)
        {
            var map = new List<Dictionary<string, object>>();

            var tree1 = new Dictionary<string, object>();
            tree1.Add("type", "American Beech");
            tree1.Add("leaf color", "dull green");
            tree1.Add("age", 15);
            tree1.Add("sex", "male");
            map.Add(tree1);

            var tree2 = new Dictionary<string, object>();
            tree2.Add("type", "Black Oak");
            tree2.Add("leaf color", "dark green");
            tree2.Add("age", 30);
            tree2.Add("sex", "female");
            map.Add(tree2);

            var tree3 = new Dictionary<string, object>();
            tree3.Add("type", "Sycamore");
            tree3.Add("leaf color", "brigth green");
            tree3.Add("age", 56);
            tree3.Add("sex", "male");
            map.Add(tree3);

            var tree4 = new Dictionary<string, object>();
            tree4.Add("type", "Red Spruce");
            tree4.Add("leaf color", "yellowish green");
            tree4.Add("age", 29);
            tree4.Add("sex", "female");
            map.Add(tree4);

            var tree5 = new Dictionary<string, object>();
            tree5.Add("type", "Sugar Maple");
            tree5.Add("leaf color", "dark green");
            tree5.Add("age", 86);
            tree5.Add("sex", "male");
            map.Add(tree5);
        }
    }
}
