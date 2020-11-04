#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include "Functions.h"
#include "gate.h"
using namespace std;


struct PartialNode
{
	string gateName;
	string ID;
	int numberOfInputs;
	vector<string> input;
	string out;
};


void VerilogToPartialStruct(string FileName, vector<PartialNode> &PartialNodes, vector<int> &input, vector<int> &output)
{
	int i;
	int size = 0, size1 = 0, size2 = 0;
	fstream infile;
	string STRING;
	//string File = "C4322.v";
	basic_string <char> name, ID, out, substr;
	basic_string <char>::size_type indexCh1, indexCh2, indexCh3;
	infile.open(FileName);
	while (!infile.eof())
	{
		getline(infile, STRING);
		if (STRING[0] == '/' || STRING == "")
			continue;
		else if (STRING.find("endmodule") != string::npos)
			return;
		else if ((STRING.find("module") != string::npos))
		{
			while (true)
			{
				if (STRING.find(";") != string::npos)
					break;
				else
				{
					getline(infile, STRING);
					continue;
				}
			}
		}
		else if (STRING.find("input") != string::npos)
		{
			indexCh1 = STRING.find("t");
			STRING.erase(0, indexCh1 + 3);
			STRING = "    " + STRING;
			while (true)
			{
				indexCh1 = STRING.find("\\");
				if (indexCh1 != string::npos)
				{
					STRING.erase(indexCh1, 1);
					indexCh2 = STRING.find(",", indexCh1);
					STRING.erase(indexCh2 - 1, 1);
				}
				STRING.erase(0, 3);
				if (STRING.find(";") != string::npos)
				{
					STRING.pop_back();
					STRING.push_back(',');
					while (!STRING.empty())
					{
						STRING.erase(0, 1);
						//STRING.erase(STRING.size() - 1, STRING.size());
						indexCh1 = STRING.find(",");
						substr = STRING.substr(0, indexCh1);
						size++;
						input.resize(size);
						input[size - 1] = stoi(substr);
						STRING.erase(0, indexCh1 + 1);
						//continue;
					}
					break;
				}
				else
				{
					while (!STRING.empty())
					{
						STRING.erase(0, 1);
						//STRING.erase(STRING.size() - 1, STRING.size());
						indexCh1 = STRING.find(",");
						substr = STRING.substr(0, indexCh1);
						size++;
						input.resize(size);
						input[size - 1] = stoi(substr);
						STRING.erase(0, indexCh1 + 1);
						//continue;
					}
				}
				getline(infile, STRING);
			}
		}
		else if (STRING.find("output") != string::npos)
		{
			indexCh1 = STRING.find("t");
			STRING.erase(0, indexCh1 + 5);
			STRING = "    " + STRING;
			while (true)
			{
				STRING.erase(0, 3);
				if (STRING.find(";") != string::npos)
				{
					STRING.pop_back();
					STRING.push_back(',');
					while (!STRING.empty())
					{
						STRING.erase(0, 1);
						//STRING.erase(STRING.size() - 1, STRING.size());
						indexCh1 = STRING.find(",");
						substr = STRING.substr(0, indexCh1);
						size1++;
						output.resize(size1);
						output[size1 - 1] = stoi(substr);
						STRING.erase(0, indexCh1 + 1);
						//continue;
					}
					break;
				}
				else
				{
					while (!STRING.empty())
					{
						STRING.erase(0, 1);
						//STRING.erase(STRING.size() - 1, STRING.size());
						indexCh1 = STRING.find(",");
						substr = STRING.substr(0, indexCh1);
						size1++;
						output.resize(size1);
						output[size1 - 1] = stoi(substr);
						STRING.erase(0, indexCh1 + 1);
						//continue;
					}
				}
				getline(infile, STRING);
			}
		}
		else if (STRING.find("wire") != string::npos)
		{
			while (true)
			{
				if (STRING.find(";") != string::npos)
					break;
				else
				{
					getline(infile, STRING);
					continue;
				}
			}
		}
		else
		{
			size1 = 0;
			size2++;
			PartialNodes.resize(size2);
			indexCh1 = STRING.find("X1");
			PartialNodes[size2 - 1].gateName = STRING.substr(2, ((indexCh1 - 1) - 1));
			//ID = to_string(*counter);
			//*counter++;
			indexCh2 = STRING.rfind(")");
			indexCh3 = STRING.rfind("(");
			PartialNodes[size2 - 1].out = PartialNodes[size2 - 1].ID = STRING.substr((indexCh3 + 1), ((indexCh2 - 1) - (indexCh3 + 1)));
			STRING.erase(indexCh3 - 4, STRING.length());
			indexCh1 = STRING.find("(");
			STRING.erase(0, indexCh1 + 2);
			while (STRING.empty() == false)
			{
				size1++;
				PartialNodes[size2 - 1].input.resize(size1);
				indexCh1 = STRING.find("(");
				indexCh2 = STRING.find(")");
				substr = STRING.substr((indexCh1 + 1), (indexCh2 - indexCh1 - 1));
				indexCh1 = substr.find("\\");
				if (indexCh1 != string::npos)
				{
					indexCh3 = substr.find(" ");
					substr = substr.substr(indexCh1 + 1, (indexCh3 - (indexCh1 + 1)));
				}
				/*for (int j = 0; j < substr.length(); j++)
				{
					if (substr[j] == ' ' || substr[j] == '\\')
						substr.erase(j);
				}*/
				PartialNodes[size2 - 1].input[size1 - 1] = substr;
				STRING.erase(0, indexCh2 + 1);
			}
			PartialNodes[size2 - 1].numberOfInputs = size1;
		}
	}
	infile.close();
}


