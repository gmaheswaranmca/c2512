#include <iostream>
#include <cmath>
using namespace std;

bool swapNums(int number){
    int copyNumber=number;
    int counter=0;
    while (copyNumber>0){
        copyNumber = copyNumber/10;
		counter = counter + 1;
    }
    copyNumber = number;
	int sum = 0;
	while (copyNumber > 0){
		int temp = copyNumber % 10;
		sum = sum + (int)pow(temp,counter);
		copyNumber = copyNumber / 10;
	}
	if (sum == number){
		return true;
	}
	return false;
}

void isArmstrongTest(){
    int num;
    cout << "Enter number:";
    cin >> num;
    bool result=swapNums(num);
    if (result ==true){
        cout << "Armstrong number";
    }
    else{
        cout << "Not Armstrong";
    }
}

int main()
{
    isArmstrongTest();
    return 0;
}