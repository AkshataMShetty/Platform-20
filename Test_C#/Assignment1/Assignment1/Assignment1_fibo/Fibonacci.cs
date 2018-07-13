using System;
using ValidateLib;

namespace Assignment1_fibo
{
	public static class Fibonacci
	{
		#region Methods

		/// <summary>
		/// Reads the input.
		/// </summary>
		/// <returns>The input.</returns>
		public static int ReadInput ()
		{
		int num;

			do {
			Console.Write ("Nth series ? :");
			}while(Validation.PositiveValidate(num = int.Parse ((Console.ReadLine ())))); 

		return num;
		}

		/// <summary>
		/// Display the specified num.
		/// </summary>
		/// <param name="num">Number.</param>
		public static void Display (int num)
		{
			Console.WriteLine ("Nth fibonacci number : " + num);
		}

		/// <summary>
		/// Fibonacci the specified num.
		/// </summary>
		/// <param name="num">Number.</param>
		static public int Fibonacci_Calc (int num) {
			if (num == 0) {
				return 0;
			}
			else if(num == 1) {
				return 1;
			}
			else {
				return Fibonacci_Calc (num - 1) + Fibonacci_Calc (num - 2);
			}
		}
		#endregion


	}
}
