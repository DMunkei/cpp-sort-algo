#include <iostream>
void swap(int* a, int p1, int p2)
{
	int tmp = *(a+p1);
	*(a+p1) = *(a+p2);
	*(a+p2) = tmp;
}



void main()
{
	int a[6] = {4,5,3,2,38,1};
	int length = sizeof(a)/sizeof(int);

	int* aP = a;

	std::cout << "Array presort:" << " ";
	for(int i=0; i<length; i++)
	{
		std::cout << *(aP+i) << ",";
	}
	std::cout << "" << std::endl;
	for(int i=0; i<length; i++)
	{
		std::cout << "index i: " << i << " element: " << a[i] << std::endl;
		for(int j=0; j<length-1; j++)
		{
			std::cout<< "index j: " << j << " element: " << a[j] << std::endl;
			std::cout<<  *(a+j) << ">" << *(a+j+1) << std::endl;
			if(*(a+j) > *(a+j+1))
			{
				std::cout<<"swapping" << *(a+j) << " with" << *(a+j+1) << std::endl;
				swap(aP,j,j+1);
			}
		}
	}
	std::cout << "" << std::endl;
	std::cout << "Array postsort:" << " ";
	for(int i=0; i<length; i++)
	{
		std::cout << *(aP+i) << ",";
	}

	return 0;
}
