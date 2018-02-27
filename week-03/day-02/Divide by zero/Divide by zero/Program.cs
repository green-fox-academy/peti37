using System;
using System.IO;

namespace Divide_by_zero
{
    class Program
    {
        public static void Main(string[] args)
        {
            int divisor = int.Parse(Console.ReadLine());
            Divider(divisor);
            
        }

        private static void Divider(int divisor)
        {
            try  
            {
                
                int result = 10 / divisor;
                Console.WriteLine(result);
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine("Fail");
            }
            catch (Exception e)
            {
                Console.WriteLine("uuups, some serious thing happened!");
            }
            finally
            {
                Console.ReadLine();
            }
        }
    }
}
