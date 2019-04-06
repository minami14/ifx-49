using System;
using System.Globalization;
using System.Linq;
using System.Text;

namespace FloatToFixedPoint
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                var builder = new StringBuilder();
                while (true)
                {
                    var input = Console.ReadLine();
                    if (input.Length == 0)
                    {
                        break;
                    }

                    builder.Append(input);
                }

                var inputs = builder.ToString()
                    .Replace(" ", "")
                    .Split(',')
                    .Select(x => decimal.Parse(x, NumberStyles.Float))
                    .Select(x => (int) ((((uint) 1) << 24) * x))
                    .ToArray();
                foreach (var i in inputs)
                {
                    Console.WriteLine(i);
                }
            }
        }
    }
}
