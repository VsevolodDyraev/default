#include <iostream>

using namespace std;

  
// Эта функция заполняет глубину i-го элемента в parent []. Глубина
// заполнено в глубину [i].

void fillDepth(int parent[], int i, int deep[])

{
    if (deep[i])
        return;

    if (parent[i] == -1)
    {
        deep[i] = 1;
        return;
    }


    if (deep[parent[i]] == 0)
        fillDepth(parent, parent[i], deep);

    deep[i] = deep[parent[i]]  + 1;
}


int hight(int parent[], int n)
{

    int deep[n];

    for (int i = 0; i < n; i++)
        deep[i] = 0;


    for (int i = 0; i < n; i++)
        fillDepth(parent, i, deep);


    int max = deep[0];

    for (int i=1; i<n; i++)
        if (max < deep[i])
            max = deep[i];

    return max;
}


int main()

{

    int arr[] = {-1, 0, 0, 1, 1, 3, 5};

    std::cout << "Height is " << hight(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;

} 