using System;

namespace Assignement4
{
	class Program
	{
		public static void Main ()
		{
			int value;
			int[] arr = ArrayOp.ReadInput (out value);
			Console.WriteLine ("Minimal numbers required to get {0} : {1}" , value , ArrayOp.FindMinimalLength (arr,value));
		}
	}
}
