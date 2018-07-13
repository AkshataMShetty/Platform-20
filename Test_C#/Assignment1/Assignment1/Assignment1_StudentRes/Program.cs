using System;

namespace Assignment1_StudentRes
{
	class Program
	{
		public static void Main ()
		{
			StudentRes stud = new StudentRes ();
			stud.ReadInput ();
			stud.Display_Results(stud.Check_Result());
		}
	}
}
