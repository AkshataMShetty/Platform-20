using System;

namespace Assignment2_Q2
{
	public class Triangle : Shape
	{
		#region DataMember
		double baseT;
		double height;
		double area;
		#endregion

		#region Constructor
		public Triangle ()
		{
		}
		#endregion

		#region Property
		public double BaseT {
			get {
				return baseT;
			}
			set {
				baseT = value;
			}
		}

		public double Height {
			get {
				return height;
			}
			set {
				height = value;
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
			Area = (BaseT * Height) / 2 ;
		}

		#endregion
	}
}

