/*
图论算法中任意两点之间的最短距离
floyed-warshall算法
	两点(u,v)之间的最短路径p与特定点k之间的关系：
		k在p上，则(u,k)的最短距离与(k,v)的最短距离之和
		k不在p上，不变
	
	基本思想：
	base:
		可经过的点的集合为空，用直接相连的边来初始化
	step:
		设可经过的点的集合为(v1,v2,...,vn),假设此时对于任意两点之间的最短距离'已知。对于可经过的点的集合为(v1,v2,...,vn,v{n+1})，任意两点之间的距离更新方式为：如果过v{n+1}的最短路径与不过v{n+1}的最短路径的最小值。
	可经过的点的集合最多为点集的全集。//这也是终止条件

	空间优化：
		每次在同一个矩阵进行更新。
*/

#include <iostream>
#include <vector>

#define MAX 100000
using namespace std ;
void read_data( vector<vector<int>>& data );
void warshall( vector<vector<int>>& data );
void show( const vector<vector<int>>& data );

int main(){
	vector<vector<int>> data ;
	read_data( data );
	warshall( data );
	show( data );
}

void read_data( vector<vector<int>>& data ){
	int size ;
	cin >> size ;
	vector<int> temp ;
	for( int i = 0 ; i < size ; i ++)
		temp.push_back( MAX );
	for( int i = 0 ; i < size ; i ++)
		data.push_back( temp );
	
	// read 
	int count , begin, end, len ;
	cin >> count ;
	for( int i = 0 ; i < count ; i++ ){
		cin >> begin >> end >> len ;
		data[begin][end] = len ;
		//data[end][begin] = len ;
	}
	return ;
}
void warshall( vector<vector<int>>& data ){
	for ( int k = 0 ; k < data.size() ; k ++ ){
		for( int i = 0 ; i < data.size() ; i ++){
			for( int j = 0 ; j < data.size(); j ++){
				if (data[i][j] > data[i][k]+data[k][j])
					data[i][j] = data[i][k]+data[k][j];
			}
		}
	}
	return ;
}
void show( const vector<vector<int>>& data ){
	for( int i = 0 ; i < data.size() ; i ++ ){
		for( int j = 0 ; j < data[i].size() ; j ++){
			cout << data[i][j] << "  ";
		}
		cout << endl ;
	}
	return ;
}

