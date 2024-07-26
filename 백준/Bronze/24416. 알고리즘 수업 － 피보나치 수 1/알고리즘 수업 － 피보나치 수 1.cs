class Program
{
    static int fibCount = 0;
    static int dynFibCount = 0;
    static int[] cache = new int[41];

    static int fib(int n)
    {
        if (n == 1 || n == 2)
        {
            fibCount++;
            return 1;
        }
        else
        {
            return fib(n - 1) + fib(n - 2);
        }
    }

    static int dynfib(int n)
    {
        
        if (cache[n] == 0)
        {
            dynFibCount++;
            cache[n] = dynfib(n - 1) + dynfib(n - 2);
            return cache[n];
        }
        else
        {
            return cache[n];
        }
    }


    static void Main()
    {
        int input;
        input = int.Parse(Console.ReadLine());
        cache[1] = 1;
        cache[2] = 2;

        fib(input);
        dynfib(input);

        Console.WriteLine($"{fibCount} {dynFibCount}"); 
    }
}