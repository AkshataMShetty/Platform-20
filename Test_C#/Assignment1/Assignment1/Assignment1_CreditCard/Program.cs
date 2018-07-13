using System;

namespace Assignment1_CreditCard
{
	class Program
	{
		public static void Main ()
		{
			Credit_Calc cc = new Credit_Calc ();
			cc.ReadInput ();
			cc.Calculation ();
		}
	}
}
