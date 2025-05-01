using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    public class Product
    {
        private string _productName;
        private float _price;
        private float _discount;
        private string _description;

        public void CalculateTax()
        {
            float tax = _price * 0.15f;
            Console.WriteLine($"Tax on {_productName} is: {tax}");
        }

        public float GetPrice()
        {
            if (_discount > 0)
            {
                float discountAmount = _price * (_discount / 100);
                float finalPrice = _price - discountAmount;
                Console.WriteLine($"Final price after discount is: {finalPrice}");
                return finalPrice;
            }
            else
            {
                Console.WriteLine($"No discount applied. Price is: {_price}");
                return _price;
            }
           
        }

        public virtual void DisplayInfo()
        {
            Console.WriteLine("---------------------------");
            Console.WriteLine($"Product Name: {_productName}");
            Console.WriteLine($"Price: {_price}");
            Console.WriteLine($"Discount: {_discount}%");
            Console.WriteLine($"Description: {_description}");
            Console.WriteLine("---------------------------");
        }
    }
}
