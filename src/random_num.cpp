#include <iostream>
#include <cstdlib>   // 用于 rand() 和 srand()
#include <ctime>     // 用于 time()
#include <limits>    // 用于 std::numeric_limits
#include <algorithm> // 用于 std::max

using namespace std;

int main() {
    int difficulty;
    int secretNumber;
    int userGuess;
    int attempts = 0;
    int maxAttempts;

    // 设置随机数种子
    srand(static_cast<unsigned int>(time(0)));

    // 选择难度等级
    cout << "欢迎来到猜数字游戏！" << endl;
    cout << "请选择难度等级：" << endl;
    cout << "1. 简单（1-50，最多10次猜测）" << endl;
    cout << "2. 中等（1-100，最多7次猜测）" << endl;
    cout << "3. 困难（1-200，最多5次猜测）" << endl;
    cout << "请输入难度等级（1/2/3）：";
    cin >> difficulty;

    // 根据难度设置随机数范围和最大猜测次数
    switch (difficulty) {
        case 1:
            secretNumber = rand() % 50 + 1; // 生成1到50之间的随机数
            maxAttempts = 10;
            cout << "你选择了简单难度。数字范围是1到50，你有最多10次猜测机会。" << endl;
            break;
        case 2:
            secretNumber = rand() % 100 + 1; // 生成1到100之间的随机数
            maxAttempts = 7;
            cout << "你选择了中等难度。数字范围是1到100，你有最多7次猜测机会。" << endl;
            break;
        case 3:
            secretNumber = rand() % 200 + 1; // 生成1到200之间的随机数
            maxAttempts = 5;
            cout << "你选择了困难难度。数字范围是1到200，你有最多5次猜测机会。" << endl;
            break;
        default:
            cout << "无效的难度选择，游戏结束。" << endl;
            return 1; // 退出程序
    }

    // 开始游戏
    cout << "我已经想好了一个数字，现在轮到你了猜！" << endl;
    while (attempts < maxAttempts) {
        cout << "请输入你的猜测（剩余次数：" << maxAttempts - attempts << "）：";
        cin >> userGuess;

        if (cin.fail()) { // 检查输入是否有效
            cin.clear(); // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
            cout << "无效输入，请输入一个数字！" << endl;
            continue;
        }

        attempts++;

        if (userGuess < secretNumber) {
            cout << "太小了！" << endl;
        } else if (userGuess > secretNumber) {
            cout << "太大了！" << endl;
        } else {
            cout << "恭喜你！猜对了！答案是 " << secretNumber << "，你用了 " << attempts << " 次猜测。" << endl;
            return 0; // 游戏胜利，退出程序
        }
    }

    // 猜测次数用完仍未猜对
    cout << "很遗憾，你没有在限定次数内猜对。答案是 " << secretNumber << "。" << endl;

    return 0;
}