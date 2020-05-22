﻿#include "cezar_atd.h"
#include <string>

using namespace std;
const int maxStringeSize = 80;

namespace simple_codes {
	void cezar::InData(ifstream& ifst)
	{
		ifst >> rot;
		ifst >> message;
		ifst >> owner;
	}

	string codingCezar(char message[maxStringeSize], int rot)
	{
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < maxStringeSize)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) 
		{
			int tmp = alf.find(str_mes[i]);
			if (tmp >= 0)
				str_mes[i] = alf[(tmp + (rot % 26)) % 26];
			tmp = ALF.find(str_mes[i]);
			if (tmp >= 0)
				str_mes[i] = ALF[(tmp + (rot % 26)) % 26];
		}
		return str_mes;
	}

	void cezar::Out(ofstream& ofst)
	{
	
		ofst << "It is Cezar: rot = " << rot
			<< ", open = " << message
			<< ", code = " << codingCezar(message, rot)
			<< ", owner = " << owner << ". ";
	}

	int cezar::MesLength()
	{
		int length = 0;
		while (message[length] != '\0' && length < maxStringeSize) length++;
		return length;
	}
} 