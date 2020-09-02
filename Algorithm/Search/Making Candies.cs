using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {

    // Complete the minimumPasses function below.
    static long minimumPasses(long m, long w, long p, long n) {
            long passes = 0;
            long candy = 0;
            long run = long.MaxValue;
            long step;

            while (candy < n)
            {
                step = (m > long.MaxValue / w) ? 0 : (p - candy) / (m * w);

                if (step <= 0)
                {
                    long mw = candy / p;

                    if (m >= w + mw)
                    {
                        w += mw;
                    }
                    else if (w >= m + mw)
                    {
                        m += mw;
                    }
                    else
                    {
                        long total = m + w + mw;
                        m = total / 2;
                        w = total - m;
                    }

                    candy %= p;
                    step = 1;
                }

                passes += step;

                if (step * m > long.MaxValue / w)
                {
                    candy = long.MaxValue;
                }
                else
                {
                    candy += step * m * w;
                    run = Math.Min(run, (long)(passes + Math.Ceiling((n - candy) / (m * w * 1.0))));
                }
            }

            return Math.Min(passes, run);
        }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string[] mwpn = Console.ReadLine().Split(' ');

        long m = Convert.ToInt64(mwpn[0]);

        long w = Convert.ToInt64(mwpn[1]);

        long p = Convert.ToInt64(mwpn[2]);

        long n = Convert.ToInt64(mwpn[3]);

        long result = minimumPasses(m, w, p, n);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
