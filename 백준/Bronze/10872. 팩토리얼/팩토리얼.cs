class Program
{
    static int factorial(int n)
    {
        int ans = 1;
        if(n > 1)
        {
            ans *= factorial(n - 1);
        }
        if(n == 0)
        {
            return 1;
        }
        ans *= n;

        return ans;
    }

    static void Main()
    {
        int input = int.Parse(Console.ReadLine());

        Console.WriteLine(factorial(input));
    }
}