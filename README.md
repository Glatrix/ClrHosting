https://discord.gg/X9gdzuJBAZ

# ClrHosting
Clr Injection for x64 and x86

<h2>Clr loader</h2>
(Only injects .NET Framework dlls)

```
static const LPCWSTR Assembly = L"\\CSharp.dll"; //dllname.dll (eg \\FolderName\\CSharp.dll
static const LPCWSTR Class = L"ISpace.IClass"; //namespace.class
static const LPCWSTR Method = L"IMain"; //method name
static const LPCWSTR Param = L"It works!!"; //string paramater (if applicable)
```
Put the C# dll, and the Clr hosting dll into the same folder.

<h2>C# Exmaple</h2>

```
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

```