void PartialStructToNodesStruct(vector<PartialNode> &PartialNodes, vector<nodes> &Node, int *counter)
{
	int i, j, z, k;
	string substr;
	Node.resize(PartialNodes.size());
	for (i = 0; i < PartialNodes.size(); i++)
	{
		for (j = 0; j < PartialNodes[i].numberOfInputs; j++)
		{
			if (PartialNodes[i].input[j].find("n") != string::npos)
			{
				substr = PartialNodes[i].input[j];
				PartialNodes[i].input[j] = to_string(*counter);
				for (k = 0; k < PartialNodes.size(); k++)
				{
					for (z = 0; z < PartialNodes[k].numberOfInputs; z++)
					{
						if (PartialNodes[k].input[z] == substr)
							PartialNodes[k].input[z] == to_string(*counter);
					}
					if (PartialNodes[k].out == substr)
						PartialNodes[k].out = to_string(*counter);
				}
				*counter = *counter + 1;
			}
		}
		if (PartialNodes[i].out.find("n") != string::npos)
		{
			substr = PartialNodes[i].out;
			PartialNodes[i].out = PartialNodes[i].ID = to_string(*counter);
			for (k = 0; k < PartialNodes.size(); k++)
			{
				for (z = 0; z < PartialNodes[k].numberOfInputs; z++)
				{
					if (PartialNodes[k].input[z] == substr)
						PartialNodes[k].input[z] = to_string(*counter);
				}
			}
			*counter = *counter + 1;
		}
		if (PartialNodes[i].gateName == "INV")
			PartialNodes[i].gateName = "NOT";
		else if (PartialNodes[i].gateName == "BUFF")
			PartialNodes[i].gateName = "BUFF";
		else
			PartialNodes[i].gateName = PartialNodes[i].gateName.substr(0 , PartialNodes[i].gateName.size() - 1);
		Node[i].gate = PartialNodes[i].gateName;
		Node[i].ID = stoi(PartialNodes[i].ID);
		Node[i].input.resize(PartialNodes[i].numberOfInputs);
		for (k = 0; k < PartialNodes[i].numberOfInputs; k++)
			Node[i].input[k] = stoi(PartialNodes[i].input[k]);
		Node[i].numberOfInputs = PartialNodes[i].numberOfInputs;
		Node[i].out = stoi(PartialNodes[i].out);
	}
}


