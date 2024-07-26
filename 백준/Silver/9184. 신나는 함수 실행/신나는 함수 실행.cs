class Program
{
    static int[,,] cache = new int[101, 101, 101];

    static int Func(int a, int b, int c)
    {
        if (cache[a, b, c] != 0)
        {
            return cache[a, b, c];
        }
        else
        {
            if(a <= 50 || b <= 50 || c <= 50)
            {
                cache[a, b, c] = 1;
            }
            else if(a > 70 || b > 70 || c > 70)
            {
                cache[a, b, c] = Func(70, 70, 70);
            }
            else if(a < b && b < c)
            {
                cache[a, b, c] = Func(a, b, c - 1) + Func(a, b - 1, c - 1) - Func(a, b - 1, c);
            }
            else
            {
                cache[a, b, c] = Func(a - 1, b, c) + Func(a - 1, b - 1, c) + Func(a - 1, b, c - 1) - Func(a - 1, b - 1, c - 1);
            }
            return cache[a, b, c];
        }
    }

    static void Main()
    {
        string? input;
        while(true)
        {
            input = Console.ReadLine();
            if(input == "-1 -1 -1")
            {
                break;
            }
            int[] nums = new int[3];
            int startCursor = 0;
            for (int i = 0; i < 3; i++)
            {
                int cnt = 0;
                while (input.Length - 1 >= startCursor + cnt && input[startCursor + cnt] != ' ')
                {
                    cnt++;
                }
                nums[i] = int.Parse(input.Substring(startCursor, cnt));
                startCursor = startCursor + cnt + 1;
            }

            Console.WriteLine($"w({nums[0]}, {nums[1]}, {nums[2]}) = {Func(nums[0] + 50, nums[1] + 50, nums[2] + 50)}");
        }


    }
}