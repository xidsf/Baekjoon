class Program
{
    static int currentcurser = 0;
    static string str;

    static int SetInputToInt()
    {
        int data;
        for (int i = currentcurser; i < str.Length; i++)
        {
            if (str[i] == ' ')
            {
                data = int.Parse(str.Substring(currentcurser, i - currentcurser));
                currentcurser = i + 1;
                return data;
            }
        }
        data = int.Parse(str.Substring(currentcurser, str.Length - currentcurser));
        currentcurser = 0;
        return data;
    }


    static int cnt = default;
    static int currentCount = 0;

    static void MergeSort(ref int[] arr, int start, int end)
    {
        if(start < end)
        {
            int half = (end + start) / 2;
            MergeSort(ref arr, start, half);
            MergeSort(ref arr, half + 1, end);
            Merge(ref arr, start, half, end);
        }
    }

    static void Merge(ref int[] arr, int start, int half, int end)
    {
        if (currentCount > cnt)
        {
            return;
        }

        int[] tempArr = new int[end - start + 1];
        for(int i = 0; i < end - start + 1; i++)
        {
            tempArr[i] = arr[i + start];
        }
        int cursor = start;

        if (start < end)
        {
            int startCursor = 0;
            int halfCursor = (end - start) / 2 + 1;

            int fEnd = end - start;
            int fHalf = halfCursor - 1;
            while (startCursor <= fHalf && halfCursor <= fEnd)
            {
                if (tempArr[startCursor] < tempArr[halfCursor])
                {
                    arr[cursor++] = tempArr[startCursor++];
                }
                else
                {
                    arr[cursor++] = tempArr[halfCursor++];
                }

                if(++currentCount == cnt)
                {
                    Console.WriteLine(arr[--cursor]);
                    return;
                }
            }
            while(startCursor <= fHalf)
            {
                arr[cursor++] = tempArr[startCursor++];
                if (++currentCount == cnt)
                {
                    Console.WriteLine(arr[--cursor]);
                    return;
                }
            }
            while (halfCursor <= fEnd)
            {
                arr[cursor++] = tempArr[halfCursor++];
                if (++currentCount == cnt)
                {
                    Console.WriteLine(arr[--cursor]);
                    return;
                }
                
            }

        }
    }

    static void Main()
    {
        int size = default;
        

        str = Console.ReadLine();

        size = SetInputToInt();
        cnt = SetInputToInt();

        int[] arr = new int[size];
        str = Console.ReadLine();
        for(int i = 0; i < size; i++)
        {
            arr[i] = SetInputToInt();
        }

        MergeSort(ref arr, 0, size - 1);

        if(currentCount < cnt)
        {
            Console.WriteLine(-1);
        }
    }
}