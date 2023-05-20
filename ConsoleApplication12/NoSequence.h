#pragma once
#include<vector>
class NoSequence
{
private:
	bool init;
	int prevEl;
	int counter;
	vector<int>list;
public:
	NoSequence(): init {false}, prevEl{0}{}
	NoSequence();
	bool operator()(int el) 
	{
		if (init) 
		{
			bool result{ prevEl != el };
			if (result) 
			{

				prevEl = el;
			}
			return result;
		}
		init = true;
		prevEl = el;
		return true;
	}
	bool operator()(int el, int n)
	{
		if (init) 
		{
			if (list[list.size() - 1] != 0) 
			{
				
				 if (!IsInVector(el)) 
				 {
                  list[counter] = el;
				  counter++;
				  return false;
				 }
		    }
			else
			{
				if (!IsInVector(el))return true;
			}
		}
		else { list.resize(n); counter = 0; }
		init = true;

	}
	bool IsInVector(int el) 
	{
		for (int item : list) 
		{
			if (item == el) return true;
		}
		return false;
	}
};

