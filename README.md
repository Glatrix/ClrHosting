# ClrHosting
Clr Injection for x64 and x86

```
static const LPCWSTR Assembly = L"\\CSharp.dll"; //dllname.dll (eg \\FolderName\\CSharp.dll
static const LPCWSTR Class = L"ISpace.IClass"; //namespace.class
static const LPCWSTR Method = L"IMain"; //method name
static const LPCWSTR Param = L"It works!!"; //string paramater (if applicable)
```
Put the C# dll, and the Clr hosting dll into the same folder.
