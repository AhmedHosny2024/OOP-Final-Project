#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut,int id):m_OutputPin(r_FanOut)
{
	ID = id;
	set_selected(false);
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	isconnected = new bool[r_Inputs]; 
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++) {
		m_InputPins[i].setComponent(this);
		isconnected[i] = false;
	}
}
bool Gate::Isconnectto(int pin_number)
{
	if (isconnected[pin_number - 1] == false)
	{
		isconnected[pin_number - 1] = true;
		return true;
	}
	else
	{
		return false;
	}
}
/*
void Gate:: save(ofstream& outputfile)
{
	outputfile << "Gate" << "\t" << ID << "\t" <<get_label() <<"\t"<< m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}*/