using System.Text;

class Program
{
    static void Main()
    {
        int testCase;
        string input; 
        input = Console.ReadLine();
        testCase = int.Parse(input);

        for (int i = 0; i < testCase; i++)
        {
            LinkedList<char> list = new LinkedList<char>();
            list.AddFirst(' ');

            LinkedListNode<char> node;
            node = list.Last;

            string edit;
            edit = Console.ReadLine();

            for (int j = 0; j < edit.Length; j++)
            {
                if (edit[j] == '<')
                {
                    if (node.Previous != null)
                    {
                        node = node.Previous;
                    }
                }
                else if (edit[j] == '>')
                {
                    if (node.Next != null)
                    {
                        node = node.Next;
                    }
                }
                else if (edit[j] == '-')
                {
                    if (node.Value != ' ')
                    {
                        node = node.Previous;
                        list.Remove(node.Next);
                    }
                }
                else
                {
                    char insertChar = edit[j];
                    list.AddAfter(node, insertChar);
                    node = node.Next;
                }
            }

            StringBuilder stringBuilder = new StringBuilder();
            node = list.First.Next;
            for (int j = 1; j < list.Count - 1; j++)
            {
                stringBuilder.Append(node.Value);
                node = node.Next;
            }
            stringBuilder.Append(node.Value);
            Console.WriteLine(stringBuilder.ToString());
            stringBuilder.Clear();
        }
    }
}