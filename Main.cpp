#include<thread>
#include "Building.h"
#include"Function.h"
int main() {
	bool ft = true;
	cout << "欢迎使用电梯模拟器，在本模拟器中，您可以创建一栋楼，确定里面的电梯" << endl;
	cout<<"数目和楼层数，然后输入需要乘坐电梯的乘客数量，即可开始模拟。\n\n请输入数字以选择功能:" << endl;
	while (ft) {
		run(ft);
	}
	return 0;
}
