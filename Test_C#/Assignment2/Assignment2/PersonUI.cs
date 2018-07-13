using System;

namespace Assignment2
{
	public class PersonUI
	{
		public static void Main ()
		{
			Outstanding os = new Outstanding();
			int num = os.AskForNumObject ();
			Person[] per = os.PopulatePerson (num);
			os.AddObjectsToArray (num , per);
		}
	}
}

