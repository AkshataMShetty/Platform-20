using System;

namespace PayRollApp.Entities
{
	public class Developer:Employee
	{

		#region DataMember
		double incentive;
		#endregion

		#region Constructor
		/// <summary>
		/// Initializes a new instance of the <see cref="PayRollApp.Entities.Developer"/> class.
		/// </summary>

		#endregion

		#region Property
		public double Incentive {
			get {
				return incentive;
			}
			set {
				incentive = value;
			}
		}
		#endregion

		#region Method
		public override void CalculateSalary() {
			this.salary = this.BasicPay + this.DaPay + this.Hra+ this.Incentive;
		}
		#endregion
	}
}

