using System;
using ValidateLib;

namespace Assignment1_Mileage
{
	public class Mileage
	{
		#region Members
		int mileage_Start;
		int mileage_End;
		int fuel_Start;
		int fuel_End;
		#endregion

		#region Property
		public Mileage ()
		{
		}

		public int Mileage_Start {
			get {
				return mileage_Start;
			}
			set {
				mileage_Start = value;
			}
		}

		public int Fuel_Start {
			get {
				return fuel_Start;
			}
			set {
				fuel_Start = value;
			}
		}

		public int Mileage_End {
			get {
				return mileage_End;
			}
			set {
				mileage_End = value;
			}
		}

		public int Fuel_End {
			get {
				return fuel_End;
			}
			set {
				fuel_End = value;
			}
		}
		#endregion

		#region Methods
		/// <summary>
		/// Reads the input.
		/// </summary>
		public void ReadInput ()
		{
			Console.WriteLine ("Enter the values :");

			do {
				Console.Write ("Fuel Level at the start of the journey :");
				Fuel_Start = int.Parse ((Console.ReadLine ()));
			}while (Validation.EqualToZero(Fuel_Start));

			do {
				Console.Write ("\nFuel Level at the end of the journey :");
				Fuel_End = int.Parse ((Console.ReadLine ()));
			} while (Validation.PositiveValidate(Fuel_End));

			do {
				Console.Write ("\nMileage reading at Start of journey :");
				Mileage_Start = int.Parse ((Console.ReadLine ()));
			} while(Validation.PositiveValidate(Mileage_Start) || Validation.EqualToZero(Mileage_Start));

			do {
				Console.Write ("\nMileage reading at Start of journey :");
				Mileage_End = int.Parse ((Console.ReadLine ()));
			} while (Validation.PositiveValidate(Mileage_End) || Validation.EqualToZero(Mileage_End));		
		}

		/// <summary>
		/// Display this instance.
		/// </summary>
		public void Display ()
		{
			if ((Mileage_End - Mileage_Start) < 10) {
				Console.WriteLine ("Trip too short for ac-curate results");
			} else {
				Console.WriteLine ("Total Fuel used: " + (Fuel_Start - Fuel_End) + "Litres");
				Console.WriteLine ("Distance covered: " + (Mileage_End - Mileage_Start) + "Km");
				Console.WriteLine ("Mileage / Liter: " + (double)(Mileage_End - Mileage_Start) / (double)(Fuel_Start - Fuel_End));
			}
		}
		#endregion
	}
}

