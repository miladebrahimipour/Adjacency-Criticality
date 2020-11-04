#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include "Functions.h"
#include "gate.h"
using namespace std;


#pragma once
struct Critical
{
	double criticality;
	int index;
};


enum mode { initial = 0, initial_optimization};


double Normal_Distribution_CDF(double x)
{
	double temp;
	int i, j = 0;
	bool flag = false;
	string STRING, str_temp, s, tz;
	basic_string <char>::size_type indexCh1, indexCh2;
	fstream infile;
	infile.open("Normal_Distribution_Predefined_table.txt");
	str_temp = to_string(x);
	str_temp = str_temp.substr(0, 4);
	temp = stod(str_temp);
	str_temp.erase(3, str_temp.length());
	if (x >= (temp + 0.005))
		temp += 0.01;
	s = to_string(temp);
	tz = s.substr(3, 1);
	j = stoi(to_string(temp).substr(3, 1));
	while (!infile.eof()) // To get you all the lines.
	{
		getline(infile, STRING); // Saves the line in STRING.
		if (STRING.substr(0, 3) == str_temp)
		{
			STRING.erase(0, 3);
			i = 0;
			while (true)
			{
				indexCh1 = STRING.find_first_of(",");
				STRING.erase(indexCh1, 1);
				indexCh2 = STRING.find_first_of(",");
				if (indexCh2 == string::npos)
					indexCh2 = STRING.length();
				if (i == j)
					return stod(STRING.substr(indexCh1, indexCh2 - indexCh1));
				STRING.erase(0, indexCh2);
				i++;
			}
		}
	}
	infile.close();
}


void swap(vector<Critical> &Criticality, int i, int j)
{
	double temp;
	int temp1;

	temp = Criticality[i].criticality;
	temp1 = Criticality[i].index;
	Criticality[i].criticality = Criticality[j].criticality;
	Criticality[i].index = Criticality[j].index;
	Criticality[j].criticality = temp;
	Criticality[j].index = temp1;
}


double Phi(double x)
{
	if (x <= 0.05)
		return 0.01994;
	else if (x <= 0.10)
		return 0.03983;
	else if (x <= 0.15)
		return 0.05962;
	else if (x <= 0.20)
		return 0.07926;
	else if (x <= 0.25)
		return 0.09871;
	else if (x <= 0.30)
		return 0.11791;
	else if (x <= 0.35)
		return 0.13683;
	else if (x <= 0.40)
		return 0.15542;
	else if (x <= 0.45)
		return 0.17365;
	else if (x <= 0.50)
		return 0.19146;
	else if (x <= 0.55)
		return 0.20884;
	else if (x <= 0.60)
		return 0.22575;
	else if (x <= 0.65)
		return 0.24215;
	else if (x <= 0.70)
		return 0.25804;
	else if (x <= 0.75)
		return 0.27337;
	else if (x <= 0.80)
		return 0.28814;
	else if (x <= 0.85)
		return 0.30234;
	else if (x <= 0.90)
		return 0.31594;
	else if (x <= 0.95)
		return 0.32894;
	else if (x <= 1.00)
		return 0.34134;
	else if (x <= 1.05)
		return 0.35314;
	else if (x <= 1.10)
		return 0.36433;
	else if (x <= 1.15)
		return 0.37493;
	else if (x <= 1.20)
		return 0.38493;
	else if (x <= 1.25)
		return 0.39435;
	else if (x <= 1.30)
		return 0.40320;
	else if (x <= 1.35)
		return 0.41149;
	else if (x <= 1.40)
		return 0.41924;
	else if (x <= 1.45)
		return 0.42647;
	else if (x <= 1.50)
		return 0.43319;
	else if (x <= 1.55)
		return 0.43943;
	else if (x <= 1.60)
		return 0.44520;
	else if (x <= 1.65)
		return 0.45053;
	else if (x <= 1.70)
		return 0.45543;
	else if (x <= 1.75)
		return 0.45994;
	else if (x <= 1.80)
		return 0.46407;
	else if (x <= 1.85)
		return 0.46784;
	else if (x <= 1.90)
		return 0.47128;
	else if (x <= 1.95)
		return 0.47441;
	else if (x <= 2.00)
		return 0.47726;
	else if (x <= 2.05)
		return 0.47982;
	else if (x <= 2.10)
		return 0.48214;
	else if (x <= 2.15)
		return 0.48422;
	else if (x <= 2.20)
		return 0.48610;
	else if (x <= 2.25)
		return 0.48778;
	else if (x <= 2.30)
		return 0.48928;
	else if (x <= 2.35)
		return 0.49061;
	else if (x <= 2.40)
		return 0.49180;
	else if (x <= 2.45)
		return 0.49286;
	else if (x <= 2.50)
		return 0.49379;
	else if (x <= 2.55)
		return 0.49461;
	else if (x <= 2.60)
		return 0.49534;
	else if (x <= 2.65)
		return 0.49597;
	else if (x <= 2.70)
		return 0.49653;
	else if (x <= 2.75)
		return 0.49702;
	else if (x <= 2.80)
		return 0.49744;
	else if (x <= 2.85)
		return 0.49781;
	else if (x <= 2.90)
		return 0.49813;
	else if (x <= 2.95)
		return 0.49841;
	else if (x <= 3.00)
		return 0.49865;
}


double UpperCase_Phi(double x)
{
	double y;
	if (x < 0)
		y = 1 - x;
	else
		y = x;
	if (y >= 4.99000000)
		return 0.9999997;
	else if (y <= -4.99000000)
		return 0.0000003;
	else
		return Normal_Distribution_CDF(y); //Phi(x);
}


double LowerCase_Phi(double x)
{
	double temp, temp1, temp2, temp3, temp4, temp5;
	temp = sqrt((2 * 3.1415));
	temp1 = 1 / temp;
	temp2 = pow(x, 2);
	temp3 = temp2 / 2;
	temp4 = -(temp3);
	temp5 = exp(temp4);
	return (temp1 * temp5);
}


double Ta(double mean1, double mean2, double teta)
{
	double temp, temp1;
	temp = (mean1 - mean2) / teta;
	/*if (temp < 0)
		temp1 = -temp;
	else
		temp1 = temp;
	if (temp1 > 1.000000e-11)
	{
		if (temp1 > 1.000000e-10)
		{
			if (temp1 > 1.000000e-9)
			{
				if (temp1 > 1.000000e-8)
				{
					temp *= 1e8;
				}
				else
				{
					temp *= 1e9;
				}
			}
			else
			{
				temp *= 1e10;
			}
		}
		else
		{
			temp *= 1e11;
		}
	}
	else
	{
		temp *= 1e11;
	}
	*/
	if (isnan(temp))
	{
		temp1 = 0;
		return Normal_Distribution_CDF(temp1);
	}
	else if (temp < 0)
	{
		temp1 = -temp;
		if (temp1 >= 4.99000000)
			return 0.0000003;
		else
			return (1 - Normal_Distribution_CDF(temp1));
	}
	else
	{
		temp1 = temp;
		if (temp1 >= 4.99000000)
			return 0.9999997;
		else
			return Normal_Distribution_CDF(temp1);
	}
}


double Ta(double mean, double SD)
{
	double temp, temp1;
	temp = (mean + (3 * SD));
	//temp = mean;
	if (temp < 0)
		temp1 = -temp;
	else
		temp1 = temp;
	if (temp1 > 1.000000e-11)
	{
		if (temp1 > 1.000000e-10)
		{
			if (temp1 > 1.000000e-9)
			{
				if (temp1 > 1.000000e-8)
				{
					temp *= 1e8;
				}
				else
				{
					temp *= 1e9;
				}
			}
			else
			{
				temp *= 1e10;
			}
		}
		else
		{
			temp *= 1e11;
		}
	}
	else
	{
		temp *= 1e11;
	}
	if (isnan(temp))
	{
		temp1 = 0;
		return Normal_Distribution_CDF(temp1);
	}
	else if (temp < 0)
	{
		temp1 = -temp;
		if (temp1 >= 4.99000000)
			return 0.0000003;
		else
			return (1 - Normal_Distribution_CDF(temp1));
	}
	else
	{
		temp1 = temp;
		if (temp1 >= 4.99000000)
			return 0.9999997;
		else
			return Normal_Distribution_CDF(temp1);
	}
}


