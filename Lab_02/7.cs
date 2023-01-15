using System;

namespace HelloWorld
{
  class Program
  {
    static void Main(string[] args)
    {
      char shotname = 'O';
      string fullname = "Opaspun Klinchuenjit";
      Console.WriteLine("My shotname is {0}", shotname); 
      Console.WriteLine("My fullname is {0}", fullname);    
      Console.WriteLine("My fullname is {0} ", fullname.ToUpper());    
    }
  }
}