using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
   public class Clothing : Product
    {
        private string _material;
        private string _color;
        private float _size;

        public Clothing(string material, string color, float size)
        {
            _material = material;
            _color = color;
            _size = size;
        }

        public override void DisplayInfo()
        {
            Console.WriteLine("---------------------------");
            Console.WriteLine($"Material: {_material}");
            Console.WriteLine($"Color: {_color}");
            Console.WriteLine($"Size: {_size}");
            Console.WriteLine("---------------------------");
        }

        public string IsAvailableInColor(string color)
        {
            if (string.Equals(color, _color, StringComparison.OrdinalIgnoreCase))   // ignores if its lower case or upper case
            {
                return "true";
            }
            else
            {
                return "false";
            }
        }
    }
}
