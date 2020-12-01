#include <iostream>

void swap(int* a, int p1, int p2)
{
	int tmp = *(a+p1);
	*(a+p1) = *(a+p2);
	*(a+p2) = tmp;
}

int getPivot(int* a)
{	
	return (sizeof(a) / sizeof(int)) / 2;
}

void quicksort(int* a, int low, int high)
{
	//base case: it's already sorted if there's only one element.
	if(high - low <= 1)
	{
		return;
	}

	int pivot = getPivot(a);
	int lWalker = low;
	int rWalker = high;
	//put the pivot to the end of the array
	for(int i=0; i<7;i++)
	{
		std::cout<< a[i] << ", ";
		if(i==6)
		{
			std::cout<<std::endl;
		}
	}
	swap(a, pivot, high);
	std::cout << lWalker << ": LW - RW : " << rWalker << std::endl;
	std::cout <<"PIVOT: " << pivot << std::endl; 
	std::cout <<"LOW: " << low << std::endl; 
	std::cout <<"HIGH: " << high << std::endl; 
	for(int i=0; i<7;i++)
	{
		std::cout<< a[i] << ", ";
	}
	std::cin.get();
	do
	{
//		std::cout << "stuck here?" << std::endl;
		while(lWalker <= high && *(a+lWalker) < *(a+high))
		{
			std::cout<< "LW: " << lWalker << std::endl;
			lWalker++;
		}
		while(rWalker >= low && *(a+rWalker) > *(a+high))
		{
			std::cout<< "RW: " << rWalker << std::endl;
			rWalker--;

		}
		swap(a,*(a+lWalker), *(a+rWalker));

		//swap the pivot element to its proper position
		if(rWalker <= lWalker)
		{
			swap(a,lWalker,high);
		}

		std::cout << lWalker << ": LW - RW : " << rWalker << std::endl;
	}
	while(lWalker <= rWalker);
	

	quicksort(a, low, pivot);
	quicksort(a, pivot+1,high);

}



int main()
{
	int a[] = {3,4,5,1,2,6,8,7};

//	for(int i = 0; i<7; i++)
//	{
//		std::cout<< a[i] << ", ";
//	}
	quicksort(a,0,7);

	for(int i = 0; i<7; i++)
	{
		std::cout<< a[i] << ", ";
	}
	 return 0;
}
