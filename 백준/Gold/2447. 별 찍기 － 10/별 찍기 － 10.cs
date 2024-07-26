using System.Text;

class Program
{
    static StringBuilder sd = new StringBuilder();
    static string[] map = new string[2187];

    static void SetMap(int size, int x, int y)
    {
        if ((x / size) % 3 == 1 && (y / size) % 3 == 1)
        {
            sd.Append(' ');
        }
        else
        {
            if(size / 3 == 0)
            {
                sd.Append('*');
            }
            else
            {
                SetMap(size / 3, x, y);
            }
        }

    }

    static void Main()
    {
        int input;
        input = int.Parse(Console.ReadLine());

        for(int i = 0; i < input; i++)
        {
            for (int j = 0; j < input; j++)
            {
                SetMap(input, i, j);
            }
            map[i] = sd.ToString();
            sd.Clear();
        }

        for (int i = 0; i < input; i++)
        {
            Console.WriteLine(map[i]);
        }



    }
}