using System;
using ValidateLib;

namespace Assignment1_MatrixArrangement
{
	public class SortingOperations
	{
		int rows;
		int cols;

		public int Rows {
			get {
				return rows;
			}
			set {
				rows = value;
			}
		}

		public int Cols {
			get {
				return cols;
			}
			set {
				cols = value;
			}
		}

		/// <summary>
		/// Inputs the rows and columns.
		/// </summary>
		/// <param name="row">Row.</param>
		public void InputRowsAndColumns( )
		{
			Console.WriteLine ("Enter the number of rows:");

			do {
				Rows = int.Parse(Console.ReadLine ());
				Cols = Rows;
			} while(Validation.PositiveValidate(Rows) || Validation.EqualToZero(Rows));
		}
//
//		/// <summary>
//		/// Checks for row.
//		/// </summary>
//		/// <param name="row">Row.</param>
//		public static void CheckForRow (int row)
//		{
//			while (row % 2 == 0)
//			{
//				InputRowsAndColumns (out row);
//			}
//		}

		/// <summary>
		/// Puts the vaules into array.
		/// </summary>
		/// <param name="arr">Arr.</param>
		/// <param name="row">Row.</param>
		/// <param name="col">Col.</param>
		public void PutVaulesIntoArray (int[,] arr)
		{
			Console.WriteLine ("************Enter the {0} X {1} values :**********", Rows,Cols);
			for (int i = 0; i <  Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					Console.Write ("[{0}][{1}] :" ,i , j);
					arr[i,j] = int.Parse(Console.ReadLine ());
				}
			}
		}

		/// <summary>
		/// Displaies the values.
		/// </summary>
		/// <param name="arr">Arr.</param>
		/// <param name="rows">Rows.</param>
		/// <param name="cols">Cols.</param>
		public void MultiDisplayValues (int[,] arr)
		{
			Console.WriteLine ("************Array values :**********");
			for (int i = 0; i <  Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					Console.Write (arr[i,j] + "\t");
				}
				Console.WriteLine ();
			}
		}

		/// <summary>
		/// Arraies the operations for2 d.
		/// </summary>
		/// <param name="rows">Rows.</param>
		/// <param name="cols">Cols.</param>
		/// <param name="arr">Arr.</param>
		public void ArrayOperationsFor2D (int[,] arr)
		{
			PutVaulesIntoArray (arr);
			MultiDisplayValues (arr);
		}

		/// <summary>
		/// Converts to single dimen.
		/// </summary>
		/// <param name="arr">Arr.</param>
		/// <param name="rows">Rows.</param>
		/// <param name="cols">Cols.</param>
		/// <param name="mod_arr">Mod_arr.</param>
		public void ConvertToSingleDimen (int[,] arr, int[] mod_arr)
		{
			int k = 0;
			for (int i = 0; i < Rows && k < arr.Length; i++) {
				for (int j = 0; j < Cols; j++) {
					mod_arr [k++] = arr [i, j];
				}
			}
		}

		/// <summary>
		/// Displaies the values.
		/// </summary>
		/// <param name="arr">Arr.</param>
		public void SingleDisplayValues (int[] arr)
		{
			Console.WriteLine ("Array Contents after arrangement:");
			for (int i = 0; i < arr.Length; i++) {
				Console.Write (arr[i]);
				Console.Write ("\t");
			}
			Console.WriteLine ("");

		}

		/// <summary>
		/// Decending_s the order.
		/// </summary>
		/// <param name="mod_arr">Mod_arr.</param>
		public void Decending_Order (int[] mod_arr)
		{
			for (int i = 0; i < mod_arr.Length; i++) {
				for (int j = 0; j < (mod_arr.Length - i - 1); j++) {
					if (mod_arr[j] < mod_arr[j + 1]) {
						mod_arr [j] = mod_arr [j] + mod_arr [j + 1];
						mod_arr [j + 1] = mod_arr [j] - mod_arr [j + 1]; 
						mod_arr [j] = mod_arr [j] - mod_arr [j + 1]; 
					}
				}
			}
		}

		/// <summary>
		/// Ordering the specified mod_arr and res_arr.
		/// </summary>
		/// <param name="mod_arr">Mod_arr.</param>
		/// <param name="res_arr">Res_arr.</param>
		public int[] Ordering (int[,] mod_arr)
		{
			int[] res_arr = new int[Rows * Cols];
			ConvertToSingleDimen (mod_arr,res_arr);
			Decending_Order (res_arr);

			int k = 0;

			int[] res_arr1 = new int[res_arr.Length];

			for (int i = 0; i < res_arr.Length; i++) {
				if (i % 2 == 0) 
					res_arr1 [k++] = res_arr [i];
			}

			for (int i = res_arr.Length - 1; i > 0; i--) {
				if (i % 2 != 0) 
					res_arr1 [k++] = res_arr [i];
			}

			return res_arr1;
		}

	}
}

