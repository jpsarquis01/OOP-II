using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assigment3
{
    public abstract class PaymentMethod(int id, float money)
    {
        private int _paymentId = id;
        private float _paymentAmount = money;

        public abstract void ProcessPayment();
    }
}