double Variance(vector<double> &Vth_sensitivity, double Vth_rand_sensitivity)
{
	int i;
	double temp = 0;
	for (i = 0; i < Vth_sensitivity.size(); i++)
	{
		if (Vth_sensitivity[i] != 0)
			temp += pow(Vth_sensitivity[i], 2);
	}

	return (temp + pow(Vth_rand_sensitivity, 2));
}


double RO_SD1_SD2(vector<double> &a_Vth_sensitivity, vector<double> &b_Vth_sensitivity)
{
	int i;
	double temp = 0;
	for (i = 0; i < a_Vth_sensitivity.size(); i++)
		temp += (a_Vth_sensitivity[i] * b_Vth_sensitivity[i]);
	return temp;
}


double Teta(double VAR1, double VAR2, double Ro_SD1_SD2)
{
	double temp;
	temp = VAR1 + VAR2 - (2 * Ro_SD1_SD2);
	return sqrt(temp);
}


#pragma once
struct Arrival
{
	vector<double> mArrival_mean;
	vector<vector<double>> mArrival_Vth_sensitivity;
	vector<double> mArrival_Vth_rand_sensitivity;
};


#pragma once
struct Sink
{
	vector<int> input_index;
	double delay_mean;
	vector<double> delay_Vth_sensitivity;
	double delay_Vth_rand_sensitivity;
	double Arrival_mean;
	vector<double> Arrival_Vth_sensitivity;
	double Arrival_Vth_rand_sensitivity;

	void make_input_index(vector<gate> &topological)
	{
		int i;
		for ((i = topological.size() - 1); i >= 0; i--)
		{
			if ((topological[i].output.size() == 0) && topological[i].getGateName() != "INPUT")
				input_index.push_back(i);
		}
	}


	void Output_Delay(vector<gate> &topological, int mode = 0)
	{
		int i, j;
		//double temp;
		if (mode == 0)
		{
			for (i = 0; i < input_index.size(); i++)
			{
				topological[input_index[i]].setArrival_mean(topological[input_index[i]].getDelay_mean() + topological[input_index[i]].getArrival_mean());
				for (j = 0; j < 16; j++)
					topological[input_index[i]].setArrival_Vth_sensitivity(j, topological[input_index[i]].getDelay_Vth_sensitivity(j)
					+ topological[input_index[i]].getArrival_Vth_sensitivity(j));
				topological[input_index[i]].setArrival_Vth_rand_sensitivity(sqrt(pow(topological[input_index[i]].getDelay_Vth_rand_sensitivity(), 2)
					+ pow(topological[input_index[i]].getArrival_Vth_rand_sensitivity(), 2)));
			}
		}
		else
		{
			for (i = 0; i < input_index.size(); i++)
			{
				topological[input_index[i]].setArrival_mean(topological[input_index[i]].getDelay_mean() + topological[input_index[i]].getArrival_mean()
					+ topological[input_index[i]].getAging_Delay_mean());
				for (j = 0; j < 16; j++)
				{
					topological[input_index[i]].setArrival_Vth_sensitivity(j, topological[input_index[i]].getDelay_Vth_sensitivity(j)
						+ topological[input_index[i]].getArrival_Vth_sensitivity(j) - topological[input_index[i]].getAging_Delay_Vth_sensitivity(j));
				}

				topological[input_index[i]].setArrival_Vth_rand_sensitivity(sqrt(pow(topological[input_index[i]].getDelay_Vth_rand_sensitivity()
					- topological[input_index[i]].getAging_Delay_Vth_rand_sensitivity(), 2) + pow(topological[input_index[i]].getArrival_Vth_rand_sensitivity(), 2)));
				//topological[input_index[i]].setArrival_Vth_rand_sensitivity(sqrt(pow(topological[input_index[i]].getDelay_Vth_rand_sensitivity(), 2) 
				//+ pow(topological[input_index[i]].getArrival_Vth_rand_sensitivity(), 2) + pow(topological[input_index[i]].getAging_Delay_Vth_rand_sensitivity(), 2)));
			}
		}
	}


	void Arrival_Max(vector<gate> &topological, int mode = 0)
	{
		int i, j;
		//int k;
		//double L_Phi, U_Phi, teta, ta, VAR1, VAR2, VAR_max, VAR_min, Ro_SD1_SD2, temp;
		double temp1 = 0;

		delay_Vth_sensitivity.resize(16);
		Arrival_Vth_sensitivity.resize(16);
		
		Arrival_mean = topological[input_index[0]].getArrival_mean();
		for (j = 0; j < 16; j++)
		{
			Arrival_Vth_sensitivity[j] = topological[input_index[0]].getArrival_Vth_sensitivity(j);
		}
		Arrival_Vth_rand_sensitivity = topological[input_index[0]].getArrival_Vth_rand_sensitivity();
		for (i = 1; i < input_index.size(); i++)
		{
			Arrival_mean = max(Arrival_mean, topological[input_index[i]].getArrival_mean());
			for (j = 0; j < 16; j++)
				Arrival_Vth_sensitivity[j] = max(Arrival_Vth_sensitivity[j], topological[input_index[i]].getArrival_Vth_sensitivity(j));
			Arrival_Vth_rand_sensitivity = max(Arrival_Vth_rand_sensitivity, topological[input_index[i]].getArrival_Vth_rand_sensitivity());
		}
		
		/*
		Arrival_mean = topological[input_index[0]].getArrival_mean();
		for (j = 0; j < 16; j++)
		{
			Arrival_Vth_sensitivity[j] = topological[input_index[0]].getArrival_Vth_sensitivity(j);
		}
		Arrival_Vth_rand_sensitivity = topological[input_index[0]].getArrival_Vth_rand_sensitivity();
		for (i = 1; i < input_index.size(); i++)
		{
			VAR1 = Variance(Arrival_Vth_sensitivity, Arrival_Vth_rand_sensitivity);
			VAR2 = Variance(topological[input_index[i]].getArrival_Vth_sensitivity(), topological[input_index[i]].getArrival_Vth_rand_sensitivity());
			Ro_SD1_SD2 = RO_SD1_SD2(Arrival_Vth_sensitivity, topological[input_index[i]].getArrival_Vth_sensitivity());
			teta = Teta(VAR1, VAR2, Ro_SD1_SD2);
			temp = (Arrival_mean - topological[input_index[i]].getArrival_mean()) / teta;
			L_Phi = LowerCase_Phi(temp);
			ta = Ta(Arrival_mean, topological[input_index[i]].getArrival_mean(), teta);
			Arrival_mean = (Arrival_mean * ta) + (topological[input_index[i]].getArrival_mean() * (1 - ta)) + (teta * L_Phi);
			VAR_max = ((VAR1 + pow(Arrival_mean, 2)) * ta) + ((VAR2 + pow(topological[input_index[i]].getArrival_mean(), 2)) * (1 - ta))
			+ ((Arrival_mean + topological[input_index[i]].getArrival_mean()) * teta * L_Phi) - pow(Arrival_mean, 2);
			for (j = 0; j < 16; j++)
			{
			Arrival_Vth_sensitivity[j] = (Arrival_Vth_sensitivity[j] * ta) + (topological[input_index[i]].getArrival_Vth_sensitivity(j) * (1 - ta));
			temp1 += pow(Arrival_Vth_sensitivity[j], 2);
			}
			Arrival_Vth_rand_sensitivity = sqrt(VAR_max - temp1);
			temp1 = 0;
		}
		*/
	}
};


