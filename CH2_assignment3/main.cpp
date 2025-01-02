#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>   // 클래스 템플릿 사용
class SimpleVector {
private:
    T* data;            // 객체 생성시 입력된 값의 자료형에 맞추어 생성됨
    int currentSize;    // 현재 배열에 할당된 원소의 개수
    int currentCapacity;// 현재 배열의 크기
    void resize(int newCapacity) {
        if (currentCapacity >= newCapacity) cout << "입력된 크기가 현재 크기보다 작습니다." << endl;
        else {
            T* newData = new T[newCapacity];
            for (int i = 0; i < currentSize; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            currentCapacity = newCapacity;
        }
    }

public:
    // 입력받은 값이 없을 때의 생성자
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[10];   // 템플릿을 통해 입력받은 자료형의 객체를 생성한다.
        cout << "용량이 10인 배열이 생성되었습니다." << endl;
    }
    // 배열의 크기를 입력 받을 경우의 생성자
    SimpleVector(int capacity) {
        currentCapacity = capacity;
        currentSize = 0;
        data = new T[capacity]; // 템플릿을 통해 입력받은 자료형의 객체를 생성한다.
    }

    SimpleVector(const SimpleVector& others) {
        this->currentSize = others.currentSize;
        this->currentCapacity = others.currentCapacity;
        this->data = new T[this->currentCapacity];
        for (int i = 0; i < this->currentSize; i++) {
            this->data[i] = others.data[i];
        }
    }
    // 소멸자
    ~SimpleVector() {
        delete[] data;          // 프로그램이 종료될 때 data 객체도 함께 제거한다. (그러나 보이드 포인터에서는 작동되지 않는것 같다.)
    }
    void push_back(const T& x) {                // 템플릿을 통해 입력받은 자료형의 값을 배열에 넣는다.
        if (currentSize >= currentCapacity) {
            resize(currentCapacity + 5);
        }
        data[currentSize] = x;
        cout << "입력받은 " << x << "을 맨 뒤에 추가합니다" << endl;
        currentSize++;
        cout << "원소의 개수는 " << currentSize << "가 되었습니다." << endl << endl;
    }
    void pop_back() {                           // 원소의 개수를 줄인다.
        if (currentSize > 0) {
            currentSize--;
            cout << "원소의 개수가 " << currentSize << "로 줄어들었습니다." << endl << endl;
        }
        else cout << "이미 원소의 개수는 0 입니다." << endl << endl;
    }
    int size() {                // currentSize를 반환한다.
        return currentSize;
    }
    int capacity() {            // currentCapacity를 반환한다.
        return currentCapacity;
    }
    T getData(int num) {        // data에 저장된 값을 반환한다.
        return data[num];
    }

    void sortData() {
        sort(data, data + currentSize);
        cout << "배열의 정렬이 완료되었습니다." << endl << endl;
    }

};

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    int capacity = 0;       // 입력받을 배열의 크기
    while (capacity < 1) {
        cout << "만들고자하는 배열의 크기를 입력해 주세요." << endl;
        cin >> capacity;
        if (capacity < 1) cout << "양수의 값을 입력해주세요." << endl;
    }
    void* vecptr = nullptr; // AI의 도움으로 구현한 void포인터 (포인터의 포인터라고 불린다고 한다)
    string inputType;       // 입력받을 배열의 타입
    while (1) {
        cout << "만들고자하는 배열의 타입을 입력해 주세요. (int, string)" << endl; // 타입이 많아지면 너무 난잡해져서 2가지로만 했습니다.
        cin >> inputType;
        if (inputType == "int") {                       // 입력받은 자료형이 int 타입인 경우
            vecptr = new SimpleVector<int>(capacity);   // int 타입의 객체를 생성한다.
            break;                                      // 반복문 탈출
        }
        else if (inputType == "string") {               // 입력받은 자료형이 string 타입인 경우
            vecptr = new SimpleVector<string>(capacity);// string 타입의 객체를 생성한다.
            break;                                      // 반복문 탈출
        }
        else cout << "지원하지 않는 타입이거나 잘못된 타입입니다." << endl; // 잘못된 값 입력 시
    }

    cout << "크기가 " << capacity << "인 " << inputType << "배열이 생성되었습니다." << endl << endl;

    for (char i = 'a'; i != 'x';) {                     // 반복문을 통해 작업, x입력시 탈출
        cout << "어떤 작업을 하시겠습니까? (1 : push_back / 2 : pop_back / 3 : sort / x : 작업종료)" << endl;
        cin >> i;                                       // 선택지 입력
        switch (i) {
        case '1':
            cout << "배열에 입력할 수를 적어주세요." << endl;
            if (inputType == "int") {                   // 자료형이 int인 경우 작동
                int input;
                cin >> input;
                ((SimpleVector<int>*)vecptr)->push_back(input); // 이부분은 AI의 도움을 받았습니다. 보이드 포인터의 경우 이렇게 작성하면 된다는 것만 압니다. push_back() 메서드 호출
            }
            else if (inputType == "string") {           // 자료형이 string인 경우 작동
                string input;
                cin >> input;
                ((SimpleVector<string>*)vecptr)->push_back(input); // push_back() 메서드 호출
            }
            break;
        case '2':
            if (inputType == "int") {                   // 자료형이 int인 경우 작동
                ((SimpleVector<int>*)vecptr)->pop_back(); // pop_back() 메서드 호출
            }
            else if (inputType == "string") {              // 자료형이 string인 경우 작동
                ((SimpleVector<string>*)vecptr)->pop_back(); // pop_back() 메서드 호출
            }
            break;
        case '3':
            if (inputType == "int") {
                ((SimpleVector<int>*)vecptr)->sortData();
            }
            else if (inputType == "string") {
                ((SimpleVector<string>*)vecptr)->sortData();
            }
            break;
        case 'x':                                       // 반복문 종료
            break;
        }
    }
    if (inputType == "int") {                           // 최종적으로 만들어진 int 배열 출력
        cout << "만들어진 배열의 크기는 :" << ((SimpleVector<int>*)vecptr)->capacity() << endl << "배열안의 원소의 개수는 :" << ((SimpleVector<int>*)vecptr)->size() << endl;
        cout << "만들어진 배열은 { ";
        for (int i = 0; i < ((SimpleVector<int>*)vecptr)->size(); i++) {    // 입력된 원소의 개수만큼 반복
            cout << ((SimpleVector<int>*)vecptr)->getData(i) << " ";        // 저장된 배열을 출력
        }
        cout << "} 입니다.";
        delete (SimpleVector<int>*)vecptr;              // 보이드 포인터는 따로 제거해줘야한다고 한다.
    }
    if (inputType == "string") {                        // 최종적으로 만들어진 string 배열 출력
        cout << "만들어진 배열의 크기는 :" << ((SimpleVector<string>*)vecptr)->capacity() << endl << "배열안의 원소의 개수는 :" << ((SimpleVector<string>*)vecptr)->size() << endl;
        cout << "만들어진 배열은 { ";
        for (int i = 0; i < ((SimpleVector<string>*)vecptr)->size(); i++) { // 입력된 원소의 개수만큼 반복
            cout << ((SimpleVector<string>*)vecptr)->getData(i) << " ";     // 저장된 배열을 출력
        }
        cout << "} 입니다.";
        delete (SimpleVector<string>*)vecptr;           // 보이드 포인터는 따로 제거해줘야한다고 한다.
    }
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    return 0;
}
