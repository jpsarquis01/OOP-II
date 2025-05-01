using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    public interface IShoppingCart
    {
        public void RemoveProduct();
        public void CalcTotalPrice();
        public void CheckOut();



    }
}
