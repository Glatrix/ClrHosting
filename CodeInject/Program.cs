using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ISpace
{
    public class IClass
    {
        public static int IMain(string args)
        {
            AllocConsole(); //Open a console window from the same process.
            Console.WriteLine("<_C# Loaded_>"); //Proof its working.
            return 0;
        }

        [DllImport("kernel32")]
        static extern bool AllocConsole();
    }
}
