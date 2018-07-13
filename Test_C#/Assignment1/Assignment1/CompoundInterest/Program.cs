using System;

namespace Assignment1_CI
{
	class Program
	{
		public static void Main ()
		{
			CompoundInterest ci = new CompoundInterest ();
			ci.ReadInput ();
			ci.Calculate ();
		}
	}
}