void SSTA_ArrivalTime(vector<gate> &topological, Sink *sink, int mode = 0)
{
	int i, j, k;
	//double L_Phi, teta, ta, VAR1, VAR2, VAR_max, Ro_SD1_SD2;
	//double temp, temp2;
	double temp1 = 0;
	vector<Arrival> AT;
	AT.resize(topological.size());

	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
		{
			// max
			
			topological[i].setArrival_mean(AT[i].mArrival_mean[0]);
			for (k = 0; k < 16; k++)
			{
				topological[i].setArrival_Vth_sensitivity(k, AT[i].mArrival_Vth_sensitivity[0][k]);
			}
			topological[i].setArrival_Vth_rand_sensitivity(AT[i].mArrival_Vth_rand_sensitivity[0]);
			for (j = 1; j < AT[i].mArrival_mean.size(); j++)
			{
				topological[i].setArrival_mean(max(topological[i].getArrival_mean(), AT[i].mArrival_mean[j]));
				for (k = 0; k < 16; k++)
					topological[i].setArrival_Vth_sensitivity(k, max(topological[i].getArrival_Vth_sensitivity(k), AT[i].mArrival_Vth_sensitivity[j][k]));
				topological[i].setArrival_Vth_rand_sensitivity(max(topological[i].getArrival_Vth_rand_sensitivity(), AT[i].mArrival_Vth_rand_sensitivity[j]));
			}
			
			/*
			topological[i].setArrival_mean(AT[i].mArrival_mean[0]);
			for (k = 0; k < 16; k++)
			{
				topological[i].setArrival_Vth_sensitivity(k, AT[i].mArrival_Vth_sensitivity[0][k]);
			}
			topological[i].setArrival_Vth_rand_sensitivity(AT[i].mArrival_Vth_rand_sensitivity[0]);
			for (j = 1; j < AT[i].mArrival_mean.size(); j++)
			{
				VAR1 = Variance(topological[i].getArrival_Vth_sensitivity(), topological[i].getArrival_Vth_rand_sensitivity());
				VAR2 = Variance(AT[i].mArrival_Vth_sensitivity[j], AT[i].mArrival_Vth_rand_sensitivity[j]);
				Ro_SD1_SD2 = RO_SD1_SD2(topological[i].getArrival_Vth_sensitivity(), AT[i].mArrival_Vth_sensitivity[j]);
				teta = Teta(VAR1, VAR2, Ro_SD1_SD2);
				temp = (topological[i].getArrival_mean() - AT[i].mArrival_mean[j]) / teta;
				if(isnan(temp))
					temp = 0;
				L_Phi = LowerCase_Phi(temp);
				ta = Ta(topological[i].getArrival_mean(), AT[i].mArrival_mean[j], teta);
				topological[i].setArrival_mean((topological[i].getArrival_mean() * ta) + (AT[i].mArrival_mean[j] * (1 - ta)) + (teta * L_Phi));
				VAR_max = ((VAR1 + pow(topological[i].getArrival_mean(), 2)) * ta) + ((VAR2 + pow(AT[i].mArrival_mean[j], 2)) * (1 - ta))
				+ ((topological[i].getArrival_mean() + AT[i].mArrival_mean[j]) * teta * L_Phi) - pow(topological[i].getArrival_mean(), 2);
				for (k = 0; k < 16; k++)
				{
				topological[i].setArrival_Vth_sensitivity(k, (topological[i].getArrival_Vth_sensitivity(k) * ta) + (AT[i].mArrival_Vth_sensitivity[j][k] * (1 - ta)));
				temp1 += pow(topological[i].getArrival_Vth_sensitivity(k), 2);
				}
				topological[i].setArrival_Vth_rand_sensitivity(sqrt(VAR_max - temp1));
				temp1 = 0;
			}
			*/
			// sum
			if (mode == 0)
			{
				for (j = 0; j < topological[i].output.size(); j++)
				{
					AT[topological[i].output[j]].mArrival_mean.push_back(topological[i].getDelay_mean() + topological[i].getArrival_mean());
					AT[topological[i].output[j]].mArrival_Vth_sensitivity.resize(AT[topological[i].output[j]].mArrival_Vth_sensitivity.size() + 1);
					for (k = 0; k < 16; k++)
					{
						AT[topological[i].output[j]].mArrival_Vth_sensitivity[AT[topological[i].output[j]].mArrival_Vth_sensitivity.size() - 1].push_back(
							topological[i].getDelay_Vth_sensitivity(k) + topological[i].getArrival_Vth_sensitivity(k));
					}
					AT[topological[i].output[j]].mArrival_Vth_rand_sensitivity.push_back(sqrt(pow(topological[i].getDelay_Vth_rand_sensitivity(), 2)
						+ pow(topological[i].getArrival_Vth_rand_sensitivity(), 2)));
				}
			}
			else
			{
				for (j = 0; j < topological[i].output.size(); j++)
				{
					AT[topological[i].output[j]].mArrival_mean.push_back(topological[i].getDelay_mean() + topological[i].getArrival_mean()
						+ topological[i].getAging_Delay_mean());
					AT[topological[i].output[j]].mArrival_Vth_sensitivity.resize(AT[topological[i].output[j]].mArrival_Vth_sensitivity.size() + 1);
					for (k = 0; k < 16; k++)
					{
						AT[topological[i].output[j]].mArrival_Vth_sensitivity[AT[topological[i].output[j]].mArrival_Vth_sensitivity.size() - 1].push_back(
							topological[i].getDelay_Vth_sensitivity(k) + topological[i].getArrival_Vth_sensitivity(k) - topological[i].getAging_Delay_Vth_sensitivity(k));
					}

					AT[topological[i].output[j]].mArrival_Vth_rand_sensitivity.push_back(sqrt(pow(topological[i].getDelay_Vth_rand_sensitivity()
						- topological[i].getAging_Delay_Vth_rand_sensitivity(), 2) + pow(topological[i].getArrival_Vth_rand_sensitivity(), 2)));
					//AT[topological[i].output[j]].mArrival_Vth_rand_sensitivity.push_back(sqrt(pow(topological[i].getDelay_Vth_rand_sensitivity(), 2) 
					//+ pow(topological[i].getArrival_Vth_rand_sensitivity(), 2) + pow(topological[i].getAging_Delay_Vth_rand_sensitivity(), 2))); 
				}
			}
		}
		else
		{
			for (j = 0; j < topological[i].output.size(); j++)
			{
				AT[topological[i].output[j]].mArrival_mean.push_back(0);
				AT[topological[i].output[j]].mArrival_Vth_sensitivity.resize(AT[topological[i].output[j]].mArrival_Vth_sensitivity.size() + 1);
				for (k = 0; k < 16; k++)
				{
					AT[topological[i].output[j]].mArrival_Vth_sensitivity[AT[topological[i].output[j]].mArrival_Vth_sensitivity.size() - 1].push_back(0);
				}
				AT[topological[i].output[j]].mArrival_Vth_rand_sensitivity.push_back(0);
			}
		}
	}
}


