using System;
using PayRollApp.Entities;

namespace PayRollApp.UI.Utility
{
	public static class UtilityProgram
	{
		static public int GetNumberOfRecords ()
		{
			Console.Write ("Number of records?:");
			return (int.Parse (Console.ReadLine ()));
		}

		static Employee CreateEmployee (int choice)
		{
			Employee emp = null;

			switch (choice) {
				case 1:
				emp = new Developer ();
				break;
				case 2:
				emp = new Hr ();
				break;

				default :
				Console.WriteLine ("Not correct option");
				break;
			}

			Console.Write ("Name : ");
			emp.Name = Console.ReadLine ();

			Console.Write ("Id : ");
			emp.Id = int.Parse(Console.ReadLine ());

			Console.Write ("Basic Pay : ");
			emp.BasicPay = double.Parse(Console.ReadLine ());

			Console.Write ("Hra : ");
			emp.Hra = double.Parse(Console.ReadLine ());

			Console.Write ("daPay : ");
			emp.DaPay = double.Parse(Console.ReadLine ());


			if (emp is Developer) {
				Console.Write ("Incentive : ");
				((Developer)emp).Incentive = double.Parse (Console.ReadLine());
			}
			if (emp is Hr) {
				Console.Write ("Gratuity Pay : ");
				((Hr)emp).GratuityPay = double.Parse (Console.ReadLine());
			}

			return emp;
		}

		static public void GetDetailsOfEmployee (Employee[] emp)
		{
			Console.Write ("Details of ");
			for (int i = 0; i < emp.Length; i++) {
				Console.WriteLine ("Record# " + (i + 1));
				Console.Write ("Name :" + emp[i].Name + "\t" + "Salary :" + emp[i].Salary);
			}
		}

		static public Employee[] CreateEmployeeRepository (int numberOfRecords)
		{
			Employee[] emp = new Employee[numberOfRecords];
			return emp;
		}

		static void Display (out int choice)
		{
			Console.Write ("Enter 1->Developer 2->HR: ");
			choice = int.Parse (Console.ReadLine ());
		}


		static public void AddNumberOfEmployees (Employee[] Emp)
		{
			int choice;

			Employee emp = null;

			for (int count = 0; count < Emp.Length; count++) {
				Console.WriteLine ("Record #" + (count + 1));
				Display (out choice);

				emp = CreateEmployee (choice);

				emp.CalculateSalary ();
				Emp [count] = emp; 
			}
		}
	}
}

