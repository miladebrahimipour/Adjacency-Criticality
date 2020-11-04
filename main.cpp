// SA_Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iomanip>
#include "gate.h"
#include "Functions.h"
#include "Timing_Analysis.h"
using namespace std;


const double Vdd = 1.1;
const double Vth = 0.4;
const double inputsSignalProbability = 0.5;
const double activityFactor = 0.5;
const double inputTransition = 0.067257142857;


void Initialization1(vector<int> &, vector<nodes> &, vector<int> &, vector<gate> &, string);
int _tmain(int argc, _TCHAR* argv[])
{
	int count;
	int level = 3;
	int i, j, no = 0;
	double temp = 0, temp1;
	double Constraint;
	double temp_Yield;
	double Area = 0, Area1 = 0, delta_Area;
	double mean, Var, t;
	double temp_mean, temp_var;
	vector<int> inputs, outputs;
	vector<nodes> node;
	vector<gate> topological;
	vector<Critical> Criticality, Criticality1;
	string FileName, output_FileName;
	Sink sink;
	fstream Results;
	clock_t clk;
	clk = clock();
	srand(time(0));
	output_FileName = "C499_Iterations_C.txt";
	FileName = "C499.bench";
	Results.open(output_FileName, ios::out | ios::ate | ios::app);
	Initialization1(inputs, node, outputs, topological, FileName);
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].output.size() == 0)
		{
			topological[i].setCL(10);
			//if (topological[i].getGateName() != "AND")
				//topological[i].setCL(5);
		}
	}
	Spatial_Correlation(topological, inputs);
	SSTA(topological, &sink, initial, 1);
	//*****************************************************************************
	temp = Variance(sink.Arrival_Vth_sensitivity, sink.Arrival_Vth_rand_sensitivity);
	//Results << left << setw(21) << "Bench" << setw(21) << "initial_mean" << setw(21) << "initial_variance" << setw(21) << "lifetime_mean" << setw(21)
		//<< "lifetime_varianc" << setw(21) << "opt_lifetime_mean" << setw(21) << "opt_lifetime_variance" << setw(21) << "     Area" << endl;
	//Results << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	Results << left << setw(21) << "Bench" << setw(21) << "initial_mean" << setw(21) << "initial_variance" << setw(21) << "initial_delay"
		    << setw(21) << "optimized_mean" << setw(21) << "optimized_variance" << setw(21) << "optimized_delay" << endl;
	Results << left << setw(21) << FileName << setw(21) << sink.Arrival_mean << setw(21) << temp << setw(21) << (sink.Arrival_mean + (3 * sqrt(temp)));
	cout << no << "\t" << sink.Arrival_mean << "\t" << temp << endl;
	temp_mean = sink.Arrival_mean;
	temp_var = temp;
	///******************************************************************************
	//temp = 0;
	//temp = Variance(sink.delay_Vth_sensitivity, sink.delay_Vth_rand_sensitivity);
	//Constraint = 0.85 * (sink.delay_mean + (3 * sqrt(temp)));
	//Constraint = sink.delay_mean + (3 * sqrt(temp));
	//temp = Variance(sink.Arrival_Vth_sensitivity, sink.Arrival_Vth_rand_sensitivity);
	//temp1 = sink.Arrival_mean + (3 * sqrt(temp));
	
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
			Area += 2;
	}

	//topological[10].setRAT_mean(0.9 * topological[10].getRAT_mean());
	//topological[9].setRAT_mean(0.8 * topological[9].getRAT_mean());
	Criticality_Computation(topological, &sink);
	//Rank_Criticality(topological, Criticality);

	//Average_Criticality_Computation_Incremental(topological);
	//Average_Criticality_Computation_Level3(topological);
	//Average_Criticality_Computation(topological);
	Average_Criticality_Computation_Levelized(topological, level);
	Rank_Average_Criticality(topological, Criticality1);
	Constraint = temp1 = Yield_Computation(sink.Arrival_mean, sink.Arrival_Vth_sensitivity, sink.Arrival_Vth_rand_sensitivity, sink.delay_mean,
		sink.delay_Vth_sensitivity, sink.delay_Vth_rand_sensitivity);
	cout << "\t" << Constraint << endl;
	//temp_Yield = Yield_Optimization(topological, Criticality1, &sink, &count, 0.97, Constraint, 30, Area, &mean, &Var, &t, level);
	//Yield_Optimization_file(topological, Criticality, &sink, &count, 2, Constraint, &mean, &Var, &t, level);
	//Time_Optimization_Time_Constraint(topological, Criticality, &sink, &count, 5*60, &mean, &Var, &t, level);
	Time_Optimization_Iteration_Constraint(topological, Criticality1, &sink, &count, 15, &mean, &Var, &t, level);
	clk = clock() - clk;
	Results << left << setw(21) << mean << setw(21) << Var << setw(21) << t << endl;
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
			Area1 += topological[i].getWL_ratio();
	}
	delta_Area = ((Area1 * 100) / Area) - 100;
	Results << "area_per : " << delta_Area << "\t" << "\t" << "count : " << count << endl;
	Results << "mean_per : " << (((temp_mean * 100) / mean) - 100) << "\t" << "\t" << "var_per : " << (((temp_var * 100) / Var) - 100) << endl;
	Results << "time : " << ((double)clk) / (CLOCKS_PER_SEC) << endl;
	Results << "size : " << (topological.size() - inputs.size()) << endl;
	//Results << "Yield : " << temp_Yield << endl;
	Results << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
	return 0;
 	//Gate_Sizing(topological, Criticality, inputs, &sink, Constraint, temp1, &count);
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
		{
			Area1 += topological[i].getWL_ratio();
			Area += 2;
		}
	}
	delta_Area = ((Area1 * 100) / Area) - 100;
	//****************************************************************************
	temp = 0;
	temp = Variance(sink.Arrival_Vth_sensitivity, sink.Arrival_Vth_rand_sensitivity);
	Results << left << setw(21) << sink.Arrival_mean << setw(21) << temp << setw(21) << "     " << delta_Area << endl;
	Results << count << endl;
	Results << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	//****************************************************************************
	Results.close();
	return 0;
}


void Initialization1(vector<int> &inputs, vector<nodes> &node, vector<int> &outputs, vector<gate> &topological, string FileName)
{
	ReadFromFile1(inputs, outputs, node, FileName);
	topologicalSort(inputs, node, topological, Vdd, Vth, inputsSignalProbability, activityFactor, inputTransition);
	SparsGenerator(topological, node);
	UpdateNodes(topological, Vdd, Vth);
}