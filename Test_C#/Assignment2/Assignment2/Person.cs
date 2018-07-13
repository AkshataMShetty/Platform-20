using System;

namespace Assignment2
{
	public class Person
	{
		#region DataMembers
		string name;
		#endregion

		#region
		public Person ()
		{
		}

		public Person (string name)
		{
			Name = name;
		}
		#endregion

		#region Property
		public string Name {
			get {
				return name;
			}
			set {
				name = value;
			}
		}
		#endregion

		#region Methods
		public abstract bool IsOutstanding ();
		#endregion
	}
}

