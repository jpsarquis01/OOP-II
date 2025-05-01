using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    class Cash(int id, float money) : PaymentMethod(id, money)
    {
        public override void ProcessPayment()
        {
            float userImput;
            bool cashGiven = false;
            Console.WriteLine("Please enter how much cash you giving");
            userImput = float.Parse(Console.ReadLine());

            while (cashGiven != true)
            {
                if (userImput >= money)
                {
                    Console.WriteLine("You have given too much cash");
                    Console.WriteLine($"Your change is {userImput - money}");
                    cashGiven = true;
                }
                else
                {
                    Console.WriteLine("PayUp loser");
                }
            }
         
        }
    }
}
