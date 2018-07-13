using System;
using ValidateLib;

namespace Assignment3_Q3
{
	public class Operation
	{

		public ProductDesc[] ReadInput ()
		{
			Console.Write ("How many products? :");
			int numOfProducts = int.Parse(Console.ReadLine ());

			ProductDesc[] product = new ProductDesc[numOfProducts];

			for (int i = 0; i < product.Length; i++) {
				product [i] = new ProductDesc ();
				Console.Write ("Product Id :");

				do {
					product [i].ProductId = int.Parse(Console.ReadLine());
				} while(Validation.PositiveValidate (product [i].ProductId));

				Console.Write ("Brand Name :");
				product [i].Brandname = Console.ReadLine();

				Console.Write ("Description :");
				product [i].Description = Console.ReadLine();

				Console.Write ("Price :");

				do {
					product [i].Price = double.Parse(Console.ReadLine());
				} while(Validation.PositiveValidate (product [i].Price) || Validation.EqualToZero (product [i].Price));
			}

			Display (product);
			return product;
		}

		int DisplayMenu ()
		{
			Console.WriteLine ("--------Menu Sorting------- ");
			Console.WriteLine ("1 : Based on product Id \t2.Based on brand Name\t 3.Based on price");

			Console.WriteLine ("Enter ur choice :");
			return (int.Parse(Console.ReadLine ()));
		}

		public void Sorting (ProductDesc[] product)
		{
			int choice;

			do {
				choice = DisplayMenu ();

				switch (choice) {
				case 1:
					ProductDesc temp;
					for (int i = 0; i < product.Length; i++) {
						for (int j = 0; j < (product.Length - i - 1); j++) {
							if (product [j].ProductId > product [j + 1].ProductId) {
								temp = product [j];
								product [j] = product [j + 1];
								product [j + 1] = temp;
							}
						}
					}
					break;

				case 2:
					for (int i = 0; i < product.Length; i++) {
						for (int j = 0; j < (product.Length - i - 1); j++) {
							if (product [j].Brandname.CompareTo (product [j + 1].Brandname) == 0) {
								if (product [j].Description.CompareTo (product [j + 1].Description) > 0) {
									temp = product [j];
									product [j] = product [j + 1];
									product [j + 1] = temp;
								}
							} else if (product [j].Brandname.CompareTo (product [j + 1].Brandname) > 0) {
								temp = product [j];
								product [j] = product [j + 1];
								product [j + 1] = temp;
							} else
								continue;
						}
					}
					break;
				case 3:
					for (int i = 0; i < product.Length; i++) {
						for (int j = 0; j < (product.Length - i - 1); j++) {
							if (product [j].Price > product [j + 1].Price) {
								temp = product [j];
								product [j] = product [j + 1];
								product [j + 1] = temp;
							} else if (product [j].Price == product [j + 1].Price) {
								if (product [j].ProductId > product [j + 1].ProductId) {
									temp = product [j];
									product [j] = product [j + 1];
									product [j + 1] = temp;
								}
							} else
								continue;
						}
					}
					break;

				default :
					Console.WriteLine ("Choice should be between 1 - 3");
					break;
				}
			} while (Validation.RangeValidation (choice, 1, 3));
			Display(product);
		
		}

		public void Display (ProductDesc[] product)
		{
			Console.WriteLine ("ProductID\tProductName\tDescription\tPrice");
			for (int i = 0; i < product.Length; i++) {
				Console.WriteLine (product[i].ProductId + "\t\t" + product[i].Brandname + "\t\t" + product[i].Description
				                   +"\t" + product[i].Price);
			}
		}
	}
}

