using System;

namespace Assignment2_Q2
{
	public class Circle
	{
		#region DataMember
		double radius;
		double area;
		#endregion

		#region Constructor
		public Circle ()
		{
		}
		#endregion

		#region Property
		public double Radius {
			get {
				return radius;
			}
			set {
				radius = value;
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
			Area = (Math.PI * Math.Pow(Radius, 2));
		}

		#endregion
	}
}

