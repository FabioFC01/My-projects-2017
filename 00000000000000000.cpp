#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdio.h>  

using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
	time_t data;
	tm *dataInfo;
	data = time(NULL); // ottiene l' ora odierna
	dataInfo = localtime(&data); // converte data in una struttura tm (nota il passaggio per indirizzo)
	cout << "Data odierna:\n";
	cout << dataInfo->tm_mday << "/" << dataInfo->tm_mon << "/" << dataInfo->tm_year + 1900;
	cout << "\nPremi invio per continuare... ";
	while (getchar() != '\n');
	return 0;
}