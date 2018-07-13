using System;
using ValidateLib;

namespace Assignment2_Q2
{
	class ShapeOp
	{
		public int Display () {
			Console.WriteLine ("-----------Menu----------- \n 1 -> Triangle 2 -> Rectangle 3 -> Circle");
			System.Console.Write ("Enter ur choice :");
			return (int.Parse(Console.ReadLine()));
		}

		public static Triangle DisplayForTri ()
		{
			Triangle tri = new Triangle ();

			do {
				Console.Write ("Enter values Base of triangle :");
				tri.BaseT = double.Parse (Console.ReadLine ());
			} while (Validation.PositiveValidate (tri.BaseT) || Validation.EqualToZero(tri.BaseT));

			do {
				Console.Write ("\nEnter values Height of triangle :");
				tri.Height = double.Parse (Console.ReadLine ());
			} while (Validation.PositiveValidate (tri.Height) || Validation.EqualToZero(tri.Height));

			return tri;
		}
	
		public static Rectangle DisplayForRec ()
		{
			Rectangle rec = new Rectangle ();

			do {
				Console.Write ("Enter values Length of retangle :");
				rec.Length = double.Parse(Console.ReadLine());
			} while (Validation.PositiveValidate (rec.Length) || Validation.EqualToZero(rec.Length));

			do {
				Console.Write ("\nEnter values Breadth of retangle :");
				rec.Breadth = double.Parse(Console.ReadLine());
			} while (Validation.PositiveValidate (rec.Breadth) || Validation.EqualToZero(rec.Breadth));

			return rec;
		}

		public static Circle DisplayForCir ()
		{
			Circle cir = new Circle ();

			do {
				Console.Write ("Enter values radius of circle :");
				cir.Radius = double.Parse(Console.ReadLine());
			} while (Validation.PositiveValidate (cir.Radius) || Validation.EqualToZero(cir.Radius));

			return cir;
		}

		public void DecidingMethod ( )
		{
			int choice;
			do {
				choice = Display ();
				switch (choice) 
				{
				case 1:
					Triangle tri = ShapeOp.DisplayForTri ();
					tri.CalculateArea ();
					Console.WriteLine ("\nArea of a triangle with base {0} and height {1}: {2}", tri.BaseT, tri.Height, tri.Area);

					break;
				
				case 2:
					Rectangle rec = ShapeOp.DisplayForRec ();
					rec.CalculateArea ();
					Console.WriteLine ("\nArea of a rectangle with breadth {0} and length {1}: {2}", rec.Breadth,rec.Length, rec.Area);

					break;

				case 3:
					Circle cir = ShapeOp.DisplayForCir ();
					cir.CalculateArea ();
					Console.WriteLine ("\nArea of a circle with radius {0} : {1}" ,cir.Radius, cir.Area);

					break;
				
				default :
					Console.WriteLine ("-----------Choice should be between 1 and 3-------------");
					break;
				}
			} while (Validation.RangeValidation (choice, 1, 3));
		}
	}
}
