using System;

namespace ValidateLib
{
	public static class Validation
	{

		#region Method

		/// <summary>
		/// Validate the specified input.
		/// </summary>
		/// <param name="input">Input.</param>
		public static bool PositiveValidate (int input)
		{
			if (input < 0) {
				Console.WriteLine ("Input must be greater than or equal to zero");
				return true;
			}
			return false;
		}

		/// <summary>
		/// Equals to zero.
		/// </summary>
		/// <returns><c>true</c>, if to zero was equaled, <c>false</c> otherwise.</returns>
		/// <param name="input">Input.</param>
		public static bool EqualToZero (int input)
		{
			if (input == 0) {
				Console.WriteLine ("Input must be greater than zero");
				return true;
			}
			return false;
		}

		/// <summary>
		/// Equals to zero.
		/// </summary>
		/// <returns><c>true</c>, if to zero was equaled, <c>false</c> otherwise.</returns>
		/// <param name="input">Input.</param>
		public static bool EqualToZero (double input)
		{
			if (input == 0) {
				Console.WriteLine ("Input must be greater than zero");
				return true;
			}
			return false;
		}

		/// <summary>
		/// Positives the validate.
		/// </summary>
		/// <returns><c>true</c>, if validate was positived, <c>false</c> otherwise.</returns>
		/// <param name="input">Input.</param>
		public static bool PositiveValidate (double input)
		{
			if (input < 0.0) {
				Console.WriteLine ("Input must be greater than or equal to zero");
				return true;
			}
			return false;
		}

		/// <summary>
		/// Validation this instance.
		/// </summary>
		public static bool RangeValidation (int num, int rangeMin, int rangeMax)
		{
			if (num < rangeMin || num > rangeMax)

				return true;
			return false; 
		}

		/// <summary>
		/// Validation this instance.
		/// </summary>
		public static bool RangeValidation (double num, int rangeMin, int rangeMax)
		{
			if (num < rangeMin || num > rangeMax) {
				Console.WriteLine ("***Input must be between rangeMin-rangeMax ****");
				return true;
			}
			return false; 
		}
		#endregion

	}
}



