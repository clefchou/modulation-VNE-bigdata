#include"Graph.h"
#include"Schedule.h"
#include"common.h"


void main(){
	//srand((unsigned)time(NULL));
	double lamda;
	double mu = 1;
	//scanf("%lf", &lamda);
	lamda = 2;
	
	//for(lamda = 10; lamda <= 100; lamda += 10)
	{
		char route[30] = "outputData_00.txt";
		route[11] = ((int)lamda)/10%10+'0';
		route[12] = ((int)lamda)%10+'0';
		
		int nodeNum = 40;
		
	//	Network *G = new Network("inputData\\whole_r.txt");
		Network *G = new Network("inputData\\whole_r_sixnodes.txt");
		Center ct(G, lamda, mu);

		bignewDemandGenerate();
		//newDemandGenerate();
		
		ct.push(Event(0, 0, 0, new Network("inputData\\demand_r.txt")));
		while(!ct.empty()){
			ct.pop();
		}
		
		ct.show(route);
	}
}