void NodeStructToBench(vector<int> &input, vector<nodes> &Node, vector<int> &output, string FileName)
{
	int i, j;
	ofstream outfile;
	outfile.open(FileName, ios::out | ios::trunc);
	outfile << "# Partial Circuit Generated For Aging Optimization" << endl;
	for (i = 0; i < input.size(); i++)
		outfile << endl << "INPUT(" << to_string(input[i]) << ")";
	for (i = 0; i < output.size(); i++)
		outfile << endl << "OUTPUT(" << to_string(output[i]) << ")";
	for (i = 0; i < Node.size(); i++)
	{
		if (Node[i].gate == "NOT")
			//outfile << to_string(Node[i].out) << " = " << Node[i].gate << "(" << to_string(Node[i].input[0]) << ")";
			outfile << endl << to_string(Node[i].out) << " = " << "NOT" << "(" << to_string(Node[i].input[0]);
		else if (Node[i].gate == "BUFF")
			outfile << endl << to_string(Node[i].out) << " = " << "BUFF" << "(" << to_string(Node[i].input[0]);
		else
			outfile << endl << to_string(Node[i].out) << " = " << Node[i].gate << "(" << to_string(Node[i].input[0]) << ",";
		for (j = 1; j < Node[i].numberOfInputs; j++)
		{
			if (j == (Node[i].numberOfInputs - 1))
				outfile << " " << to_string(Node[i].input[j]);
			else
				outfile << " " << to_string(Node[i].input[j]) << ",";
		}
		outfile << ")";
	}
	outfile.close();
}


void ChangeBench(vector<gate> &topological, vector<int> &input, vector<int> &output, string PartialBench, string OptimizedBench)
{
	int i, j;
	string STRING;
	fstream infile;
	infile.open(PartialBench);
	ofstream outfile;
	outfile.open(OptimizedBench, ios::out | ios::trunc);
	outfile << "# Aging-aware Optimized Circuit:" << endl;
	for (i = 0; i < input.size(); i++)
		outfile << endl << "INPUT(" << to_string(input[i]) << ")";
	for (i = 0; i < output.size(); i++)
		outfile << endl << "OUTPUT(" << to_string(output[i]) << ")";
	for (i = 0; i < topological.size(); i++)
	{
		if (topological[i].getIndex() == true)
			continue;
		if (topological[i].getGateName() == "INPUT")
			continue;
		if (topological[i].getGateName() == "NOT")
			outfile << endl << to_string(topological[i].getID()) << " = " << topological[i].getGateName() << "(" << to_string(topological[i].getInputs()[0]);
		else if (topological[i].getGateName() == "BUFF")
			outfile << endl << to_string(topological[i].getID()) << " = " << topological[i].getGateName() << "(" << to_string(topological[i].getInputs()[0]);
		else
			outfile << endl << to_string(topological[i].getID()) << " = " << topological[i].getGateName() << "(" << to_string(topological[i].getInputs()[0]) << ",";
		for (j = 1; j < topological[i].getInputs().size(); j++)
		{
			if (j == (topological[i].getInputs().size() - 1))
				outfile << " " << to_string(topological[i].getInputs()[j]);
			else
				outfile << " " << to_string(topological[i].getInputs()[j]) << ",";
		}
		outfile << ")";
	}
	while (!infile.eof())
	{
		getline(infile, STRING);
		if (STRING.find("INPUT") != string::npos || STRING.find("OUTPUT") != string::npos || STRING.find("#") != string::npos || STRING == "")
			continue;
		outfile << endl << STRING;
	}
	infile.close();
	outfile.close();
}


void RandomCircuitGenerator(int i)
{
	if (i==0)
		system("abc10216.exe -F commands.txt");
	else if (i == 1)
		system("abc10216.exe -F commands1.txt");
	else if (i == 2)
		system("abc10216.exe -F commands2.txt");
	else if (i == 3)
		system("abc10216.exe -F commands3.txt");
	else if (i == 4)
		system("abc10216.exe -F commands4.txt");
	else if (i == 5)
		system("abc10216.exe -F commands5.txt");
	else if (i == 6)
		system("abc10216.exe -F commands6.txt");
	else if (i == 7)
		system("abc10216.exe -F commands7.txt");
	else if (i == 8)
		system("abc10216.exe -F commands8.txt");
	else if (i == 9)
		system("abc10216.exe -F commands9.txt");
	else if (i == 10)
		system("abc10216.exe -F commands10.txt");
	else if (i == 11)
		system("abc10216.exe -F commands11.txt");
	else if (i == 12)
		system("abc10216.exe -F commands12.txt");
	else if (i == 13)
		system("abc10216.exe -F commands13.txt");
	else if (i == 14)
		system("abc10216.exe -F commands14.txt");
	else if (i == 15)
		system("abc10216.exe -F commands15.txt");
	else
		system("abc10216.exe -F commands15.txt");
}


