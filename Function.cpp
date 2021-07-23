#include"Function.h"
void getParameter(int& e_num, int& f_num, int& p_num)
{
	cout << "_________________________________________________________\n\n现在开始模拟：" << endl;
	cout << "请输入电梯数: ";
	cin >> e_num;
	cout << "请输入楼层数: ";
	cin >> f_num;
	while (f_num <= 1) { 
		cout << "数据有误，最少两层。\n";
		cin >> f_num;
	}
	cout << "请输入乘客数量: ";
	cin >> p_num;
	while (p_num <= 0) {
		cout << "数据有误，最少一个人。\n";
		cin >> p_num;
	}
	cout << "\n**********************************************************\n正在模拟中... \n";
}
void PrintPeople(vector<vector<People>> the_floors, int &max_floor)
{
	for (int k = 0; k < the_floors.size(); k++) { 
		while (the_floors[k].empty() == false) {
			cout << "  乘客 " << the_floors[k].back().getId() << ": \t所在楼层 " << the_floors[k].back().getCurrentFloor() << " \t目标楼层：" << the_floors[k].back().getDestination() << endl;
			if (max_floor < the_floors[k].back().getCurrentFloor())
				max_floor = the_floors[k].back().getCurrentFloor();
			the_floors[k].pop_back();
		}
	}
}
void run(bool& f)
{
	cout << "1.开始模拟\n" << "2.退出" << endl;
	srand(time(0));
	int choice;
	cin >> choice;
	//开始模拟
	if (choice == 1) {
		int e_num = -1; //电梯数
		int f_num = -1; //层数
		int p_num; //人数
		int max_floor = 1;//最高层数
		getParameter(e_num, f_num, p_num);
		Building My_Building(e_num, f_num); //创楼
		int count = 1; //次数
		int People_ID = 0; //人的编号
		int num_exited = 0; //出电梯的人数
		queue <People> Exit_People; //出电梯的人的队列
		for (int i = 0; i < p_num; i++) {  //初始化
			People the_People(count, People_ID, f_num); 
			People_ID++; 
			My_Building.add_People_Floor(the_People);
		}
		PrintPeople(My_Building.get_FloorVec(), max_floor);
		//cout << "***" << max_floor << " ** " << endl;
		while (num_exited < p_num) {
			cout << "\n··········第 " << count << " 次···········\n\n";
			num_exited += My_Building.Function(count, Exit_People, max_floor);
			count++;
		}
		cout << "\n模拟结束\n******************************************************\n\n总人数: " << p_num << endl;
		double sum = 0;
		while (!Exit_People.empty()) {
			People current = Exit_People.front();
			sum += current.getWaitTime();
			Exit_People.pop();
		}
		cout << "平均等待时间: " << sum / p_num << "\n__________________________________________________________";
		cout << endl << endl;
	}
	else if (choice == 2) { //结束
		f = false;
	}
}