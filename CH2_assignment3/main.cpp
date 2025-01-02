#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>   //클래스 템플릿 사용
class SimpleVector {
private:
    T* data;            //객체 생성시 입력된 값의 자료형에 맞추어 생성됨
    int currentSize;    //현재 배열에 할당된 원소의 개수
    int currentCapacity;//현재 배열의 크기
    void resize();      //필수 기능에서는 사용하지 않는다.

public:
    //
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[10];
        cout << "용량이 10인 배열이 생성되었습니다." << endl;
    }
    SimpleVector(int capacity) {
        currentCapacity = capacity;
        currentSize = 0;
        data = new T[capacity];
        cout << "크기가 " << capacity << "인 배열이 생성되었습니다." << endl << endl;
    }
    ~SimpleVector() {
        delete[] data;
    }
    void push_back(const T& x) {
        if (currentSize < currentCapacity) {
            data[currentSize] = x;
            cout << "입력받은 " << x << "을 맨 뒤에 추가합니다" << endl;
            currentSize++;
            cout << "원소의 개수는 " << currentSize << "가 되었습니다." << endl << endl;
        }
        else cout << "배열이 가득 찼습니다." << endl << endl;
    }
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
            cout << "원소의 개수가 " << currentSize << "로 줄어들었습니다." << endl << endl;
        }
        else cout << "이미 원소의 개수는 0 입니다." << endl << endl;
    }
    int size() {
        return currentSize;
    }
    int capacity() {
        return currentCapacity;
    }
    T getData(int num) {
        return data[num];
    }

};

int main() {
    int capacity = 0;
    while (capacity <= 0) {
        cout << "만들고자하는 배열의 크기를 입력해 주세요." << endl;
        cin >> capacity;
        if (capacity <= 0) cout << "양수의 값을 입력해주세요." << endl;
    }
    SimpleVector<int> vec(capacity);    // 다른 자료형을 만들려면 int를 바꾸면 됨  
    int input;                          // 위의 자료형과 같은 타입으로 바꿔줘야 함

    for (char i = 'a'; i != 'x';) {
        cout << "어떤 작업을 하시겠습니까? (1 : push_back / 2 : pop_back / x : 작업종료)" << endl;
        cin >> i;
        switch (i) {
        case '1':
            cout << "배열에 입력할 수를 적어주세요." << endl;
            cin >> input;
            vec.push_back(input);
            break;
        case '2':
            vec.pop_back();
            break;
        case 'x':
            break;
        }
    }
    cout << "만들어진 배열의 크기는 :" << vec.capacity() << endl << "배열안의 원소의 개수는 :" << vec.size() << endl;
    cout << "만들어진 배열은 { ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.getData(i) << " ";
    }
    cout << "} 입니다.";
    return 0;
}
