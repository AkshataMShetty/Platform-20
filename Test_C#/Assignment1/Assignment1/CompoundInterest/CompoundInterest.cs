using System;
using ValidateLib;

namespace Assignment1_CI
{
	public class CompoundInterest
	{
		#region DataMember
		int year;
		double end_Of_Year;
		double target_Amount;
		double principal;
		double interest;
		#endregion



		#region Constructor
		/// <summary>
		/// Initializes a new instance of the <see cref="Assignment1_CI.CompoundInterest"/> class.
		/// </summary>
		public CompoundInterest ()
		{
			Year = 1;
			End_Of_Year = 0.0;
		}

		#endregion

		public double End_Of_Year {
			get {
				return end_Of_Year;
			}
			set {
				end_Of_Year = value;
			}
		}



		public double Principal {
			get {
				return principal;
			}
			set {
				principal = value;
			}
		}

		public double Interest {
			get {
				return interest;
			}
			set {
				interest = value;
			}
		}

		public double Target_Amount {
			get {
				return target_Amount;
			}
			set {
				target_Amount = value;
			}
		}

		public int Year {
			get {
				return year;
			}
			set {
				year = value;
			}
		}

		#region Method

		/// <summary>
		/// Validation this instance.
		/// </summary>
		bool TargetAmt_Validation ()
		{
			if (Target_Amount < Principal) {
				Console.WriteLine ("***Target Amount Should be greater than Principal amount*****");
				return true;
			}
			return false;
		}



		/// <summary>
		/// Reads the input.
		/// </summary>
		public void ReadInput () {
			Console.WriteLine ("Enter the values for :");

			do {
			Console.Write ("Pricipal :");
			Principal = double.Parse(Console.ReadLine ());
			}while(Validation.PositiveValidate (Principal)); 

			do {
			Console.Write ("\nRate of Interest :");
			Interest = (double.Parse(Console.ReadLine ()));
			}while(Validation.PositiveValidate (Interest) || Validation.EqualToZero(Interest) 
				|| Validation.RangeValidation (Interest , 0 , 100));

			do {
			Console.Write ("\nTarget_Amount :");
			Target_Amount = double.Parse(Console.ReadLine ());
			}while(Validation.PositiveValidate (Target_Amount) || (TargetAmt_Validation ()));

		}

		/// <summary>
		/// Calculate this instance.
		/// </summary>
		public void Calculate () {

			double Actual_Interest = 0.0;
			Interest = Interest / 100;

			for ( ; End_Of_Year < Target_Amount ; Year++) {
				Actual_Interest = Principal * Interest;
				End_Of_Year = Principal = Principal + Actual_Interest;
			}
			Display ();
		}

		/// <summary>
		/// Display this instance.
		/// </summary>
		void Display ()
		{
			Console.WriteLine ("Principal :" + Principal + "\n" +"Interest :" + Interest + "\n" +"End of year : " + End_Of_Year);
			Console.WriteLine ("Target is acheived after " + this.year + " " + "long years");
		}

	#endregion

	}
}