void SSTA_ReqiredArrivalTime(vector<gate> &topological, Sink *sink, int mode = 0)
{
	int i, j, k;
	//double L_Phi, teta, ta, VAR1, VAR2, VAR_min, Ro_SD1_SD2;
	//double temp;
	double temp1 = 0;
	vector<Arrival> AT;
	AT.resize(topological.size());

	for ((i = topological.size() - 1); i >= 0; i--)
	{
		if ((topological[i].output.size() != 0) && (topological[i].getGateName() != "INPUT"))
		{
			// min
			
			topological[i].setRAT_mean(AT[i].mArrival_mean[0]);
			for (k = 0; k < 16; k++)
			{
				topological[i].setRAT_Vth_sensitivity(k, AT[i].mArrival_Vth_sensitivity[0][k]);
			}
			topological[i].setRAT_Vth_rand_sensitivity(AT[i].mArrival_Vth_rand_sensitivity[0]);
			for (j = 1; j < AT[i].mArrival_mean.size(); j++)
			{
				topological[i].setRAT_mean(min(topological[i].getRAT_mean(), AT[i].mArrival_mean[j]));
				for (k = 0; k < 16; k++)
					topological[i].setRAT_Vth_sensitivity(k, min(topological[i].getRAT_Vth_sensitivity(k), AT[i].mArrival_Vth_sensitivity[j][k]));
				topological[i].setRAT_Vth_rand_sensitivity(min(topological[i].getRAT_Vth_rand_sensitivity(), AT[i].mArrival_Vth_rand_sensitivity[j]));
			}
			
			/*
			topological[i].setRAT_mean(AT[i].mArrival_mean[0]);
			for (k = 0; k < 16; k++)
			{
				topological[i].setRAT_Vth_sensitivity(k, AT[i].mArrival_Vth_sensitivity[0][k]);
			}
			topological[i].setRAT_Vth_rand_sensitivity(AT[i].mArrival_Vth_rand_sensitivity[0]);
			for (j = 1; j < AT[i].mArrival_mean.size(); j++)
			{
				VAR1 = Variance(topological[i].getRAT_Vth_sensitivity(), topological[i].getRAT_Vth_rand_sensitivity());
				VAR2 = Variance(AT[i].mArrival_Vth_sensitivity[j], AT[i].mArrival_Vth_rand_sensitivity[j]);
				Ro_SD1_SD2 = RO_SD1_SD2(topological[i].getRAT_Vth_sensitivity(), AT[i].mArrival_Vth_sensitivity[j]);
				teta = Teta(VAR1, VAR2, Ro_SD1_SD2);
				temp = (AT[i].mArrival_mean[j] - topological[i].getRAT_mean()) / teta;
				if (isnan(temp))
				temp = 0;
				L_Phi = LowerCase_Phi(temp);
				ta = Ta(AT[i].mArrival_mean[j], topological[i].getRAT_mean(), teta);
				topological[i].setRAT_mean((topological[i].getRAT_mean() * ta) + (AT[i].mArrival_mean[j] * (1 - ta)) - (teta * L_Phi));
				VAR_min = ((VAR1 + pow(topological[i].getRAT_mean(), 2)) * ta) + ((VAR2 + pow(AT[i].mArrival_mean[j], 2)) * (1 - ta))
				- ((topological[i].getRAT_mean() + AT[i].mArrival_mean[j]) * teta * L_Phi) - pow(topological[i].getRAT_mean(), 2);
				for (k = 0; k < 16; k++)
				{
				topological[i].setRAT_Vth_sensitivity(k, abs((topological[i].getRAT_Vth_sensitivity(k) * ta) + (AT[i].mArrival_Vth_sensitivity[j][k] * (1 - ta))));
				temp1 += pow(topological[i].getRAT_Vth_sensitivity(k), 2);
				}

				topological[i].setRAT_Vth_rand_sensitivity(sqrt(abs((VAR_min - temp1))));
				temp1 = 0;
			}
			*/

			//sub         //*************************************** correct
			if (mode == 0)
			{
				for (j = 0; j < topological[i].getIndex_Inputs().size(); j++)
				{
					AT[topological[i].getIndex_Inputs()[j]].mArrival_mean.push_back(topological[i].getRAT_mean() - topological[i].getDelay_mean());
					AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.resize(AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.size() + 1);
					for (k = 0; k < 16; k++)
					{
						AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity[AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.size() - 1].push_back(
							topological[i].getRAT_Vth_sensitivity(k) - topological[i].getDelay_Vth_sensitivity(k));
					}
					AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_rand_sensitivity.push_back(
						sqrt(pow(topological[i].getDelay_mean(), 2) + pow(topological[i].getArrival_mean(), 2)));
				}
			}
			else
			{
				for (j = 0; j < topological[i].getIndex_Inputs().size(); j++)
				{
					AT[topological[i].getIndex_Inputs()[j]].mArrival_mean.push_back(
						topological[i].getRAT_mean() - (topological[i].getDelay_mean() + topological[i].getAging_Delay_mean()));
					AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.resize(AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.size() + 1);
					for (k = 0; k < 16; k++)
					{
						AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity[AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.size() - 1].push_back(
							topological[i].getRAT_Vth_sensitivity(k) - (topological[i].getDelay_Vth_sensitivity(k) - topological[i].getAging_Delay_Vth_sensitivity(k)));
					}

					AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_rand_sensitivity.push_back(
						sqrt(pow(topological[i].getDelay_mean() - topological[i].getAging_Delay_mean(), 2) + pow(topological[i].getRAT_mean(), 2)));
					//AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_rand_sensitivity.push_back(
					//sqrt(pow(topological[i].getDelay_mean(), 2) + pow(topological[i].getRAT_mean(), 2) + pow(topological[i].getAging_Delay_mean(), 2)));
				}
			}
		}
		else if ((topological[i].getGateName() == "INPUT") || ((topological[i].output.size() == 0) && topological[i].getGateName() == "INPUT"))
			continue;
		else
		{
			for (j = 0; j < topological[i].getIndex_Inputs().size(); j++)
			{
				AT[topological[i].getIndex_Inputs()[j]].mArrival_mean.push_back(topological[i].getRAT_mean());
				AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.resize(AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.size() + 1);
				for (k = 0; k < 16; k++)
				{
					AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity[AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_sensitivity.size() - 1]
						.push_back(topological[i].getRAT_Vth_sensitivity(k));
				}
				AT[topological[i].getIndex_Inputs()[j]].mArrival_Vth_rand_sensitivity.push_back(topological[i].getRAT_Vth_rand_sensitivity());
			}
		}
	}
}


void SSTA(vector<gate> &topological, Sink *sink, mode Mode, double constr)
{
	int i, j, k;
	//double VAR1, VAR2, Ro_SD1_SD2, teta;
	SSTA_ArrivalTime(topological, sink, 0);// Mode);
	if (Mode == initial)
	{
		sink->make_input_index(topological);
		//**** calculate RAT
		sink->Output_Delay(topological, 0);// Mode);
		sink->Arrival_Max(topological, 0);// Mode);
		sink->delay_mean = constr * sink->Arrival_mean;
		for (k = 0; k < 16; k++)
			sink->delay_Vth_sensitivity[k] = constr * sink->Arrival_Vth_sensitivity[k];
		sink->delay_Vth_rand_sensitivity = constr * sink->Arrival_Vth_rand_sensitivity;
		for (i = 0; i < sink->input_index.size(); i++)
		{
			topological[sink->input_index[i]].setRAT_mean(sink->delay_mean);
			for (j = 0; j < 16; j++)
			{
				topological[sink->input_index[i]].setRAT_Vth_sensitivity(j, sink->delay_Vth_sensitivity[j]);
			}
			topological[sink->input_index[i]].setRAT_Vth_rand_sensitivity(sink->delay_Vth_rand_sensitivity);
		}
		SSTA_ReqiredArrivalTime(topological, sink, 0);// Mode);
	}
	else if (Mode == initial_optimization)
	{
		sink->Output_Delay(topological, 0);// Mode);
		sink->Arrival_Max(topological, 0);// Mode);
		SSTA_ReqiredArrivalTime(topological, sink, 0);// Mode);
	}
}


void Criticality_Computation(vector<gate> &topological, Sink *sink)
{
	//double x;
	int i, j;
	double VAR1, VAR2, Ro_SD1_SD2, teta, U_Phi;
	double mean, Vth_rand_sensitivity, dVth_sensitivity;
	vector<double> Vth_sensitivity;
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
		{
			/*if (i == 241)
			cin >> x;*/
			Vth_sensitivity.clear();
			Vth_sensitivity.resize(16);
			mean = topological[i].getArrival_mean() - topological[i].getRAT_mean();
			for (j = 0; j < 16; j++)
			{
				Vth_sensitivity[j] = topological[i].getArrival_Vth_sensitivity(j) - topological[i].getRAT_Vth_sensitivity(j);
			}
			Vth_rand_sensitivity = topological[i].getArrival_Vth_rand_sensitivity() - topological[i].getRAT_Vth_rand_sensitivity();
			VAR1 = Variance(Vth_sensitivity, Vth_rand_sensitivity);
			VAR2 = Variance(sink->delay_Vth_sensitivity, sink->delay_Vth_rand_sensitivity);
			Ro_SD1_SD2 = RO_SD1_SD2(Vth_sensitivity, sink->delay_Vth_sensitivity);
			teta = Teta(VAR1, VAR2, Ro_SD1_SD2);
			topological[i].setCriticality(Ta(mean, sink->delay_mean, teta));
		}
	}
}


