using System;

namespace Assignment3_Q3
{
	public class ProductDesc
	{
		int productId;
		string brandname;
		string description;
		double price;


		public int ProductId {
			get {
				return productId;
			}
			set {
				productId = value;
			}
		}

		public string Brandname {
			get {
				return brandname;
			}
			set {
				brandname = value;
			}
		}

		public string Description {
			get {
				return description;
			}
			set {
				description = value;
			}
		}

		public double Price {
			get {
				return price;
			}
			set {
				price = value;
			}
		}
	}
}

