using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1 {
     class Program
    {
        static void Main(string[] args)
        {
             double height;
            double weight;
            double bmi;
            Console.WriteLine("Please enter your height in inches:");

            //Fixed error using Double.Parse to cast input string to double for both height and weight
            height = Double.Parse(Console.ReadLine());

            Console.WriteLine("Please enter your weight in pounds:");
            weight = Double.Parse(Console.ReadLine());

            Person p = new Person(height, weight);
            bmi = CalculateBMI(p.HeightInInches, p.WeightInPounds);
            Console.WriteLine("Your BMI is: {0}", bmi);
            Console.Read();

        }

        private static double CalculateBMI(double h, double w) {
            var heightInMeters = h * 0.025;
            var weightInKg = w * 0.45;

            heightInMeters = Math.Pow(heightInMeters, 2);

            var bmi = weightInKg / heightInMeters;

            return bmi;
        }
    }
    public class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public double HeightInInches { get; set; }
        public double WeightInPounds { get; set; }

        //Changed height formula to set HeightInInches variable to value of height argument. *

        public Person(double height, double weight)
        {
            HeightInInches = height;
            WeightInPounds = weight;
        }
    }
}

