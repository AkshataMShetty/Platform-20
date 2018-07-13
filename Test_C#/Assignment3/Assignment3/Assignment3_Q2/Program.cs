using System;

namespace Assignment3_Q2
{
	class Program
	{
		public static void Main ()
		{
			StringOp.String[] st = null;
			StringOp so = new StringOp ();
			st = so.ReadInput ();
			so.Display (st);
		}
	}
}
