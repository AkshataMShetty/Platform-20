using System;

namespace Assignment3_Q3
{
	class Program
	{
		public static void Main ()
		{
			Operation desc = new Operation ();
			ProductDesc[] prod = desc.ReadInput ();
			desc.Sorting (prod);
		}
	}
}
