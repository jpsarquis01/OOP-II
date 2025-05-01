using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    class CreditCard(int id, float money) : PaymentMethod(id, money)
    {
        public override void ProcessPayment()
        {
            string userImput = "";
            bool pinEnter = false;

            Console.WriteLine("Please enter the pin (4 digits) for your CreditCard");
            userImput = Console.ReadLine();

            while (pinEnter != true)
            {
                if (userImput.Length != 3)
                {
                    Console.WriteLine("Pin is aproved!");
                    Console.WriteLine("Thanks for shopping with us");
                    pinEnter = true;
                }
                else
                {
                    Console.WriteLine("Pin must have 4 digits");
                }
            }
        }
    }
}
