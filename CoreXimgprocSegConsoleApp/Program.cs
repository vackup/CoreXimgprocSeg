using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CoreXimgprocSegWrapper;

namespace CoreXimgprocSegConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                var fileName = "deer.jpg";

                var selectiveSearch = new SelectiveSearch();

                var rects = selectiveSearch.GetRectangles(fileName, "f");

                foreach (var r in rects.ToList())
                {
                    Console.WriteLine($"X {r.X} Y {r.Y} Width {r.Width} Height {r.Height}");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
