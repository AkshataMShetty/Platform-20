using System;

namespace PayRollApp.Entities
{
	public class Hr:Employee
	{
		#region DataMember
		double gratuityPay;
		#endregion

		#region Constructor
		/// <summary>
		/// Initializes a new instance of the <see cref="PayRollApp.Entities.Developer"/> class.
		/// </summary>
		public Hr ()
		{
		}
		#endregion

		#region Property
		public double GratuityPay {
			get {
				return gratuityPay;
			}
			set {
				gratuityPay = value;
			}
		}
		#endregion

		#region Method
		public override void CalculateSalary() {
			this.salary = this.Hra + this.DaPay + this.BasicPay + this.GratuityPay;
		}
		#endregion
	}
}

