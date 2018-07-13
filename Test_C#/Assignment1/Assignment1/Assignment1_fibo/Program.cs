using System;

namespace Assignment1_fibo
{
	class Program
	{
		public static void Main ()
		{
			int Num = Fibonacci.ReadInput ();
			Num = Fibonacci.Fibonacci_Calc (Num);

			Fibonacci.Display (Num);
		}
	}
}
