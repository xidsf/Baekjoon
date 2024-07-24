using System.Text;

class Program
{
    static StringBuilder stringBuilder = new StringBuilder();

    static void HanoiTower(int count, int start, int sub, int target)
    {
        if(count > 1)
        {
            HanoiTower(count - 1, start, target, sub);
            stringBuilder.Append($"{start} {target}\n");
            HanoiTower(count - 1, sub, start, target);
        }
        if(count == 1)
        {
            stringBuilder.Append($"{start} {target}\n");
        }
    }

    static void Main()
    {
        int input = int.Parse(Console.ReadLine());

        Console.WriteLine(Math.Pow(2, input) - 1);

        HanoiTower(input, 1, 2, 3);

        Console.WriteLine(stringBuilder.ToString());

    }
}
