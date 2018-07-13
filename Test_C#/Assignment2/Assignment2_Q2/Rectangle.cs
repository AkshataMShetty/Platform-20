using System;

namespace Assignment2_Q2
{
	public class Rectangle : Shape
	{
		#region DataMember
		double length;
		double breadth;
		double area;
		#endregion

		#region Constructor
		public Rectangle ()
		{
		}
		#endregion

		#region Property
		public double Length {
			get {
				return length;
			}
			set {
				length = value;
			}
		}

		public double Breadth {
			get {
				return breadth;
			}
			set {
				breadth = value;
			}
		}

		public double Area {
			get {
				return area;
			}
			set {
				area = value;
			}
		}
	
		#endregion

		#region Methods
		public void CalculateArea () {
			Area =  Breadth * Length;
		}
		#endregion
	}
}


