using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string num = Console.ReadLine();
        Console.WriteLine(FindMinGreater(num));
    }

    private static string FindMinGreater(string number)
    {
        List<string> permutations = new List<string>();
        MakePermutation(number, permutations, 0, number.Length - 1);
        List<string> filtered = permutations.Where(x => int.Parse(x) > int.Parse(number)).ToList();
        
        if (filtered.Count > 0)
            return filtered.Min(x => int.Parse(x)).ToString();

        return "-1";
    }

    private static void MakePermutation(string seq, List<string> permutations, int start, int end)
    {
        if (start == end)
        {
            permutations.Add(seq);
        }
        else
        {
            for (int i = start; i <= end; i++)
            {
                seq = Swap(seq, start, i);
                MakePermutation(seq, permutations, start + 1, end);
                seq = Swap(seq, start, i);
            }
        }
    }

    private static string Swap(string seq, int index_1, int index_2)
    {
        char[] char_array = seq.ToCharArray();

        char temp = char_array[index_1];
        char_array[index_1] = char_array[index_2];
        char_array[index_2] = temp;

        return new string(char_array);
    }
}