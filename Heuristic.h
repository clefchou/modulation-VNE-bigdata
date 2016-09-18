#include "common.h"
#include "Graph.h"


class Nodes{
public:
	int vertexID;
	int degree;
	
};

class Heu_return{				//�����洢�������ͬ�������ij��Ӧvector�в�ͬ��Ԫ��
public:
	int isSuccess;
	vector<int> grid_a;				//ij��a�Ŀ�ʼλ��
	vector<int> demand_tail;			//ij��ͷ�ڵ�i�����������еı��
	vector<int> demand_head;			//ij��β�ڵ�j�����������еı��
	vector<int> total_distance;		//�ܵĴ���
	vector<int> physical_distance;	//�ܵ�������룬�����ж��Ƿ񳬹�mod��������
	vector<vector<int> > edge_head;	//ӳ�����������ߵ�ͷ�ڵ���
	vector<vector<int> > edge_tail;	//ӳ�����������ߵ�β�ڵ���
	vector<int> bandwidth;
	vector<int> modtype;
	double proccessTime, resultWeight; 

};


class Heuristic{
private:
	Network  *ori , *aux , *demand, *resource;
	Network auxGraph;
	//Network auxGraph;
	//Event result;
	vector<Edge> edges_before,edges_after, edges_middle;
	vector<Nodes> nodes;
	vector<vector<int>> FIk;//��¼�ڵ�ӳ��
	vector<int> last_vertex_ID;		//��¼һ�η���dijkstra ���ص����磬�ǵ����㡣
		

	static const int inf = 10000000;
	FILE *logFile, *optimalData;
	
	
	double solve();
	void sortnetwork();
	Network auxGraph_generate(int demand_head, int demand_tail, int a, int g, int maxdistance);
	int findpath();
	int findpath(Network *r,int source_vertexID, int dest_vertexID);
	
public:
	
	Heuristic();
	Heuristic(Network *d,Network *r,FILE *lf);
	Event solveByHeuristic(Network *d, Network *r, FILE *logFile);
	Heu_return work();
	~Heuristic();


};


