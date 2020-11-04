#include<iostream>
#include <vector>
#include<string>
using namespace std;


#pragma once
class gate
{
public:
	gate();
	virtual ~gate();
	void signalProbability();
	void activityFactor();
	double gamma(int t, double sp);// double gamma(int t, double sp);
	double dVth(int t, double sp);
	void Initialization(double, double);
	double maxSignalProbability();
	void SetCircuiteInputs(double vdd, double vth, double sp, double a);
	void setSignalProbability(double sp, int i);
	void setActivityFactor(double a, int i);
	double getSignalProbability();
	double getActivityFactor();
	vector<int>& getInputs();
	vector<int>& getIndex_Inputs();
	void setInputCapacitance();
	double getInputCapacitance(int i);
	void setCL(double c);
	void set(int I, string g, int numberOfInputs, vector<int> input, int out);
	void setID(int I);
	int getID();
	double getCL();
	string getGateName();
	void setOutputProbability(double i);
	void setOutSwitchingActivity(double i);
	//***********************************************************
	// mean
	void setDelay_mean();
	double getDelay_mean();

	void setAging_Delay_mean(int t);
	double getAging_Delay_mean();

	void setArrival_mean(double i);
	double getArrival_mean();

	void setRAT_mean(double i);
	double getRAT_mean();

	// Vth sensitivity
	void setDelay_Vth_sensitivity(int i);
    double getDelay_Vth_sensitivity(int i);

	void setAging_Delay_Vth_sensitivity(int i, int t);//void setAging_Delay_Vth_sensitivity(int i, int t);
	double getAging_Delay_Vth_sensitivity(int i);

	void setArrival_Vth_sensitivity(int i, double j);
	double getArrival_Vth_sensitivity(int i);

	void setRAT_Vth_sensitivity(int i, double j);
	double getRAT_Vth_sensitivity(int i);

	// Vth rand sensitivity
	void setDelay_Vth_rand_sensitivity();
	double getDelay_Vth_rand_sensitivity();

	void setAging_Delay_Vth_rand_sensitivity(int t);//void setAging_Delay_Vth_rand_sensitivity(int t);
	double getAging_Delay_Vth_rand_sensitivity();

	void setArrival_Vth_rand_sensitivity(double i);
	double getArrival_Vth_rand_sensitivity();

	void setRAT_Vth_rand_sensitivity(double i);
	double getRAT_Vth_rand_sensitivity();

	//***************************************************************
	vector<double>& getArrival_Vth_sensitivity();
	vector<double>& gate::getRAT_Vth_sensitivity();

	void setCriticality(double i);
	double getCriticality();

	void setAverage_Criticality(double i);
	double getAverage_Criticality();

	void setFan_in_Average_Criticality(double i);
	double getFan_in_Average_Criticality();

	void setFan_out_Average_Criticality(double i);
	double getFan_out_Average_Criticality();

	void setFan_out_number(int i);
	int getFan_out_number();

	void setFan_in_number(int i);
	int getFan_in_number();

	void setWL_ratio(double i);
	double getWL_ratio();

	vector<int> output;

private:
	double Vth;
	double Vdd;
	int ID;
	string gateName;
	int numberOfInputs;
	vector<int> input;
	vector<int> index_input;    //**********************************************************************************************************  Index_Input
	int out;
	vector<double> inputProbability;
	double outputProbability;
	double switchingActivity;
	vector<double> Cin;
	double CL;
	//double dVth;

	double Delay_mean;
	double Aging_Delay_mean;
	double Arrival_mean;
	double RAT_mean;

	vector<double> Delay_Vth_sensitivity;
	vector<double> Aging_Delay_Vth_sensitivity;
	vector<double> Arrival_Vth_sensitivity;
	vector<double> RAT_Vth_sensitivity;

	double Delay_Vth_rand_sensitivity;
	double Aging_Delay_Vth_rand_sensitivity;
	double Arrival_Vth_rand_sensitivity;
	double RAT_Vth_rand_sensitivity;

	double Criticality;
	double Average_Criticality;
	double fan_in_Average_Criticality;
	double fan_out_Average_Criticality;
	int Fan_out_number;
	int Fan_in_number;
	double WL_ratio;
};