void Average_Criticality_Computation(vector<gate> &topological)
{
	int i, j, k, t;
	double temp;
	queue<int> q;
	vector<bool> visited;
	visited.resize(topological.size());

	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].output.size() == 0)
		{
			topological[i].setFan_out_Average_Criticality(1);
			topological[i].setFan_out_number(1);
			continue;
		}
		temp = 0;
		k = 0;
		visited.clear();
		visited.resize(topological.size());
		if (topological[i].getGateName() != "INPUT")
		{
			for (j = 0; j < topological[i].output.size(); j++)
			{
				//temp = max(temp, topological[topological[i].output[j]].getCriticality());
				temp += topological[topological[i].output[j]].getCriticality();
				k++;
				visited[topological[i].output[j]] = true;
				q.push(topological[i].output[j]);
			}
			while (!q.empty())
			{
				t = q.front();
				q.pop();
				for (j = 0; j < topological[t].output.size(); j++)
				{
					if (visited[topological[t].output[j]] != true)
					{
						//temp = max(temp, topological[topological[t].output[j]].getCriticality());
						temp += topological[topological[t].output[j]].getCriticality();
						k++;
						visited[topological[t].output[j]] = true;
						q.push(topological[t].output[j]);
					}
				}
			}
			topological[i].setFan_out_Average_Criticality(temp);
			topological[i].setFan_out_number(k);
		}
		//topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getCriticality()) / (topological[i].getFan_out_number() + 1));
	}
	
	
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
		{

			//temp = topological[i].getFan_out_Average_Criticality() / topological[i].getFan_out_number();
			//topological[i].setFan_out_Average_Criticality(temp);
			//temp = topological[i].getFan_in_Average_Criticality() / topological[i].getFan_in_number();
			//topological[i].setFan_in_Average_Criticality(temp);

			topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getCriticality()) / (topological[i].getFan_out_number() + 1));
		}
		else
			topological[i].setAverage_Criticality(0);
	}
	
	//**********************************
	/*
	for (i = 0; i < topological.size(); i++)
	{
		temp = 0;
		k = 0;
		visited.clear();
		visited.resize(topological.size());
		if (topological[i].getGateName() != "INPUT")
		{
			for (j = 0; j < topological[i].getIndex_Inputs().size(); j++)
			{
				if (topological[topological[i].getIndex_Inputs()[j]].getGateName() != "INPUT")
				{
					//temp = max(temp, topological[topological[i].getIndex_Inputs()[j]].getCriticality());
					temp += topological[topological[i].getIndex_Inputs()[j]].getCriticality();
					k++;
					visited[topological[i].getIndex_Inputs()[j]] = true;
					q.push(topological[i].getIndex_Inputs()[j]);
				}
			}
			if (k == 0)
			{
				topological[i].setFan_in_Average_Criticality(1);
				topological[i].setFan_in_number(1);
				continue;
			}
			while (!q.empty())
			{
				t = q.front();
				q.pop();
				for (j = 0; j < topological[t].getIndex_Inputs().size(); j++)
				{
					if (topological[topological[t].getIndex_Inputs()[j]].getGateName() != "INPUT")
					{
						if (visited[topological[t].getIndex_Inputs()[j]] != true)
						{
							//temp = max(temp, topological[topological[t].getIndex_Inputs()[j]].getCriticality());
							temp += topological[topological[t].getIndex_Inputs()[j]].getCriticality();
							k++;
							visited[topological[t].getIndex_Inputs()[j]] = true;
							q.push(topological[t].getIndex_Inputs()[j]);
						}
					}
				}
			}
			topological[i].setFan_in_Average_Criticality(temp);
			topological[i].setFan_in_number(k);
		}
	}
	*/

	/*
	for (i = 0; i < topological.size(); i++)
	{
		temp = 0;
		k = 0;
		visited.clear();
		visited.resize(topological.size());
		if (topological[i].getGateName() != "INPUT")
		{
			for (j = 0; j < topological[i].output.size(); j++)
			{
				temp += topological[topological[i].output[j]].getCriticality();
				k++;
				visited[topological[i].output[j]] = true;
				q.push(topological[i].output[j]);
			}
			while (!q.empty())
			{
				t = q.front();
				q.pop();
				for (j = 0; j < topological[t].output.size(); j++)
				{
					if (visited[topological[t].output[j]] != true)
					{
						temp += topological[topological[t].output[j]].getCriticality();
						k++;
						visited[topological[t].output[j]] = true;
						q.push(topological[t].output[j]);
					}
				}
			}
			topological[i].setFan_out_Average_Criticality(temp);
			topological[i].setFan_out_number(k);
		}
		topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getCriticality()) / (topological[i].getFan_out_number() + 1));
	}
	//**********************************

	for (i = 0; i < topological.size(); i++)
	{
		temp = 0;
		k = 0;
		visited.clear();
		visited.resize(topological.size());
		if (topological[i].getGateName() != "INPUT")
		{
			for (j = 0; j < topological[i].getIndex_Inputs().size(); j++)
			{
				if (topological[topological[i].getIndex_Inputs()[j]].getGateName() != "INPUT")
				{
					temp += topological[topological[i].getIndex_Inputs()[j]].getCriticality();
					k++;
					visited[topological[i].getIndex_Inputs()[j]] = true;
					q.push(topological[i].getIndex_Inputs()[j]);
				}
			}
			while (!q.empty())
			{
				t = q.front();
				q.pop();
				for (j = 0; j < topological[t].getIndex_Inputs().size(); j++)
				{
					if (topological[topological[t].getIndex_Inputs()[j]].getGateName() != "INPUT")
					{
						if (visited[topological[t].getIndex_Inputs()[j]] != true)
						{
							temp += topological[topological[t].getIndex_Inputs()[j]].getCriticality();
							k++;
							visited[topological[t].getIndex_Inputs()[j]] = true;
							q.push(topological[t].getIndex_Inputs()[j]);
						}
					}
				}
			}
			topological[i].setFan_in_Average_Criticality(temp);
			topological[i].setFan_in_number(k);
		}
	}
	*/

	/*
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
			topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getFan_in_Average_Criticality() + topological[i].getCriticality()) /
			(topological[i].getFan_in_number() + topological[i].getFan_out_number() + 1));
		else
			topological[i].setAverage_Criticality(0);
	}
	*/
	/*
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
			topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getCriticality()) /
			(topological[i].getFan_out_number() + 1));
		else
			topological[i].setAverage_Criticality(0);
	}
	*/
	/*
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
		{
			if (topological[i].getFan_in_number() == 0)
				topological[i].setAverage_Criticality(((topological[i].getCriticality()) * (topological[i].getFan_out_Average_Criticality() / topological[i].getFan_out_number())));
			else if (topological[i].getFan_out_number() == 0)
				topological[i].setAverage_Criticality(((topological[i].getFan_in_Average_Criticality() / topological[i].getFan_in_number()) * (topological[i].getCriticality())));
			else
				topological[i].setAverage_Criticality(((topological[i].getFan_in_Average_Criticality() / topological[i].getFan_in_number()) *
				(topological[i].getCriticality()) * (topological[i].getFan_out_Average_Criticality() / topological[i].getFan_out_number())));
		}
		else
			topological[i].setAverage_Criticality(0);
	}
	*/
	///////////////////////////*************************************************************************
	/*
	for (i = topological.size() - 1; i >= 0; i--)
	{
		if (topological[i].output.size() == 0)
			topological[i].setFan_out_Average_Criticality(topological[i].getCriticality());
	}

	for (i = topological.size() - 1; i >= 0; i--)
	{
		temp = 0;
		if ((topological[i].output.size() != 0) && (topological[i].getGateName() != "INPUT"))
		{
			for (j = 0; j < topological[i].output.size(); j++)
				temp += topological[topological[i].output[j]].getAverage_Criticality();
			topological[i].setAverage_Criticality(temp / topological[i].output.size());
		}
		//topological[i].setAverage_Criticality((topological[i].getAverage_Criticality() + topological[i].getCriticality()) / 2);
	}
	
	for (i = 0; i < topological.size(); i++)
	{
		temp = 0;
		k = 0;
		if (topological[i].getGateName() != "INPUT")
		{
			for (j = 0; j < topological[i].getIndex_Inputs().size(); j++)
			{
				if (topological[topological[i].getIndex_Inputs()[j]].getGateName() != "INPUT")
				{
					temp += topological[topological[i].getIndex_Inputs()[j]].getFan_in_Average_Criticality();
					k++;
				}
			}
			if (k != 0)
				topological[i].setFan_in_Average_Criticality(temp / k);
			else
				topological[i].setFan_in_Average_Criticality(topological[i].getCriticality());
			//topological[i].setAverage_Criticality((topological[i].getAverage_Criticality() + topological[i].getFan_in_Average_Criticality()) / 2);
			topological[i].setAverage_Criticality(topological[i].getFan_in_Average_Criticality() * topological[i].getCriticality() * topological[i].getFan_out_Average_Criticality());
		}
	}
	*/
}


