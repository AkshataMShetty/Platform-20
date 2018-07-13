using System;

namespace Assignement4
{
	public class ArrayOp
	{
		public static int[] ReadInput (out int value)
		{
			int noOfEle;

			Console.Write ("Enter num of elements in an array? :");
			noOfEle = int.Parse (Console.ReadLine ());

			int[] arr = new int[noOfEle];

 			Console.Write ("Enter Elements : ");
			for (int i = 0; i < arr.Length; i++) {
				arr[i] = int.Parse(Console.ReadLine ());
			}

			Console.Write ("Enter value : ");
			value = int.Parse (Console.ReadLine ());

			return arr;
		}

		public static int FindMinimalLength (int[] arr, int value)
		{
			int k = -1;
			int sum;
			int countOfEle = 0;
			int[] count = new int[2 * arr.Length]; 

			for (int i = 0; i < arr.Length; i++) {
				sum = 0;

				countOfEle = 0;
				for (int j = i; j < arr.Length; j++) {
					sum = sum + arr [j];
					countOfEle++;

//					Console.WriteLine (sum);

					if (sum == value) {
						count [++k] = countOfEle;
						break;
					}
					else if (sum < value) {
						continue;
					}
					else {
						break;
					}

				}
			}

//			for (int i = 0; i < count.Length; i++) {
//				Console.Write (count[i] +"\t");
//			}

//			for (int i = 0; i < count.Length ; i++) {
//				for (int j = 0; j < count.Length - i -1; j++) {
//					if (count [j] == 0) {
//						continue;
//					} else {
//						if (count [j] > count [j + 1]) {
//							count [j] = count [j] + count [j + 1];
//							count [j + 1] = count [j] - count [j + 1];
//							count [j] = count [j] - count [j + 1];
//						}
//					}
//				}
//			}

//			for (int i = 0; i < count.Length; i++) {
//				Console.Write (count[i] +"\t");
//			}
//			Console.WriteLine (count[0]);
			return count [0];
		}
	}
}

