#include <iostream>

/* 用栈模拟队列*/

template<typename T> class CQueue{
public:
	CQueue();
	~CQueue();

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue::appendTail(const T& node){
	stack1.push(node);
}

template<typename T>
T deleteHead(){
	if (stack2.empty()){ // 只有当stack2为空时才需要将stack1中的数据导入过来
		while (!stack1.empty()){
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	if (stack2.empty())
		throw new exception("queue is empty!");

	T node = stack2.top();
	stack2.pop();

	return node;
}

int main(){



	return 0;
}