void Average_Criticality_Computation_Incremental(vector<gate> &topological)
{
	int i, j;
	//int k, t;
	//double temp;
	queue<int> q;
	vector<bool> visited;
	visited.resize(topological.size());
	
	for ((i = topological.size() - 1); i >= 0; i--)
	{
		if (topological[i].getGateName() == "INPUT")
		{
			topological[i].setAverage_Criticality(0);
			continue;
		}
		topological[i].setFan_out_Average_Criticality(0);
		topological[i].setFan_out_number(0);
		if (topological[i].output.size() == 0)
		{
			topological[i].setAverage_Criticality(topological[i].getCriticality());
			//topological[i].setAverage_Criticality(1);
			topological[i].setFan_out_number(0);
			continue;
		}
		for (j = 0; j < topological[i].output.size(); j++)
		{
			topological[i].setFan_out_Average_Criticality(topological[i].getFan_out_Average_Criticality() + topological[topological[i].output[j]].getCriticality()
			                                                                                      + topological[topological[i].output[j]].getFan_out_Average_Criticality());
			topological[i].setFan_out_number(topological[i].getFan_out_number() + topological[topological[i].output[j]].getFan_out_number() + 1);
		}
		topological[i].setAverage_Criticality((topological[i].getCriticality() + topological[i].getFan_out_Average_Criticality()) / (topological[i].getFan_out_number() + 1));
	}
}


void Average_Criticality_Computation_Level3(vector<gate> &topological)
{
	int i, j, k, t, z, l, m;
	int level = 0;
	double temp;
	queue<int> q;
	vector<bool> visited;
	visited.resize(topological.size());

	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].output.size() == 0)
		{
			topological[i].setFan_out_Average_Criticality(1);
			topological[i].setFan_out_number(1);
			continue;
		}
		if (topological[i].getGateName() == "INPUT")
		{
			topological[i].setAverage_Criticality(0);
			continue;
		}
		temp = 0;
		t = 0;
		level = 0;
		visited.clear();
		visited.resize(topological.size());
		for (j = 0; j < topological[i].output.size(); j++)
		{
			z = topological[i].output[j];
			temp += topological[z].getCriticality();
			t++;
			for (k = 0; k < topological[z].output.size(); k++)
			{
				m = topological[z].output[k];
				temp += topological[m].getCriticality();
				t++;
				for (l = 0; l < topological[m].output.size(); l++)
				{
					temp += topological[topological[m].output[l]].getCriticality();
					t++;
				}
			}
		}
		topological[i].setFan_out_Average_Criticality(temp);
		topological[i].setFan_out_number(t);
	}


	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
		{

			//temp = topological[i].getFan_out_Average_Criticality() / topological[i].getFan_out_number();
			//topological[i].setFan_out_Average_Criticality(temp);
			//temp = topological[i].getFan_in_Average_Criticality() / topological[i].getFan_in_number();
			//topological[i].setFan_in_Average_Criticality(temp);

			topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getCriticality()) / (topological[i].getFan_out_number() + 1));
		}
		else
			topological[i].setAverage_Criticality(0);
	}
}


struct Level
{
	int index;
	int level;
};


void Average_Criticality_Computation_Levelized(vector<gate> &topological, int level_constraint)
{
	int i, j, k;
	int level = 0;
	double temp;
	vector<bool> visited;
	visited.resize(topological.size());
	queue<Level> st;
	Level lv, t;
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].output.size() == 0)
		{
			topological[i].setFan_out_Average_Criticality(1);
			topological[i].setFan_out_number(1);
			continue;
		}
		temp = 0;
		level = 1;
		k = 0;
		visited.clear();
		visited.resize(topological.size());
		if (topological[i].getGateName() != "INPUT")
		{
			for (j = 0; j < topological[i].output.size(); j++)
			{
				//temp = max(temp, topological[topological[i].output[j]].getCriticality());
				temp += topological[topological[i].output[j]].getCriticality();
				k++;
				visited[topological[i].output[j]] = true;
				lv.index = topological[i].output[j];
				lv.level = level;
				st.push(lv);
			}
			level++;
			while (!st.empty())
			{
				t = st.front();
				st.pop();
				if (t.level == level_constraint)
					continue;
				for (j = 0; j < topological[t.index].output.size(); j++)
				{
					if (visited[topological[t.index].output[j]] != true)
					{
						//temp = max(temp, topological[topological[t.index].output[j]].getCriticality());
						temp += topological[topological[t.index].output[j]].getCriticality();
						k++;
						visited[topological[t.index].output[j]] = true;
						lv.index = topological[t.index].output[j];
						lv.level = t.level + 1;
						st.push(lv);
					}
				}
			}
			topological[i].setFan_out_Average_Criticality(temp);
			topological[i].setFan_out_number(k);
			topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getCriticality()) / (topological[i].getFan_out_number() + 1));
			//topological[i].setAverage_Criticality(topological[i].getFan_out_Average_Criticality());
		}
		else
			topological[i].setAverage_Criticality(0);
	}
}


void Average_Criticality_Computation_Levelized_Sum(vector<gate> &topological, int level_constraint)
{
	int i, j, k;
	int level = 0;
	double temp;
	queue<Level> st;
	Level lv, t;
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].output.size() == 0)
		{
			topological[i].setFan_out_Average_Criticality(1);
			topological[i].setFan_out_number(1);
			continue;
		}
		temp = 0;
		level = 1;
		k = 0;
		if (topological[i].getGateName() != "INPUT")
		{
			for (j = 0; j < topological[i].output.size(); j++)
			{
				//temp = max(temp, topological[topological[i].output[j]].getCriticality());
				temp += topological[topological[i].output[j]].getCriticality();
				k++;
				lv.index = topological[i].output[j];
				lv.level = level;
				st.push(lv);
			}
			level++;
			while (!st.empty())
			{
				t = st.front();
				st.pop();
				if (t.level == level_constraint)
					continue;
				for (j = 0; j < topological[t.index].output.size(); j++)
				{
					//temp = max(temp, topological[topological[t].output[j]].getCriticality());
					temp += topological[topological[t.index].output[j]].getCriticality();
					k++;
					lv.index = topological[t.index].output[j];
					lv.level = t.level + 1;
					st.push(lv);
				}
			}
			topological[i].setFan_out_Average_Criticality(temp);
			topological[i].setFan_out_number(k);
			//topological[i].setAverage_Criticality((topological[i].getFan_out_Average_Criticality() + topological[i].getCriticality()) / (topological[i].getFan_out_number() + 1));
			topological[i].setAverage_Criticality(topological[i].getFan_out_Average_Criticality());
		}
		else
			topological[i].setAverage_Criticality(0);
	}
}


void Rank_Criticality(vector<gate> &topological, vector<Critical> &Criticality)
{
	int i;
	Criticality.resize(topological.size());
	for (i = 0; i < topological.size(); i++)
	{
		Criticality[i].criticality = topological[i].getCriticality();
		Criticality[i].index = i;
	}

	stable_sort(Criticality.begin(), Criticality.end(), [](const Critical &a, const Critical &b)  {	return (a.criticality < b.criticality); });
	reverse(Criticality.begin(), Criticality.end());
}


void Rank_Average_Criticality(vector<gate> &topological, vector<Critical> &Criticality)
{
	int i;
	Criticality.resize(topological.size());
	for (i = 0; i < topological.size(); i++)
	{
		Criticality[i].criticality = topological[i].getAverage_Criticality();
		Criticality[i].index = i;
	}

	stable_sort(Criticality.begin(), Criticality.end(), [](const Critical &a, const Critical &b)  {	return (a.criticality < b.criticality); });
	reverse(Criticality.begin(), Criticality.end());
}


void Spatial_Correlation(vector<gate> &topological, vector<int> input)
{
	int i, j = 1, k = 5, z = 0, m = 0;
	double temp = ceil((topological.size() - input.size()) / 4.0);
	double temp1 = ceil((topological.size() - input.size()) / 16.0);
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getGateName() != "INPUT")
		{
			topological[i].setDelay_mean();
			topological[i].setDelay_Vth_rand_sensitivity();
			topological[i].setDelay_Vth_sensitivity(0);
			topological[i].setDelay_Vth_sensitivity(j);
			z++;
			if (z == temp)
			{
				z = 0;
				j++;
			}
			topological[i].setDelay_Vth_sensitivity(k);
			m++;
			if (m == temp1)
			{
				m = 0;
				if (k != 15)
					k++;
			}
		}
	}
}


