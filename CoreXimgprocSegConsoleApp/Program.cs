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
                if (args.Length < 3)
                {
                    Console.WriteLine("Must specify fileName and strategyType (q = SelectiveSearchQuality, s = SingleStrategy, other = SelectiveSearchFast)" +
                                      " and if you want to display and save results. EG: deer.jpg f y");
                    return;
                }

                var watch = System.Diagnostics.Stopwatch.StartNew();

                var fileName = args[0];
                var strategyType = args[1];
                var displayResult = args[2].ToLower() == "y";

                var selectiveSearch = new SelectiveSearch();

                var rects = selectiveSearch.GetRectangles(fileName, strategyType);

                watch.Stop();
                var elapsedMs = watch.ElapsedMilliseconds;

                if (displayResult)
                {
                    string text = string.Empty;

                    foreach (var r in rects.ToList())
                    {
                        Console.WriteLine($"X {r.X} Y {r.Y} Width {r.Width} Height {r.Height}");

                        text = $"{text}{r.X} {r.Y} {r.Width} {r.Height} ";
                    }

                    System.IO.File.WriteAllText(System.IO.Directory.GetCurrentDirectory() + @"\Rois.txt", text.Trim());
                }

                Console.WriteLine($"Total time {elapsedMs} milliseconds");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
        }
    }
}
