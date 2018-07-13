using System;
using ValidateLib;

namespace Assignment2
{
	public class Outstanding
	{
		public Person[] PopulatePerson (int num) {
			Person[] person = new Person[num];
			return person;
		}

		public int AskForNumObject ()
		{
			int num;

			do {
				Console.Write ("Number of Objects to be created :");
				num = int.Parse(Console.ReadLine ());
			} while (Validation.PositiveValidate (num) || Validation.EqualToZero (num));

			return num;
		}

		int Display ()
		{
			Console.Write ("\nEnter 1->Student 2->Professor :");
			return (int.Parse (Console.ReadLine ()));
		}

		public void AddObjectsToArray (int num, Person[] per)
		{
			int choice;

			Person person = null;

			Console.WriteLine ("");
			for (int i = 0; i < num; i++) {
				Console.Write ("Details#{0}", (i + 1));

				person = new Person ();

				do {
					choice = Display ();
					switch (choice) {
					case 1: 
						person = new Student ();
						break;

					case 2: 
						person = new Professor ();
						break;

					default:
						Console.Write ("\n----------Choice Should be either 1 or 2-----------");
						break;
					}
				} while (Validation.RangeValidation(choice ,1 , 2));

				Console.Write ("\nName : ");
				person.Name = (Console.ReadLine ());

				if (person is Student) {
					Console.Write ("\nPercentage :");
					do {
						((Student)person).Percentage = int.Parse (Console.ReadLine ());
					} while(Validation.RangeValidation(((Student)person).Percentage , 0 , 100)); 
				}

				if (person is Professor) {
					Console.Write ("\nNumber of books published :");
					do {
						((Professor)person).BooksPublished = int.Parse (Console.ReadLine ());
					} while (Validation.PositiveValidate(((Professor)person).BooksPublished));

					per [i] = person;
					DecidingMethod (per [i]);
				}
			}
		}

		void DecidingMethod (Person person)
		{
			if (person is Student) {
				if (person.IsOutstanding ()) {
					Console.WriteLine ("\n-----------OUTSTANDING STUDENT--------");
					((Student)person).display ();
				} else {
					Console.WriteLine ("\n-----------NOT A OUTSTANDING STUDENT------");
					((Student)person).display ();
				}
			} else {
				if (person is Professor) {
					if (person.IsOutstanding ()) {
						Console.WriteLine ("\n---------OUTSTANDING PROFESSOR--------");
						((Professor)person).print ();
					} else {
						Console.WriteLine ("\n---------NOT A OUTSTANDING PROFESSOR---------");
						((Professor)person).print ();
					}
				}
			}
		}

	}
}
