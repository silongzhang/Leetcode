#pragma once

#include"Header.h"


constexpr auto Seven = 7;
constexpr auto TwentyFour = 24;
constexpr auto Ten = 10;
constexpr auto DECI = 0.1;
constexpr auto CENTI = 1e-2;
constexpr auto MILLI = 1e-3;
constexpr auto PPM = 1e-6;
constexpr auto InfinityPos = 9999999999;
constexpr auto InfinityNeg = -InfinityPos;


typedef int IDType;
typedef int FleetType;
typedef double TimeType;
typedef double LengthType;
typedef double DraftType;
typedef double QuantityType;
typedef double MoneyType;
typedef double SpeedType;
typedef double BunkerType;
typedef double DualType;


typedef IloArray<IloNumVarArray> IloNumVarArray2;
typedef IloArray<IloNumVarArray2> IloNumVarArray3;
typedef IloArray<IloNumVarArray3> IloNumVarArray4;
typedef IloArray<IloIntVarArray> IloIntVarArray2;
typedef IloArray<IloBoolVarArray> IloBoolVarArray2;
typedef IloArray<IloBoolVarArray2> IloBoolVarArray3;


void printErrorAndExit(const string &str);
double runTime(const clock_t &start);
string getNowTime();
bool lessThanReal(const double &lhs, const double &rhs);
bool greaterThanReal(const double &lhs, const double &rhs);
bool equalToReal(const double &lhs, const double &rhs);
bool lessThanReal(const double &lhs, const double &rhs, const double &threshold);
bool greaterThanReal(const double &lhs, const double &rhs, const double &threshold);
bool equalToReal(const double &lhs, const double &rhs, const double &threshold);
void printSeparator(const int &numOfEnter, const int &vertical, const int &horizontal, 
	const char &character);
void printSeparator(const int &numOfEnter, const int &vertical, const int &horizontal,
	const char &character, ofstream &os);


template<typename T>
IDType getID(const T &rhs) { return rhs.getID(); }


template<typename T>
void print(const T &cont, const int &num) {
	int i = 0;
	for (const auto &elem : cont) {
		cout << elem << '\t';
		if (++i % num == 0) { cout << endl; }
	}
}


class thread_guard
{
private:
	thread &t;
public:
	//构造函数
	explicit thread_guard(thread &myT) :t(myT) {}
	//析构函数
	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	thread_guard(const thread_guard &) = delete;
	thread_guard& operator=(const thread_guard &) = delete;
};

