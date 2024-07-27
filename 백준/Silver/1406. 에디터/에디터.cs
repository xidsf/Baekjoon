using System.Text;

class Program
{
    static void Main()
    {
        LinkedList<char> list = new LinkedList<char>();

        string input;
        input = " " + Console.ReadLine();
        for (int i = 0; i < input.Length; i++)
        {
            list.AddLast(input[i]);
        }

        LinkedListNode<char> node;
        node = list.Last;

        int cnt;
        input = Console.ReadLine();
        cnt = int.Parse(input);

        for (int i = 0; i < cnt; i++)
        {
            string edit;
            edit = Console.ReadLine();

            if (edit[0] == 'P')
            {
                char insertChar = edit[2];
                list.AddAfter(node, insertChar);
                node = node.Next;
            }
            else if (edit[0] == 'L')
            {
                if(node.Previous != null)
                {
                    node = node.Previous;
                }
            }
            else if (edit[0] == 'D')
            {
                if (node.Next != null)
                {
                    node = node.Next;
                }
            }
            else if (edit[0] == 'B')
            {
                if (node.Value != ' ')
                {
                    node = node.Previous;
                    list.Remove(node.Next);
                }
            }
        }

        StringBuilder stringBuilder = new StringBuilder();
        node = list.First.Next;
        for (int i = 1;i < list.Count - 1;i++)
        {
            stringBuilder.Append(node.Value);
            node = node.Next;
        }
        stringBuilder.Append(node.Value);
        Console.WriteLine(stringBuilder.ToString());
    }
}