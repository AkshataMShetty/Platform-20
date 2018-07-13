using System;
using ValidateLib;

namespace Assignment1_CreditCard
{
	public class Credit_Calc
	{
		#region DataMembers
		static int month;
		double owned_Amt;
		double rateOfInterest;
		double payment;
		#endregion

		#region Property
		public double Owned_Amt {
			get {
				return owned_Amt;
			}
			set {
				owned_Amt = value;
			}
		}

		public double RateOfInterest {
			get {
				return rateOfInterest;
			}
			set {
				rateOfInterest = value;
			}
		}

		public static int Month {
			get {
				return month;
			}
			set {
				month = value;
			}
		}

		public double Payment {
			get {
				return payment;
			}
			set {
				payment = value;
			}
		}
		#endregion

		#region Methods
		public void ReadInput ()
		{
			Console.WriteLine ("Enter values :");

			do {
			Console.Write ("Owned Amt :");
			Owned_Amt = (double.Parse(Console.ReadLine ()));
			}while(Validation.PositiveValidate(Owned_Amt));

			do {
			Console.Write ("Rate of Interest:");
			RateOfInterest = (double.Parse(Console.ReadLine ()));
			}while(Validation.PositiveValidate(RateOfInterest) ||
			       Validation.RangeValidation (RateOfInterest , 0 , 100));

			do {
			Console.Write ("Monthly Payment :");
			Payment = (double.Parse(Console.ReadLine ()));
			}while (Validation.PositiveValidate(Payment));
		}

		public void Calculation() {
			RateOfInterest /= 100; 
			Owned_Amt = Owned_Amt + (Owned_Amt * RateOfInterest);

			Console.WriteLine ("Balance sheet :");
			while (Owned_Amt > Payment) {
				Owned_Amt = Owned_Amt - Payment;
				Owned_Amt = Owned_Amt + (Owned_Amt * RateOfInterest);
				Display ();
			}

			Owned_Amt = Payment - Owned_Amt;
			Display ();
		}

		void Display ()
		{
			Console.WriteLine ("Month :" + Month + "Balance :" + Owned_Amt + "Total Payments" + (Month * Payment));
		}
		#endregion
	}
}

