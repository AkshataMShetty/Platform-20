using System;

using System.Collections.Generic;

using System.Linq;

using System.Text;

namespace Inheritance

{

	class Program

	{

		static void Main(string[] args)

		{

		//	Teacher d = new Teacher();

			Teacher.Teach();

			Student s = new Student();

			s.Learn();

			Student.Teach();

			Console.ReadKey();

		}

		class Teacher

		{

			public static void Teach()

			{

				Console.WriteLine("Teach");

			}

		}

		class Student : Teacher

		{

			public void Learn()

			{

				Console.WriteLine("Learn");

			}

		}

	}

}