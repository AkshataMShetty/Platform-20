using System;

namespace Assignment2
{
	public class Professor : Person
	{
		#region DataMembers
		int booksPublished;
		#endregion

		#region
		public Professor ()
		{
		}

		public Professor (string name, int booksPublished)
		{
			Name = name;
			BooksPublished = booksPublished;
		}
		#endregion

		#region Property
		public int BooksPublished {
			get {
				return booksPublished;
			}
			set {
				booksPublished = value;
			}
		}
		#endregion

		#region Methods
		public override bool IsOutstanding () {
			if (BooksPublished > 4) 
				return true;
			return false;
		}

		public void print () {
			Console.WriteLine ("Professor "+ Name + " " +"has Published " + BooksPublished + " " +"books");
		}
		#endregion
	}
}

