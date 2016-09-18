#include"Graph.h"
//#include"ILPSolver.h"
#include"common.h"
#include "Heuristic.h"

#define WAIT 5
#define DEMANDNUM 1000
#define CHECKNUM 10

int uniform(int a, int b){
	return a + rand()%(b-a+1);
}

void bigtopoGenerate(char route[], int n, int mod, int maxWeight, int maxdistance) {
	/*
	�����������
	routeΪ�����ļ��洢·��
	nΪ������mΪ����
	maxCapacityΪ�����ڵ��������
	maxWeightΪ��Ȩ��Ȩ���ֵ������ֵΪ[0,maxWeight]���ȷֲ�
	*/

	FILE *out = fopen(route, "w");
	int topo[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			topo[i][j] = 0;
	int m;
	m = uniform(n, n * 3);
	fprintf(out, "%d %d %d\n", n, m, mod);
	for (int i = 0; i < n; i++)//ÿ���ڵ�ļ�������
		fprintf(out, "%d ", uniform(1, 4));
	fprintf(out, "\n");
	for (int i = 0; i < n; i++)
		fprintf(out, "%d ", maxWeight);
	fprintf(out, "\n");
	for (int i = 0; i < mod; i++)
		fprintf(out, "%d ", maxdistance);//ֻ������ͼ��Ҫmoddistance��Ϊ�̶�ֵ
	fprintf(out, "\n");
	for (int i = 1; i < n; i++) {
		int randomi = rand() % i;
		//fprintf(out, "%d %d %d %d %d\n", i, randomi, maxCapacity, maxWeight, maxdistance);
		topo[i][randomi] = 1;
	}
	for (int i = 0; i < m - n + 1; i++) {
		int u = rand() % n, v, ucount = 0;
		int uvalready = 0;
		do {
			uvalready = 0;
			v = rand() % n;
			ucount++;
			if (topo[u][v] == 1)
				uvalready = 1;
			if (ucount > n) {		//�������ײ�����ѭ�������v = 1��1��0,2,3ȫ�����ˣ��ͻ�һֱ������ת
									//u++;
				break;
			}
		} while (u == v || uvalready);
		topo[u][v] = 1;
	}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (topo[i][j] == 1)
				fprintf(out, "%d %d %d %d %d\n", i, j, uniform(1, 10), maxWeight, maxdistance);
	fclose(out);
	//system("type D:\\����\\xuni\\inputData\\demand_r.txt>>D:\\����\\xuni\\inputData\\alldemand.txt");
}

void topoGenerate(char route[], int n, int mod, int maxWeight,int maxdistance){
/*
	�����������
	routeΪ�����ļ��洢·��
	nΪ������mΪ����
	maxCapacityΪ�����ڵ��������
	maxWeightΪ��Ȩ��Ȩ���ֵ������ֵΪ[0,maxWeight]���ȷֲ�
*/
	FILE *out = fopen(route, "w");
	int topo[4][4];
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			topo[i][j] = 0;
	int m;
	switch(n)
	{
	case 2:
		m = uniform(1, 2);
	    break;
	case 3:
		m = uniform(2, 5);
		break;
	case 4:
		m = uniform(3, 6);
		break;
	}
	fprintf(out, "%d %d %d\n", n, m, mod);
	for(int i = 0; i < n; i++)//ÿ���ڵ�ļ�������
		fprintf(out, "%d ", uniform(1, 4));
	fprintf(out, "\n");
	for(int i = 0; i < n; i++)
		fprintf(out, "%d ", maxWeight);
	fprintf(out, "\n");
	for(int i = 0; i < mod; i++)
		fprintf(out, "%d ", maxdistance);//ֻ������ͼ��Ҫmoddistance��Ϊ�̶�ֵ
	fprintf(out, "\n");
	for(int i = 1; i < n; i++){
		int randomi = rand()%i;
		//fprintf(out, "%d %d %d %d %d\n", i, randomi, maxCapacity, maxWeight, maxdistance);
		topo[i][randomi] = 1;
	}
	for(int i = 0; i < m - n + 1; i++){
		int u = rand()%n, v ,ucount = 0;
		int uvalready = 0;
		do{
			uvalready = 0;
			v = rand()%n;
			ucount++;
			if(topo[u][v] == 1)
				uvalready = 1;
			if(ucount > n){		//�������ײ�����ѭ�������v = 1��1��0,2,3ȫ�����ˣ��ͻ�һֱ������ת
				//u++;
				break;
			}
		}while(u == v || uvalready);
	    topo[u][v] = 1;
	}
	for(int i = 0 ; i < 4; i++) 
		for(int j = 0; j < 4; j++)
			if(topo[i][j] == 1)
		       fprintf(out, "%d %d %d %d %d\n", i, j, uniform(1, 10), maxWeight, maxdistance);
	fclose(out);
	//system("type D:\\����\\xuni\\inputData\\demand_r.txt>>D:\\����\\xuni\\inputData\\alldemand.txt");
}

double U_Random()   /* ����һ��0~1֮�������� */
{
	double f;
	//srand( (unsigned)time( NULL ) );
	f = (float)(rand() % 100);
	/* printf("%f\n",f); */
	return f/100;
}
int possion(double lamda)  /* ����һ�����ɷֲ����������LamdaΪ����ƽ����*/
{
    int k = 0;
    long double p = 1.0;
    long double l=exp(-lamda);  /* Ϊ�˾��ȣ��Ŷ���Ϊlong double�ģ�exp(-Lambda)�ǽӽ�0��С��*/
    //printf("%.15Lf\n",l);
    while (p>=l)
    {
        double u = U_Random();
        p *= u;
        k++;
    }
    return (k-1)/2;
}
double Exponential( double Beta)
{
    double Random_Number;
    double Return_Value;
    
    Random_Number = U_Random();
    while(Random_Number<0.0000001)
    Random_Number = U_Random();
    Return_Value = -1.0 * Beta * log( Random_Number);
    return Return_Value ;

}

void bignewDemandGenerate() {
	int vn = uniform(8, 10);
	bigtopoGenerate("inputData\\demand_r.txt", vn, 4, 1, 300);
}

void newDemandGenerate(){
	int vn = uniform(2, 4);
	topoGenerate("inputData\\demand_r.txt", vn, 4, 1, 300);
}

class Center{
    private:
		int eventCount;
		int numILPSuccess, numILPBlock, numHeuSuccess;
		double totalILPTime, totalILPWeight, totalHeuTime, totalHeuWeight, HeuWeight,totalmod,totaldistance;
		
		int Success_Count,check_count;
		
		Network *resource;
		Network resource_original;
		Network *resource_Hr;
		double lamda, mu;
        priority_queue<Event> schedule;
		FILE *logFile;
		FILE *logresult;
		
        void arrange(Event cur){
			fprintf(logFile, "Event No.%d Eventtype:%d process\n", cur.ID, cur.type);

			printf("\n_________________________before arrange___________________\n");
			//if(eventCount == 4 && cur.type == 0){
			    for(int k = 0; k < resource->n; k++)
			        cout<<resource->vertexWeight[k];
				cout<<"\n";
				int m = resource->edges.size();
			    for(int ij = 0; ij < m; ij++){
				        int bandwidth = resource->edges[ij].wave.size();
				        for(int b = 0; b < bandwidth; b++)
					        cout<<resource->edges[ij].wave[b];
						printf("   ij: %d--%d \n",resource->edges[ij].tail,resource->edges[ij].head);
			}//���ڼ��
			int checkError;
			//**********************************************************************

			Heuristic *Hr = new Heuristic(cur.demand, resource, logFile);
			
			
			//**********************************************************************
			//����ILP��Ⲣ���
			printf("\nDemandNum: %d \n***************************\n",eventCount);
			if(eventCount == 100)
				printf("100!\n");

			  Event retILP = Hr->solveByHeuristic(cur.demand, resource, logFile);

			//Event retILP = solveBySimpleILP(cur.demand, resource, logFile);
			if(retILP.isSuccess){
				numILPSuccess += 1;
				totalILPTime += retILP.proccessTime;
				totalILPWeight += retILP.resultWeight;
			}
			else
				numILPBlock += 1;
			checkError = 0;
			if(retILP.isSuccess){
				int m = resource->edges.size();
				for(int ij = 0; ij < m; ij++){
					int bandwidth = resource->edges[ij].wave.size();
					for(int b = 0; b < bandwidth; b++)
						if(retILP.demand->edges[ij].wave[b] > resource->edges[ij].wave[b])
							checkError = 1;
				}
			}
			if(checkError)
				fprintf(logFile, "error, ILPSolver use unavaiable wave\n");
			else
				fprintf(logFile, "ILPSolver correct after check\n");
			/*if(retILP.isSuccess)
				fprintf(logFile, "ILP success, get object of %f, using Time %f\n ", retILP.resultWeight, retILP.proccessTime);*/
				if(retILP.isSuccess){
					//if(eventCount == 4){
					Success_Count++;
					float averagemod = 0;
					float averagedistance = 0;


				    fprintf(logFile, "ILP success, get object of %f, using Time %f\n ", retILP.resultWeight, retILP.proccessTime);
				    for(int i = 0; i < cur.demand->n; i++)
					   for(int k = 0; k < resource->n; k++)
					       if(retILP.a[i][k] == 1){
								fprintf(logFile, "A: virtualNod; %d,--> phsicalNod: %d\n ", i, k);}
					for(int i = 0; i < cur.demand->m; i++)
		                for(int j = 0; j < resource->m ; j++)
				            for (int a =0; a < resource->edges[j].bandwidth - cur.demand->edges[i].bandwidth + 1; a++)
					            for(int mod =0; mod < resource->mod; mod++)
									if(retILP.b[i][j] == 1 && retILP.b_a_mod[i][a][mod] ==1 ){
										fprintf(logFile, "Z: virtualedge; %d,--> phsicaledge: %d, startgrid: %d, modulation: %d\n", i, j, a, mod);
										averagemod += mod;//2016/9/4��� ����ƽ��mod
										averagedistance += resource->edges[j].distance;//2016/9/9 ����ƽ������
									}								
					for(int i = 0; i < cur.demand->m; i++)
		                for(int j = 0; j < resource->m ; j++)
				            for (int a =0; a < resource->edges[j].bandwidth - cur.demand->edges[i].bandwidth + 1; a++)
								if(retILP.c[i][j][a] == 1){
									fprintf(logFile, "M: virtualedge; %d,--> phsicaledge: %d, startgrid: %d\n ", i, j, a);
							}
					for(int i = 0; i < cur.demand->m; i++)
			            for (int a =0; a < resource->maxBandwidth - cur.demand->edges[i].bandwidth + 1; a++)
							if(retILP.d[i][a] == 1){
								fprintf(logFile, "T: virtualedge; %d,--> startgrid: %d\n ", i, a);
							}
					 for(int i = 0; i < cur.demand->m; i++){
		                 for(int mod =0; mod < resource->mod; mod++)
							 if(retILP.e[i][mod] == 1){
								 fprintf(logFile, "S: virtualedge; %d,--> modulation: %d\n ", i, mod);
							 }
					 }
					 totalmod += averagemod/(cur.demand->m);
					 totaldistance += averagedistance / (cur.demand->m);

				}
				else
					fprintf(logFile, "ILP failed\n");
				
			
			int thisTime = cur.arrivalTime;
			if(retILP.isSuccess){
				//������Դ
				int m = resource->edges.size();
				for(int ij = 0; ij < m; ij++){
					int bandwidth = resource->edges[ij].wave.size();
					for(int b = 0; b < bandwidth; b++)
						if(retILP.demand->edges[ij].wave[b] == 1)
							resource->edges[ij].wave[b] = 0;
				}
				for(int k = 0; k < resource->n; k++)
				    resource->vertexWeight[k] -= retILP.demand->vertexWeight[k];
					
				*(cur.demand) = *(retILP.demand);
				cur.arrivalTime +=  Exponential(mu);
				cur.type = 1;
				push(cur);
			}

						printf("\n_________________________after arrange___________________\n");
			//if(eventCount == 4 && cur.type == 0){
			    for(int k = 0; k < resource->n; k++)
			        cout<<resource->vertexWeight[k];
				cout<<"\n";
				int mm = resource->edges.size();
			    for(int ij = 0; ij < mm; ij++){
				        int bandwidth = resource->edges[ij].wave.size();
				        for(int b = 0; b < bandwidth; b++)
					        cout<<resource->edges[ij].wave[b];
						printf("   ij: %d--%d \n",resource->edges[ij].tail,resource->edges[ij].head);
			}//���ڼ��

			
			delete retILP.demand;

		//	fprintf(logresult,"%d \n",eventCount);
			if(eventCount == CHECKNUM*check_count){//����Ƿ񵽴���Ҫ��¼�Ľ׶�
				float SuccessRate = float(Success_Count)/(CHECKNUM*check_count);	//
				float AverageWeight = float(totalILPWeight )/ Success_Count;
				float AverageMod = totalmod/Success_Count;	//
				float AverageTime = float(totalILPTime)/(CHECKNUM*check_count);	//
				float AverageDistance = totaldistance / Success_Count;
				int waveCount = 0,totalwave = 0;
				for(int k = 0; k < resource->m; k++){
					for(int a = 0; a < resource->edges[k].wave.size(); a++){
						totalwave++;
						if(resource->edges[k].wave[a] == 0)
							waveCount++;
					}
				}
				float waveUtilization = float(waveCount)/totalwave;


				fprintf(logresult,"The success rate of the %dth %d events is : %f\n",check_count,CHECKNUM,SuccessRate);
				fprintf(logresult,"AverageWeight : %f \n",AverageWeight );
				fprintf(logresult,"AverageMod : %f \n",AverageMod );
				fprintf(logresult,"AverageDistance : %f \n", AverageDistance);
				fprintf(logresult,"AverageTime : %f \n",AverageTime );
				fprintf(logresult,"waveUtilization : %f \n",waveUtilization );
				fprintf(logresult,"*******************************\n\n");
/*
				 for(int ij = 0; ij < mm; ij++){
				        int bandwidth = resource->edges[ij].wave.size();
				        for(int b = 0; b < bandwidth; b++){
							int waveflag = 0;
							if(resource->edges[ij].wave[b])
								 waveflag = 1;
					        fprintf(logresult,"%d",waveflag);
						}
						fprintf(logresult,"   ij: %d--%d \n",resource->edges[ij].tail,resource->edges[ij].head);
				 }*/
			//	Success_Count = 0;
			//	totalmod = 0;
				check_count ++;

			}
			

			//��һ�������¼�
			if(eventCount < DEMANDNUM){

				bignewDemandGenerate();
				//newDemandGenerate();
				Network *new_network = new Network("inputData\\demand_r.txt");
				Event *new_event = new Event(0, thisTime + Exponential(1 / lamda), eventCount, new_network);
				push(*new_event);
				delete new_event;
				delete new_network;
			}
        }
		//�ͷ���Դ
        void release(Event cur){
			fprintf(logFile, "Event No.%d Eventtype:%d process\n", cur.ID, cur.type);
			int m = resource->edges.size();
			for(int ij = 0; ij < m; ij++){
				int bandwidth = resource->edges[ij].wave.size();
				for(int b = 0; b < bandwidth; b++)
					if(cur.demand->edges[ij].wave[b] == 1)
						resource->edges[ij].wave[b] = 1;
			}
			for(int k = 0; k < resource->n; k++)
			    resource->vertexWeight[k] += cur.demand->vertexWeight[k];
			
			printf("\n*********************************leaving event \n");
			printf("___________________________________________________________________________ \n");
			printf("___________________________________________________________________________ \n");
			 for(int k = 0; k < resource->n; k++)
			        cout<<resource->vertexWeight[k];
				cout<<"\n";
				 int mmm = resource->edges.size();
			    for(int ij = 0; ij < mmm; ij++){
				        int bandwidth = resource->edges[ij].wave.size();
				        for(int b = 0; b < bandwidth; b++)
					        cout<<resource->edges[ij].wave[b];
						printf("   ij: %d--%d \n",resource->edges[ij].tail,resource->edges[ij].head);
			}
			printf("\n********************************************** \n");	
			
			//delete cur.demand;
			
        }
    public:
		
        Center() {
			logFile = fopen("outputData\\logFile.txt", "w");
		}
        Center(Network *t, double lam, double muu){
            resource = t;
			lamda = lam;
			mu = muu;
			eventCount = 0;
			Success_Count = totalmod = 0,check_count = 1;
			numILPSuccess = numILPBlock = 0;
			totalILPTime = totalILPWeight = 0;
			logFile = fopen("outputData\\logFile.txt", "w");
			logresult = fopen("outputData\\result.txt","w");
			
        }

        void push(Event cur){
            schedule.push(cur);
			if(cur.type == 0)
			    eventCount++;
		}
        void pop(){
	
           Event cur = schedule.top();
            schedule.pop();

			if(!cur.type){
                arrange(cur);
				show("outputData\\processInfo.txt", cur.ID);
			}
			else{
                release(cur);								//�ͷ���ԴӰ�쵽resource������ô��resource��������cur�ı��������� ������ȥ�¼���
				
			}
        }
		bool empty(){
			return schedule.empty();
		}
		void show(char *outputFile, int curID = -1){
			FILE *info = fopen(outputFile, "w");
			if(curID != -1)
				fprintf(info, "lamda %.2f: demand NO.%d proccess\n\n", lamda, curID);
			else
				fprintf(info, "lamda %.2f:", lamda);
			fprintf(info, "ILP:\n\tblock: %d\n\tsuccess %d\n\ttime %f\n\tweight %f\n\n", numILPBlock, numILPSuccess, totalILPTime, totalILPWeight);
			fclose(info);
		}

		~Center(){
			fclose(logFile);
			fclose(logresult);
		}
};
