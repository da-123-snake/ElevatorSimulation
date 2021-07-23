#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class People {
private:
	int ArrivalTime, CurrentFloor, Destination, ExitTime, WaitTime, Direction, Id;
	bool if_OnElevator;//是否在电梯上

public:
	People(int arrive = -1, int ID = -1, int numFloor = -1);
	int getArrivalTime();
	int getCurrentFloor();
	int getDestination();
	int getExitTime();
	int getWaitTime();
	int getId();
	int getDirection();//向上返回1，向下返回0
	bool get_if_OnElevator();
	void set_if_OnElevator(bool a); 
	void setArrivalTime(int AT);
	void setExitTime(int ET);
	void setCurrentFloor(int CF);
	void setDestination(int Destin);
	void setDirection(int D);//向上设为1，向下设为0
	void setId(int ID);
};

class Elevator {
private:
	vector <People> Elevator_People; // 用于存储电梯里面的人
	int Elevator_Current_Floor;		// 电梯所在楼层
	int Elevator_Number;	// 电梯号
	bool If_Empty;//判断电梯是否为空，空为true,不空为false
public:
	Elevator(); 
	Elevator(int ID); 
	bool get_If_Empty();
	void set_and_print_Elevator_Current_Floor(int f);
	void setElevatorNumber(int n);
	void set_If_Empty(bool i);
	vector <People> getElevator_People();
	int getElevator_Current_Floor();
	int getElevatorNumber();
	bool still_exiting(); //检查是否有人要下电梯
	void load_Elevator_People(People &p); //把人放入电梯容器
	People exit_Elevator_People(int cf); // 下电梯
};

class Building
{
private:
	int elevator_Num, floor_Num;
	vector<Elevator> Elevator_vec; //电梯容器，用于存储电梯
	vector<vector<People>> Floor_vec; //楼层容器，用于存储楼层，以及各楼层的人
public:
	Building(int e_num, int f_num);
	int get_elevators();
	int get_floors();
	vector <Elevator> get_ElevatorVec();
	vector<vector<People>> get_FloorVec();
	void set_elevators(int e);
	void set_floors(int f);
	void add_People_Floor(People p); //把人加到楼层容器中
	void loading_people(int e, int f, int tag); //让f楼层的人上电梯
	int Function(int count, queue<People>& Exitors, int max_floor);
};