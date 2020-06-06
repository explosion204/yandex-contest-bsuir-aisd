using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        string S = Console.ReadLine();

        Console.WriteLine(MaxNotSubPolyndrome(S));
    }

    static int MaxNotSubPolyndrome(string s)
    {
        if (s.Distinct().Count() == 1)
            return -1;

        if (IsPolyndrome(s))
            return s.Length - 1;
        else
            return s.Length;
    }

    static bool IsPolyndrome(string s)
    {
        bool is_polyndrome = true;
        for (int i = 0, j = s.Length - 1; i <= j; i++, j--)
        {
            if (s[i] != s[j])
                is_polyndrome = false;
        }

        return is_polyndrome;
    }
}