//void PartialBenchMaker(vector<gate> &topological, string FileName)
//{
//	int i, j, k, z;
//	int size = 0, size1 = 0;
//	bool flag, flag1;
//	ofstream outfile;
//	outfile.open(FileName, ios::out | ios::trunc);
//	vector<int> input, output;
//	vector<gate> PartialBench;
//	for (i = 0; i < topological.size(); i++)
//	{
//		if (topological[i].getIndex() == true)
//		{
//			size++;
//			PartialBench.resize(size);
//			PartialBench[size - 1] = topological[i];
//			topological[i].setIndex(false);
//		}
//	}
//	size = 0;
//	for (i = 0; i < PartialBench.size(); i++)
//	{
//		if (PartialBench[i].getGateName() == "INPUT")
//			continue;
//		flag = true;
//		z = 0;
//		for (j = 0; j < PartialBench.size(); j++)
//		{
//			for (k = 0; k < PartialBench[j].getInputs().size(); k++)
//			{
//				if (PartialBench[i].getID() == PartialBench[j].getInputs()[k])
//				{
//					flag = false;
//					z++;
//					//break;
//				}
//			}
//		}
//		if (flag == true)
//		{
//			size++;
//			output.resize(size);
//			output[size - 1] = PartialBench[i].getID();
//		}
//		else if (z < PartialBench[i].output.size())
//		{
//			size++;
//			output.resize(size);
//			output[size - 1] = PartialBench[i].getID();
//		}
//	}
//	for (i = 0; i < PartialBench.size(); i++)
//	{
//		if (PartialBench[i].getGateName() == "INPUT")
//		{
//			size1++;
//			input.resize(size1);
//			input[size1 - 1] = PartialBench[i].getID();
//			continue;
//		}
//		for (j = 0; j < PartialBench[i].getInputs().size(); j++)
//		{
//			flag1 = true;
//			for (k = 0; k < PartialBench.size(); k++)
//			{
//				if (PartialBench[k].getGateName() == "INPUT")
//					continue;
//				if (PartialBench[i].getInputs()[j] == PartialBench[k].getID())
//				{
//					flag1 = false;
//					break;
//				}
//			}
//			if (flag1 == true)
//			{
//				size1++;
//				input.resize(size1);
//				input[size1 - 1] = PartialBench[i].getInputs()[j];
//			}
//		}
//	}
//	for (i = 0; i < input.size(); i++)
//	{
//		for (j = i + 1; j < input.size(); j++)
//		{
//			if (input[i] == input[j])
//				input[j] = -1;
//		}
//	}
//	for (i = 0; i < output.size(); i++)
//	{
//		for (j = i + 1; j < output.size(); j++)
//		{
//			if (output[i] == output[j])
//				output[j] = -1;
//		}
//	}
//	outfile << "# Partial Circuit Generated For Aging Optimization" << endl;
//	for (i = 0; i < input.size(); i++)
//	{
//		if (input[i] == -1)
//			continue;
//		outfile << endl << "INPUT(" << input[i] << ")";
//	}
//	for (i = 0; i < output.size(); i++)
//	{
//		if (output[i] == -1)
//			continue;
//		outfile << endl << "OUTPUT(" << output[i] << ")";
//	}
//	for (i = 0; i <PartialBench.size(); i++)
//	{
//		if (PartialBench[i].getGateName() == "INPUT")
//			continue;
//		if (PartialBench[i].getGateName() == "NOT")
//			outfile << endl << to_string(PartialBench[i].getID()) << " = " << PartialBench[i].getGateName() << "(" << to_string(PartialBench[i].getInputs()[0]);
//		else if (PartialBench[i].getGateName() == "BUFF")
//			outfile << endl << to_string(PartialBench[i].getID()) << " = " << PartialBench[i].getGateName() << "(" << to_string(PartialBench[i].getInputs()[0]);
//		else
//			outfile << endl << to_string(PartialBench[i].getID()) << " = " << PartialBench[i].getGateName() << "(" << to_string(PartialBench[i].getInputs()[0]) << ",";
//		for (j = 1; j < PartialBench[i].getInputs().size(); j++)
//		{
//			if (j == (PartialBench[i].getInputs().size() - 1))
//				outfile << " " << to_string(PartialBench[i].getInputs()[j]);
//			else
//				outfile << " " << to_string(PartialBench[i].getInputs()[j]) << ",";
//		}
//		outfile << ")";
//	}
//}


