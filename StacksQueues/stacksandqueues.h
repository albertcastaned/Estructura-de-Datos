/*-----------------------------------------
 *	Actividad de Programacion: Stacks and Queues
 *	Fecha: 15-Oct-2018  
 *	Autor: A01250647 Alberto Castaneda Arana
 ------------------------------------------*/

#ifndef STACKSANDQUEUES_H_
#define STACKSANDQUEUES_H_

#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <stack>

using namespace std;

class StacksAndQueues
{
  private:
	queue<string> tokenize(string);
	bool hasHigherPrecedence(const string &, const string &);

  public:
	bool balancedBrackets(const string &);
	queue<int> merge(const queue<int> &, const queue<int> &);
	string convertInfixToPostfix(const string &);
};

queue<string> StacksAndQueues::tokenize(string str)
{
	int i = 0;
	int length = str.size();
	string aux;
	queue<string> result;

	while (i < length)
	{
		if (isdigit(str[i]))
		{
			aux.clear();
			do
			{
				aux += str[i];
				i++;
			} while (isdigit(str[i]));
			result.push(aux);
		}
		else if (isspace(str[i]))
		{
			i++;
		}
		else
		{
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

bool StacksAndQueues::hasHigherPrecedence(const string &stackTop, const string &op)
{
	return !((stackTop == string("+") || stackTop == string("-")) &&
			 (op == string("*") || op == string("/")));
}

bool StacksAndQueues::balancedBrackets(const string &expr)
{
	stack<char> simb;

	for (int i = 0; i < expr.size(); i++)
	{
		if ((expr[i] == '(') || (expr[i] == '[') || (expr[i] == '{'))
		{
			simb.push(expr[i]);
		}
		else if ((expr[i] == ')') || (expr[i] == ']') || (expr[i] == '}'))
		{
			if (simb.empty())
				return false;
			char top = simb.top();
			simb.pop();
			if (expr[i] == ')' && top != '(')
				return false;

			if (expr[i] == ']' && top != '[')
				return false;

			if (expr[i] == '}' && top != '{')
				return false;
		}
		else
		{
			continue;
		}
	}
	if (simb.empty())
		return true;
	else
		return false;
}

queue<int> StacksAndQueues::merge(const queue<int> &queue1, const queue<int> &queue2)
{
	queue<int> q1 = queue1;
	queue<int> q2 = queue2;

	queue<int> result;
	int temp;

	while (!q1.empty() && !q2.empty())
	{
		if (q1.front() < q2.front())
		{
			temp = q1.front();
			q1.pop();
			result.push(temp);
		}
		else if (q1.front() > q2.front())
		{
			temp = q2.front();
			q2.pop();
			result.push(temp);
		}
	}
	if (!q1.empty())
	{
		while (!q1.empty())
		{
			temp = q1.front();
			q1.pop();
			result.push(temp);
		}
	}
	else if (!q2.empty())
	{
		while (!q2.empty())
		{
			temp = q2.front();
			q2.pop();
			result.push(temp);
		}
	}
	temp = 0;
	return result;
}

string StacksAndQueues::convertInfixToPostfix(const string &expr)
{
	queue<string> resultado;
	stack<string> pila;
	queue<string> temp = tokenize(expr);

	while (!temp.empty())
	{
		if (isdigit(temp.front()[0]))
			resultado.push(temp.front());
		if (temp.front() == "(")
			pila.push(temp.front());
		if ((temp.front() == "+") || (temp.front() == "-") || (temp.front() == "*") || (temp.front() == "/"))
		{
			while (!pila.empty() && pila.top() != "(")
			{
				if (hasHigherPrecedence(pila.top(), temp.front()))
				{
					string topString = pila.top();
					pila.pop();
					resultado.push(topString);
				}
				else
					break;
			}
			pila.push(temp.front());
		}
		if (temp.front() == ")")
		{
			while (!pila.empty() && pila.top() != "(")
			{
				string topString = pila.top();
				pila.pop();
				resultado.push(topString);
			}
			if (!pila.empty())
			{
				pila.pop();
			}
		}
		temp.pop();
	}
	if (!pila.empty())
	{
		while (!pila.empty())
		{
			string topString = pila.top();
			pila.pop();
			resultado.push(topString);
		}
	}
	string resultString;
	while (!resultado.empty())
	{
		resultString += resultado.front();
		if (resultado.size() != 1)
			resultString += " ";
		resultado.pop();
	}

	return resultString;
}

#endif /* STACKSANDQUEUES_H_ */