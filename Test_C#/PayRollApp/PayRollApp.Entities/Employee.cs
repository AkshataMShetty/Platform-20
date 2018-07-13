using System;

namespace PayRollApp.Entities
{
	public class Employee 
	{
		#region DataMembers
		string name;
		int id;
		public double salary;
		double hra;
		double daPay;
		double basicPay;
		#endregion
	
		#region Property

		public string Name {
			get {
				return name;
			}
			set {
				name = value;
			}
		}

		public double Hra {
			get {
				return hra;
			}
			set {
				hra = value;
			}
		}

		public double DaPay {
			get {
				return daPay;
			}
			set {
				daPay = value;
			}
		}

		public double BasicPay {
			get {
				return basicPay;
			}
			set {
				basicPay = value;
			}
		}

		public double Salary {
			get {
				return salary;
			}
		}

		public int Id {
			get {
				return id;
			}
			set {
				id = value;
			}
		}

		#endregion

		#region Method
		public virtual void CalculateSalary () {
			 this.salary = this.BasicPay + this.DaPay + this.Hra;
		}
		#endregion
	}
}