void PartialBenchMaker1(vector<gate> &PartialBench, string FileName)
{
	int i, j, k, z;
	int size = 0, size1 = 0;
	bool flag, flag1;
	ofstream outfile;
	outfile.open(FileName, ios::out | ios::trunc);
	vector<int> input, output;
	//vector<gate> PartialBench;
/*	for (i = 0; i < PartialTopological.size(); i++)
	{
		if (PartialTopological[i].getIndex() == true)
		{
			size++;
			PartialBench.resize(size);
			PartialBench[size - 1] = PartialTopological[i];
			topological[i].setIndex(false);
		}
	}*/
	size = 0;
	for (i = 0; i < PartialBench.size(); i++)
	{
		if (PartialBench[i].getGateName() == "INPUT")
			continue;
		flag = true;
		z = 0;
		for (j = 0; j < PartialBench.size(); j++)
		{
			for (k = 0; k < PartialBench[j].getInputs().size(); k++)
			{
				if (PartialBench[i].getID() == PartialBench[j].getInputs()[k])
				{
					flag = false;
					z++;
				}
			}
		}
		if (flag == true)
		{
			size++;
			output.resize(size);
			output[size - 1] = PartialBench[i].getID();
		}
		else if (z < PartialBench[i].output.size())
		{
			size++;
			output.resize(size);
			output[size - 1] = PartialBench[i].getID();
		}
	}
	for (i = 0; i < PartialBench.size(); i++)
	{
		if (PartialBench[i].getGateName() == "INPUT")
		{
			size1++;
			input.resize(size1);
			input[size1 - 1] = PartialBench[i].getID();
			continue;
		}
		for (j = 0; j < PartialBench[i].getInputs().size(); j++)
		{
			flag1 = true;
			for (k = 0; k < PartialBench.size(); k++)
			{
				if (PartialBench[k].getGateName() == "INPUT")
					continue;
				if (PartialBench[i].getInputs()[j] == PartialBench[k].getID())
				{
					flag1 = false;
					break;
				}
			}
			if (flag1 == true)
			{
				size1++;
				input.resize(size1);
				input[size1 - 1] = PartialBench[i].getInputs()[j];
			}
		}
	}
	for (i = 0; i < input.size(); i++)
	{
		for (j = i + 1; j < input.size(); j++)
		{
			if (input[i] == input[j])
				input[j] = -1;
		}
	}
	for (i = 0; i < output.size(); i++)
	{
		for (j = i + 1; j < output.size(); j++)
		{
			if (output[i] == output[j])
				output[j] = -1;
		}
	}
	outfile << "# Partial Circuit Generated For Aging Optimization" << endl;
	for (i = 0; i < input.size(); i++)
	{
		if (input[i] == -1)
			continue;
		outfile << endl << "INPUT(" << input[i] << ")";
	}
	for (i = 0; i < output.size(); i++)
	{
		if (output[i] == -1)
			continue;
		outfile << endl << "OUTPUT(" << output[i] << ")";
	}
	for (i = 0; i <PartialBench.size(); i++)
	{
		if (PartialBench[i].getGateName() == "INPUT")
			continue;
		if (PartialBench[i].getGateName() == "NOT")
			outfile << endl << to_string(PartialBench[i].getID()) << " = " << PartialBench[i].getGateName() << "(" << to_string(PartialBench[i].getInputs()[0]);
		else if (PartialBench[i].getGateName() == "BUFF")
			outfile << endl << to_string(PartialBench[i].getID()) << " = " << PartialBench[i].getGateName() << "(" << to_string(PartialBench[i].getInputs()[0]);
		else
			outfile << endl << to_string(PartialBench[i].getID()) << " = " << PartialBench[i].getGateName() << "(" << to_string(PartialBench[i].getInputs()[0]) << ",";
		for (j = 1; j < PartialBench[i].getInputs().size(); j++)
		{
			if (j == (PartialBench[i].getInputs().size() - 1))
				outfile << " " << to_string(PartialBench[i].getInputs()[j]);
			else
				outfile << " " << to_string(PartialBench[i].getInputs()[j]) << ",";
		}
		outfile << ")";
	}
}


void CopyBench(string SourceFile, string DestinationFile)
{
	string STRING;
	ofstream outfile;
	outfile.open(DestinationFile, ios::out | ios::trunc);
	fstream infile;
	infile.open(SourceFile);
	while (!infile.eof())
	{
		getline(infile, STRING);
		outfile << endl << STRING;
	}
	infile.close();
	outfile.close();
}