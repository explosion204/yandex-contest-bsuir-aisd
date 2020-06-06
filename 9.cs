using System;

class Program
{
    static void Main(string[] args)
    {
        char[] S = Console.ReadLine().ToCharArray();
        int Q = int.Parse(Console.ReadLine());

        int[] case_swapped = new int[S.Length + 1];

        for (int i = 0; i < Q; i++)
        {
            string[] input = Console.ReadLine().Split();

            int L = int.Parse(input[0]);
            int R = int.Parse(input[1]);
            
            if (L > R)
            {
                int temp = L;
                L = R;
                R = temp;
            }

            case_swapped[L - 1] += 1;
            case_swapped[R] -= 1;
        }

        for (int i = 1; i < case_swapped.Length; i++)
        {
            case_swapped[i] += case_swapped[i - 1];
        }

        for (int i = 0; i < S.Length; i++)
        {
            if (case_swapped[i] % 2 == 1)
                SwapCaseAt(S, i);
        }

        Console.WriteLine(new string(S));
    }

    static void SwapCaseAt(char[] s, int index)
    {
        if (char.IsUpper(s[index]))
            s[index] = char.ToLower(s[index]);
        else
            s[index] = char.ToUpper(s[index]);
    }

}