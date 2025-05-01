using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    public class PayPal (int id, float money) : PaymentMethod (id, money)
    {
      public override void ProcessPayment()
        {
            string userImput;
            bool signedIn = false;

            Console.WriteLine("Please enter your PayPal email address:");
            userImput = Console.ReadLine();

            while (signedIn != true)
            {
                if (userImput.Contains("@gmail.com"))
                {
                    Console.WriteLine("Please enter your password");
                    userImput = Console.ReadLine();
                    signedIn = true;
                }
                else
                {
                    Console.WriteLine("Enter a valid email");
                }
            }
        
            Console.WriteLine("Processing payment through PayPal...");
            Console.WriteLine($"Thanks for you purchase!");
        }
    }
   
}
