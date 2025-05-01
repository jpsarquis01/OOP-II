using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    public class Electronics : Product
    {
        private string _brand;
        private string _model;
        private float _warrantyPeriod;

        public Electronics(string brand, string model, float warrantyPeriod)
        {
            _brand = brand;
            _model = model;
            _warrantyPeriod = warrantyPeriod;
        }

        public override void DisplayInfo()
        {
            Console.WriteLine("---------------------------");
            Console.WriteLine($"Brand: {_brand}");
            Console.WriteLine($"Model: {_model}");
            Console.WriteLine($"Warranty Period: {_warrantyPeriod} months");
            Console.WriteLine("---------------------------");
        }

        public void IsWarantyValid(float years)
        {
            bool isValid = years <= _warrantyPeriod;
            if (isValid)
            {
                Console.WriteLine($"Warranty is check: {isValid}.");
                Console.WriteLine($"Warranty is valid for {_warrantyPeriod - years} years.");
            }
            else
            {
                Console.WriteLine($"Warranty is check: {isValid}.");
            }
        }
    }
}
