using System;

namespace Assignment3_Q2
{
	public class StringOp
	{
		public struct String {
			public string str;
			public int length;
		}

		public String[] ReadInput () {

			String[] st = null;

			Console.Write ("Enter the number of strings :");
			int noOfStrings = int.Parse (Console.ReadLine());
			st = new String[noOfStrings];

			//			int[] length = new int[input.Length];

			for (int i = 0; i < st.Length; i++) {
				Console.Write ("\nString#" +  (i + 1) + " :");
				st [i].str = (Console.ReadLine ());
				st [i].length = st[i].str.Length; 
			}

			string temp;

			for (int i = 0; i < noOfStrings; i++) {
				for (int j = 0; j < (noOfStrings - i - 1); j++) {
					if (st [j].length < st [j + 1].length) {
						st [j].length = st [j].length + st [j + 1].length;
						st [j + 1].length = st [j].length - st [j + 1].length;
						st [j].length = st [j].length - st [j + 1].length;
						temp = st [j].str;
						st [j].str = st [j + 1].str;
						st [j + 1].str = temp;
					}
				}
			}
			return st;
		}

//	    String[] sort (String[] st, int noOfStrings)
//		{
//			string temp;
//
//			for (int i = 0; i < noOfStrings; i++) {
//				for (int j = 0; j < (noOfStrings - i - 1); j++) {
//					if (st [j].length < st [j + 1].length) {
//						st [j].length = st [j].length + st [j + 1].length;
//						st [j + 1].length = st [j].length - st [j + 1].length;
//						st [j].length = st [j].length - st [j + 1].length;
//						temp = st [j].str;
//						st [j].str = st [j + 1].str;
//						st [j + 1].str = temp;
//					}
//				}
//			}
//			return st;
//		}

		public void Display (String[] st) {
			Console.WriteLine ("*****Output*****");

			for (int i = 0; i < st.Length; i++) {
				Console.WriteLine (st[i].str);
			}
		}

	}
}

