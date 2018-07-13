using System;
using ValidateLib;

namespace Assignment1_StudentRes
{
	public class StudentRes
	{
		#region Members
		double[] sub_marks = new double[3];
		#endregion

		#region Property
		public double[] Sub_marks {
			get {
				return sub_marks;
			}
			set {
				sub_marks = value;
			}
		}

		public void ReadInput ()
		{
			Console.WriteLine ("Enter the marks :");
		
			for (int i = 0; i < 3; i++) {
				do {
					Console.Write ("subject#" + (i + 1) + ":");
					Sub_marks [i] = double.Parse (Console.ReadLine ());
				} while (Validation.PositiveValidate(Sub_marks[i]));
			}
		}
		public bool Check_Result ()
		{
			double avg = 0.0;
			int count = 0;
			for (int i = 0; i < 3; i++) {
				if (Sub_marks[i] < 40)
					count++;
				avg += Sub_marks [i];
			}
			avg /= 3; 

			if (count > 1) 
				return false;
			else 
				return true;
		}

		public void Display_Results(bool t)
		{
			if (t) 
				Console.WriteLine ("PASS");
			else
				Console.WriteLine ("FAIL");
		}
		#endregion
	}
}