void Gate_Sizing(vector<gate> &topological, vector<Critical> &Criticality, vector<int> &inputs, Sink *sink, double terminationCondition, double Initial_Constraint, int *count)
{
	int i = 0, j = 0;
	double temp = 0;
	double Constraint;

	*count = 0;
	while (true)
	{
		if (Initial_Constraint <= terminationCondition)
			break;
		//for (i = 0; i < 50; i++)
		for (i = 0; Criticality[i].criticality >= (0.95 * Criticality[0].criticality); i++)
		{
			topological[Criticality[i].index].setWL_ratio(topological[Criticality[i].index].getWL_ratio() + 1);
			topological[Criticality[i].index].setDelay_mean();
			topological[Criticality[i].index].setDelay_Vth_rand_sensitivity();
			for (j = 0; j < 16; j++)
			{
				if (topological[Criticality[i].index].getDelay_Vth_sensitivity(j) != 0)
				{
					topological[Criticality[i].index].setDelay_Vth_sensitivity(j);
				}
			}
		}

		/*while (Criticality[i].criticality >= (0.98 * Criticality[0].criticality))
		{
			topological[Criticality[i].index].setWL_ratio(topological[Criticality[i].index].getWL_ratio() + 1);
			topological[Criticality[i].index].setDelay_mean();
			topological[Criticality[i].index].setAging_Delay_mean(10 * 365 * 24 * 60 * 60);
			topological[Criticality[i].index].setDelay_Vth_rand_sensitivity();
			topological[Criticality[i].index].setAging_Delay_Vth_rand_sensitivity(10 * 365 * 24 * 60 * 60);
			for (j = 0; j < 16; j++)
			{
				if (topological[Criticality[i].index].getDelay_Vth_sensitivity(j) != 0)
				{
					topological[Criticality[i].index].setDelay_Vth_sensitivity(j);
					topological[Criticality[i].index].setAging_Delay_Vth_sensitivity(j, 10 * 365 * 24 * 60 * 60);
				}
			}
			i++;
		}*/

		// ssta
		(*count)++;
		SSTA(topological, sink, initial_optimization, 0.8);
		for (j = 0; j < sink->Arrival_Vth_sensitivity.size(); j++)
			temp += pow(sink->Arrival_Vth_sensitivity[j], 2);
		temp += pow(sink->Arrival_Vth_rand_sensitivity, 2);
		cout << sink->Arrival_mean << "\t" << temp << endl;
		Constraint = sink->Arrival_mean + (3 * sqrt(temp));
		if (Constraint <= terminationCondition)
			break;
		Criticality_Computation(topological, sink);
		//Average_Criticality_Computation(topological);
		//Rank_Average_Criticality(topological, Criticality);
		Rank_Criticality(topological, Criticality);
		temp = 0;
	}
}


double Yield_Computation(double Delay_mean, vector<double> &Delay_Vth, double Delay_Vth_rand, double Constraint_mean, vector<double> &Constraint_Vth,
	double Constraiant_Vth_rand)
{
	/*
	double VAR1, VAR2;
	double TC, TR;

	VAR1 = Variance(Delay_Vth, Delay_Vth_rand);
	VAR2 = Variance(Constraint_Vth, Constraiant_Vth_rand);
	TC = Delay_mean + (3 * sqrt(VAR1));
	TR = Constraint_mean + (3 * sqrt(VAR2));
	*/
	int i;
	double Vth_rand_sensitivity, VAR, VAR1, VAR2, Ro_SD1_SD2;
	vector<double> Vth_sensitivity;

	Vth_sensitivity.resize(16);

	for (i = 0; i < 16; i++)
		Vth_sensitivity[i] = Constraint_Vth[i] - Delay_Vth[i];
	//Vth_rand_sensitivity = Constraiant_Vth_rand - Delay_Vth_rand;
	VAR1 = Variance(Delay_Vth, Delay_Vth_rand);
	VAR2 = Variance(Constraint_Vth, Constraiant_Vth_rand);
	Ro_SD1_SD2 = RO_SD1_SD2(Delay_Vth, Constraint_Vth);
	Vth_rand_sensitivity = Teta(VAR1, VAR2, Ro_SD1_SD2);//sqrt(pow(Constraiant_Vth_rand, 2) + pow(Delay_Vth_rand, 2) - (2 * ));
	VAR = Variance(Vth_sensitivity, Vth_rand_sensitivity);

	return Ta((Constraint_mean - Delay_mean), sqrt(VAR));
	//return Ta(Constraint_mean, Delay_mean, sqrt(VAR));
}


double Yield_Optimization(vector<gate> &topological, vector<Critical> &Criticality, Sink *sink, int *count, double Yield_Constraint, double InitialYield, double Area_Constraint, double Initial_Area, double *mean, double *VAR, double *t, int level)
{
	int i = 0, j = 0;
	//int k;
	double temp = 0, t1 = 1e9;
	double temp_Yield = 0, temp_Area, constraint;
	*count = 0;
	//for (k = 0; k < 25; k++)
	temp_Area = Initial_Area;
	while (true)
	{
		if (InitialYield >= Yield_Constraint)
			break;
		//for (i = 0; (i <= 0.2 * Criticality.size()); i++)
		for (i = 0; (Criticality[i].criticality >= 0.95 * Criticality[0].criticality); i++)
		//for (i = 0; i < 50; i++)
		{
			topological[Criticality[i].index].setWL_ratio(topological[Criticality[i].index].getWL_ratio() + 1);
			temp_Area++;
			topological[Criticality[i].index].setDelay_mean();
			topological[Criticality[i].index].setDelay_Vth_rand_sensitivity();
			for (j = 0; j < 16; j++)
			{
				if (topological[Criticality[i].index].getDelay_Vth_sensitivity(j) != 0)
				{
					topological[Criticality[i].index].setDelay_Vth_sensitivity(j);
				}
			}
		}

		(*count)++;
		SSTA(topological, sink, initial_optimization, 1);
		temp = Variance(sink->Arrival_Vth_sensitivity, sink->Arrival_Vth_rand_sensitivity);
		if ((sink->Arrival_mean + (3 * sqrt(temp))) <= t1)
		{
			t1 = sink->Arrival_mean + (3 * sqrt(temp));
			*t = sink->Arrival_mean + (3 * sqrt(temp));
			*mean = sink->Arrival_mean;
			*VAR = temp;
		}
		cout << "\t" << sink->Arrival_mean << "\t" << temp;
		temp_Yield = Yield_Computation(sink->Arrival_mean, sink->Arrival_Vth_sensitivity, sink->Arrival_Vth_rand_sensitivity, sink->delay_mean,
			sink->delay_Vth_sensitivity, sink->delay_Vth_rand_sensitivity);
		cout << "\t" << temp_Yield << endl;
		if (temp_Yield >= Yield_Constraint)
			break;
		constraint = ((temp_Area * 100) / Initial_Area) - 100;
		if (constraint >= Area_Constraint)
			break;
		Criticality_Computation(topological, sink);
		//Rank_Criticality(topological, Criticality);
		//Average_Criticality_Computation(topological);
		//Average_Criticality_Computation_Incremental(topological);
		//Average_Criticality_Computation_Level3(topological);
		Average_Criticality_Computation_Levelized(topological, level);
		Rank_Average_Criticality(topological, Criticality);
		temp = 0;
		i = 0;
	}
	return temp_Yield;
}


