using System;

namespace Assignment2
{
	public class Student : Person
	{
		#region DataMembers
		double percentage;
		#endregion

		#region
		public Student ()
		{
		}

		public Student (string name, double percentage)
		{
			Name = name;
			Percentage = percentage;
		}
		#endregion

		#region Property
		public double Percentage {
			get {
				return percentage;
			}
			set {
				percentage = value;
			}
		}
		#endregion

		#region Methods
		public override bool IsOutstanding () {
			if (Percentage > 85) 
				return true;
			return false;
		}

		public void display () {
			Console.WriteLine ("Student : {0} Secured {1}", Name , Percentage);
		}
		#endregion
	}
}

