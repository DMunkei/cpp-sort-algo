#include <iostream>

void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int getPivot(int* a)
{	
	return (sizeof(a) / sizeof(int)) / 2;
}
int partition(int* a, int low, int high)
{
	//base case: it's already sorted if there's only one element.

	int pivot = getPivot(a);
	int lWalker = low;
	int rWalker = high;

	swap(&a[pivot], &a[high]);
//	std::cout << lWalker << ": LW - RW : " << rWalker << std::endl;
//	std::cout <<"PIVOT: " << pivot << std::endl; 
//	std::cout <<"LOW: " << low << std::endl; 
//	std::cout <<"HIGH: " << high << std::endl; 
	do
	{
//		std::cout << "stuck here?" << std::endl;
		while(lWalker <= high && a[lWalker] < a[high])
		{
			lWalker++;
		}
		while(rWalker >= low && a[rWalker] > a[high])
		{
			rWalker--;

		}
		swap(&a[lWalker], &a[rWalker]);

		//swap the pivot element to its proper position
		if(rWalker <= lWalker)
		{
			swap(&a[lWalker],&a[high]);
		}

	}
	while(lWalker < rWalker);
	return lWalker;
}

void quicksort(int* a, int low, int high)
{
	if((high - low) <= 1 )
	{
		return;
	}
	int pivot = partition(a,low,high);

	quicksort(a, low, pivot-1);
	quicksort(a, pivot+1,high);

}



void showArray(int* a,int n){
	for(int i =0; i<n;i++)
	{
		std::cout<< a[i] << "\t";
	}
}
int main()
{
	int a[] = {3,4,5,1,2,6,8,7,420,99,0,674,300};
	int n = sizeof(a) /sizeof(int);
	std::cout<<"pre"<<std::endl;
	showArray(a,n);
	quicksort(a,0,n-1);
	std::cout<<"post"<<std::endl;
	showArray(a,n);
	 return 0;
}
