using System;

namespace Assignment3
{
	class Program
	{
		public static void Main (string[] args)
		{
			WordCount word = new WordCount ();

			WordCount.wordcount[] wc = null;
			wc = word.ReadInput (args);

			word.Display (wc);
		}
	}
}
