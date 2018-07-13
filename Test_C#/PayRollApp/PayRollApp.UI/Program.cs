using System;
using PayRollApp.Entities;
using PayRollApp.UI.Utility;

namespace PayRollApp.UI
{
	class Program
	{
		public static void Main ()
		{
			int numberOfRecords = UtilityProgram.GetNumberOfRecords ();
			Employee[] Emp = UtilityProgram.CreateEmployeeRepository (numberOfRecords);
			UtilityProgram.AddNumberOfEmployees (Emp);
			UtilityProgram.GetDetailsOfEmployee (Emp);
		}
	}
}
