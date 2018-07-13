using System;

namespace Assignment3
{
	public class WordCount
	{
		public struct wordcount {
			public string str;
			public int count;
		}

		public wordcount[] ReadInput (string[] str)
		{
//			string str;
//			char[] delim = {' '};

//			Console.Write ("Enter the string :");
//			str = (Console.ReadLine ());

//			Console.Write ("\nDelimiter :");
//			char[] delimiter = (Console.ReadLine ()).ToCharArray ();
//			char[] d = {'\0'};
//
//			char[] delimiter = GetDelimiter (delim, d);	

//			string[] sub_str = str.Split (delim);
//			Console.WriteLine (sub_str.Length);

			for (int i = 0 ; i < str.Length; i++) {
//				if (sub_str [i][j] == delimiter [j])
//					sub_str [i] = null;
				if (str[i] != null)
				Console.WriteLine ("sub_str: {0}", str [i]);
			}

			return (CreationOfList (str));
		}

//		char[] GetDelimiter (string delim,params char[] d)
//		{
//			string[] arr = delim.Split (d);
//			Console.WriteLine ("arr: {0}", arr);
//			int noOfdelim = arr.Length;
//			char[] delimiters = new char[noOfdelim];
//
//			for (int i = 0; i < noOfdelim; i++) {
//				delimiters [i] = arr [i][0];
//			}
//			Console.WriteLine ("delimiters: {0}", delimiters);
//
//			return delimiters;
//		}

//		string[] split (string str, char[] delim)
//		{
//			string[] res_str;
//			res_str = str.Split (delim);
//			return res_str;
//		}

		int Compare (string str, string[] res_str)
		{
			int count = 0;
			for (int i = 0; i < res_str.Length; i++) {
				if (str.CompareTo (res_str [i]) == 0) {
					count++;
					if (count > 1)
						res_str [i] = null;
				}
			}
			return count;
		}

		public void Display (wordcount[] wc)
		{
			Console.Write ("[");

			for (int i = 0; i < wc.Length; i++) {
				if (wc[i].str != null )
					Console.Write (wc[i].str + "=" + wc[i].count + ",");
			}
			Console.Write ("]");
		}


		wordcount[] CreationOfList (string[] res_str)
		{
			wordcount[] wc = new wordcount[res_str.Length];

			Array.Sort (res_str);

			for (int i = 0; i < res_str.Length; i++) {
				if (res_str [i] != null) {
					wc [i].str = res_str [i];
					wc [i].count = Compare (wc [i].str, res_str);
				}
			}
//			for (int i = 0; i < wc.Length; i++) {
//				Console.Write (wc[i].str);
//			}
			
			return wc;
		}
	}
}

