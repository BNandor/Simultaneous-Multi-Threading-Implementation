#include <iostream>
#include <queue>
#include "PARALLEL.h"
#include <string>


struct job{

	int *row;
	int length;
	concurrent::Output<int>* output;

};


struct SumFunctor
{
	void operator()( job& temp)const{

		int sum = 0;
		for (int i = 0; i < temp.length; ++i)
		{
			
			sum+=temp.row[i];
		}
		temp.output->push(sum);
	}
};

int main(int argc,char* args[]){
	
	if(argc<=1){std::cout<<"usage: N ThreadNum"<<std::endl;return -1;}

	int N=std::stoi(args[1]);
	int threads;
	if(argc == 3){
		threads=std::stoi(args[2]);

	}else{
		threads=1;
	}
	int matrix[N][N];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{	
			matrix[i][j]=1;
			
		}	
	}
	
	std::queue<job> jobs;
	job jobdata;
	concurrent::Output<int> output;
	for (int i = 0; i < N; ++i)
	{
		jobdata.row=matrix[i];
		jobdata.length=N;
		jobdata.output=&output;	
		jobs.push(jobdata);
	}
	

	SumFunctor summer;
	concurrent::PARALLEL<SumFunctor,job> magic(summer,jobs,threads);
	magic.pstart();
	
	int result = 0;
	while(output.size() > 0){
		result+=output.pop();
	}
	std::cout<<"Sum = "<<result;
	


	return 0;
}