void Time_Optimization_Area_Constraint(vector<gate> &topological, vector<Critical> &Criticality, Sink *sink, int *count, double terminationCondition, double InitialCondition, double *mean, double *VAR, double *t, int level)
{
	int i = 0, j = 0;
	//int k;
	double temp = 0, t1 = 1e9;
	double Constraint, Area;
	*count = 0;
	Area = InitialCondition;
	while (true)
	{
		for (i = 0; (i <= 0.1 * Criticality.size()); i++)
		//for (i = 0; (Criticality[i].criticality >= 0.95 * Criticality[0].criticality); i++)
		//for (i = 0; i < 50; i++)
		{
			topological[Criticality[i].index].setWL_ratio(topological[Criticality[i].index].getWL_ratio() + 1);
			topological[Criticality[i].index].setDelay_mean();
			topological[Criticality[i].index].setDelay_Vth_rand_sensitivity();
			Area += 1;
			for (j = 0; j < 16; j++)
			{
				if (topological[Criticality[i].index].getDelay_Vth_sensitivity(j) != 0)
				{
					topological[Criticality[i].index].setDelay_Vth_sensitivity(j);
				}
			}
		}

		(*count)++;
		SSTA(topological, sink, initial_optimization, 0.98);
		temp = Variance(sink->Arrival_Vth_sensitivity, sink->Arrival_Vth_rand_sensitivity);
		if ((sink->Arrival_mean + (3 * sqrt(temp))) <= t1)
		{
			t1 = sink->Arrival_mean + (3 * sqrt(temp));
			*t = sink->Arrival_mean + (3 * sqrt(temp));
			*mean = sink->Arrival_mean;
			*VAR = temp;
		}
		cout << "\t" << sink->Arrival_mean << "\t" << temp;
		Constraint = ((Area * 100) / InitialCondition) - 100;
		if (Constraint >= terminationCondition)
			break;
		Criticality_Computation(topological, sink);
		Rank_Criticality(topological, Criticality);
		//Average_Criticality_Computation(topological);
		//Average_Criticality_Computation_Incremental(topological);
		//Average_Criticality_Computation_Level3(topological);
		//Average_Criticality_Computation_Levelized(topological, level);
		//Rank_Average_Criticality(topological, Criticality);
		temp = 0;
		i = 0;
	}
}


void Time_Optimization_Iteration_Constraint(vector<gate> &topological, vector<Critical> &Criticality, Sink *sink, int *count, int terminationCondition, double *mean, double *VAR, double *t, int level)
{
	int i = 0, j = 0, k;
	double temp = 0, t1 = 1e9;
	//double Constraint;
	*count = 0;
	for (k = 0; k < terminationCondition; k++)
	{
		for (i = 0; (i <= 0.1 * Criticality.size()); i++)
		//for (i = 0; (Criticality[i].criticality >= 0.95 * Criticality[0].criticality); i++)
		//for (i = 0; i < 50; i++)
		{
			topological[Criticality[i].index].setWL_ratio(topological[Criticality[i].index].getWL_ratio() + 1);
			topological[Criticality[i].index].setDelay_mean();
			topological[Criticality[i].index].setDelay_Vth_rand_sensitivity();
			for (j = 0; j < 16; j++)
			{
				if (topological[Criticality[i].index].getDelay_Vth_sensitivity(j) != 0)
				{
					topological[Criticality[i].index].setDelay_Vth_sensitivity(j);
				}
			}
		}

		(*count)++;
		SSTA(topological, sink, initial_optimization, 0.98);
		temp = Variance(sink->Arrival_Vth_sensitivity, sink->Arrival_Vth_rand_sensitivity);
		if ((sink->Arrival_mean + (3 * sqrt(temp))) <= t1)
		{
			t1 = sink->Arrival_mean + (3 * sqrt(temp));
			*t = sink->Arrival_mean + (3 * sqrt(temp));
			*mean = sink->Arrival_mean;
			*VAR = temp;
		}
		cout << "\t" << sink->Arrival_mean << "\t" << temp;
		Criticality_Computation(topological, sink);
		//Rank_Criticality(topological, Criticality);
		
		//Average_Criticality_Computation_Incremental(topological);
		//Average_Criticality_Computation_Level3(topological);
		//Average_Criticality_Computation(topological);
		Average_Criticality_Computation_Levelized(topological, level);
		Rank_Average_Criticality(topological, Criticality);
		temp = 0;
		i = 0;
	}
}


void Time_Optimization_Time_Constraint(vector<gate> &topological, vector<Critical> &Criticality, Sink *sink, int *count, double terminationCondition, double *mean, double *VAR, double *t, int level)
{
	clock_t clk, clk1;
	int i = 0, j = 0;
	//int k;
	double temp = 0, t1 = 1e9;
	double Constraint;
	*count = 0;
	clk = clock();
	while (true)
	{
		for (i = 0; (i <= 0.1 * Criticality.size()); i++)
		//for (i = 0; (Criticality[i].criticality >= 0.95 * Criticality[0].criticality); i++)
		//for (i = 0; i < 50; i++)
		{
			topological[Criticality[i].index].setWL_ratio(topological[Criticality[i].index].getWL_ratio() + 1);
			topological[Criticality[i].index].setDelay_mean();
			topological[Criticality[i].index].setDelay_Vth_rand_sensitivity();
			for (j = 0; j < 16; j++)
			{
				if (topological[Criticality[i].index].getDelay_Vth_sensitivity(j) != 0)
				{
					topological[Criticality[i].index].setDelay_Vth_sensitivity(j);
				}
			}
		}

		(*count)++;
		SSTA(topological, sink, initial_optimization, 0.98);
		temp = Variance(sink->Arrival_Vth_sensitivity, sink->Arrival_Vth_rand_sensitivity);
		if ((sink->Arrival_mean + (3 * sqrt(temp))) <= t1)
		{
			t1 = sink->Arrival_mean + (3 * sqrt(temp));
			*t = sink->Arrival_mean + (3 * sqrt(temp));
			*mean = sink->Arrival_mean;
			*VAR = temp;
		}
		cout << "\t" << sink->Arrival_mean << "\t" << temp;
		clk1 = clock() - clk;
		Constraint = ((double)clk1) / (CLOCKS_PER_SEC);
		if (Constraint >= terminationCondition)
			break;
		Criticality_Computation(topological, sink);
		//Rank_Criticality(topological, Criticality);
		//Average_Criticality_Computation(topological);
		//Average_Criticality_Computation_Incremental(topological);
		//Average_Criticality_Computation_Level3(topological);
		Average_Criticality_Computation_Levelized(topological, level);
		Rank_Average_Criticality(topological, Criticality);
		temp = 0;
		i = 0;
	}
}


void Yield_Optimization_file(vector<gate> &topological, vector<Critical> &Criticality, Sink *sink, int *count, double terminationCondition, double InitialCondition, double *mean, double *VAR, double *t, int level)
{
	int i = 0, j = 0, k;
	double temp = 0, t1 = 1e9;
	double Constraint;
	*count = 0;
	fstream outfile; 
	outfile.open("C499_Iterations_delay_distribution_C.bench", ios::out | ios::trunc);
	for (k = 0; k < 50; k++)
	//while (true)
	{
		if (InitialCondition >= terminationCondition)
			break;
		for (i = 0; (i <= 0.1 * Criticality.size()); i++)
		//for (i = 0; (Criticality[i].criticality >= 0.98 * Criticality[0].criticality); i++)
		//for (i = 0; i < 50; i++)
		{
			topological[Criticality[i].index].setWL_ratio(topological[Criticality[i].index].getWL_ratio() + 1);
			topological[Criticality[i].index].setDelay_mean();
			topological[Criticality[i].index].setDelay_Vth_rand_sensitivity();
			for (j = 0; j < 16; j++)
			{
				if (topological[Criticality[i].index].getDelay_Vth_sensitivity(j) != 0)
				{
					topological[Criticality[i].index].setDelay_Vth_sensitivity(j);
				}
			}
		}

		(*count)++;
		SSTA(topological, sink, initial_optimization, 0.98);
		temp = Variance(sink->Arrival_Vth_sensitivity, sink->Arrival_Vth_rand_sensitivity);
		if ((sink->Arrival_mean + (3 * sqrt(temp))) <= t1)
		{
			t1 = sink->Arrival_mean + (3 * sqrt(temp));
			*t = sink->Arrival_mean + (3 * sqrt(temp));
			*mean = sink->Arrival_mean;
			*VAR = temp;
		}
		cout << "\t" << sink->Arrival_mean << "\t" << temp << endl;
		outfile << "\t" << sink->Arrival_mean << "\t" << temp << endl;
		Constraint = Yield_Computation(sink->Arrival_mean, sink->Arrival_Vth_sensitivity, sink->Arrival_Vth_rand_sensitivity, sink->delay_mean,
			sink->delay_Vth_sensitivity, sink->delay_Vth_rand_sensitivity);
		cout << "\t" << Constraint << endl;
		if (Constraint >= terminationCondition)
			break;
		Criticality_Computation(topological, sink);
		Rank_Criticality(topological, Criticality);
		//Average_Criticality_Computation(topological);
		//Average_Criticality_Computation_Incremental(topological);
		//Average_Criticality_Computation_Level3(topological);
		//Average_Criticality_Computation_Levelized(topological, level);
		//Rank_Average_Criticality(topological, Criticality);
		temp = 0;
		i = 0;
	}
	outfile.close();
}
