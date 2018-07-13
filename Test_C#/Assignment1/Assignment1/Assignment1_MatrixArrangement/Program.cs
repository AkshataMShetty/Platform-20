using System;

namespace Assignment1_MatrixArrangement
{
	class Program
	{
		public static void Main ()
		{

			SortingOperations so = new SortingOperations ();

			so.InputRowsAndColumns ();

			int[,] arr = new int[so.Rows,so.Cols];

			so.ArrayOperationsFor2D (arr);

			int[] arr1;

			arr1 = so.Ordering (arr);

			so.SingleDisplayValues (arr1);
		}
	}
}
