#include <iostream>

void goisland(int** arr, int m, int n, int i, int j, int numb) 
{
	arr[i][j] = numb;
	
	if (i + 1 < m) 
		if (arr[i + 1][j] == 0) 
			goisland(arr, m, n, i + 1, j, numb);
		
	

	if (j + 1 < n) 
		if (arr[i][j + 1] == 0) 
			goisland(arr, m, n, i, j + 1, numb);
		
	
	
	if (j > 0) 
		if (arr[i][j - 1] == 0)
			goisland(arr, m, n, i, j - 1, numb);
	

    if (i > 0)
		if (arr[i - 1][j - 1] == 0)
			goisland(arr, m, n, i - 1, j - 1, numb);

}

int found(int** arr, int m, int n) {
	int counter = 0; 
    int numb = 2;

	for (int i = 0; i < m; i++) 
    {
		for (int j = 0; j < n; j++) 
        {
			if (arr[i][j] == 0) 
            {
				counter++;
				goisland(arr, m, n, i, j, numb);
				numb += 2;
			}
		}
	}
	return counter;
}

void return_correct(int** arr,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
                continue;
            else
                arr[i][j]=0;
        }
    }
}

void display(int** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		std::cout << '\n';
		for (int j = 0; j < n; j++) {
			std::cout << arr[i][j] << ' ';
		}
	}
}