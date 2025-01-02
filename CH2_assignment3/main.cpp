#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>   //Ŭ���� ���ø� ���
class SimpleVector {
private:
    T* data;            //��ü ������ �Էµ� ���� �ڷ����� ���߾� ������
    int currentSize;    //���� �迭�� �Ҵ�� ������ ����
    int currentCapacity;//���� �迭�� ũ��
    void resize();      //�ʼ� ��ɿ����� ������� �ʴ´�.

public:
    //
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[10];
        cout << "�뷮�� 10�� �迭�� �����Ǿ����ϴ�." << endl;
    }
    SimpleVector(int capacity) {
        currentCapacity = capacity;
        currentSize = 0;
        data = new T[capacity];
        cout << "ũ�Ⱑ " << capacity << "�� �迭�� �����Ǿ����ϴ�." << endl << endl;
    }
    ~SimpleVector() {
        delete[] data;
    }
    void push_back(const T& x) {
        if (currentSize < currentCapacity) {
            data[currentSize] = x;
            cout << "�Է¹��� " << x << "�� �� �ڿ� �߰��մϴ�" << endl;
            currentSize++;
            cout << "������ ������ " << currentSize << "�� �Ǿ����ϴ�." << endl << endl;
        }
        else cout << "�迭�� ���� á���ϴ�." << endl << endl;
    }
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
            cout << "������ ������ " << currentSize << "�� �پ������ϴ�." << endl << endl;
        }
        else cout << "�̹� ������ ������ 0 �Դϴ�." << endl << endl;
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
        cout << "��������ϴ� �迭�� ũ�⸦ �Է��� �ּ���." << endl;
        cin >> capacity;
        if (capacity <= 0) cout << "����� ���� �Է����ּ���." << endl;
    }
    SimpleVector<int> vec(capacity);    // �ٸ� �ڷ����� ������� int�� �ٲٸ� ��  
    int input;                          // ���� �ڷ����� ���� Ÿ������ �ٲ���� ��

    for (char i = 'a'; i != 'x';) {
        cout << "� �۾��� �Ͻðڽ��ϱ�? (1 : push_back / 2 : pop_back / x : �۾�����)" << endl;
        cin >> i;
        switch (i) {
        case '1':
            cout << "�迭�� �Է��� ���� �����ּ���." << endl;
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
    cout << "������� �迭�� ũ��� :" << vec.capacity() << endl << "�迭���� ������ ������ :" << vec.size() << endl;
    cout << "������� �迭�� { ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.getData(i) << " ";
    }
    cout << "} �Դϴ�.";
    return 0;
}
